import csv

bug_class = "dataset/CISB-dataset-classification.csv"
bug_detail = "dataset/CISB-dataset-detailed-info.csv"

class unique_bug:
    def __init__(self, id, bug_class):
        self.id = id
        self.id_alias_list = self.id.split(' ')
        self.bug_class = bug_class
        self.occurance = []

bugs = []
with open(bug_class, mode = 'r', encoding='utf-8-sig') as c:
    reader = csv.DictReader(c)
    class_rows = list(reader)

# ubug_id_index = reader.fieldnames.index('Unique bug id')
# ubug_class_idx = reader.fieldnames.index('Insecure optimization behaviors')
bug_class_map = {
    "Eliminating security related code": "IS1",
    "Reordering order-sensitive security code": "IS2",
    "Introducing insecure instructions": "IS3",
    "Making sensitive data out of bound": "OS1",
    "Breaking timing guarantees": "OS2",
    "Introducing insecure micro-architectural side effect": "OS3"
}

for line in class_rows:
    if line:
        bid = line["Unique bug id"]
        bclass= bug_class_map[line["Insecure optimization behaviors"]]
        new_bug = unique_bug(bid, bclass)
        bugs.append(new_bug)   

with open(bug_detail, mode = 'r', encoding='utf-8-sig') as t:
    reader = csv.DictReader(t)
    detail_rows = list(reader)

for line in detail_rows:
    if line:
        bid = line["Unique bug id"]
        byear = line["Year"]
        # bkey = line[bug_key_idx]
        for b in bugs:
            if bid in b.id_alias_list:
                b.occurance.append(byear)
                break
        else:
            print('unknown bug', line)            

s = set()
for b in bugs:
    if set(b.id_alias_list).intersection(s):
        print('bug id is not unique')
        print(b.id, set(b.id_alias_list).intersection(s))
        exit(0)
    s.update(b.id_alias_list)

def table_2():
    taxonomy = ['IS1', 'IS2', 'IS3', 'OS1', 'OS2', 'OS3']
    num_all = 0
    for b in bugs:
        num_all += len(b.occurance)

    bug_occ = dict()
    with open(bug_detail, mode = 'r', encoding='utf-8-sig') as t:
        reader = csv.DictReader(t)
        detail_rows = list(reader)
    for line in detail_rows:
        if line:
            bid = line["Unique bug id"]
            byear = line["Year"]
            bug_occ.setdefault(bid, []).append(byear) 

    data = []
    for bc in taxonomy:
        num_ubug = num_bug = 0
        num_bugzilla_ubug = num_bugzilla_bug = 0
        num_linux_ubug = num_linux_bug = 0
        for b in bugs:
            if b.bug_class == bc:
                num_ubug += 1
                num_bug += len(b.occurance)
                for alias in b.id_alias_list:
                    if alias not in bug_occ.keys():
                        print('Unique bug not found ', alias)
                        continue
                    # alias bugs are the same unique bug 
                    b_counted = l_counted = False
                    if alias.startswith('b-'):
                        if not b_counted:
                            num_bugzilla_ubug += 1
                            b_counted = True
                        num_bugzilla_bug += len(bug_occ[alias])
                    elif alias.startswith('l-'):
                        if not l_counted:
                            num_linux_ubug += 1
                            l_counted = True
                        num_linux_bug += len(bug_occ[alias])

        row = [num_ubug, num_bug]
        row += [num_bug/num_all]
        row += [num_bugzilla_ubug, num_bugzilla_bug]
        row += [num_linux_ubug, num_linux_bug]
        data.append(row)   

    from tabulate import tabulate
    headers = ["BugClass", "UniBug", "Num", "P", "UniBz", "NumBz", "UniLinux", "NumLinux"]

    contents = []
    for i in range(len(taxonomy)):
        contents.append([taxonomy[i]] + data[i])

    # Calculate the summary of each column
    row_sums = [sum(row[i] for row in data) for i in range(len(data[0]))]
    summary = ["Total"] + row_sums
    contents.append(summary)

    # Use tabulate to print the table
    print(tabulate(contents, headers=headers, showindex=False, floatfmt=".2f", tablefmt='fancy_grid'))                   


def table_3():
    class_occurance = dict()
    for b in bugs:
        class_occurance.setdefault(b.bug_class, []).extend(b.occurance)

    class_occurance_statistic = dict()
    for c,o in class_occurance.items():
        # Years 04-06 07-09 10-12 13-15 16-18 19-21
        p = [0] * 6
        for year in o:
            if int(year) <= 2006:
                p[0] += 1
            elif int(year) <= 2009:
                p[1] += 1
            elif int(year) <= 2012:
                p[2] += 1
            elif int(year) <= 2015:
                p[3] += 1
            elif int(year) <= 2018:
                p[4] += 1
            else:
                p[5] += 1
        class_occurance_statistic[c] = p


    from tabulate import tabulate
    # Add a summary row and column to the dictionary object
    for key, value in class_occurance_statistic.items():
        class_occurance_statistic[key].append(sum(value))
    class_occurance_statistic['Total'] = [sum(x) for x in zip(*class_occurance_statistic.values())]

    # Convert the dictionary to a list of lists for tabulate
    table = [[key, *value] for key, value in class_occurance_statistic.items()]

    # Print the table using tabulate and specify row and column headers
    print(tabulate(table, headers=['', '04-06', '07-09', '10-12', '13-15', '16-18', '19-21', 'Total'], tablefmt='fancy_grid'))

table_2()
table_3()

class mitigation_work():
    def __init__(self, name, scope):
        self.name = name
        self.scope = scope
        self.target_cisb = set()
    
    def add_cisb(self, cisb_list):
        self.target_cisb.update(cisb_list)
    

def table_7():
    # the bug number of each bug class
    bug_class_occ = dict()
    for b in bugs:
        bug_class_occ.setdefault(b.bug_class, 0) 
        bug_class_occ[b.bug_class] += len(b.occurance)

    ubsan = mitigation_work('UBSan', ['IS1', 'IS2', 'IS3'])
    ubsan.add_cisb(['l-13', 'l-8', 'l-24', 'b-8', 'b-9', 'b-11', 'b-4', 'b-14'])
    tsan = mitigation_work('ThreadSan',['IS1', 'IS2', 'IS3'])
    tsan.add_cisb(['b-12', 'l-5', 'l-40', 'l-46', 'l-30', 'l-49', 'l-3', 'l-21', 'l-4', 'l-4a'])
    tysan = mitigation_work('TySan',['IS1', 'IS2', 'IS3'])
    tysan.add_cisb(['b-13', 'b-26'])

    time_secure_comp = mitigation_work('Ct-verif, Jasmin, FaCT, CT-wasm, Simon, Barthe', ['OS2'])
    time_secure_comp.add_cisb(['l-6'])

    data_sensitive = mitigation_work('Besson', ['OS1'])
    data_sensitive.add_cisb(['l-9', 'b-21'])

    cache_sc = mitigation_work('Patrignani', ['OS3'])
    cache_sc.add_cisb(['l-25'])

    stack = mitigation_work('STACK', ['IS1'])
    stack.add_cisb(['l-13', 'l-8', 'l-24', 'b-8', 'b-9', 'b-10'])

    unisan = mitigation_work('Unisan', ['OS1'])
    unisan.add_cisb(['l-11', 'l-29', 'b-22'])

    yang = mitigation_work('Yang', ['OS1'])
    yang.add_cisb(['l-9', 'b-21'])

    khunt = mitigation_work('K-Hunt', ['OS2'])
    khunt.add_cisb(['l-6'])

    spr = mitigation_work('Sprundel', ['OS1'])
    spr.add_cisb(['l-9', 'b-21'])

    wu = mitigation_work('Wu', ['IS1', 'IS2', 'IS3'])
    # suppose they can prevent all UB-based elimination of clang
    wu.add_cisb(['l-13', 'l-8', 'b-2', 'l-24', 'b-8', 'b-9', 'b-10', 'b-12', 'b-5', 'b-6', 'l-30', 'b-4'])

    spec = mitigation_work('SpecFuzz, SpecTaint', ['OS3'])
    spec.add_cisb(['l-25'])

    kubo = mitigation_work('KUBO', ['IS1', 'IS2', 'IS3'])
    # they support OOB, IO, Divby0, nullptrderef, out of range object size, pointer overflow, shift oob  
    kubo.add_cisb(['l-13', 'l-8', 'l-24', 'b-9', 'b-10', 'b-11', 'b-4'])

    mitigations = [ubsan, tsan, tysan, time_secure_comp, data_sensitive, cache_sc,
                stack, unisan, yang, khunt, spr, wu, spec, kubo]
    mitigation_rate = dict()
    for m in mitigations:
        ucisb_set = set()
        for b in bugs:
            for cisb in m.target_cisb:
                if cisb in b.id_alias_list:
                    ucisb_set.add(b.id)
        target_cisb_num = 0
        for b in bugs:
            for ucisb in ucisb_set:
                if b.id == ucisb:
                    target_cisb_num += len(b.occurance)
        scope_bug_num = 0
        for t in m.scope:
            scope_bug_num += bug_class_occ[t]
        mitigation_rate[m.name] = target_cisb_num/scope_bug_num
    for n, p in mitigation_rate.items():
        print(n, round(p,2))
        


table_7()
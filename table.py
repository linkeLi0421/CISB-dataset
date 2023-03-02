from tabulate import tabulate
from effectiveness_evaluation import get_dataset_value

file_path = 'extra_options'
strategy = ['O3', 'O2', 'O1', 'O0', 'all-ub_clang', 'all-ub_gcc', 'all-options_gcc', 'all-options_clang', 'ubsan', 'wall']
if __name__ == '__main__':
    table_header = ['Strategy', '', 'Eff.(UB-CISB)',  'Eff. (all CISB)']
    table_data = []
    for s in strategy:
        res = get_dataset_value(file_path + '/' + s + '.txt', output=None)
        if 'ub' in s or s == 'wall':
            if 'clang' not in s:
                table_data.append((s, 'gcc', res[1]/(res[1]+res[0]), '/'))
            if 'gcc' not in s:
                table_data.append((s, 'clang', res[5]/(res[5]+res[4]), '/'))
            continue
        if 'clang' not in s:
            table_data.append((s, 'gcc', res[1]/(res[1]+res[0]), res[3]/(res[3]+res[2])))
        if 'gcc' not in s:
            table_data.append((s, 'clang', res[5]/(res[5]+res[4]), res[7]/(res[7]+res[6])))
    # print(table_data)
    print(tabulate(table_data, headers=table_header, tablefmt='grid'))
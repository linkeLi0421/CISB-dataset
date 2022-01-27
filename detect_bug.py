#!/usr/bin/python3

import yaml
import sys
import os
import argparse

def bug_not_trigger(check_type, input, test_str, section_start, section_end='>:'):
    trigger = 0
    if check_type == 1:
        res = os.popen("./a.out " + input)
        if res.read() == test_str:
            trigger = 1

    if check_type == 2:
        res = os.popen("./a.out " + input)
        if res.read() != test_str:
            trigger = 1

    if check_type == 3:
        f = open('temp.txt', 'w+')
        os.system('objdump -d a.out > ' + ' temp.txt')
        read_res = f.read()
        if (read_res.find(test_str, read_res.find(section_start),
                          read_res.find(section_end, read_res.find(section_start) + len(section_start))) != -1):
            trigger = 1
        f.close()

    if check_type == 4:
        f = open('temp.txt', 'w+')
        os.system('objdump -d a.out > ' + ' temp.txt')
        read_res = f.read()
        if (read_res.find(test_str, read_res.find(section_start),
                          read_res.find(section_end, read_res.find(section_start) + len(section_start))) == -1):
            trigger = 1
        f.close()

    if check_type == 5:
        f = open('temp.s', 'r')
        read_res = f.read()
        if (read_res.find(test_str, read_res.find(section_start),
                          read_res.find(section_end, read_res.find('\n', read_res.find(section_start) + len(section_start)))) != -1):
            trigger = 1
        f.close()

    if check_type == 6:
        f = open('temp.s', 'r')
        read_res = f.read()
        if (read_res.find(test_str, read_res.find(section_start),
                          read_res.find(section_end, read_res.find('\n', read_res.find(section_start) + len(section_start)))) == -1):
            trigger = 1
        f.close()

    if check_type == 7:
        f = open('temp.s', 'r')
        read_res = f.read()
        if (read_res.find(test_str, read_res.find('\n', read_res.find(section_start)),
                          read_res.find('\n', read_res.find('\n', read_res.find(section_start)) + 1)) == -1):
            trigger = 1
        f.close()

    return trigger

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('file', type=argparse.FileType('r'), help='It is the test file name.')
    parser.add_argument('-n', default=1, type=int, help='For user to choose which config is applied to the test file.')
    parser.add_argument('-opt', default=None, type=argparse.FileType('r'), help='Users can choose whether or not to use default option')
    args = parser.parse_args()
    file = args.file.name
    num = args.n
    argss = ''
    section_end = '>:'
    if args.opt:
        f = open(args.opt.name, 'r')
        argss = f.read()
    file = file + '-' + str(num)
    args = ''
    with open('config.yml', 'r') as f:
        config = yaml.safe_load(f.read())[file]
        file_name = config['file_name']
        cc = config['cc']
        opti_level = '-' + config['opti_level']
        input = str(config['input'])
        check_type = config['check_type']
        test_str = config['test_str']
        section_name = config['section_name']
        if section_name.split(' ')[0] == 'between':
            section_start = section_name.split(' ')[1]
            section_end = section_name.split(' ')[2]
        else:
            section_start = section_name
        if 'default_option' in config:
            default_option = config['default_option']
            args += default_option
        if(input == None):
            input = ''

        args = opti_level + ' ' + argss
        if check_type == 5 or check_type == 6 or check_type == 7:
            section_end = ':'
            args += ' -S -o temp.s '
            os.system(cc + ' ' + args + ' ' + file_name)
            # os.system(cc + ' ' + args + ' ' + file_name + '> /dev/null 2>&1')
        else:
            os.system(cc + ' ' + args + ' ' + file_name)
            # os.system(cc + ' ' + args + ' ' + file_name + '> /dev/null 2>&1')
        print(cc + ' ' + args + ' ' + file_name)
        if not bug_not_trigger(check_type, input, test_str, section_start, section_end):
            print('Bug detected!')

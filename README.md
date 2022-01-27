# CISB_detecter

This repo records all the information of CISBs we collect in bugzilla and linux kernel. We also provide a way to automatically detect whether a test case compiled with some options tigger the bug.

## Features

## Dependencies

This tool requires multiple versions of gcc and clang to trigger different bugs.

Here are some compilers we need:

- gcc-4.4
- gcc-4.8
- gcc-4.9
- gcc-5
- gcc-7
- gcc-8
- gcc-9
- clang-3.9

And this tool is written in python, python3 is required.

## Usage

1. Download the repo

2. Run `python3 detect_bug.py -h` to know the options used in this tool

3. Run `python3 detect_bug.py -n number_in_config_file -opt options_file test_case.c`

   This tool will test test_case.c with config.yml in the same directory and options_file.

## Output

```shell
root@d0eba27d1e6a:/# ./detect_bug.py b_1-redefine_strcmp.c -n 1
gcc-4.8 -O2 b_1-redefine_strcmp.c
Successfully detect a bug!

root@d0eba27d1e6a:/# ./detect_bug.py b_1-redefine_strcmp.c -n 1 -opt extra_option.txt
gcc-4.8 -O2 -fno-tree-dominator-opts -fno-tree-vrp -fno-tree-fre -fno-strict-overflow -fno-dce -fno-tree-ccp -fno-tree-copy-prop -fno-tree-forwprop -fno-tree-ter -fno-tree-pre -fno-aggressive-loop-optimizations -fno-strict-aliasing -fno-builtin -fno-tree-dse -fno-optimize-strlen -fno-tree-dce -fno-cse-follow-jumps b_1-redefine_strcmp.c
No bug detected!
```

## Config

- We write oracles and information of some test cases in config.yml. It has the following items:

- file_name: The file name of the test program.

- cc: C compiler name.

- opti_level: Optimization level of the test program.

- input: Some test programs need compile and run and it is the input string. 

- check_type:

  - 1: if output is not test_str, the bug triggers.

  - 2: if output is test_str, the bug triggers.

  - 3: if the disassembly code doesn't contain test_str in section section_name, the bug triggers.

  - 4: if the disassembly code contains test_str in section section_name, the bug triggers.
  - 5: Generate assembly code, if the assembly code doesn't contain test_str in section section_name, the bug triggers.
  - 6: Generate assembly code, if the assembly code contains test_str in section section_name, the bug triggers.
  - 7: Generate assembly code, if the assembly code contains test_str in the next line of section_name, the bug triggers.

- test_str: String used in detecting bugs. 

- section_name: String used in detecting bugs. If section_name begins with "between", it means section_name contains section_start and section_end after "between". Then the detecter will check test_str between section_start and section_end.

## CISB List

Number|Reproduce|gcc|llvm|File name|Have oracle
:---------|:-------|--------|----------|----------|----------
b_1 | success | 4.1.2-10.1 -O1 | |b_1-redefine_strcmp.c|yes
b_2 | success | 4.8-12.0.1 -O1                   | 3.0.0-14.0.0 -O1 |b_2-builtin_ctz.c|yes
b_3 | success | 8-12.0.1 -O2                     | |b_3-strlen-oob.c|yes
b_4 | success | 4.1-12.0.1 -O1                   | 3.0.0-14.0.0 -O1 |b_4-int_overflow.c|yes
b_5 | success | 9-12.0.1 -O1 | 3.3-14.0.0 -O1 |b_5-ptr_sub_to_0.c|yes
b_6 | success | 4.1-12.0.1 -O1 | 3.0.0-14.0.0 -O1 |b_6-modify_constPtr.c|yes
b_7 | success | 4.4-12.0.1 -O1 | 3.0.0-14.0.0 -O1 |b_7-int_promotion.c|yes
b_8 | success | 4.5-7.3 -O2 | 3.0.0-14.0.0 -O2 |b_8.c|yes
b_9 | success | 4.1-12.0.1 -O1 | 3.0.0-14.0.0 -O1 |b_9.c|yes
b_10 | success | 4.6.4-12.0.1 -O1; 4.4 -O2 | 3.0.0-14.0.0 -O1 |b_10.c|yes
b_11 | success | 4.8.1-12.0.1 -O2 | |b_11_for_loop.c|yes
b_12 | success | 4.4-12.0.1 -O1 | 3.0.0-14.0.0-O1 |b_12.c|yes
b_13 | success | 6.1-12.0.1 -O2 | |b_13.c|yes
b_14 | success | 4.1-12.0.1 -O0 | 3.0.0-14.0.0 -O1 |b_14-printf_null.c|no
b_15 | success | | 3.0.0-12.0.0 |b_15.c|no
b_16 | success | 8.1-12.0.1 -O2; 4.8 -O2; 4.9 -O2 | |b_16.c|no
b_19 | fail | | |-|no
b_20 | success | 4.4.7 | |b_20.c|yes
b_21 | success | 4.1-12.0.1 -O1 | 3.0.0-14.0.0 -O1 |b_21-dse_memset.c|yes
b_22 | success | 4.6-12.0.1 -O0 | 3.0-14.0.0 -O0 |b_22.c|no
l_2 | success | 4.1-12.0.1 -O1 | 11.0.0-14.0.0 -O1 |l_2-modify_constVar.c|yes
l_4 | fail |  |  ||
l_6 | success | 7.1-12.0.1 -O2 | 5.0.0-14.0.0 -O1 |l_6.c|yes
l_8 | success |  | 3.0-14.0.0 -O1 |l_8-oversized_shift.c|yes
l_11 | success | 4.1.2-12.0.1 -O0 | 3.0.0-14.0.0 -O0 |l_11.c|no
l_13 | success | 4.1.2 -O0 9.1-12.0.1  -O1 | 3.3 - 14.0.0   -O1 |l_13.c|yes
l_15 | success | 4.4-12.0.1 -O1 | 3.0.0-14.0.0 -O1 |l_15.c|yes
l_16 | success | 4.1.2 -O2 |  |l-16(prefetch).c|no
l_18 | success | 4.1.2 -O0 |  |l_18.c|yes
l_19 | success | 4.3-4.9 -O1 |  |l_19.c|yes
l_20 | fail |  |  ||
l_21 | fail |  |  ||
l_22 | success | arm all version -O0 | arm all version -O0 |l-22(mrc ret reg).c|no
l_23 | success | arm all version -O0 | arm all version -O0 |l-23(memcpy-ldr-x0).c|no
l_24 | success | 4.1.2-12.0.1 -O2 | 3.0.0-3.4.1 -O1; 3.0.0-14.0.0 -O2 |l_24.c|yes
l_29 | success | 4.6.4-12.0.1 -O0 | 3.4.1-14.0.0 -O0 |l_29.c|yes
l_30 | success | 4.1-12.0.1 -O1 | 3.0.0-14.0.0 -O1 |l_30.c|yes
l_35 | fail |  |  ||
l_37 | success | 4.5-11.2 -O2 | 3.0.0-14.0.0 -O1 |l_37.c|yes
l_38 | fail |  |  ||
l_40 | fail |  |  ||
l_41 | success | 4.1.2-12.0.1 -O1 | 3.7-14.0.0 -O1 |l_41.c|yes
l_43 | success |  | 3.0.0-14.0.0 -O1 |l_43.c|yes
l_44 | fail |  |  ||
l_46 | fail |  |  ||
l_47 | fail |  |  ||
l_48 | fail |  |  ||
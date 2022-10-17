A dataset of Compiler-Introduced-Security-bugs (CISB) with reproduction materials.
These CISBs are manually collected from the GCC/Clang bugzilla and Linux kernel 
through an empirical study.

See our paper (to appear) for more information on the CISB taxonomy and collection methodology. 

# CISB-dataset

This is a brief table of CISB. More details in *CISB-dataset/data.tat.gz*.

| Number   | Reproduce | gcc                                 | llvm                              | File name             | Have oracle |
| :------- | :-------- | ----------------------------------- | --------------------------------- | --------------------- | ----------- |
| b-1      | success   | 4.1.2-10.1 -O1                      |                                   | b_1-redefine_strcmp.c | yes         |
| b-2      | success   | 4.8-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | b_2-builtin_ctz.c     | yes         |
| b-3      | success   | 8-12.0.1 -O2                        |                                   | b_3-strlen-oob.c      | yes         |
| b-4      | success   | 4.1-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | b_4-int_overflow.c    | yes         |
| b-5      | success   | 9-12.0.1 -O1                        | 3.3-14.0.0 -O1                    | b_5-ptr_sub_to_0.c    | yes         |
| b-6      | success   | 4.1-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | b_6-modify_constPtr.c | yes         |
| b-7      | success   | 4.4-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | b_7-int_promotion.c   | yes         |
| b-8      | success   | 4.5-7.1 -O2; 8-12.0.1 -O1           | 10.0.0-14.0.0 -O1                 | b_8.c                 | yes         |
| b-9      | success   | 4.1-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | b_9.c                 | yes         |
| b-10     | success   | 4.6.4-12.0.1 -O1; 4.4 -O2           | 3.0.0-14.0.0 -O1                  | b_10.c                | yes         |
| b-11     | success   | 4.8.1-12.0.1 -O2                    |                                   | b_11_for_loop.c       | yes         |
| b-12     | success   | 4.4-12.0.1 -O1                      | 3.0.0-14.0.0-O1                   | b_12.c                | yes         |
| b-13     | success   | 6.1-12.0.1 -O2                      |                                   | b_13.c                | yes         |
| b-14     | success   | 4.1-12.0.1 -O0                      | 3.0.0-14.0.0 -O1                  | b_14-printf_null.c    | no          |
| b-15     | success   | 10.1-12.01 -O2                      | 3.0.0-12.0.0                      | b_15.c                | no          |
| b-16     | success   | 8.1-12.0.1 -O2; 4.8 -O2; 4.9 -O2    |                                   | b_16.c                | no          |
| b-19     | fail      |                                     |                                   | -                     | no          |
| b-20     | success   | 4.4.7                               |                                   | b_20.c                | yes         |
| b-21/l-9 | success   | 4.1-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | b_21-dse_memset.c     | yes         |
| b-22     | success   | 4.6-12.0.1 -O0                      | 3.0-14.0.0 -O0                    | b_22.c                | no          |
| b-26     | success   | arm all version -O0                 | arm all version -O0               | b_26.c                | no          |
| l-2      | success   | 4.1-12.0.1 -O1                      | 11.0.0-14.0.0 -O1                 | l_2-modify_constVar.c | no          |
| l-4      | fail      |                                     |                                   |                       |             |
| l-6      | success   | 7.1-12.0.1 -O2                      | 5.0.0-14.0.0 -O1                  | l_6.c                 | yes         |
| l-8      | success   |                                     | 3.0-14.0.0 -O1                    | l_8-oversized_shift.c | yes         |
| l-11     | success   | 4.1.2-12.0.1 -O0                    | 3.0.0-14.0.0 -O0                  | l_11.c                | yes         |
| l-13     | success   | 4.1.2 -O0 9.1-12.0.1  -O1           | 3.3 - 14.0.0   -O1                | l_13.c                | yes         |
| l-15     | success   | 4.4-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | l_15.c                | yes         |
| l-16     | success   | 4.1.2 -O2                           |                                   | l-16(prefetch).c      | no          |
| l-18     | success   | 4.1.2 -O0                           |                                   | l_18.c                | yes         |
| l-19     | success   | 4.3-4.9 -O1                         |                                   | l_19.c                | yes         |
| l-20     | fail      |                                     |                                   |                       |             |
| l-21     | fail      |                                     |                                   |                       |             |
| l-22     | success   | arm all version -O0                 | arm all version -O0               | l-22(mrc ret reg).c   | no          |
| l-23     | success   | arm all version -O0                 | arm all version -O0               | l-23(memcpy-ldr-x0).c | no          |
| l-24     | success   | 4.1.2-12.0.1 -O2                    | 3.0.0-3.4.1 -O1; 3.0.0-14.0.0 -O2 | l_24.c                | yes         |
| l-25     | success   | 7.3-8.3 -O0 -mindirect-branch=thunk |                                   | l_25.c                | no          |
| l-30     | success   | 4.1-12.0.1 -O1                      | 3.0.0-14.0.0 -O1                  | l_30.c                | yes         |
| l-35     | fail      |                                     |                                   |                       |             |
| l-37     | success   | 4.5-12.0.1 -O2                      | 3.0.0-14.0.0 -O1                  | l_37.c                | yes         |
| l-38     | fail      |                                     |                                   |                       |             |
| l-40     | fail      |                                     |                                   |                       |             |
| l-41     | success   | 4.1.2-12.0.1 -O1                    | 3.7-14.0.0 -O1                    | l_41.c                | yes         |
| l-43     | success   |                                     | 3.0.0-14.0.0 -O1                  | l_43.c                | yes         |
| l-44     | fail      |                                     |                                   |                       |             |
| l-46     | fail      |                                     |                                   |                       |             |
| l-47     | fail      |                                     |                                   |                       |             |
| l-48     | fail      |                                     |                                   |                       |             |

## Dataset Format

CISB-dataset/data.tat.gz has three tables.

table1 CISB-dataset-classification.csv

| Column | Header                          | Description                                                  |
| ------ | ------------------------------- | ------------------------------------------------------------ |
| 1      | Root cause                      | The root cause of CISB, layer1 in three-layer classification. |
| 2      | Insecure optimization behaviors | Insecure optimizations behaviors of CISB, layer2 in three-layer classification. |
| 3      | Security consequences           | Security consequences of CISB, layer3 in three-layer classification. |
| 4      | Result                          | Specific effect of the bug.                                  |
| 5      | unique bug id                   | We give each kind of bug a unique id, b-(number) from bugzilla, l-(number) from linux kernel patch. |
| 6      | frequency                       | The number of times that we find this kind of bug.           |

table2 CISB-dataset-detailed info.csv

| Column | Header              | Description                                                  |
| ------ | ------------------- | ------------------------------------------------------------ |
| 1      | unique bug id       | We give each kind of bug a unique id, b-(number) from bugzilla, l-(number) from linux kernel patch. |
| 2      | unique bug name     | We give each kind of bug a name.                             |
| 3      | occurence           | The number of times that we find a unique bug.               |
| 4      | source              | From where we find the bug.                                  |
| 5      | commit/bugzilla ID  | Linux kernel git commit log or llvm/gcc bugzilla ID.         |
| 6      | year                | Time when the bug is submitted.                              |
| 7      | first appearance    | Time when this kind of bugs is submitted.                    |
| 8      | possible effects    | Possible effects of the bug.                                 |
| 9      | special cause       | The causes of implicit-specification. No-UB, default-behavior or environment assumption. |
| 10     | count of  bug class | The number of times that we find this kind of bug totally.   |

table3 CISB-dataset-reproduce.csv

| Column | Header                     | Description                                                  |
| ------ | -------------------------- | ------------------------------------------------------------ |
| 1      | key                        | We give each kind of bug a unique id, b-(number) from bugzilla, l-(number) from linux kernel patch. |
| 2      | result                     | Whether we reproduce it.                                     |
| 3      | repro version:gcc          | The compiler(gcc) version we successfully reproduce the bug. |
| 4      | repro version:llvm         | The compiler(llvm) version we successfully reproduce the bug. |
| 5      | compiler explorer snapshot | An online compiler snapshot that preserve the code to reproduce bugs. |
| 6      | fit remove/reorder         | The effect of the bug. (remove or reorder)                   |



# Reproduction Material
We provide the following reproduction materials:
- test code for all the reproducted CISB
- an automatic tool to test whether one CISB is triggered with pre-defined oracles

## Dependencies

1. Different versions of gcc and clang to be tested

   Here are some compilers we have tested:

   gcc-4.4

   gcc-4.8

   gcc-4.9

   gcc-5

   gcc-7

   gcc-8

   gcc-9

   clang-3.9

   We also provide our own script to install these compilers in CISB_detecter/scirpt/auto_get_compiler.sh. Use it with

   ```
   chomod +x auto_get_compiler.sh
   sudo ./auto_get_compiler.sh
   ```

2. Setup a python 3.x environment and install requirements:

   ```
   pip install -r requirements.txt
   ```

## Usage

1. Download the repo
2. Run `python3 reproduction-tester.py -h` to know the options used in this tool
3. Run `python3 reproduction-tester.py -n number_in_config_file -opt options_file test_case.c`

   This tool will test test_case.c with CISB-dataset/config.yml and options_file. The argument number_in_config_file means use *test_case.c-(`number_in_config_file`)* in config.yml.
4. Before run reproduction-tester.py, user should edit *options_file* as the options to be tested. 

## Output

```shell
root@d0eba27d1e6a:/# python3 reproduction-tester.py ./reproduce_set/b_1-redefine_strcmp.c -n 1
gcc-4.8 -O2 b_1-redefine_strcmp.c
One CISB here!

root@d0eba27d1e6a:/# python3 reproduction-tester.py ./reproduce_set/b_1-redefine_strcmp.c -n 1 -opt extra_option.txt
gcc-4.8 -O2 -fno-tree-dominator-opts -fno-tree-vrp -fno-tree-fre -fno-strict-overflow -fno-dce -fno-tree-ccp -fno-tree-copy-prop -fno-tree-forwprop -fno-tree-ter -fno-tree-pre -fno-aggressive-loop-optimizations -fno-strict-aliasing -fno-builtin -fno-tree-dse -fno-optimize-strlen -fno-tree-dce -fno-cse-follow-jumps b_1-redefine_strcmp.c
No CISB here!
```

## Config

We write oracles and information of some test cases in *config.yml*. It has the following items:

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

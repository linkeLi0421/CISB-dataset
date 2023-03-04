A dataset of Compiler-Introduced-Security-bugs (CISB) with reproduction materials.
These CISBs are manually collected from the GCC/Clang bugzilla and Linux kernel 
through an empirical study.

See our paper (to appear) for more information on the CISB taxonomy and collection methodology. 

# CISB-dataset

Our data is stored in *CISB-dataset/dataset*.

## Dataset Format

CISB-dataset/dataset has three tables.

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

   gcc-4.1

   gcc-4.4

   gcc-4.9

   gcc-7

   gcc-12

   clang-12

   clang-14

   We also provide our own script to install these compilers in CISB_detecter/scirpt/auto_get_compiler.sh. Use it with

   ```
   chomod +x auto_get_compiler.sh
   sudo ./auto_get_compiler.sh
   ```

2. Setup a python 3.x environment and install requirements:

   ```
   apt-get install python3-pip
   pip3 install -r requirements.txt
   ```

## Usage

1. Download the repo
2. To test one single test case in **_./reproduce_set_**, use _reproduction_tester.py_
   1. useage:`python3 reproduction_tester.py [-h] [-level LEVEL] [-cc CC] [-opt OPT] file`
   2. example: `python3 reproduction_tester.py ./reproduce_set/b_1.c -level O3 -cc gcc -opt extra_options/all-options_gcc.txt 2> /dev/null` can test whether b_1.c trigger bug using **gcc** with options in _**extra_options/all-options_gcc.txt**_
3. To test all test cases in **_./reproduce_set _**at one time, use _effectiveness_evaluation.py_
   1. useage: `python3 effectiveness_evaluation.py [-h] [-opt OPT]`
   2. example: `python3 effectiveness_evaluation.py -opt extra_options/all-options_gcc.txt 2> /dev/null` can get the result of all test cases using **gcc** with options in _**extra_options/all-options_gcc.txt**_
4. To get all results from _effectiveness_evaluation.py _with 8 kinds of option strategy in a table, use _table.py_
   1. example `python3 table.py 2> /dev/null`

## Output

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
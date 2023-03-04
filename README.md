A dataset of Compiler-Introduced-Security-bugs (CISB) with reproduction materials.
These CISBs are manually collected from the GCC/Clang bugzilla and Linux kernel 
through an empirical study.

See our paper (to appear) for more information on the CISB taxonomy and collection methodology. 

# CISB-dataset

Our data is stored in *CISB-dataset/dataset*.

## Dataset Format

CISB-dataset/dataset has three tables.

table1 CISB-dataset-classification.csv

| Column | Header(\* means the key)          | Description                                                  |
| ------ | ------------------------------- | ------------------------------------------------------------ |
| 1      | Root cause                      | The root cause of the bug (the 1st layer of our taxonomy) |
| 2      | Insecure optimization behaviors | Insecure optimizations behaviors of the bug (the 2nd layer of our taxonomy) |
| 3      | Security consequences           | Security consequences of the bug (the 3rd layer of our taxonomy) |
| 4      | Security Impacts                | Specific security impacts of the bug                     |
| 5      | Unique bug id\*                   | The identifier for each unique bug type with the same cause and impacts; b-(number) for the ones from Bugzilla, l-(number) for the ones from the Linux |
| 6      | Frequency                       | The number of times we found this kind of bug          |

table2 CISB-dataset-detailed-info.csv

| Column | Header (\* means the key)| Description                                                  |
| ------ | ------------------- | ------------------------------------------------------------ |
| 1      | Unique bug id       | The identifier for each unique bug type with the same cause and impacts; b-(number) for the ones from Bugzilla, l-(number) for the ones from the Linux |
| 2      | Unique bug name     | A short description to name the bug                          |
| 3      | Occurence           | The number of times we found this kind of bug                |
| 4      | Source              | From where we find the bug.                                  |
| 5      | Commit/Bugzilla ID\*| Linux kernel git commit log or llvm/gcc bugzilla ID.         |
| 6      | Year                | Time when this bug report is submitted.                              |
| 7      | First appearance    | Time when this kind of bugs is firstly submitted.                    |
| 8      | Security impacts    | Specific security impacts of the bug                                 |
| 9      | Specific cause      | The sub classification of Implicit-Specification. See the definition of No-UB, default-behavior or environment assumption in our paper |

table3 CISB-dataset-reproduce.csv

| Column | Header(\* means the key)   | Description                                                  |
| ------ | -------------------------- | ------------------------------------------------------------ |
| 1      |  Unique bug id\*           | The identifier for each unique bug type with the same cause and impacts; b-(number) for the ones from Bugzilla, l-(number) for the ones from the Linux |
| 2      | Result                     | The result of our reproducation                                    |
| 3      | Compiler version:gcc          | The compiler(gcc) version we reproduce the bug |
| 4      | Compiler version:llvm         | The compiler(llvm) version we reproduce the bug |
| 5      | Compiler Explorer snapshot | An online compiler snapshot that preserve the code to reproduce the bug |



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
3. To test all test cases in  **_./reproduce_set** at one time, use _effectiveness_evaluation.py_
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
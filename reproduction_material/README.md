# Reproduction Material

We provide the following reproduction materials:
- test code for all the reproducted CISB;
- an automatic tool to test whether one CISB is triggered with pre-defined oracles.

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

   We also provide our own script to install these compilers in env/auto_get_compiler.sh. Use it with

   ```
   cd path/to/aritifact/env
   chomod +x auto_get_compiler.sh
   sudo auto_get_compiler.sh
   ```

   Run CISB-dataset/check-compiler.py to check whether all required compilers are installed properly.

   ```
   python3 check-compiler.py
   ```

2. Setup a python 3.x environment and install requirements:

   ```
   apt-get install python3-pip
   pip3 install -r requirements.txt
   ```

## Script

<!-- 1. CISB-dataset/check-key.py

   - check whether data set tables in ***CISB-dataset/dataset*** has unique key
   - useage: `python3 check-key.py`

2. CISB-dataset/check-compiler.py

   - check whether required compilers ready
   - useage: `python3 check-compiler.py` -->

 CISB-dataset/reproduction_tester.py

   - test single test case in **_CISB-dataset/reproduction_material/test_cases/_**
   - useage:`python3 reproduction_tester.py [-h] [-level LEVEL] [-cc CC] [-opt OPT] file`
   - example: `python3 reproduction_tester.py ./test_cases/b-1.c -level O3 -cc gcc -opt ../extra_options/All-cisb_gcc.txt 2> /dev/null` can test whether b-1.c trigger bug using **gcc** with options in _**CISB-dataset/extra_options/All-cisb_gcc.txt**_

<!-- 4. CISB-dataset/effectiveness_evaluation.py

   - test all test cases in  **_CISB-dataset/reproduce_set_** at one time
   - useage: `python3 effectiveness_evaluation.py [-h] [-opt OPT]`
   - example: `python3 effectiveness_evaluation.py -opt extra_options/all-cisb_gcc.txt 2> /dev/null` can get the result of all test cases using **gcc** with options in _**CISB-dataset/extra_options/all-cisb_gcc.txt**_

5. CISB-dataset/statistic.py

   - functions:
     - table_2(): print results of bugs reported to Bugzilla and in the Linux kernel
     - table_3(): print temporal distribution (report date) of bug classes
     - table_6(): print all results using *effectiveness_evaluation.py* with 8 kinds of option strategy stored in ***CISB-dataset/extra_options***
     - table_7(): print automatic prevention works
   - example: `python3 statistic.py 2> /dev/null ` to print all results in tables

6. Performance Overhead

   See [SPEC CPU2006](https://github.com/linkeLi0421/CISB-dataset/tree/main/spec) -->

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

<!-- ## Use docker

to reproduce result in docker, see [here](https://github.com/linkeLi0421/CISB-dataset/tree/main/reproduction). -->
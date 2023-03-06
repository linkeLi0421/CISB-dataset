A dataset of Compiler-Introduced-Security-bugs (CISB) with reproduction materials.
These CISBs are manually collected from the GCC/Clang bugzilla and Linux kernel 
through an empirical study.

See our paper (to appear) for more information on the CISB taxonomy and collection methodology. 

# CISB-dataset

Our data is stored in *CISB-dataset/dataset*.

## Dataset Format

CISB-dataset/dataset has three tables.

table1 CISB-dataset-classification.csv

| Column | Header(\* means the key)        | Description                                                  |
| ------ | ------------------------------- | ------------------------------------------------------------ |
| 1      | Root cause                      | The root cause of the bug (the 1st layer of our taxonomy)    |
| 2      | Insecure optimization behaviors | Insecure optimizations behaviors of the bug (the 2nd layer of our taxonomy) |
| 3      | Security consequences           | Security consequences of the bug (the 3rd layer of our taxonomy) |
| 4      | Security Impacts                | Specific security impacts of the bug                         |
| 5      | Unique bug id\*                 | The identifier for each unique bug type with the same cause and impacts; b-(number) for the ones from Bugzilla, l-(number) for the ones from the Linux |
| 6      | Frequency                       | The number of times we found this kind of bug                |

table2 CISB-dataset-detailed-info.csv

| Column | Header (\* means the key) | Description                                                  |
| ------ | ------------------------- | ------------------------------------------------------------ |
| 1      | Unique bug id             | The identifier for each unique bug type with the same cause and impacts; b-(number) for the ones from Bugzilla, l-(number) for the ones from the Linux |
| 2      | Unique bug name           | A short description to name the bug                          |
| 3      | Occurence                 | The number of times we found this kind of bug                |
| 4      | Source                    | From where we find the bug.                                  |
| 5      | Commit/Bugzilla ID\*      | Linux kernel git commit log or llvm/gcc bugzilla ID.         |
| 6      | Year                      | Time when this bug report is submitted.                      |
| 7      | First appearance          | Time when this kind of bugs is firstly submitted.            |
| 8      | Security impacts          | Specific security impacts of the bug                         |
| 9      | Specific cause            | The sub classification of Implicit-Specification. See the definition of No-UB, default-behavior or environment assumption in our paper |

table3 CISB-dataset-reproduce.csv

| Column | Header(\* means the key)   | Description                                                  |
| ------ | -------------------------- | ------------------------------------------------------------ |
| 1      | Unique bug id\*            | The identifier for each unique bug type with the same cause and impacts; b-(number) for the ones from Bugzilla, l-(number) for the ones from the Linux |
| 2      | Result                     | The result of our reproducation                              |
| 3      | Compiler version:gcc       | The compiler(gcc) version we reproduce the bug               |
| 4      | Compiler version:llvm      | The compiler(llvm) version we reproduce the bug              |
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
   sudo script/auto_get_compiler.sh
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

## Scripts

1. CISB-dataset/check-key.py

   - check whether data set tables in ***CISB-dataset/dataset*** has unique key
   - useage: `python3 check-key.py`

2. CISB-dataset/check-compiler.py

   - check whether required compilers ready
   - useage: `python3 check-compiler.py`

3. CISB-dataset/reproduction_tester.py

   - test single test case in **_CISB-dataset/reproduce_set_**
   - useage:`python3 reproduction_tester.py [-h] [-level LEVEL] [-cc CC] [-opt OPT] file`
   - example: `python3 reproduction_tester.py ./reproduce_set/b-1.c -level O3 -cc gcc -opt extra_options/all-options_gcc.txt 2> /dev/null` can test whether b-1.c trigger bug using **gcc** with options in _**CISB-dataset/extra_options/all-options_gcc.txt**_

4. CISB-dataset/effectiveness_evaluation.py

   - test all test cases in  **_CISB-dataset/reproduce_set_** at one time
   - useage: `python3 effectiveness_evaluation.py [-h] [-opt OPT]`
   - example: `python3 effectiveness_evaluation.py -opt extra_options/all-options_gcc.txt 2> /dev/null` can get the result of all test cases using **gcc** with options in _**CISB-dataset/extra_options/all-options_gcc.txt**_

5. CISB-dataset/statistic.py

   - functions:
     - table_2(): print results of bugs reported to Bugzilla and in the Linux kernel
     - table_3(): print temporal distribution (report date) of bug classes
     - table_6(): print all results using *effectiveness_evaluation.py* with 8 kinds of option strategy stored in ***CISB-dataset/extra_options***
     - table_7(): print automatic prevention works
   - example: `python3 statistic.py 2> /dev/null ` to print all results in tables

6. Performance Overhead

   See [SPEC CPU2006](https://github.com/linkeLi0421/CISB-dataset/tree/main/spec)

## Output

We can get the tables in our paper using script.

```
root@compiler:/CISB-dataset# python3 statistic.py 2>/dev/null 
Table 2: Statistics of bugs reported to Bugzilla and in the Linux kernel
╒════════════╤══════════╤═══════╤══════╤═════════╤═════════╤════════════╤════════════╕
│ BugClass   │   UniBug │   Num │    P │   UniBz │   NumBz │   UniLinux │   NumLinux │
╞════════════╪══════════╪═══════╪══════╪═════════╪═════════╪════════════╪════════════╡
│ IS1        │       18 │    59 │ 0.49 │      13 │      50 │          8 │          9 │
├────────────┼──────────┼───────┼──────┼─────────┼─────────┼────────────┼────────────┤
│ IS2        │        7 │    10 │ 0.08 │       1 │       4 │          6 │          6 │
├────────────┼──────────┼───────┼──────┼─────────┼─────────┼────────────┼────────────┤
│ IS3        │       17 │    25 │ 0.21 │       5 │      12 │         12 │         13 │
├────────────┼──────────┼───────┼──────┼─────────┼─────────┼────────────┼────────────┤
│ OS1        │        3 │    20 │ 0.17 │       2 │       2 │          3 │         18 │
├────────────┼──────────┼───────┼──────┼─────────┼─────────┼────────────┼────────────┤
│ OS2        │        2 │     5 │ 0.04 │       0 │       0 │          2 │          5 │
├────────────┼──────────┼───────┼──────┼─────────┼─────────┼────────────┼────────────┤
│ OS3        │        1 │     1 │ 0.01 │       0 │       0 │          1 │          1 │
├────────────┼──────────┼───────┼──────┼─────────┼─────────┼────────────┼────────────┤
│ Total      │       48 │   120 │ 1.00 │      21 │      68 │         32 │         52 │
╘════════════╧══════════╧═══════╧══════╧═════════╧═════════╧════════════╧════════════╛
Table 3: Temporal distribution (report date) of bug classes
╒═══════╤═════════╤═════════╤═════════╤═════════╤═════════╤═════════╤═════════╕
│       │   04-06 │   07-09 │   10-12 │   13-15 │   16-18 │   19-21 │   Total │
╞═══════╪═════════╪═════════╪═════════╪═════════╪═════════╪═════════╪═════════╡
│ IS1   │       1 │      12 │      14 │      10 │      11 │      11 │      59 │
├───────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│ IS2   │       0 │       2 │       0 │       2 │       0 │       6 │      10 │
├───────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│ IS3   │       3 │       0 │       4 │       4 │      10 │       4 │      25 │
├───────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│ OS1   │       1 │       1 │       0 │       8 │       4 │       6 │      20 │
├───────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│ OS2   │       0 │       2 │       0 │       2 │       1 │       0 │       5 │
├───────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│ OS3   │       0 │       0 │       0 │       0 │       0 │       1 │       1 │
├───────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│ Total │       5 │      17 │      18 │      26 │      26 │      28 │     120 │
╘═══════╧═════════╧═════════╧═════════╧═════════╧═════════╧═════════╧═════════╛
Table 6: An evaluation of the mitigations provided by the compiler
╒═══════════════════╤═══════╤═════════════════╤═════════════════════╕
│ Strategy          │       │   Eff.(UB-CISB) │ Eff. (all CISB)     │
╞═══════════════════╪═══════╪═════════════════╪═════════════════════╡
│ O3                │ gcc   │        0.1      │ 0.0967741935483871  │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ O3                │ clang │        0.266667 │ 0.16                │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ O2                │ gcc   │        0.1      │ 0.06451612903225806 │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ O2                │ clang │        0.266667 │ 0.16                │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ O1                │ gcc   │        0.3      │ 0.25806451612903225 │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ O1                │ clang │        0.266667 │ 0.16                │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ O0                │ gcc   │        0.789474 │ 0.6774193548387096  │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ O0                │ clang │        0.933333 │ 0.8                 │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ all-ub_clang      │ clang │        0.533333 │ /                   │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ all-ub_gcc        │ gcc   │        0.55     │ /                   │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ all-options_gcc   │ gcc   │        0.75     │ 0.6129032258064516  │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ all-options_clang │ clang │        0.533333 │ 0.48                │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ ubsan             │ gcc   │        0.3      │ /                   │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ ubsan             │ clang │        0.333333 │ /                   │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ wall              │ gcc   │        0.2      │ /                   │
├───────────────────┼───────┼─────────────────┼─────────────────────┤
│ wall              │ clang │        0.266667 │ /                   │
╘═══════════════════╧═══════╧═════════════════╧═════════════════════╛
Table7: Automatic Prevention works
UBSan 0.31
ThreadSan 0.13
TySan 0.1
Ct-verif, Jasmin, FaCT, CT-wasm, Simon, Barthe 0.8
Besson 0.6
Patrignani 1.0
STACK 0.63
Unisan 0.4
Yang 0.6
K-Hunt 0.8
Sprundel 0.6
Wu 0.53
SpecFuzz, SpecTaint 1.0
KUBO 0.45
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
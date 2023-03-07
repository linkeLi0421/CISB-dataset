# Reproduction Material

We provide the following reproduction materials:
- testcases for all the reproducted CISB;
- an automatic tool to test whether one CISB is triggered with pre-defined oracles.

## Tested Compilers 

All the test compilers should have been installed if you start by 
using our [Dockerfile](../env/Dockerfile).

The compilers we use in the experiment script are the latest ones that can be 
used to reproduce the CISBs. This group includes 
gcc-4.1, gcc-4.4, gcc-4.9, gcc-7, gcc-12, clang-12, and clang-14.

To help with installation, we provide our own [script](../env/auto_get_compiler.sh) 
that installs these compilers
   ```
cd path/to/aritifact/env
chomod +x auto_get_compiler.sh
sudo auto_get_compiler.sh
```

To check whether all required compilers are installed properly, simply
execute the [scritp](../check-compiler.py).
```
python3 check-compiler.py
```
## Testcases
The source code of these testcases can be found in the folder 
`path/to/artifact/reproduction_material/testcases`.

## The script to check the reproduction

We provide a [script](./reproduction_tester.py) to check the reproduction of each 
single testcase automatically.
- useage:`python3 reproduction_tester.py [-h] [-level LEVEL] [-cc CC] [-opt OPT] file`
- example: `python3 reproduction_tester.py ./test_cases/b-1.c -level O3 -cc gcc -opt ../compiler_strategies/All-cisb_gcc.txt 2> /dev/null` can test whether b-1.c trigger bug using **gcc** with options in _**CISB-dataset/compiler_strategies/All-cisb_gcc.txt**_


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

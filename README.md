# Overview
A dataset of Compiler-Introduced-Security-bugs (CISB) with reproduction materials.
These CISBs are manually collected from the GCC/Clang bugzilla and Linux kernel 
through an empirical study.

See our paper (to appear) for more information on the CISB taxonomy and collection methodology. 

# CISB-dataset

Our data is stored in *CISB-dataset/dataset*.
More details [here](dataset/README.md).

# Reproduction Material

We provide the following reproduction materials:
- test code for all the reproducted CISB;
- an automatic tool to test whether one CISB is triggered with pre-defined oracles.

More details [here](reproduction_material/README.md)

# Aritifact setup
We provide a [Dockerfile](env/Dockerfile) that automates the setup process for our artifact.
With this Dockerfile, users can easily download the dataset and evaluation materials, as well as install all the necessary software requirements in one step.

For running one of the mitigation evaluation experiments that requires SPEC CPU 2006, it is recommended to mount the host directory containing SPEC CPU 2006 to a specific directory (/cisb_docker/spec/cpu2006) in the Docker container. Here are the instructions to build and run a Docker container with this:

1. Make sure you have Docker installed on your system.
2. Download the SPEC CPU 2006 benchmark and extract it to a directory on your host machine.
3. Navigate to the directory where you have the Dockerfile and run the following command to build the Docker image: 
```
cd path/to/Dockerfile
docker build -t cisb_docker .
```
4. Once the build is complete, run the following command to start a container:
```
docker run -itd -v /path/to/spec/cpu2006:/cisb_docker/spec/cpu2006 --name dataset --privileged cisb_docker
```

As an alternative, you can also place SPEC CPU 2006 anywhere you like within the Docker container. In that case, you will need to set the environment variable before running the experiment in the container.
```
export SEPC_CPU_2006_PATH='path/to/spec/cpu2006'
``` 

# Aritifact experiments
All of our experiments can be done through a [script](statistic.py).

## CISB statistics

Execute the Python script to obtain the statistics of CISBs in our dataset. 
The result should be in line with the data in Figure 2 and Figure 3 of the paper.

```
python3 statistic.py -e cisb-statistics
```
## Evaulation of mitigations
1. Review a list of bugs where the prevention performed by programmers failed. 
This list can be obtained by executing a script. The expected result is those CISBs exist.
```
python3 statistic.py -e human-mitigation
```
2. Run a script to obtain statistics on the effectiveness of compiler mitigations.
The output results should be in line with the data shown in Table 6 of the paper.
We also provide a [guide](compiler_strategiess/README.md) to measure the effectiveness 
of each strategy separately.
```
python3 statistic.py -e mitigation-effectiveness
```
3. Run a script to measure the overhead of different compiler prevention 
strategies using the SPEC CPU 2006 benchmark.
The output results should be in line with the data shown in Table 6 of the paper.
We also provide a [guide](spec/README.md) to measure the overhead of each strategy
separately.
```
python3 statistic.py -e mitigation-overhead
```


As an alternative, you can also run the script to obtain all the results in one step.
```
python3 statistic.py -e mitigation-evaluation
```

## Target bugs of automatic prevention works
1. Execute the script to obtain the statistics of CISBs that can theoretically 
   be prevented by automatic prevention works. 
   The result should be in line with the data in Figure 7 of the paper.
```
python3 statistic.py -e target-cisb
```
2. Check the lists of CISBs we summarized and shown in the script. 
   These bugs should be within the scope of the corresponding prevention work.



<!-- ## Scripts

1. CISB-dataset/check-key.py

   - check whether data set tables in ***CISB-dataset/dataset*** has unique key
   - useage: `python3 check-key.py`

2. CISB-dataset/check-compiler.py

   - check whether required compilers ready
   - useage: `python3 check-compiler.py` -->

<!-- 4. CISB-dataset/effectiveness_evaluation.py

   - test all test cases in  **_CISB-dataset/reproduce_set_** at one time
   - useage: `python3 effectiveness_evaluation.py [-h] [-opt OPT]`
   - example: `python3 effectiveness_evaluation.py -opt compiler_strategiess/all-cisb_gcc.txt 2> /dev/null` can get the result of all test cases using **gcc** with options in _**CISB-dataset/compiler_strategiess/all-cisb_gcc.txt**_ -->

<!-- 5. CISB-dataset/statistic.py

   - functions:
     - table_2(): print results of bugs reported to Bugzilla and in the Linux kernel
     - table_3(): print temporal distribution (report date) of bug classes
     - table_6(): print all results using *effectiveness_evaluation.py* with 8 kinds of option strategy stored in ***CISB-dataset/compiler_strategiess***
     - table_7(): print automatic prevention works
   - example: `python3 statistic.py 2> /dev/null ` to print all results in tables -->

<!-- 6. Performance Overhead

   See [SPEC CPU2006](https://github.com/linkeLi0421/CISB-dataset/tree/main/spec) -->

<!-- ## Config

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

## Use docker

to reproduce result in docker, see [here](https://github.com/linkeLi0421/CISB-dataset/tree/main/reproduction). -->
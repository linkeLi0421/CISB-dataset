# Setup for SPEC CPU 2006 
1. Install [SPEC CPU2006 Benchmark](https://www.spec.org/cpu2006/).
- Please note that we can't share SPEC CPU2006 here becuase it is commercial.

2. After obtaining SPEC CPU2006 Benchmark, it is needed to 
**place the `cpu2006` folder under the `spec` directory**，which is automatically 
setted if you follow the [installation guide](../README.md#aritifact-setup).

3. To set up SPEC CPU 2006, please follow the instructions below:
```
# cd path/to/artifact
# cp -r spec/config cpu2006
# cd cpu2006
# source ./shrc
```

# Performance evaluation of compiler mitigations

To measure the performance overhead of each compiler strategy separately, we 
provide the following script to run SPEC CPU 2006 Benchmark. Here is an example 
of how to test the performance of gcc with O3 optimization:

> Note that it may take about 3-4 hours to do this test. 

```
# cd path/to/artifact/spec
# bash config/spec.sh gcc_O3.cfg
```
You can replace gcc_O3.cfg with the config file name of the compiler strategy 
you want to test.

TODO
- How to read the report
- If `config/test_all.py` is needed?
<!-- 4. Run the following script to run all SPEC CPU2006 Benchmark. 

   ```
   # python3 config/test_all.py
   ``` -->

## SPEC CPU 2006 config files
Below is the config file and compiler options used for each compiler strategy we test. 
The config file can be found in `path/to/artifact/spec`:

   | File name          | Compiler options                                             |
   | ------------------ | ------------------------------------------------------------ |
   | gcc_O3.cfg         | -O3                                                          |
   | clang_O3.cfg       | -O3                                                          |
   | gcc_O2.cfg         | -O2                                                          |
   | clang_O2.cfg       | -O2                                                          |
   | gcc_O1.cfg         | -O1                                                          |
   | clang_O1.cfg       | -O1                                                          |
   | gcc_O0.cfg         | -O0                                                          |
   | clang_O0.cfg       | -O0                                                          |
   | gcc_All-UB.cfg     | -O3 -fno-strict-overflow -fwrapv -fno-delete-null-pointer-checks -fno-strict-aliasing -fno-aggressive-loop-optimizations |
   | clang_All-UB.cfg   | -O3 -fno-strict-overflow  -fno-delete-null-pointer-checks   -fno-strict-aliasing -fwrapv |
   | gcc_All-CISB.cfg   | -O3 -fno-tree-dominator-opts -fno-tree-vrp -fno-tree-fre   -fno-strict-overflow -fno-dce -fno-tree-ccp -fno-tree-copy-prop   -fno-tree-forwprop -fno-tree-ter -fno-tree-pre  -fno-strict-aliasing -fno-aggressive-loop-optimizations  -fno-builtin   -fno-tree-dse -fno-optimize-strlen -fno-tree-dce -fno-cse-follow-jumps  -fno-unswitch-loops |
   | clang_All-CISB.cfg | -O3 -fno-builtin -fno-strict-overflow  -fno-strict-aliasin -fwrapv -fno-delete-null-pointer-checks |
   | gcc_UBSan.cfg      | -O3 -fsanitize=undefined                                     |
   | clang_UBSan.cfg    | -O3 -fsanitize=undefined                                     |

   
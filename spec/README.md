## Compiler mitigations overhead testing

1. Install [SPEC CPU2006 Benchmark](https://www.spec.org/cpu2006/).

- Please note that we can't share SPEC CPU2006 here becuase it is commercial.

2. After you obtained SPEC CPU2006 Benchmark (**assuming you place `cpu2006` under the folder of `spec`**):

   ```
   $ root@compiler:/CISB-dataset/spec# cp -r config ./cpu2006
   $ root@compiler:/CISB-dataset/spec# cd cpu2006
   $ root@compiler:/CISB-dataset/spec/cpu2006# source ./shrc
   ```

3. Run the following script to run SPEC CPU2006 Benchmark. We give an example to test the perforname of gcc with O3 optimization.

   ```
   $ root@compiler:/CISB-dataset/spec/cpu2006# bash config/spec.sh gcc_O3.cfg
   ```

4. SPEC CPU2006 config files are stored in ***spec/cpu2006/config***. We also provide a table of config files to illustrate these files. 

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

   
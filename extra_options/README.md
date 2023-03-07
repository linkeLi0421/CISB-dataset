# Compiler strategies to prevent CISBs
We provide a list of recommeded combination of compiler options.
They are organized in the following mitigation strategies. 

   | Compiler prevention strategy | Config file | Compiler options                     |
   | ------------------ | -------|---------------------------------------------------- |
   | O0                 | O0.txt | -O0                                                 |
   | O1                 | O1.txt | -O1                                                 |
   | O2                 | O2.txt | -O2                                                 |
   | O3                 | O3.txt | -O3                                                 |
   | All-cisb (gcc)     | all-cisb_gcc.txt | -O3  -fno-tree-dominator-opts -fno-tree-vrp -fno-tree-fre -fno-strict-overflow -fno-dce -fno-tree-ccp -fno-tree-copy-prop -fno-tree-forwprop -fno-tree-ter -fno-tree-pre -fno-aggressive-loop-optimizations -fno-strict-aliasing -fno-builtin -fno-tree-dse -fno-optimize-strlen -fno-tree-dce -fno-cse-follow-jumps -fno-unswitch-loops|
   | All-cisb (clang)    | all-cisb_clang.txt  | -O3 -fno-strict-overflow  -fno-delete-null-pointer-checks -fno-strict-aliasing                                                         |
   | All-ub (gcc) | all-ub_gcc.txt         | -O3 -fno-strict-overflow  -fno-delete-null-pointer-checks  -fno-strict-aliasing -fno-aggressive-loop-optimizations -fwrapv                                                          |
   | All-ub (clang) | all-ub_clang.txt       | -O3 -fno-strict-overflow  -fno-delete-null-pointer-checks  -fno-strict-aliasing                                                          |

# Effectiveness evaluation

Run the [script](../effectiveness_evaluation.py) tp obtain the detailed 
effectiveness of each compiler.
- Useage: `python3 effectiveness_evaluation.py [-h] [-opt OPT]`
- An example to get the effectiveness result of strategy `all-cisb` for gcc with 
the corresponding compiler config ([all-options_gcc.txt](all-options_gcc.txt)).
```
python3 effectiveness_evaluation.py -opt extra_options/all-options_gcc.txt 2> /dev/null
```

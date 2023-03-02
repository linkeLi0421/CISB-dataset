#! /bin/bash 
echo "obtain compiliers now"
apt-add-repository "deb http://dk.archive.ubuntu.com/ubuntu/ bionic main universe"
apt-add-repository "deb http://dk.archive.ubuntu.com/ubuntu/ bionic main universe"
apt-add-repository "deb http://dk.archive.ubuntu.com/ubuntu/ xenial main universe"
add-apt-repository 'deb http://archive.ubuntu.com/ubuntu/ trusty main universe'
add-apt-repository 'deb http://archive.ubuntu.com/ubuntu/ jammy main universe'
apt-get update
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
apt-add-repository "deb https://apt.llvm.org/xenial/ llvm-toolchain-xenial-3.9 main"
apt-get install  clang-3.9 clang-14 lldb-3.9 gcc-4.4 gcc-4.7 gcc-4.8 gcc-4.9 gcc-5 gcc-6 gcc-7 gcc-8 gcc-9 gcc-12 -y

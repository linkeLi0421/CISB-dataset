#! /bin/bash 
echo "obtain compiliers now"
apt-add-repository "deb http://dk.archive.ubuntu.com/ubuntu/ focal main universe"
apt-add-repository "deb http://dk.archive.ubuntu.com/ubuntu/ bionic main universe"
apt-add-repository "deb http://dk.archive.ubuntu.com/ubuntu/ xenial main universe"
add-apt-repository 'deb http://archive.ubuntu.com/ubuntu/ trusty main universe'
add-apt-repository 'deb http://archive.ubuntu.com/ubuntu/ jammy main universe'
apt-get update
apt-get install  clang-14 gcc-4.4 gcc-4.9 gcc-7 gcc-12 -y
pip3 install -r requirements.txt
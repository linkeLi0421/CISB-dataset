#! /bin/bash 
echo "obtain compiliers now"
cp /etc/apt/sources.list /etc/apt/sources.list.bak
echo  "deb http://dk.archive.ubuntu.com/ubuntu/ focal main universe"  >> /etc/apt/sources.list
echo  "deb http://dk.archive.ubuntu.com/ubuntu/ bionic main universe" >> /etc/apt/sources.list
echo  "deb http://dk.archive.ubuntu.com/ubuntu/ xenial main universe" >> /etc/apt/sources.list
echo  'deb http://archive.ubuntu.com/ubuntu/ trusty main universe' >> /etc/apt/sources.list
echo  'deb http://archive.ubuntu.com/ubuntu/ jammy main universe' >> /etc/apt/sources.list
apt-get update
apt-get install clang-12 clang-14 gcc-4.4 gcc-4.9 gcc-7 gcc-12 -y
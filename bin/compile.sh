#!/bin/zsh

file_name=$1

g++-12 -std=c++20 -Wall -Wextra $file_name
clang-format -i $file_name

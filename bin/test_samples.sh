#!/bin/zsh

file_name=$1
g++-11 -std=c++17 -g -Wall -Wextra -fsanitize=address,undefined $file_name
oj t -N

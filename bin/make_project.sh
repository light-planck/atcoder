#!/bin/zsh

number=$1
mkdir $number
cd $number

for problem in a b c d e f g
do
  cp ~/workspace/atcoder/bin/template.cpp ${problem}.cpp
done

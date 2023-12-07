#!/bin/bash

contest=$(basename ${PWD%/*})
number=$(basename $PWD)
problem=$1

url="https://atcoder.jp/contests/${contest}${number}/tasks/${contest}${number}_${problem}"

rm -rf test
oj d $url

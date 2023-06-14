#!/bin/zsh

contest=$1
number=$2
problem=$3
url="https://atcoder.jp/contests/${contest}${number}/tasks/${contest}${number}_${problem}"

rm -rf test
oj d $url

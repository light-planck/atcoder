#!/bin/zsh

base_dir=~/workspace/atcoder

cargo compete new abc$1

mv ${base_dir}/abc/abc$1 ${base_dir}/abc/$1

cd ${base_dir}/abc/$1

#!/bin/zsh

base_dir=~/workspace/atcoder

number=$(basename "$PWD")
cargo compete new abc$number

mv ${base_dir}/abc/abc$number/* ${base_dir}/abc/$number
rmdir ${base_dir}/abc/abc$number

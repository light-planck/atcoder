#!/bin/zsh

# ホストの作業ディレクトリを取得
host_dir=$(pwd)

# ベースディレクトリを設定
base_dir=~/workspace/atcoder

cargo compete new abc$1

mv ${base_dir}/abc/abc$1 ${base_dir}/abc/$1

cd ${base_dir}/abc/$1

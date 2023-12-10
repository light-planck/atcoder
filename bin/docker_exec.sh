#!/bin/bash

# ホストの作業ディレクトリを取得
host_dir=$(pwd)

# ベースディレクトリを設定
base_dir=~/workspace/atcoder

# ホストの作業ディレクトリからベースディレクトリを削除してコンテナ内のパスを取得
container_dir=${host_dir#$base_dir}

# docker compose execコマンドを実行
docker compose exec -w /atcoder$container_dir ubuntu bash

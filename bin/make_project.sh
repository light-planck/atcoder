#!/bin/zsh

PROBLEMS=("a" "b" "c" "d" "e" "f" "g")

function create_template_files {
  local problems=("$@")
  for problem in "${problems[@]}"
  do
    cp ~/workspace/atcoder/bin/template.cpp ${problem}.cpp
  done
}

function create_atcoder_info {
  local contest=$1
  local number=$2
  shift 2
  local tasks=("$@")

  # contestがabc, arc, agcのどれでもない場合、エラーを出力して終了
  if [[ "$contest" != "abc" && "$contest" != "arc" && "$contest" != "agc" ]]; then
    echo "Error: Invalid contest. The contest must be one of 'abc', 'arc', or 'agc'."
    exit 1
  fi

  # numberが001, 002, ..., 123のような3桁の0埋めの整数でない場合、エラーを出力して終了
  if ! [[ "$number" =~ ^[0-9]{3}$ ]]; then
    echo "Error: Invalid number. The number must be a three-digit zero-padded integer."
    exit 1
  fi

  # YAMLファイルの内容を生成
  yaml_content="urls:"

  # 各タスクに対してURLを生成
  for task in "${tasks[@]}"; do
    yaml_content+="\n  $task: https://atcoder.jp/contests/${contest}${number}/tasks/${contest}${number}_$task"
  done

  echo -e "$yaml_content" > .atcoder_info.yaml
}

function main {
  local number=$1
  mkdir $number
  cd $number

  cp -r ../../.vscode .

  create_template_files "${PROBLEMS[@]}"

  local contest=$(basename ${PWD%/*})
  create_atcoder_info $contest $number "${PROBLEMS[@]}"
}

main $1

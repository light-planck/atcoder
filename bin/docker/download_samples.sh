#!/bin/bash

problem=$1

url=$(yq ".urls.$problem" .atcoder_info.yaml -r)

rm -rf test
oj d $url

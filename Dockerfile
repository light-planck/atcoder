FROM --platform=linux/x86_64 ubuntu:20.04

RUN apt-get update
RUN apt-get install -y locales git python3 g++
RUN yes | unminimize
RUN locale-gen ja_JP.UTF-8
ENV LANG=ja_JP.UTF-8
ENV TZ=Asia/Tokyo
WORKDIR /AtCoder
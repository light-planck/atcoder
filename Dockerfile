FROM --platform=linux/x86_64 ubuntu:20.04

RUN apt-get update
RUN apt-get install -y locales git python3 g++
RUN echo 'alias g="g++ -std=c++17"' >> ~/.bashrc
RUN echo 'alias a="./a.out"' >> ~/.bashrc
RUN echo 'alias py="python3"' >> ~/.bashrc
RUN yes | unminimize
RUN locale-gen ja_JP.UTF-8
ENV LANG=ja_JP.UTF-8
ENV TZ=Asia/Tokyo
WORKDIR /AtCoder

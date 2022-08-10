FROM --platform=linux/x86_64 ubuntu:20.04

RUN apt-get update
RUN apt-get install -y locales git build-essential sudo

RUN echo 'alias g="g++ -std=c++17 -g -Wall -Wextra -fsanitize=address,undefined"' >> ~/.bashrc
RUN echo 'alias a="./a.out"' >> ~/.bashrc
RUN echo 'alias cppwd="pwd | clip.exe"' >> ~/.bashrc
RUN echo 'alias mkfile="touch a.cpp b.cpp c.cpp d.cpp e.cpp"' >> ~/.bashrc
RUN echo 'alias vscode="cp -r ../../.vscode ."' >> ~/.bashrc

RUN yes | unminimize
RUN locale-gen ja_JP.UTF-8
ENV LANG=ja_JP.UTF-8
ENV TZ=Asia/Tokyo
WORKDIR /atcoder

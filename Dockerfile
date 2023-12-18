FROM --platform=linux/amd64 ubuntu:latest

RUN apt-get update && \
  apt-get install -y locales git build-essential sudo software-properties-common vim jq python3-pip && \
  yes | unminimize && \
  locale-gen ja_JP.UTF-8 && \
  add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
  apt-get update && \
  apt-get install -y gcc-12 g++-12 && \
  update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 90 && \
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 90 && \
  pip3 install --user online-judge-tools && \
  pip3 install yq && \
  git clone https://github.com/atcoder/ac-library.git /opt/ac-library

COPY bin/docker/* /root/bin/
RUN cat /root/bin/env.sh >> ~/.bashrc

ENV LANG=ja_JP.UTF-8
ENV TZ=Asia/Tokyo

WORKDIR /atcoder

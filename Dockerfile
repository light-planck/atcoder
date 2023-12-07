FROM --platform=linux/amd64 ubuntu:latest

RUN apt-get update && \
  apt-get install -y locales git build-essential sudo software-properties-common python3-pip && \
  yes | unminimize && \
  locale-gen ja_JP.UTF-8 && \
  add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
  apt-get update && \
  apt-get install -y gcc-12 g++-12 && \
  update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 90 && \
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-12 90 && \
  pip3 install --user online-judge-tools

COPY bin/download_samples.sh /root/bin/download_samples.sh
COPY bin/docker_env.sh /root/docker_env.sh
RUN echo 'source /root/docker_env.sh' >> ~/.bashrc && \
  rm /root/docker_env.sh

ENV LANG=ja_JP.UTF-8
ENV TZ=Asia/Tokyo

WORKDIR /atcoder

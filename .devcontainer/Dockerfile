FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        gfortran \
        git \
        cmake \
        make \
        nano \
        wget \
        sudo \
        curl \
        ca-certificates \
        bash-completion \
        python3-pip \
    && rm -rf /var/lib/apt/lists/*

RUN git config --global user.name "Derek Wingard" && \
    git config --global user.email "derekwingard@gmail.com"

RUN useradd -ms /bin/bash VOID && \
    echo "VOID ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    mkdir -p /home/VOID/app && chown -R VOID:VOID /home/VOID/app

USER VOID
WORKDIR /home/VOID/app

RUN echo "source /etc/bash_completion" >> /home/VOID/.bashrc && \
    echo "alias python=python3" >> /home/VOID/.bashrc && \
    echo "alias lr='ls -lart'" >> /home/VOID/.bashrc && \
    echo "alias cd..='cd ..'" >> /home/VOID/.bashrc

RUN pip3 install --user fortls

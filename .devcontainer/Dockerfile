FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive



# Install system packages including gfortran, pip, and other dev tools

RUN apt-get update && apt-get install -y --no-install-recommends gfortran
    
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
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
        python3-venv \
    && rm -rf /var/lib/apt/lists/*

# Git global config
RUN git config --global user.name "Derek Wingard" && \
    git config --global user.email "derekwingard@gmail.com"

RUN useradd -ms /bin/bash VOID && \
    echo "VOID ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    mkdir -p /home/VOID/app && chown -R VOID:VOID /home/VOID/app


USER VOID
WORKDIR /home/VOID/app

ENV FC=gfortran
ENV PATH="/home/VOID/.local/bin:$PATH"

RUN echo "source /etc/bash_completion" >> /home/VOID/.bashrc && \
    echo "alias python=python3" >> /home/VOID/.bashrc && \
    echo "alias lr='ls -lart'" >> /home/VOID/.bashrc && \
    echo "alias cd..='cd ..'" >> /home/VOID/.bashrc

RUN pip3 install --user fortls
RUN gfortran --version && fortls --version

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

# Create user VOID
RUN useradd -ms /bin/bash VOID && \
    echo "VOID ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    mkdir -p /home/VOID/app && chown -R VOID:VOID /home/VOID/app

# Create scripts folder and add to PATH
RUN mkdir -p /home/VOID/app/scripts && \
    echo 'export PATH="/home/VOID/app/scripts:$PATH"' >> /home/VOID/.bashrc

# Switch to user and working directory
USER VOID
WORKDIR /home/VOID/app

# Environment variables and aliases
ENV FC=gfortran
ENV PATH="/home/VOID/.local/bin:$PATH"

RUN echo "source /etc/bash_completion" >> /home/VOID/.bashrc && \
    echo "alias python=python3" >> /home/VOID/.bashrc && \
    echo "alias lr='ls -lart'" >> /home/VOID/.bashrc && \
    echo "alias cd..='cd ..'" >> /home/VOID/.bashrc
    alias gitmain=scripts/gitmain
    alias gitbranch=scripts/gitbranch
    alias gitster=scripts/gitster

# Install Python package
RUN pip3 install --user fortls

# Verify installations
RUN gfortran --version && fortls --version

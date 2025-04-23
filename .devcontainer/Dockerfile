FROM debian:12.10-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    make\
    git\
    ninja-build\
    wget\
    python3\
    python3-pip\
    lsb-release\
    wget\
    software-properties-common\
    gnupg\
    python3-venv

RUN  wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 17 && \
    rm llvm.sh

RUN wget https://github.com/Kitware/CMake/releases/download/v4.0.1/cmake-4.0.1-linux-x86_64.sh && \
    chmod +x cmake-4.0.1-linux-x86_64.sh && \
    ./cmake-4.0.1-linux-x86_64.sh --skip-license --prefix=/usr/local && \
    rm cmake-4.0.1-linux-x86_64.sh

RUN apt-get install -y --no-install-recommends \
    clang-format-17\
    clang-tidy-17\
    clang-tools-17

RUN update-alternatives --install /usr/bin/cc cc /usr/bin/clang-17 100 &&\
    update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-17 100 

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME -s /bin/bash\
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

+++
title = "Installing GCC"
date = "2023-08-05"
tags = [
    "gcc",
    "setup",
]
weight = 1
+++

# Installing gcc

This tutorial will be a quick walkthrough on installing gcc on different OS. We recommend you try installing gcc on your own before the start of classes. If, for some reason, you are unable to install gcc, then we will help you in the first tutorial session. We also recommend you install some text editor (VS Code for example).

{{<hint info>}}
We recommend the usage of Linux as this would be advantageous for your future courses as well.
{{</hint>}}

{{< tabs "uniqueid" >}}
{{< tab "linux" >}}

## Linux (Ubuntu 22.04)

For Linux-based systems, gcc usually comes installed by default.

Check if gcc is installed on Ubuntu by running the command:
`$ gcc --version`

If running this shows a version (For eg 13.1 or say any other version) then you are good to go.

Otherwise, if you see an error that reads “command not found” or something similar, run the following commands:

`$ sudo apt update`

`$ sudo apt install build-essential`

After running this, check if gcc is installed by running:

`$ gcc --version`
{{< /tab >}}
{{< tab "mac" >}} 

## MacOS

For Mac-based systems, first start with installing homebrew (if not installed).

`$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`

After installing homebrew, you simply have to run:

`$ brew install gcc`

After running this, check if gcc is installed by running:

`$ gcc --version`

This should show the path in which gcc has been installed on your Mac.

{{< /tab >}}
{{< tab "windows" >}} 
## Windows

In Windows, C programs can be compiled using the MinGW C compiler.

For installation details, refer:
[`https://www.scaler.com/topics/c/c-compiler-for-windows/`](https://www.scaler.com/topics/c/c-compiler-for-windows/)

Alternatively, you can install [WSL](https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-11-with-gui-support#1-overview) or a Virtual Machine to have a Linux-like environment.

{{< /tab >}}
{{< /tabs >}}


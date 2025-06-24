# My Operating System
Building an os from scratch

## Setup
Install Dependencies
```bash
sudo apt-get install g++ binutils libc6-dev-i386 grub-pc xorriso mtools
```
Make ISO File
```bash
make loader.o
make kernel.o
make mykernel.bin
make mykernel.iso
```
Install Virtual Box
```bash
wget https://download.virtualbox.org/virtualbox/7.0.20/virtualbox-7.0_7.0.20-163906~Ubuntu~jammy_amd64.deb
sudo apt --fix-broken install virtualbox-7.0_7.0.20-163906~Ubuntu~jammy_amd64.deb
```
Run The OS in the VM
```bash
make run
```

## Intro
A Simple Hello World OS

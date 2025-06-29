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
Setup Virtual Box

Open Virtual Box and Setup the VM
- Name: My Operating System"
- ISO Image: [Select location of the .iso file]
- Type: Other
- Version: Other/Unknown
- Do Not Add a Virtual Hard Disk

Run The OS in the VM
```bash
make run
```

## File Purposes
### kernel.cpp
- Contains main C++ kernel code
### loader.s
- Sets stack pointer then jumps to kernel.cpp
### linker.ld
- Links kernel.o and loader.o into kernel.bin
### Makefile
- Automates the build process
- Runs the kernel in Virtual Box
### types.h
- Defines consistent types to use
### gdt.cpp/gdt.h
- Sets up the Global Descriptor Table

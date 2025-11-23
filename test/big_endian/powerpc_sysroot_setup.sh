#!/bin/bash
# 
# Setups up powerpc sysroot on Ubuntu 22.04
#
set -e

sudo apt install -y qemu-user-static debootstrap
SYSROOT=${HOME}/powerpc_sysroot
mkdir -p ${SYSROOT}
sudo debootstrap --arch=powerpc --foreign \
    jessie ${SYSROOT} \
    http://archive.debian.org/debian
sudo cp /usr/bin/qemu-ppc-static ${SYSROOT}/usr/bin/
sudo chroot ${SYSROOT} /debootstrap/debootstrap --second-stage

sudo chroot ${SYSROOT} /bin/bash -c "apt update && apt install -y --force-yes zlib1g-dev build-essential vim file"

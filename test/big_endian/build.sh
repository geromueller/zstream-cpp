#!/bin/bash
set -e

SYSROOT=${HOME}/powerpc_sysroot

sudo cp -r ../../../zstream-cpp ${SYSROOT}
sudo chroot ${SYSROOT} /bin/bash -c "cd zstream-cpp/test && make"

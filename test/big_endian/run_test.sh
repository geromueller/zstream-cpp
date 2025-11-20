#!/bin/bash
set -e

SYSROOT=${HOME}/powerpc_sysroot
TEST_FILE=${SYSROOT}/test.txt

sudo rm -f ${TEST_FILE} ${SYSROOT}/test.txt.gz
sudo chroot ${SYSROOT} ./zstream-cpp/test/output_test
sudo chroot ${SYSROOT} gunzip ./test.txt.gz

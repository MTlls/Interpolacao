#!/bin/bash

METRICA="FLOPS_DP"
CPU=3

LIKWID_HOME=/home/soft/likwid
CFLAGS="-I${LIKWID_HOME}/include -DLIKWID_PERFMON"
LFLAGS="-L${LIKWID_HOME}/lib -llikwid"

PROGRAM="interpola"
MAKEFILE="make"
PURGE="purge"

arg="$1"

make -B CFLAGS="${CFLAGS}" LFLAGS="${LFLAGS}"

for k in $METRICA
do
    likwid-perfctr -C ${CPU} -g ${k} -m ./${PROGRAM} ${arg} > ${k}.log
    flops=$(awk -F "|" '/\| +DP \[?MFLOP\/s\]?/ { print $3 }' ${k}.log | sed 's/ //g')

    sed -i '/Region/,$d' ${k}.log
    echo "$flops" | awk -v k="$k" '{print "DP [MFLOPS/s] " $0}' >> "${k}.log"
    sed -i '/^-*$/,/^-*$/d' ${k}.log
    cat ${k}.log
done


#!/bin/bash

export DYNINSTAPI_RT_LIB=/usr/local/lib/libdyninstAPI_RT.so
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

make clean && make


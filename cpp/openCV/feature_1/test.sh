#!/usr/bin/env bash

./build.sh
./build/DisplayImage ../samples/hana.jpg ../samples/hana2.jpg; if ! $(exit $?);then EXIT_STATUS=1;fi

exit $EXIT_STATUS

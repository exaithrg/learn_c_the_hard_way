#***************************************************************
# Description: 
# File Name: runtests.sh
# Author: Haoran Geng
# Email: 
# Created Time: Sun 26 Feb 2023 05:30:48 PM CST
# Revision history:
#***************************************************************
echo "Running unit tests:"

for i in tests/*_tests
do
    if test -f $i
    then
        if $VALGRIND ./$i build/libex29.so 2>> tests/tests.log
        then
            echo $i PASS
        else
            echo "ERROR in test $i: here's tests/tests.log"
            echo "------"
            tail tests/tests.log
            exit 1
        fi
    fi
done

echo ""

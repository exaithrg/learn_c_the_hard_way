#***************************************************************
# Description: 
# File Name: runtests.sh
# Author: Haoran Geng
# Email: 
# Created Time: Sun 26 Feb 2023 05:30:48 PM CST
# Revision history:
#***************************************************************

# color the output nicely
RED='\e[1;31m'
GREEN='\e[1;32m'
YELLOW='\e[1;33m'
BLUE='\e[1;34m'
PINK='\e[1;35m'
NC='\e[0m'

echo "${YELLOW}Running unit tests:${NC}"

for i in tests/*_tests
do
    if test -f $i
    then
        if $VALGRIND ./$i 2>> tests/tests.log
        then
            echo "${GREEN}$i PASS${NC}"
        else
            echo "${RED}ERROR in test $i${NC}" 
            echo "For more info, see tests.log"
            echo "------"
            #tail tests/tests.log
            exit 1
        fi
    fi
done

echo ""

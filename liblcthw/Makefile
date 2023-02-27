# Makefile written by Zed A. Shaw
# Comments: https://www.cntofu.com/book/25/ex28.md

# # WARNING! Just a demonstration, won't really work right now.
# # this installs the library into /tmp
# $ make PREFIX=/tmp install
# # this tells it to add pthreads
# $ make OPTFLAGS=-pthread
SRC_DIR=./src
LCTHW_DIR=$(SRC_DIR)/lcthw
BUILD_DIR=./build
TESTS_DIR=./tests
 
CC=gcc
INCLUDES=-I$(SRC_DIR) -I$(LCTHW_DIR) 

CFLAGS=-g -std=c99 -O2 -Wall -Wextra -rdynamic -DNDEBUG $(INCLUDES) $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)

PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
# OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
OBJECTS=$(SOURCES:%.c=%.o)

TEST_SOURCES=$(wildcard $(TESTS_DIR)/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SOURCES))

SLIB_TARGET=$(BUILD_DIR)/liblcthw.a
DLIB_TARGET=$(patsubst %.a,%.so,$(SLIB_TARGET))

# The Target Build
all: target tests

target: build $(SLIB_TARGET) $(DLIB_TARGET)

$(SLIB_TARGET): CFLAGS += -fPIC
$(SLIB_TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(DLIB_TARGET): $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

# $(TESTS_DIR)/%.tst: $(TESTS_DIR)/%.c
#     $(CC) $(CFLAGS) $< $(SLIB_TARGET) -o $@ $(LIBS)

# The Unit Tests
.PHONY: tests
tests: $(TESTS)
	sh ./tests/runtests.sh

build:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(TESTS_DIR)

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
# clean:
#     rm -rf build $(OBJECTS) $(TESTS)
#     rm -f tests/tests.log
#     find . -name "*.gc*" -exec rm {} \;
#     rm -rf `find . -name "*.dSYM" -print`

clean:
	rm -rf $(BUILD_DIR) || true
	rm $(OBJECTS) || true
	rm $(TESTS) || true
	rm tests/tests.log || true

# The Install
# install: all
#     install -d $(DESTDIR)/$(PREFIX)/lib/
#     install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true


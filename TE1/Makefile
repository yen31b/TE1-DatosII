
WD=$(shell pwd)

BIN_NAME=te1

CC=g++
CFLAGS=-O2 -std=c++11

BIN_DIR=bin
HEADER=include
BENCH_DIR=benchmarks


C_FILES=$(wildcard src/*.cpp)

.PHONY: clean main

main: dir build
	@echo "Building binaries"

build:
	@$(CC) -I"$(HEADER)" -o "$(BIN_DIR)/$(BIN_NAME)" $(C_FILES) $(CFLAGS)

dir:
	@mkdir -p $(BIN_DIR)

clean:
	@rm $(BIN_DIR) -rf
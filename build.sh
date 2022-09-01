#!/bin/bash

clang++ -Wall -std=c++17 -stdlib=libstdc++ -ggdb3 -o test test.cpp
#clang++ -Wall -std=c++17 -ggdb3 -fsanitize=address -o test test.cpp

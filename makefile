SHELL=zsh

INC_DIR = ./
DEBUG = -Og -g3 -fno-omit-frame-pointer -U"NDEBUG"
NDEBUG = -Ofast -funroll-loops -D"NDEBUG"
CXXFLAGS_ADD = -march=native
CXXFLAGS = -Wall -I$(INC_DIR) $(CXXFLAGS_ADD) $(NDEBUG) -pipe
#-Winline 

all: main

main: main.cpp GaussQuad.cpp GaussQuad.hpp
	g++ $(CXXFLAGS) -o $@ main.cpp GaussQuad.cpp

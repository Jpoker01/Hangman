cmake_minimum_required(VERSION 3.17)
project(Hangman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hangman main.cpp Engine.cpp Engine.h Dictionary.cpp Dictionary.h Player.cpp Player.h)
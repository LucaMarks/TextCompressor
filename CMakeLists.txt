cmake_minimum_required(VERSION 4.0)
project(TextCompressor C)

set(CMAKE_C_STANDARD 23)

add_executable(TextCompressor main.c
        MainHeader.h
        FrequencyAnalysis/Frequency.c
        Compress/CompressWord.c)

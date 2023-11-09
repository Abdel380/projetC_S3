cmake_minimum_required(VERSION 3.26)
project(Projet_c C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_c main.c
        fonctions.c
        fonctions.h
        cell.c
        cell.h
        list.c
        list.h
        timer.c)

cmake_minimum_required(VERSION 3.17)
project(Proiect_OOP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proiect_OOP main.cpp includes/Traseu.h sources/Traseu.cpp includes/Marcaj.h sources/Marcaj.cpp sources/Traseu_marcat.cpp includes/Traseu_marcat.h sources/Meteo.cpp includes/Meteo.h sources/Traseu_nemarcat.cpp includes/Traseu_nemarcat.h sources/Excursie.cpp includes/Excursie.h includes/Strategy.h)
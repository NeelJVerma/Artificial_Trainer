cmake_minimum_required(VERSION 3.13)
project(Artificial_Trainer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Artificial_Trainer src/main.cc src/clientelements/gui.cc src/clientelements/gui.h src/pokemon/species.h src/pokemon/pokemon.cc src/pokemon/pokemon.h src/stat/statnames.h src/clientelements/sanitizer.cc src/clientelements/sanitizer.h src/team/team.cc src/team/team.h)
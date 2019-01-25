cmake_minimum_required(VERSION 3.13)
project(Artificial_Trainer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Artificial_Trainer src/main.cc src/clientelements/gui.cc src/clientelements/gui.h src/pokemon/species.h src/pokemon/pokemon.cc src/pokemon/pokemon.h src/stat/statnames.h src/clientelements/sanitizer.cc src/clientelements/sanitizer.h src/team/team.cc src/team/team.h src/stat/stat.cc src/stat/stat.h src/stat/hp.cc src/stat/hp.h src/stat/ev.cc src/stat/ev.h src/stat/iv.cc src/stat/iv.h)
cmake_minimum_required(VERSION 3.24)
project(untitled9)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled9 main.cpp Domeniu/cheltuiala.cpp Domeniu/cheltuiala.h Repository/repository.cpp Repository/repository.h Test/test.cpp Test/test.h Service/Service.cpp Service/Service.h Domeniu/Undo.cpp Domeniu/Undo.h Repository/FileRepo.h Repository/FileRepo.cpp Domeniu/cheltuiala.cpp)

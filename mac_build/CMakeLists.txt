cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(IBAN-GUARD VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/mac)

add_executable(IBAN-GUARD 
                    ../src/main.cpp
                    ../src/ibanNumber.cpp
                    ../src/command_handlers.cpp)

target_include_directories(IBAN-GUARD PRIVATE ../include)
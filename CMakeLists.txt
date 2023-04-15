cmake_minimum_required(VERSION 3.18.4)

project(Monopoly_for_Linux)

add_library(own_random_libary Own_Random_Libary/own_random_libary.hpp Own_Random_Libary/own_random_libary.cpp)
add_library(event_field Fields/event_field.hpp Fields/event_field.cpp)
add_library(plots Fields/plots.hpp Fields/plots.cpp)
add_library(player Player/player.hpp Player/player.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(Monopoly_for_Linux PRIVATE own_random_libary)
target_link_libraries(Monopoly_for_Linux PRIVATE event_field)
target_link_libraries(Monopoly_for_Linux PRIVATE plots)
target_link_libraries(Monopoly_for_Linux PRIVATE player)
cmake_minimum_required(VERSION 3.18.4)

project(Monopoly_for_Linux)

add_library(dice Dice/dice.hpp Dice/dice.cpp)
add_library(event_field fields/event_field.hpp fields/event_field.cpp)
add_library(plots fields/plots.hpp fields/plots.cpp)
add_library(player player/player.hpp player/player.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(Monopoly_for_Linux PRIVATE dice)
target_link_libraries(Monopoly_for_Linux PRIVATE event_field)
target_link_libraries(Monopoly_for_Linux PRIVATE plots)
target_link_libraries(Monopoly_for_Linux PRIVATE player)
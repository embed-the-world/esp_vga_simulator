
cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME vga_controller)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

option(DO_GPIO_TEST "start controller in endless loop, blinking ios." ON)

project(${PROJECT_NAME})

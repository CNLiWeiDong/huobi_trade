cmake_minimum_required(VERSION 3.5)
project(num_monitor)

#set constum find_package modele path.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/hbapp_public/CMakeModules")

include(hbapp)

add_subdirectory(hbapp_public)
add_subdirectory(plugins)
add_subdirectory(hbapp)
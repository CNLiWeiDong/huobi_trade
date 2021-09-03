cmake_minimum_required(VERSION 3.5)
project(grid_trade_test)

set(CMAKE_CXX_STANDARD 14)


add_executable(grid_trade_test main.cpp)

target_include_directories(grid_trade_test
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}"
        )

target_link_libraries( grid_trade_test
        grid_trade_plugin
        )

add_test(NAME grid_trade_test COMMAND grid_trade_test)
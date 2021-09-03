cmake_minimum_required(VERSION 3.5)
project(trade_api_test)

set(CMAKE_CXX_STANDARD 14)


add_executable(trade_api_test main.cpp)

target_include_directories(trade_api_test
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}"
        )

target_link_libraries( trade_api_test
        trade_api_plugin
        )

add_test(NAME trade_api_test COMMAND trade_api_test)
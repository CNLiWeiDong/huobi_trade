cmake_minimum_required(VERSION 3.5)
project(trade_db_test)

set(CMAKE_CXX_STANDARD 14)


add_executable(trade_db_test main.cpp)

target_include_directories(trade_db_test
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}"
        )

target_link_libraries( trade_db_test
        trade_db_plugin
        )

add_test(NAME trade_db_test COMMAND trade_db_test)
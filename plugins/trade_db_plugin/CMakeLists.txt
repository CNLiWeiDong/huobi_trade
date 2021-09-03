cmake_minimum_required(VERSION 3.5)
project(trade_db_plugin)

set(CMAKE_CXX_STANDARD 14)

file(GLOB HEADERS "include/hb/trade_db_plugin/*.h"
        )

add_library(trade_db_plugin
        trade_db_plugin.cpp
        trade_db_plugin_impl.cpp
        ${HEADERS}
        )

target_include_directories( trade_db_plugin
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include"
        )

target_link_libraries( trade_db_plugin
        appbase
        hb
        log_plugin
        mysql_plugin
        )
add_subdirectory(test)

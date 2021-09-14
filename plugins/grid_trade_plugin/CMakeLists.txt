cmake_minimum_required(VERSION 3.5)
project(grid_trade_plugin)

file(GLOB HEADERS "include/hb/grid_trade_plugin/*.h"
        )

add_library(grid_trade_plugin
        grid_trade_plugin.cpp
        grid_trade_plugin_impl.cpp
        delvier_order.cpp
        new_order.cpp
        ${HEADERS}
        )

target_include_directories( grid_trade_plugin
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include"
        )

target_link_libraries( grid_trade_plugin
        appbase
        hb
        log_plugin
        trade_db_plugin
        send_mail_plugin
        trade_api_plugin
        )

add_subdirectory(test)
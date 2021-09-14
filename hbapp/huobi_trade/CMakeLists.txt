cmake_minimum_required(VERSION 3.5)
project(huobi_trade)

set(CMAKE_CXX_STANDARD 14)


add_executable(huobi_trade trade.cpp)

target_include_directories(huobi_trade
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}"
        )

target_link_libraries(huobi_trade
        PRIVATE appbase
        PRIVATE ${Boost_LIBRARIES} #boost test
        PRIVATE -Wl,${whole_archive_flag} log_plugin                             -Wl,${no_whole_archive_flag}
        PRIVATE -Wl,${whole_archive_flag} grid_trade_plugin                      -Wl,${no_whole_archive_flag}
        )
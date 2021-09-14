cmake_minimum_required(VERSION 3.5)
project(num_monitor)

set( CMAKE_CXX_STANDARD 20 )
#set constum find_package modele path.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/hbapp_public/CMakeModules")
#set cmake test enable
enable_testing()
#New CXX_STANDARD and CXX_EXTENSIONS target properties may specify values which CMake uses to compute required compile options such as -std=c++11 or -std=gnu++11.
#The CMAKE_CXX_STANDARD and CMAKE_CXX_EXTENSIONS variables may be set to initialize the target properties.
set( CMAKE_CXX_EXTENSIONS ON )
set( CXX_STANDARD_REQUIRED ON)
#Enable/Disable output of compile commands during generation.If enabled, generates a compile_commands.json file containing the exact compiler calls
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
#use static lib
set( BUILD_SHARED_LIBS NO )
#编译静态库使用fPIC
add_compile_options(-fPIC)

if (UNIX AND APPLE)
    #Path used for searching by FIND_XXX(), with appropriate suffixes added.
    #list(APPEND CMAKE_INCLUDE_PATH "include_path")
    #list(APPEND CMAKE_LIBRARY_PATH "lib_path")
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/llvm")
endif()

# detect operating system
message(STATUS "project is in ${CMAKE_SYSTEM_NAME} system")
if( APPLE )
    # Apple Specific Options Here
    set(darwin true CACHE INTERNAL "darwin flag" )
    add_definitions(-Ddarwin)
else( APPLE )
    set(linux true CACHE INTERNAL "linux flag" )
    add_definitions(-Dlinux)
endif( APPLE )
if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(
            -D_DEBUG
            -DDEBUG
    )
    message(STATUS "project is in Debug modle")
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    add_definitions(
            -DNDEBUG
            -D_RELEASE
    )
    message(STATUS "project is in Release modle")
endif ()


message( STATUS "CMAKE_GENERATOR:${CMAKE_GENERATOR}")
message(STATUS "CMAKE_CXX_COMPILER_ID:${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION:${CMAKE_CXX_COMPILER_VERSION}")
# http://stackoverflow.com/a/18369825
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 11.0)
        message(FATAL_ERROR "GCC version must be at least 11.0!")
    endif()
    if ("${CMAKE_GENERATOR}" STREQUAL "Ninja")
        add_compile_options(-fdiagnostics-color=always)
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 11.0)
        message(FATAL_ERROR "Clang version must be at least 11.0!")
    endif()
    if ("${CMAKE_GENERATOR}" STREQUAL "Ninja")
        add_compile_options(-fcolor-diagnostics)
    endif()
endif()

if(UNIX)
    if(APPLE)
        set(whole_archive_flag "-force_load")
        set(no_whole_archive_flag "")
    else()
        set(whole_archive_flag "--whole-archive")
        set(no_whole_archive_flag "--no-whole-archive")
    endif()
endif()

if( APPLE )
    # Apple Specific Options Here
    message( STATUS "Configuring project on OS X" )
    set( CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations" )
else( APPLE )
    # Linux Specific Options Here
    message( STATUS "Configuring project on Linux" )
    set( CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS} -Wall" )
    # FULL_STATIC_BUILD
    set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc")

    if( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" )
        if( CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL 4.0.0 OR CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.0.0 )
            set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-partial-specialization" )
        endif()
    endif()
endif( APPLE )


# # add defaults for thread
# set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
# set(THREADS_PREFER_PTHREAD_FLAG TRUE)

add_subdirectory(hbapp_public)
add_subdirectory(plugins)
add_subdirectory(hbapp)
# Root Cmake. Use to link the different libraries
#
# @version 1.0


#########################################################################################################
###                                       GENERAL CONFIG                                               ##
#########################################################################################################

message("%%% SYNTHESIS PROJECT : TEST API CALL")
message("\n%% GENERAL CONFIGURATION")

# GENERAL SETTINGS
project(ApiCall CXX)
cmake_minimum_required(VERSION 3.2)
set(VERSION 1.0.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(APP_NAME ApiCall)

# OUTPUT DIR SETTINGS
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

# COMPILER OPTIONS
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG   " -g3 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE " -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}") # Warning : option are important for some lib

########################################################################################################
###                                       LIBRARY CONFIG                                              ##
########################################################################################################

message("\n%% EXTERNALS libs configuration")

message("- Checking : curl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

message("- Checking : Cpr")
find_library(CPR_LIB cpr REQUIRED)

message("- Checking : Thread")
find_package(Threads)

message("- Checking : Curses")
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


######################################################################################################
###                                            LINKS                                                ##
######################################################################################################

link_libraries(
    ${CPR_LIB}  
    ${CURL_LIBRARIES}
    ${CURSES_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    dl
    config++
    panel
    curl
    cpr
)

add_subdirectory(lib)
include_directories(lib)
include_directories(src)

######################################################################################################
###                                         APPLICATION                                             ##
######################################################################################################

message("\n%% APPLICATION GENERATION")

file(GLOB_RECURSE drone_SRC 
    "lib/*.h"
    "lib/*.hpp"
    "src/*.h"
    "src/*.cpp"
)

# %% App files
add_executable(${APP_NAME} ${drone_SRC})

target_link_libraries(${APP_NAME} PUBLIC
    loguru
    nlohmann
)
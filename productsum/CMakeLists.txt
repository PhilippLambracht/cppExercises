#
# at least use version 2.6 (syntax changes..)
#
cmake_minimum_required(VERSION  2.8)

#
# run make in verbose mode, let IDE discover errors from build log
#
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)

#
# project settings
#
project(productsum)

#
# Additional GNU Compiler flags for UNIX systems
#
IF(UNIX)
    set(GENFLAGS "-pipe -DDEBUG -ggdb -DLINUX")
    add_definitions("-DUNIX")
ENDIF(UNIX)

#
# Additional compiler for gcc and g++.
#
IF(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${GENFLAGS} ${CMAKE_C_FLAGS} -fmessage-length=0 -Wall -Wextra")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

IF(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${GENFLAGS} ${CMAKE_CXX_FLAGS} -fmessage-length=0 -Wall -std=c++11 -Wextra -rdynamic")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

#
# Build directories.
#
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib/)
message("binary install path  : " ${EXECUTABLE_OUTPUT_PATH})
message("library install path : " ${LIBRARY_OUTPUT_PATH})

#
# Add CMake subdirectories.
#

# sources
add_subdirectory(src)
# libraries
add_subdirectory(lib)
# gtest
add_subdirectory(ext/gtest)
# tests
add_subdirectory(test)

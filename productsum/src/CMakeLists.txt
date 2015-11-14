set(APPNAME ${PROJECT_NAME}-cli)

file(GLOB_RECURSE CPPSOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")

include_directories("${${PROJECT_NAME}_SOURCE_DIR}/lib")

add_executable(${APPNAME} ${CPPSOURCES} ${HEADERS})
target_link_libraries(${APPNAME} pthread productsum-lib timing-lib)

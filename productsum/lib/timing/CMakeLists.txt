set(LIBNAME timing-lib)

file(GLOB_RECURSE CPPSOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")

add_library(${LIBNAME} ${CPPSOURCES})

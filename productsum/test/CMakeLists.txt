# Enable testing with cmake.
enable_testing()

# Create the name of the test executable.
set(PROJECT_TEST_NAME ${PROJECT_NAME}-test)
# Create dependency to googletest, so that this is build first.
#add_dependencies(${PROJECT_TEST_NAME} googletest)

# Add include directories.
include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${${PROJECT_NAME}_SOURCE_DIR}/lib
)

# Get all files for tests.
file(GLOB_RECURSE TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# Create the executable.
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

# Link googletest libraries.
target_link_libraries(${PROJECT_TEST_NAME}
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    pthread
    timing-lib
    productsum-lib
)

cmake_minimum_required(VERSION 2.6)
 
# Manually adding the gmock lib & include paths
set(GMOCK_INCLUDE_DIRS /usr/local/include)
set(GMOCK_LIBRARIES /usr/local/lib/libgmock.a)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

message(STATUS "gtest include dir: ${GTEST_INCLUDE_DIRS}")
message(STATUS "gtest libs: ${GTEST_LIBRARIES}")
message(STATUS "gmock include dir: ${GMOCK_INCLUDE_DIRS}")
message(STATUS "gmock libs: ${GMOCK_LIBRARIES}")

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests test.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)


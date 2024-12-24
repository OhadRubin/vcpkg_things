cmake_minimum_required(VERSION 3.15)

project(hello_world)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

# Main executable
add_executable(hello_world helloworld.cpp)
target_link_libraries(hello_world PRIVATE 
    fmt::fmt
    nlohmann_json::nlohmann_json
)

# Test executable
add_executable(hello_test test/hello_test.cpp)
target_link_libraries(hello_test PRIVATE 
    fmt::fmt
    nlohmann_json::nlohmann_json
    GTest::gtest
    GTest::gtest_main
)

# Enable testing
enable_testing()
add_test(NAME hello_test COMMAND hello_test)
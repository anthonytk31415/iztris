cmake_minimum_required(VERSION 3.30)
project(iztris VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your main executable
add_executable(main src/main.cpp)

# Fetch and include Catch2
Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)

# Add your test executable
add_executable(tests 
    tests/test_main.cpp
    tests/utils/test_random.cpp
)

add_library(utils
    src/utils/Random.cpp
)

# added required libraries to the test executable
target_link_libraries(tests PRIVATE utils)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# Register your tests
include(CTest)
include(Catch)
catch_discover_tests(tests)
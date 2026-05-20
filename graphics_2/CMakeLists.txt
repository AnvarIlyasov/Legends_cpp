cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-15")

project(ProjectEndPrimitives CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_library(GraphicsLib
    src/pixel_buffer.cpp
    src/circle.cpp
    src/rectangle.cpp
    src/canvas.cpp
)
target_include_directories(GraphicsLib PUBLIC include)

add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE GraphicsLib)

enable_testing()

add_executable(unit_tests tests/test_main.cpp)
target_link_libraries(unit_tests PRIVATE GraphicsLib Catch2::Catch2WithMain)
add_test(NAME PrimitiveSystemTests COMMAND unit_tests)

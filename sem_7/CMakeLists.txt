cmake_minimum_required(VERSION 3.10)

project(WorkshopX VERSION 1.0 LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/external)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)

set(CATCH_BUILD_TESTING OFF)
set(CATCH_INSTALL_DOCS OFF)
set(CATCH_ENABLE_WERROR OFF)

FetchContent_MakeAvailable(Catch2)

add_library(BracketCheckerLib src/bracket_checker.cpp)
target_include_directories(BracketCheckerLib PUBLIC include)

add_library(WordSplitterLib src/word_splitter.cpp)
target_include_directories(WordSplitterLib PUBLIC include)

add_library(FrequencyDictLib src/frequency_dict.cpp)
target_include_directories(FrequencyDictLib PUBLIC include)

add_library(ReportPrinterLib src/report_printer.cpp)
target_include_directories(ReportPrinterLib PUBLIC include)

add_executable(MyApp src/main.cpp)
target_include_directories(MyApp PRIVATE include)
target_link_libraries(MyApp PRIVATE
    BracketCheckerLib
    WordSplitterLib
    FrequencyDictLib
    ReportPrinterLib
)

enable_testing()

if(EXISTS ${CMAKE_SOURCE_DIR}/tests/test_basic.cpp)
    add_executable(unit_tests tests/test_basic.cpp)
    target_include_directories(unit_tests PRIVATE include)

    target_link_libraries(unit_tests PRIVATE
        BracketCheckerLib
        WordSplitterLib
        FrequencyDictLib
        ReportPrinterLib
    )

    target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

    add_test(NAME TextAnalyzerTests COMMAND unit_tests)
    message(STATUS "Tests enabled: test_basic.cpp found")
else()
    message(WARNING "Tests disabled: test_basic.cpp not found in tests/ directory")
endif()

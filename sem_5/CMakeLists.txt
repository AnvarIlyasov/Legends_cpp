cmake_minimum_required(VERSION 3.10)

project(WorkshopX VERSION 1.0 LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/external)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# --- 1. Fetch Catch2 Dependency ---
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)

# Важно! Добавляем опцию для сборки Catch2
set(CATCH_BUILD_TESTING OFF)
set(CATCH_INSTALL_DOCS OFF)
set(CATCH_ENABLE_WERROR OFF)

FetchContent_MakeAvailable(Catch2)

# --- 2. Create Libraries for shared logic ---
add_library(ReadingLib src/reading.cpp)
target_include_directories(ReadingLib PUBLIC include)

add_library(CountLinesLib src/count_lines.cpp)
target_include_directories(CountLinesLib PUBLIC include)

add_library(CountSymbolsLib src/count_symbols.cpp)
target_include_directories(CountSymbolsLib PUBLIC include)

add_library(CountWordsLib src/count_words.cpp)
target_include_directories(CountWordsLib PUBLIC include)

add_library(MaxWordsLineLib src/max_words_line.cpp)
target_include_directories(MaxWordsLineLib PUBLIC include)

# --- 3. Main Application ---
add_executable(MyApp src/main.cpp)
target_include_directories(MyApp PRIVATE include)
target_link_libraries(MyApp PRIVATE 
    ReadingLib 
    CountLinesLib 
    CountSymbolsLib 
    CountWordsLib
    MaxWordsLineLib
)

# --- 4. Testing Setup ---
enable_testing()

# Проверяем наличие тестового файла
if(EXISTS ${CMAKE_SOURCE_DIR}/tests/test_basic.cpp)
    add_executable(unit_tests tests/test_basic.cpp)
    target_include_directories(unit_tests PRIVATE include)
    
    # Линкуем тесты с нашими библиотеками и Catch2
    target_link_libraries(unit_tests PRIVATE 
        ReadingLib 
        CountLinesLib 
        CountSymbolsLib 
        CountWordsLib
        MaxWordsLineLib
    )
    
    # Явно линкуем Catch2
    target_link_libraries(unit_tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
    
    add_test(NAME TextAnalyzerTests COMMAND unit_tests)
    
    message(STATUS "Tests enabled: test_basic.cpp found")
else()
    message(WARNING "Tests disabled: test_basic.cpp not found in tests/ directory")
endif()
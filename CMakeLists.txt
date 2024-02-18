cmake_minimum_required(VERSION 3.27)

project(NodeGridSolver)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ENABLE_CMAKE ON)

# Подключите Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Включите тестирование
enable_testing()

# Добавьте ваши директории
add_subdirectory(GridPatternGenerator)
add_subdirectory(Google_Test)

# Включите Google Test
include(GoogleTest)
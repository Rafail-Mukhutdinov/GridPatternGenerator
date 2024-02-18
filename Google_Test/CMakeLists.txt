file(GLOB TEST_SOURCES "*.cpp")


add_executable(MyTests ${TEST_SOURCES} ../GridPatternGenerator/AllDirectionGrid.cpp ../GridPatternGenerator/HorizontalVerticalGrid.cpp ../GridPatternGenerator/Grid.cpp )

target_link_libraries(MyTests gtest_main)

# Включите Google Test
include(GoogleTest)

gtest_discover_tests(MyTests)

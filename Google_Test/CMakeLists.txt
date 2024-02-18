#file(GLOB TEST_SOURCES "*.cpp")
#file(GLOB SRC_SOURCES "../lib/jsonparser.cpp")
#file(GLOB LIB_SOURCES "../Project_2/*.cpp")

#add_executable(MyTests ${TEST_SOURCES} ${SRC_SOURCES} )#${LIB_SOURCES})



#target_link_libraries(MyTests  gtest_main)

# Включите Google Test
#include(GoogleTest)

#gtest_discover_tests(MyTests)
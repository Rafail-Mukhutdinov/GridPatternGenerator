cmake_minimum_required(VERSION 3.27)

project(GridNodeCombinatorics)

set(CMAKE_CXX_STANDARD 17)

add_executable(GridNodeCombinatorics   main.cpp
                                       Grid.cpp
                                       Grid.h                                       
                                       HorizontalVerticalGrid.cpp 
                                       HorizontalVerticalGrid.h                                      
                                       AllDirectionGrid.cpp
                                       AllDirectionGrid.h)




target_link_libraries(GridNodeCombinatorics)

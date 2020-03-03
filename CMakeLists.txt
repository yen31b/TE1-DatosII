cmake_minimum_required(VERSION 3.14)
project(TE1_DatosII)

set(CMAKE_CXX_STANDARD 14)

include_directories(TE1/include)

add_executable(TE1_DatosII
        TE1/include/algorithm.hpp
        TE1/include/structures.hpp
        TE1/src/algorithm.cpp
        TE1/src/main.cpp
        TE1/src/structures.cpp TE1/src/Node.cpp TE1/include/Node.h TE1/include/Graph.h TE1/src/Graph.cpp TE1/include/DijkstraWalker.h TE1/src/DijkstraWalker.cpp TE1/include/GraphNode.h TE1/src/GraphNode.cpp TE1/include/AlgebraLib.h TE1/src/AlgebraLib.cpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES AStar.cpp AStar.h MainWindow.cpp MainWindow.h main.cpp)
# Include a library search using find_package()
# via REQUIRED, specify that libraries are required
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
#add_executable(TE1_DatosII ${SOURCE_FILES})
# specify which libraries to connect
target_link_libraries(${TE1_DatosII} Qt5::Core)
target_link_libraries(${TE1_DatosII} Qt5::Gui)
target_link_libraries(TE1_DatosII Qt5::Widgets)
set(CMAKE_CXX_STANDARD 17)

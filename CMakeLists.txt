cmake_minimum_required(VERSION 3.16)
project(EX)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc lib)
file(GLOB SOURCES inc/*.hpp lib/*.hpp src/*.cpp)

add_executable(dialp2p app/dial.cpp ${SOURCES})
add_executable(dialss app/dial.cpp ${SOURCES})
add_executable(dijp2p app/dijkstra.cpp ${SOURCES})
add_executable(dijss app/dijkstra.cpp ${SOURCES})
add_executable(radip2p app/radixheap.cpp ${SOURCES})
add_executable(radiss app/radixheap.cpp ${SOURCES})
add_executable(test app/test.cpp ${SOURCES})
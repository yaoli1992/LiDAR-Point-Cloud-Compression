cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(pcl_test)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall" "-pedantic")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")


find_package (PCL 1.7 REQUIRED)

include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})

ADD_EXECUTABLE  (pcl_bin2pcd pcl_bin2pcd.cpp)

TARGET_LINK_LIBRARIES (pcl_bin2pcd ${PCL_LIBRARIES} )


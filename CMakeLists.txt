cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cloud_compress)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall" "-pedantic")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")



find_package(OpenCV 3.4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})


#find_package(Boost REQUIRED )
find_package(Boost COMPONENTS program_options system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

if(NOT Boost_FOUND)
    message("Not found Boost")
endif()


INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src) 
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)  

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(decoder                      
        SHARED                         
        src/decoder.cpp
        src/encoder.cpp
 	src/io.cpp
	src/pcc_module.cpp
	src/utils.cpp
        )
target_link_libraries (decoder ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES} )  


add_executable (pcc_test  test/pcc_test.cpp )
target_link_libraries (pcc_test  ${PROJECT_SOURCE_DIR}/lib/libdecoder.so ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES})

add_executable (pcc_decoder  test/pcc_decoder.cpp )
target_link_libraries (pcc_decoder  ${PROJECT_SOURCE_DIR}/lib/libdecoder.so ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES})

add_executable (pcc_encoder  test/pcc_encoder.cpp )
target_link_libraries (pcc_encoder  ${PROJECT_SOURCE_DIR}/lib/libdecoder.so ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES})


add_executable (pcc_stream_decoder  test/pcc_stream_decoder.cpp )
target_link_libraries (pcc_stream_decoder  ${PROJECT_SOURCE_DIR}/lib/libdecoder.so ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES})


add_executable (pcc_stream_encoder  test/pcc_stream_encoder.cpp )
target_link_libraries (pcc_stream_encoder  ${PROJECT_SOURCE_DIR}/lib/libdecoder.so ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES})


add_executable (pcc_stream_test  test/pcc_stream_test.cpp )
target_link_libraries (pcc_stream_test  ${PROJECT_SOURCE_DIR}/lib/libdecoder.so ${OpenCV_LIBRARIES}  ${Boost_LIBRARIES})



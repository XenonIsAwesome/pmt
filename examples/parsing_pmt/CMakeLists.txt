cmake_minimum_required(VERSION 3.31)
project(parsing_pmt)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC gnuradio-pmt)
target_include_directories(${PROJECT_NAME} PUBLIC ${PMT_INCLUDE_DIR})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${PMT_EXAMPLES_DIR})
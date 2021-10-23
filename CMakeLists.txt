cmake_minimum_required(VERSION 3.0.0)
project(imu-ble-device-shared VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test_triaxal_reading  ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/test_triaxal_reading.cpp)
add_test(triaxal_reading test_triaxal_reading)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.0.0)
project(imu-ble-device-shared VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/eigen
)

add_executable(test_triaxial_reading  ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/test_triaxial_reading.cpp)
add_test(triaxial_reading test_triaxial_reading)

add_executable(test_uuid  ${CMAKE_CURRENT_SOURCE_DIR}/tests/constants/test_uuid.cpp)
add_test(uuid test_uuid)

add_executable(test_rotation_euler  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/rotation/test_euler.cpp
)
add_test(rotation_euler test_rotation_euler)

add_executable(test_rotation_quarternion  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/rotation/test_quarternion.cpp
)
add_test(rotation_quarternion test_rotation_quarternion)

add_executable(test_spacial_conversions  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/algorithms/test_spacial_conversions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/spacial_conversions.cpp
)
add_test(rotation_spacial_conversions test_spacial_conversions)

add_executable(test_angle  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/test_angle.cpp
)
add_test(angle test_angle)

add_executable(test_ahrs_angular  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/algorithms/ahrs/test_angular.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/ahrs/angular.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/spacial_conversions.cpp
)
add_test(ahrs_angular test_ahrs_angular)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

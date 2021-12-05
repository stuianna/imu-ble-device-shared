cmake_minimum_required(VERSION 3.0.0)
project(imu-ble-device-shared VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test_triaxal_reading  ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/test_triaxal_reading.cpp)
add_test(triaxal_reading test_triaxal_reading)

add_executable(test_uuid  ${CMAKE_CURRENT_SOURCE_DIR}/tests/constants/test_uuid.cpp)
add_test(uuid test_uuid)

add_executable(test_rotation_euler  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/test_rotation_euler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/containers/rotation_euler.cpp
)
add_test(rotation_euler test_rotation_euler)

add_executable(test_angle  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/containers/test_angle.cpp
)
add_test(angle test_angle)

add_executable(test_tilt_estimator  
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/algorithms/test_tilt_estimator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/tilt_estimator.cpp
)
add_test(tilt_estimator test_tilt_estimator)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

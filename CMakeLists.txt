cmake_minimum_required(VERSION 3.5.1)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(${SRC_DIR}/cmake_helpers/helpers.cmake)

project(GameEngine)

find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(SDL2_ttf REQUIRED)
#find_package(SDL2_mixer REQUIRED)

# generate project binary
add_executable(${PROJECT_NAME}
				${SRC_DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

#SDL2_LIBRARY
#SDL2_INCLUDE_DIR

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_INCLUDE_DIR})
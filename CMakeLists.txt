cmake_minimum_required(VERSION 3.5.1)

project(GameEngine LANGUAGES CXX)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH} ${SRC_DIR}/cmake_helpers/find_modules)

include(${SRC_DIR}/cmake_helpers/helpers.cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

# generate project binary
add_executable(${PROJECT_NAME}
				${SRC_DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})


target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR}
													${SDL2_INCLUDE_DIR}
													${SDL2_IMAGE_INCLUDE_DIR}
													${SDL2_TTF_INCLUDE_DIR}
													${SDL2_MIXER_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY}
												${SDL2_IMAGE_LIBRARY}
												${SDL2_TTF_LIBRARY}
												${SDL2_MIXER_LIBRARY})


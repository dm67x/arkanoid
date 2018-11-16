cmake_minimum_required(VERSION 3.7)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

project(Arkanoid LANGUAGES CXX)

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE source_files src/**/* src/*)

add_executable(${PROJECT_NAME} ${source_files})
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS} src)
target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_nullptr)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/Arkanoid_sprites.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

if (MSVC)
	file(COPY ${SDL2_DIR}/${VC_LIB_PATH_SUFFIX}/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
	file(COPY ${SDL2_DIR}/${VC_LIB_PATH_SUFFIX}/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

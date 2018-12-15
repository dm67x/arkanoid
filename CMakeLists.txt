cmake_minimum_required(VERSION 3.7)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

project(Arkanoid LANGUAGES CXX)

# telecharger et installer SDL2 sur la machine
include(ExternalProject)
ExternalProject_Add(sdl2 
	PREFIX ${CMAKE_BINARY_DIR}/external
	URL "https://www.libsdl.org/release/SDL2-2.0.8.tar.gz"
    	URL_HASH SHA256=edc77c57308661d576e843344d8638e025a7818bff73f8fbfab09c3c5fd092ec
	INSTALL_DIR ${CMAKE_BINARY_DIR}/external/installed
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/external/installed
)
set_target_properties(sdl2 PROPERTIES EXCLUDE_FROM_ALL TRUE)

include(GNUInstallDirs)
link_directories(${CMAKE_BINARY_DIR}/external/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/external/installed/${CMAKE_INSTALL_INCLUDEDIR})
find_package(SDL2 HINTS ${CMAKE_BINARY_DIR}/external/installed)

file(GLOB_RECURSE source_files src/**/* src/*)

add_executable(${PROJECT_NAME} ${source_files})
target_include_directories(${PROJECT_NAME} PUBLIC src)

if (MINGW)
	target_link_libraries(${PROJECT_NAME} PUBLIC mingw32 SDL2main SDL2)
else ()
	target_link_libraries(${PROJECT_NAME} PUBLIC SDL2main SDL2)
endif ()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_nullptr)

# Copier les assets
file (GLOB ASSETS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/assets/*)
file(COPY ${ASSETS_FILES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)

if (MSVC)
	source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_files}) 

	file(COPY ${SDL2_DIR}/${VC_LIB_PATH_SUFFIX}/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
	file(COPY ${SDL2_DIR}/${VC_LIB_PATH_SUFFIX}/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

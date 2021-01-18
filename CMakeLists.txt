cmake_minimum_required(VERSION 3.15)

project(EZ_GUI
VERSION 0.1.0
LANGUAGES C CXX
)

option(BUILD_TESTS "Build the tests for the ez-gui library" ON)

include(GNUInstallDirs)
find_package(ez-cmake CONFIG REQUIRED)

find_package(ez-window CONFIG REQUIRED)
find_package(ez-nuklear CONFIG REQUIRED)
find_package(ez-pathfinder CONFIG REQUIRED)
find_package(ez-mq CONFIG REQUIRED)

add_library(ez-gui STATIC 
	"src/Engine.cpp"
 )
target_link_libraries(ez-gui PUBLIC ez-window)

target_include_directories(ez-gui PUBLIC 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>"
)

target_compile_features(ez-gui PUBLIC cxx_std_17)


if(${BUILD_TESTS})
	add_subdirectory("tests")
endif()
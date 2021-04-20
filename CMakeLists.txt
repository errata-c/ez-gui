cmake_minimum_required(VERSION 3.19)

project(EZ_GUI
VERSION 0.2.1
LANGUAGES C CXX
)

include(GNUInstallDirs)
include("cmake/ez-cmake/install_package.cmake")

option(BUILD_TESTS "Build the test executables" ON)
option(SEPARATE_DIRECTORY "Install the package into its own directory" ON)
set(CONFIG_DIR "${CMAKE_INSTALL_DATAROOTDIR}/ez-gui" CACHE STRING "The relative directory to install package config files.")



# Provide a variety of convienence functions and classes for gui

# Provide a better way to use Vector Graphics
# Provide some ImGui integration to make it easier to setup complicated things like lists, trees, etc...
# Make it possible to use ImGui more like a traditional GUI system.

find_package(ez-window CONFIG REQUIRED)
find_package(rt-loader CONFIG REQUIRED glew)
find_package(rt-core CONFIG REQUIRED)

add_library(gui INTERFACE)
target_link_libraries(gui INTERFACE
	ez::window
	rt::loader-glew
	rt::core
)
target_include_directories(gui INTERFACE 
	"$<INSTALL_INTERFACE:include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

add_library(ez::gui ALIAS gui)


if(BUILD_TESTS)
	add_subdirectory("tests")
endif()

if(SEPARATE_DIRECTORY)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/ez-gui")
endif()

install(FILES 
	"cmake/imgui.cmake" 
	"cmake/mq.cmake" 
	"cmake/pathfinder.cmake" 
	"cmake/skia.cmake"

	DESTINATION "share"
)

install(DIRECTORY "include/"
	DESTINATION "include"
	FILES_MATCHING
	PATTERN "*.hpp" PATTERN "*.h"
)

install(TARGETS gui 
	EXPORT ez-gui-targets
	RUNTIME DESTINATION "bin/$<CONFIG>"
	ARCHIVE DESTINATION "lib/$<CONFIG>"
	LIBRARY DESTINATION "lib/$<CONFIG>"
)

install_package(
	NAME "ez-gui"
	NAMESPACE "ez::"
	DESTINATION "${CONFIG_DIR}"
	EXPORT "ez-gui-targets"
	VERSION "${EZ_GUI_VERSION}"
	COMPATIBILITY "SameMajorVersion"
	PRECONFIG "cmake/preconfig.cmake"
	POSTCONFIG "cmake/postconfig.cmake"
)
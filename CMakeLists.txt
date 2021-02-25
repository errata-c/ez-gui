cmake_minimum_required(VERSION 3.15)

project(EZ_GUI
VERSION 0.1.0
LANGUAGES C CXX
)

# Provide a variety of convienence functions and classes for gui

option(BUILD_TESTS "Build the tests for the ez-gui library" ON)

option(USE_PATHFINDER "Use pathfinder for vector graphics" OFF)
option(USE_SKIA "Use skia for vector graphics" ON)
option(USE_IMGUI "Use imgui for gui elements" ON)
option(USE_MQ "Use ez-mq for a message queue" OFF)



include(GNUInstallDirs)
find_package(ez-cmake CONFIG REQUIRED)
find_package(ez-window CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)


add_library(ez-gui STATIC 
	"src/GuiWindow.cpp"
)
target_link_libraries(ez-gui PUBLIC ez::window GLEW::GLEW)
target_include_directories(ez-gui PUBLIC 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>"
)
target_compile_features(ez-gui PUBLIC cxx_std_17)

set_target_properties(ez-gui PROPERTIES EXPORT_NAME "gui")
add_library(ez::gui ALIAS ez-gui)



# ---------------------------------------------------------------------
if(${USE_MQ})
	find_package(ez-mq CONFIG REQUIRED)
	add_library(ez-gui-mq INTERFACE)
	target_link_libraries(ez-gui-mq INTERFACE ez::gui ez::mq)
	target_compile_definitions(ez-gui-mq INTERFACE "EZ_GUI_USE_MQ")
endif()
# ---------------------------------------------------------------------



# ---------------------------------------------------------------------
if(${USE_IMGUI})
	find_package(ez-imgui CONFIG REQUIRED)
	add_library(ez-gui-imgui INTERFACE)
	target_link_libraries(ez-gui-imgui INTERFACE ez::gui ez::imgui ez::imgui-opengl3)
	target_compile_definitions(ez-gui-imgui INTERFACE "EZ_GUI_USE_IMGUI")
endif()
# ---------------------------------------------------------------------



# ---------------------------------------------------------------------
if(${USE_SKIA})
	find_package(skia CONFIG REQUIRED)
	add_library(ez-gui-skia INTERFACE)
	target_link_libraries(ez-gui-skia INTERFACE skia ez::gui)
	target_compile_definitions(ez-gui-skia INTERFACE "EZ_GUI_USE_SKIA")
endif()
# ---------------------------------------------------------------------



if(${BUILD_TESTS})
	add_subdirectory("tests")
endif()
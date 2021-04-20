project(EZ_GUI_TESTS
VERSION 0.1.0
LANGUAGES C CXX)
	
set(ez-gui_DIR "${EZ_GUI_SOURCE_DIR}/share/ez-gui")

add_subdirectory("imgui")
add_subdirectory("skia")

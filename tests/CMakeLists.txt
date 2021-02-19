project(EZ_GUI_TESTS
VERSION 0.1.0
LANGUAGES C CXX)

if(NOT TARGET "ez::gui")
	find_package(ez-gui CONFIG REQUIRED)
endif()

if(${USE_IMGUI})
	add_subdirectory("imgui")
endif()

if(${USE_SKIA})
	add_subdirectory("skia")
endif()
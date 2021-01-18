project(EZ_GUI_TESTS
VERSION 0.1.0
LANGUAGES C CXX)

if(not target ez-gui)
	find_package(ez-gui CONFIG REQUIRED)
endif()


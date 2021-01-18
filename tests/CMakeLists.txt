project(EZ_GUI_TESTS
VERSION 0.1.0
LANGUAGES C CXX)

if(NOT TARGET "ez-gui")
	find_package(ez-gui CONFIG REQUIRED)
endif()

find_package(SFML CONFIG REQUIRED COMPONENTS main system window)
find_package(fmt CONFIG REQUIRED)

add_library(test_interface INTERFACE)
target_link_libraries(test_interface INTERFACE ez-gui fmt::fmt sfml-main sfml-system sfml-window)

add_executable(basic_test "basic/main.cpp")
target_link_libraries(basic_test PRIVATE test_interface)

find_package(fmt CONFIG REQUIRED)

add_executable(imgui_test 
	"main.cpp"
)
target_link_libraries(imgui_test PRIVATE ez::gui ez-gui-imgui fmt::fmt)
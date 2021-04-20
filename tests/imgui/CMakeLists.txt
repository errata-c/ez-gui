
find_package(fmt CONFIG REQUIRED)
find_package(ez-imgui CONFIG REQUIRED)

add_executable(imgui_test 
	"main.cpp"
)
target_link_libraries(imgui_test PRIVATE ez::gui fmt::fmt ez::imgui-opengl3)
target_compile_definitions(imgui_test PRIVATE EZ_GUI_USE_IMGUI)
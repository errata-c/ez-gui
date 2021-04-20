
if(NOT TARGET "ez::imgui")
	find_dependency(ez-imgui CONFIG)
endif()

set_property(TARGET ez::gui APPEND
	PROPERTY 
	INTERFACE_COMPILE_DEFINITIONS "EZ_GUI_USE_IMGUI"
)
set_property(TARGET ez::gui APPEND
	PROPERTY 
	INTERFACE_LINK_LIBRARIES "ez::imgui;ez::imgui-opengl3"
)
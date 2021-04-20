
if(NOT TARGET "skia")
	find_dependency(skia CONFIG)
endif()

set_property(TARGET ez::gui APPEND
	PROPERTY 
	INTERFACE_COMPILE_DEFINITIONS "EZ_GUI_USE_SKIA"
)
set_property(TARGET ez::gui APPEND
	PROPERTY 
	INTERFACE_LINK_LIBRARIES "skia::skia"
)
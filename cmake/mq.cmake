
if(NOT TARGET "ez::mq")
	find_dependency(ez-mq CONFIG)
endif()

set_property(TARGET ez::gui APPEND
	PROPERTY 
	INTERFACE_COMPILE_DEFINITIONS "EZ_GUI_USE_MQ"
)
set_property(TARGET ez::gui APPEND
	PROPERTY 
	INTERFACE_LINK_LIBRARIES "ez::mq"
)
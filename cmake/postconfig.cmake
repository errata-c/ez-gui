
foreach(COM ${ez-gui_FIND_COMPONENTS})
	string(TOLOWER "${COM}" COM)

	if(NOT MATCHES "skia|imgui|mq|pathfinder")
		message(FATAL_ERROR "Failed to locate a component of 'ez-gui' named '${COM}'")
	endif()

	include("${ez-gui_SHARE}/${COM}.cmake")
endforeach()
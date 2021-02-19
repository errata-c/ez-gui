
include_guard(DIRECTORY)
include(CMakeFindDependencyMacro)

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was ConfigTemplate.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

####################################################################################

set(PACK_NAME ez-gui)
set(PACK_VERSION 0.1)
set(PACK_ROOT ${PACKAGE_PREFIX_DIR})
set(PACK_CONFIG_DIR share/ez-gui)

if(NOT TARGET "ez::window")
	find_dependency(ez-window CONFIG)
endif()


include("${CMAKE_CURRENT_LIST_DIR}/ez-gui-targets.cmake")


foreach(COM ${ez-gui_FIND_COMPONENTS})
	if(NOT MATCHES "skia|imgui|mq|pathfinder")
		message(FATAL_ERROR "Failed to locate a component of 'ez-gui' named '${COM}'")
	endif()

	include("${CMAKE_CURRENT_LIST_DIR}/${COM}.cmake")
endforeach()

unset(PACK_NAME)
unset(PACK_VERSION)
unset(PACK_ROOT)
unset(PACK_CONFIG_DIR)

check_required_components(ez-gui)
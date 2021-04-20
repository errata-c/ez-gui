
find_package(fmt CONFIG REQUIRED)
find_package(skia CONFIG REQUIRED)

add_executable(skia_test "main.cpp")
target_link_libraries(skia_test PRIVATE ez::gui fmt::fmt skia::skia)
target_compile_definitions(skia_test PRIVATE EZ_GUI_USE_SKIA)
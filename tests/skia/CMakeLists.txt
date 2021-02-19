
find_package(fmt CONFIG REQUIRED)

add_executable(skia_test "main.cpp")
target_link_libraries(skia_test PRIVATE ez-gui ez-gui-skia fmt::fmt)
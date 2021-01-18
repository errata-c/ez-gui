#pragma once

namespace ez {
	namespace gui {
		/// <summary>
		/// Bitfield with window style options.
		/// </summary>
		enum class Style {
			None = 0,
			Titlebar = 1, // Show titlebar
			Resize = 2, // Show maximize or minimize button, and allow resizing the window
			Close = 4, // Show a close button
			Visible = 8, // The window will be visible immediately after creation
			HighDPI = 16, // Create with high DPI support, not supported by all backends
			AlwaysOnTop = 32, // The window will attempt to always be above other windows
			Fullscreen = 64, // The window will be a fullscreen window for whichever monitor it opens on. Incompatible with Titlebar/Resize/Close

			OpenGL = 128, // Create window with opengl support.
			Vulkan = 256, // Create window with vulkan support.

			Default = Titlebar | Resize | Close | Visible | OpenGL,

			All = Titlebar | Resize | Close | Visible | HighDPI | AlwaysOnTop | Fullscreen | OpenGL | Vulkan
		};
	}
}

ez::gui::Style operator|(const ez::gui::Style & lv, const ez::gui::Style & rv) {
	return static_cast<ez::gui::Style>(static_cast<int>(lv) | static_cast<int>(rv));
}
ez::gui::Style operator&(const ez::gui::Style& lv, const ez::gui::Style& rv) {
	return static_cast<ez::gui::Style>(static_cast<int>(lv) & static_cast<int>(rv));
}
ez::gui::Style operator~(const ez::gui::Style& lv) {
	return static_cast<ez::gui::Style>((~static_cast<int>(lv)) & static_cast<int>(ez::gui::Style::All));
}

ez::gui::Style& operator|=(ez::gui::Style& lv, const ez::gui::Style& rv) {
	lv = static_cast<ez::gui::Style>(static_cast<int>(lv) | static_cast<int>(rv));
	return lv;
}
ez::gui::Style& operator&=(ez::gui::Style& lv, const ez::gui::Style& rv) {
	lv = static_cast<ez::gui::Style>(static_cast<int>(lv) & static_cast<int>(rv));
	return lv;
}
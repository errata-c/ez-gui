#pragma once
namespace ez::window {
	class Window;
}
namespace ez {
	struct InputEvent;
}

#ifdef EZ_GUI_USE_IMGUI
#include <ez/window/Window.hpp>

#include <rt/loader.hpp>
#include <imgui.h>
#include <ez/imgui/Context.hpp>

namespace ez::gui {
	struct ImguiSubsystem {
		ImguiSubsystem(ez::Window& window)
		{}

		void beginDraw(ez::Window& window) {
			window.setActive(true);
			context.makeActive();
			context.newFrame(window);
		}
		void endDraw(ez::Window& window) {
			context.render();
		}

		void beginInput(ez::Window& window) {
			context.makeActive();
		}
		bool handleInput(const ez::InputEvent& ev) {
			return context.processEvent(ev);
		}
		void endInput(ez::Window& window) {

		}

		ez::imgui::Context context;
	};
}
#else
namespace ez::gui {
	struct ImguiSubsystem {
		ImguiSubsystem(ez::window::Window& window) {};

		void beginDraw(ez::window::Window& window) {};
		void endDraw(ez::window::Window& window) {};

		void beginInput(ez::window::Window& window) {};
		bool handleInput(const ez::InputEvent& ev) { return false; };
		void endInput(ez::window::Window& window) {};

		bool wantsInput() const noexcept { return false; };
	};
};
#endif


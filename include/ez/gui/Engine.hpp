#pragma once
#include <ez/window/Engine.hpp>

/*
Add message queue + nuklear + pathfinder
*/

namespace ez::gui {
	using Window = ez::window::Window;

	// Subclass of window::Engine providing extra utilities.
	class Engine: public ez::window::Engine {
	public:
		void handleInput(std::vector<std::shared_ptr<Window>>& windows) override;
		void drawWindows(std::vector<std::shared_ptr<Window>>& windows) override;
		void processCommandLine(int argc, char **argv) override;

	private:

	};
}
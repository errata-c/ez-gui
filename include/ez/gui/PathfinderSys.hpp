#pragma once

namespace ez::window {
	class Window;
}
namespace ez {
	struct InputEvent;
}

#ifdef EZ_GUI_USE_PATHFINDER
namespace ez::gui {
	struct PathfinderSubsystem {

	};
};
#else
namespace ez::gui {
	struct PathfinderSubsystem {
		PathfinderSubsystem(ez::window::Window& window) {};

		void beginDraw(ez::window::Window& window) {};
		void endDraw(ez::window::Window& window) {};
	};
};
#endif
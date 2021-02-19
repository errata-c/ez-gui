#pragma once

#ifdef EZ_GUI_USE_MQ
//#include "Pathfinder.hpp"
#else
namespace ez::gui {
	struct MQSubsystem {
		MQSubsystem(ez::window::Window& window) {};
	};
};
#endif
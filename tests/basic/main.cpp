#include <fmt/core.h>

#include <ez/gui/BasicEngine.hpp>
#include <ez/gui/backends/SFML.hpp>

class CustomWindow: public ez_gui::SFMLWindow {
public:
	CustomWindow(glm::ivec2 _size, std::string_view _title, ez_gui::Style _style)
		: ez_gui::SFMLWindow(_size, _title, _style)
	{}

	void handleInput(const ez::InputEvent & ev) override {

		if (ev.type == ez::InputEventType::KeyRelease) {
			fmt::print("Got a keypress!\n");
		}
		else if (ev.type == ez::InputEventType::Closed) {
			close();
		}
	}
	void draw() override {

	}
};

int main(int argc, char** argv) {
	// Create the engine.
	ez_gui::BasicEngine engine;

	// Create a window class, give it to the engine.
	engine.takeOwnership(new CustomWindow{ {800, 600}, "Basic Test", ez_gui::Style::Default });

	// have engine call the appropriate functions for various events.
	// Provide a nuklear context, a pathfinder context, and a MQ context from the engine.
	// Execute the various rendering commands from the contexts.

	return engine.run(argc, argv);
}
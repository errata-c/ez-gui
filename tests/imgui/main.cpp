#include <fmt/core.h>
#include <ez/window/BasicEngine.hpp>
#include <ez/GuiWindow.hpp>


class CustomWindow : public ez::GuiWindow {
public:
	CustomWindow(std::string_view title, glm::ivec2 size, ez::window::Style style)
		: GuiWindow(title, size, style)
		, show_demo_window(true)
	{
		ImGui::StyleColorsDark();
	}
	
	// We override the guiDraw function instead of window::draw
	void guiDraw() override {
		glClearColor(242 / 255.f, 248 / 255.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (show_demo_window) {
			ImGui::ShowDemoWindow(&show_demo_window);
		}
	}

	// We override the guiHandleInput function instead of window::handleInput
	void guiInput(const ez::InputEvent & ev) override {
		if (ev.type == ez::InEv::Closed) {
			close();
		}
	}

	bool show_demo_window;
};

int main(int argc, char* argv[]) {
	ez::window::BasicEngine engine;

	engine.add(new CustomWindow{ "Imgui test", glm::ivec2{800, 600}, ez::window::StylePreset::Default });

	return engine.run(argc, argv);
}
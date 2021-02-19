#include <fmt/core.h>
#include <ez/window/BasicEngine.hpp>
#include <ez/GuiWindow.hpp>

class CustomWindow : public ez::GuiWindow {
public:
	CustomWindow(std::string_view title, glm::ivec2 size, ez::window::Style style, const ez::window::RenderSettings& rs)
		: GuiWindow(title, size, style, rs)
	{
		
	}

	// We override the guiDraw function instead of window::draw
	void guiDraw() override {
		static float pi = 3.141592653f;
		static float tau = pi * 2.f;

		glClearColor(242 / 255.f, 248 / 255.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		SkCanvas& canvas = skia.getCanvas();

		SkPath path;
		path.moveTo(1.f, 0.f);
		for (int i = 0; i < 5; ++i) {
			float u = tau * i / 5.f;
			float v = u + tau / 10.f;

			path.lineTo(std::cos(u), std::sin(u));
			path.lineTo(std::cos(v) * 0.5f, std::sin(v) * 0.5f);
		}
		path.close();

		SkPaint paint;
		paint.setColor(SK_ColorBLUE);
		paint.setAntiAlias(true);

		canvas.save();
		
		canvas.scale(200, 200);
		canvas.translate(2, 1.5f);

		static float rot = 0.f;
		canvas.rotate(rot);
		rot += 0.1f;

		canvas.drawPath(path, paint);
		canvas.restore();


		canvas.flush();
	}

	// We override the guiHandleInput function instead of window::handleInput
	void guiHandleInput() override {
		ez::InputEvent ev;
		while (pollInput(ev)) {
			if (ev.type == ez::InEv::Closed) {
				close();
			}
		}
	}
};

int main(int argc, char* argv[]) {
	ez::window::BasicEngine engine;

	ez::window::GLSettings rset;
	rset.stencilBits() = 8;
	rset.depthBits() = 24;
	rset.majorVersion() = 4;
	rset.minorVersion() = 5;

	engine.add(new CustomWindow{ "Skia test", glm::ivec2{800, 600}, ez::window::Style::Default, rset });

	//engine.setRealtime(false);
	return engine.run(argc, argv);
}
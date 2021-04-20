#pragma once
#include <rt/loader.hpp>
#include <rt/Core.hpp>
#include <ez/window/Window.hpp>

#include "gui/subsystems/Subsystem.hpp"

namespace ez {
	class GuiWindow: public Window {
		static ez::window::GLSettings glset() {
			ez::window::GLSettings gset;
			gset.majorVersion() = 4;
			gset.minorVersion() = 5;
			gset.depthBits() = 24;
			gset.stencilBits() = 8;
			return gset;
		}
	public:
		GuiWindow(std::string_view title, glm::ivec2 size, ez::window::Style style = ez::window::StylePreset::Default)
			: Window(title, size, style, glset())
			, imgui(*this)
			, skia(*this)
			, pathfinder(*this)
			, mq(*this)
		{}

		void draw() override final {
			glm::ivec2 viewport = getViewportSize();
			if (viewport.x <= 1 || viewport.y <= 1) {
				return;
			}

			imgui.beginDraw(*this);
			skia.beginDraw(*this);
			pathfinder.beginDraw(*this);

			guiDraw();

			pathfinder.endDraw(*this);
			skia.endDraw(*this);
			imgui.endDraw(*this);
		}

		void handleInput() override final {
			imgui.beginInput(*this);

			ez::InputEvent ev;
			while (pollInput(ev)) {
				imgui.handleInput(ev);

				guiInput(ev);
			}

			imgui.endInput(*this);
		}

		virtual void guiDraw() = 0;

		virtual void guiInput(const ez::InputEvent & ev) = 0;

		gui::ImguiSubsystem imgui;
		gui::SkiaSubsystem skia;
		gui::PathfinderSubsystem pathfinder;
		gui::MQSubsystem mq;
	};
}
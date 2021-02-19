#pragma once
#include <ez/gl.hpp>
#include <ez/window/Window.hpp>
#include "gui/Subsystem.hpp"

namespace ez {
	namespace intern {
		// Simple stub class to prepare the window BEFORE the GuiWindow is constructed
		class PrepareWindow: public Window {
		public:
			PrepareWindow(std::string_view title, glm::ivec2 size, ez::window::Style style, const ez::window::RenderSettings& rs)
				: Window(title, size, style, rs)
			{
				setActive(true);
				ez::gl::load();
			}
		};
	}

	class GuiWindow: public intern::PrepareWindow {
	public:
		GuiWindow(std::string_view title, glm::ivec2 size, ez::window::Style style, const ez::window::RenderSettings& rs)
			: PrepareWindow(title, size, style, rs)
			, imgui(*this)
			, skia(*this)
			, pathfinder(*this)
			, mq(*this)
		{}

		void draw() override final {
			imgui.beginDraw(*this);
			guiDraw();
			imgui.endDraw(*this);
		}

		void handleInput() override final {
			imgui.beginInput(*this);
			guiHandleInput();
			imgui.endInput(*this);
		}

		virtual void guiDraw() = 0;

		virtual void guiHandleInput() = 0;

	public:
		gui::ImguiSubsystem imgui;
		gui::SkiaSubsystem skia;
		gui::PathfinderSubsystem pathfinder;
		gui::MQSubsystem mq;
	};
}
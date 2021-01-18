#pragma once

// For the window title.
#include <string>
#include <string_view>

// For the window dimensions.
#include <glm/vec2.hpp>

// For opengl integration.
#include "gui/OpenGL.hpp"

#include "gui/Style.hpp"

namespace ez {
	/*
		Abstract base class for all your windowing needs!
	*/
	class Window {
	public:
		virtual gui::Style getStyle() const = 0;
		virtual glm::ivec2 getSize() const = 0;
		virtual glm::ivec2 getPosition() const = 0;

		virtual bool isOpen() const = 0;
		virtual std::string_view getTitle() const = 0;

		virtual void setSize(glm::ivec2 val) = 0;
		virtual void setPosition(glm::ivec2 val) = 0;
		
		virtual void setOpen(bool val) = 0;
		virtual void setTitle(std::string_view title) = 0;


		virtual void swapBuffers() = 0;
	};
}
#pragma once
namespace ez::window {
	class Window;
}
namespace ez {
	struct InputEvent;
}


#ifdef EZ_GUI_USE_SKIA 

#include <rt/loader.hpp>
#include <GL/glew.h>
#include <ez/window/Window.hpp>

#include <skia/gpu/GrContext.h>
#include <skia/gpu/gl/GrGLInterface.h>
#include <skia/gpu/gl/GrGLFunctions.h>
#include <skia/gpu/GrBackendSurface.h>

#include <skia/core/SkData.h>
#include <skia/core/SkImage.h>
#include <skia/core/SkStream.h>
#include <skia/core/SkSurface.h>
#include <skia/core/SkPaint.h>
#include <skia/core/SkCanvas.h>

namespace ez::gui {
	struct SkiaSubsystem {
		SkiaSubsystem(ez::window::Window& window) 
		{
			window.setActive(true);

			interface = GrGLMakeNativeInterface();
			context = GrContext::MakeGL(interface);

			createSurface(window.getViewportSize());
		}

		void createSurface(glm::ivec2 size) {
			GrGLint buffer;
			glGetIntegerv(GL_FRAMEBUFFER_BINDING, &buffer);

			GrGLFramebufferInfo fbInfo;
			fbInfo.fFBOID = buffer;
			fbInfo.fFormat = GL_RGBA8;

			SkColorType colorType = SkColorType::kRGBA_8888_SkColorType;
			SkSurfaceProps props{ 0, kRGB_H_SkPixelGeometry };

			viewport = size;
			GrBackendRenderTarget target(viewport.x, viewport.y, 0, 8, fbInfo);

			gpuSurface = SkSurface::MakeFromBackendRenderTarget(
				context.get(),
				target,
				kBottomLeft_GrSurfaceOrigin,
				colorType,
				nullptr,
				&props);

			if (!gpuSurface) {
				SkDebugf("SkSurface::MakeRenderTarget returned null\n");
			}
		}

		SkCanvas& canvas() {
			return *gpuSurface->getCanvas();
		}
		const SkCanvas& canvas() const {
			return *gpuSurface->getCanvas();
		}

		void beginDraw(ez::window::Window& window) {
			glm::ivec2 framesize = window.getViewportSize();
			if (viewport != framesize) {
				createSurface(viewport);
			}
		}
		void endDraw(ez::window::Window& window) {

		}

		glm::ivec2 viewport;

		sk_sp<const GrGLInterface> interface;
		sk_sp<GrContext> context;
		SkImageInfo imageInfo;
		sk_sp<SkSurface> gpuSurface;
	};
}
#else
namespace ez::gui {
	struct SkiaSubsystem {
		SkiaSubsystem(ez::window::Window& window) {}

		void beginDraw(ez::window::Window& window) {};
		void endDraw(ez::window::Window& window) {};
	};
};
#endif

#pragma once
namespace ez::window {
	class Window;
}
namespace ez {
	struct InputEvent;
}


#ifdef EZ_GUI_USE_SKIA 

#include <ez/gl.hpp>
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
		SkiaSubsystem(ez::window::Window& window) {
			window.setActive(true);
			glm::ivec2 viewport = window.getViewportSize();

			interface = GrGLMakeNativeInterface();
			context = GrContext::MakeGL(interface);

			int32_t buffer;
			glGetIntegerv(GL_FRAMEBUFFER_BINDING, &buffer);

			fbInfo.fFBOID = buffer;
			fbInfo.fFormat = GL_RGBA8;
			SkColorType colorType = SkColorType::kRGBA_8888_SkColorType;

			SkSurfaceProps props{ 0, kUnknown_SkPixelGeometry };
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

		SkCanvas& getCanvas() {
			return *gpuSurface->getCanvas();
		}
		const SkCanvas& getCanvas() const {
			return *gpuSurface->getCanvas();
		}

		sk_sp<const GrGLInterface> interface;
		sk_sp<GrContext> context;
		SkImageInfo imageInfo;
		sk_sp<SkSurface> gpuSurface;
		GrGLFramebufferInfo fbInfo;
	};
}
#else
namespace ez::gui {
	struct SkiaSubsystem {
		SkiaSubsystem(ez::window::Window& window) {}
	};
};
#endif

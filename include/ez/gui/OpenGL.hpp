#pragma once

namespace ez {
	namespace gui {
		enum class GLVersion {
			// Old versions, not recommended for use.
			gl_1_0,
			gl_1_1,
			gl_1_2,
			gl_1_2_1,
			gl_1_3,
			gl_1_4,
			gl_1_5,
			gl_2_0,
			gl_2_1,

			// Modern versions.
			gl_3_0,
			gl_3_1,
			gl_3_2,
			gl_3_3,
			gl_4_0,
			gl_4_1,
			gl_4_2,
			gl_4_3,
			gl_4_4,
			gl_4_5,
			gl_4_6
		};

		enum class GLOptions {
			None = 0,
			DoubleBuffered = 1,
			Stereo = 2,
		};
	}
}
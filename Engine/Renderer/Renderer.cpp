#include "Renderer.h"

namespace Starlight {
	void Renderer::init() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Renderer::render(RawModel model) {
		glBindVertexArray(model.getVaoId());
		glEnableVertexAttribArray(0);
		glDrawElements(GL_TRIANGLES,model.getVertexCount(),GL_UNSIGNED_INT,NULL);
		glDisableVertexAttribArray(0);
		glBindVertexArray(0);
	}
}
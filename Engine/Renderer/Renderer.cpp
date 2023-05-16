#include "Renderer.h"

namespace Starlight {
	void Renderer::init() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Renderer::render(RawModel model) {
		glBindVertexArray(model.getVaoId());
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glDrawElements(GL_TRIANGLES,model.getVertexCount(),GL_UNSIGNED_INT,0);
		glDisableVertexAttribArray(0);
		glBindVertexArray(0);
	}
}
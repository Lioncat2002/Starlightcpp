#pragma once
#include<GLFW/glfw3.h>

namespace Starlight{
	class InputManager{
	public:
		static void processInput(GLFWwindow* window);
	};
}

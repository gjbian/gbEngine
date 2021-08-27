#pragma once

#include <glad/glad.h> 
#include "GLFW/glfw3.h"

namespace Renderer
{
  static GLFWwindow* window;

  bool RendererInit();

  void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);

  bool RenderLoop();
  
  bool RendererEnd();
}


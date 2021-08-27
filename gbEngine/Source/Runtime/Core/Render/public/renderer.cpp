#include "renderer.h"

#include <iostream>

namespace Renderer
{
  void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
  {
    glViewport(0, 0, width, height);
  }

  bool RendererInit()
  {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "GbEngine", NULL, NULL);
    if (window == NULL)
    {
      std::cout << "Failed to create GbEngine Window" << std::endl;
      glfwTerminate();
      return false;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return false;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallBack);
    return true;
  }

  bool RenderLoop()
  {
    if (glfwWindowShouldClose(window))
    {
      return false;
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
    return true;
  }

  bool RendererEnd()
  {
    glfwTerminate();
    return true;
  }
}

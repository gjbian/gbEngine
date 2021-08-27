#include <iostream>

#include "renderer.h"

int main()
{
  if (!Renderer::RendererInit())
    return -1;

  while (true)
  {
    if (!Renderer::RenderLoop())
      break;
  }

  Renderer::RendererEnd();
  
  return 0;
}

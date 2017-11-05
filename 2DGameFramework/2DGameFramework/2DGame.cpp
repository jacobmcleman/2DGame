#include "Window.h"

int main(int argc, char** argv)
{
  Window window("2D Game");

  while (window.UpdateWindow())
  {
    float dt = window.GetDeltaTime();



    window.SwapBuffers();
  }
}
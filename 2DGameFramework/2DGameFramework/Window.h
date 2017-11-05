#pragma once
#pragma once

#include <string>

struct GLFWwindow;

enum struct CursorMode
{
  Disabled, Hidden, Normal
};



class Window
{
public:
  Window(const std::string& title, CursorMode cursor = CursorMode::Normal, int width = 800, int height = 600);
  ~Window();

  bool UpdateWindow();
  void SwapBuffers();

  double GetDeltaTime();

private:
  GLFWwindow* window_;
  int width_;
  int height_;

  double lastFrameTime_;
};



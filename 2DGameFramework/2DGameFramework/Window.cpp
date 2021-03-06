#include "Window.h"

#include <glad\glad.h>

//GLFW
#include <GLFW\glfw3.h>

#include <assert.h>
#include <iostream>
#include <string>
#include <functional>

#include "InputHandler.h"

Window::Window(const std::string& title, CursorMode cursor, int width, int height) :
    width_(width), height_(height), lastFrameTime_(0)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  glfwMakeContextCurrent(window_);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    glfwTerminate();
  }

  glfwGetFramebufferSize(window_, &width_, &height_);

  glViewport(0, 0, width_, height_);

  switch (cursor)
  {
  case CursorMode::Disabled:
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    break;
  case CursorMode::Hidden:
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    break;
  case CursorMode::Normal:
    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    break;
  }

  glEnable(GL_DEPTH_TEST);

  glfwSetKeyCallback(window_, InputHandler::KeyCallback);
  glfwSetCursorPosCallback(window_, InputHandler::MouseCallback);
}

Window::~Window()
{
  glfwTerminate();
}

bool Window::UpdateWindow()
{
  glfwPollEvents();

  return !glfwWindowShouldClose(window_);
}

void Window::SwapBuffers()
{
  glfwSwapBuffers(window_);

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glFrontFace(GL_CCW);
  glCullFace(GL_BACK);
}
double Window::GetDeltaTime()
{
  double currentFrame = glfwGetTime();
  double deltaTime = currentFrame - lastFrameTime_;
  lastFrameTime_ = currentFrame;
  return deltaTime;
}

#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
public:
  Camera(glm::vec2 pos, float rot);
  const glm::mat4 GetMatrix();

  virtual void Update(float dt);

  glm::vec2 size;

private:
  glm::mat4 camMatrix_;
};
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec2 pos, float rot) :
  GameObject("Camera", pos, rot, glm::vec2(1, 1), 0)
{
}

const glm::mat4 Camera::GetMatrix()
{
  return camMatrix_;
}

void Camera::Update(float dt)
{
  camMatrix_ = glm::ortho(position.x - size.x, position.x + size.x, position.y - size.y, position.x + size.y);
}

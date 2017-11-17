#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

const glm::mat4 Camera::GetMatrix()
{
  return camMatrix_;
}

void Camera::Update(float dt)
{
  camMatrix_ = glm::ortho(position.x - size.x, position.x + size.x, position.y - size.y, position.x + size.y);
}

#pragma once
#include <glm\glm.hpp>
#include <string>

class GameObject
{
public:
  GameObject(const std::string& name);
  GameObject(const std::string& name, glm::vec2 pos, float rot, glm::vec2 scale, int layer);
  virtual ~GameObject() {}

  virtual void Update(float dt) {}
  virtual void Draw(float dt) {}

  std::string Name;

  glm::vec2 position;
  float rotation;
  glm::vec2 scale;
  int layer;

protected:
  glm::mat4 transform;
};
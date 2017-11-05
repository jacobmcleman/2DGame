#include "GameObject.h"

GameObject::GameObject(const std::string & name) : 
  Name(name), position(0, 0), rotation(0), scale(1, 1), layer(1)
{
}

GameObject::GameObject(const std::string & name, glm::vec2 pos, float rot, glm::vec2 scale, int layer) :
  Name(name), position(pos), rotation(rot), scale(scale), layer(layer)
{
}

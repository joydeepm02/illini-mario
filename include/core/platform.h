#pragma once

#include <physics/entity.h>

namespace game {

namespace core {

class Platform : public physics::Entity {
 public:
  Platform() = default;
  Platform(std::string name, glm::dvec2 position, glm::dvec2 velocity, size_t width, size_t height);
  size_t GetWidth();
  size_t GetHeight();
  glm::dvec2 GetTopLeftCorner();
  glm::dvec2 GetBottomRightCorner();
 private:
  size_t width_;
  size_t height_;
};

}

}
#include <physics/accelerated_entity.h>

namespace physics {

AcceleratedEntity::AcceleratedEntity(std::string name, glm::dvec2 position, glm::dvec2 velocity, glm::dvec2 acceleration)
        : Entity(name, position, velocity) {
  acceleration_ = acceleration;
}

glm::dvec2 AcceleratedEntity::GetAcceleration() {
  return acceleration_;
}

void AcceleratedEntity::UpdateState() {
  velocity_ += acceleration_;
  position_ += velocity_;
}


}

#pragma once

#include "physics/entity.h"

namespace game {

namespace core {

/**
 * A class that represents a player in the game.
 */
class Player : public physics::Entity {
 public:
  Player() = default;
  Player(const glm::dvec2& position, const glm::dvec2& velocity,
         const glm::dvec2& acceleration, size_t width, size_t height);
  size_t GetScore() const;
  bool IsJumping() const;
  bool IsOnGround() const;
  bool IsFacingRight() const;
  void IncrementScore();
  void SetOnGround(bool on_ground);
  void SetJumping(bool is_jumping);
  void UpdateState(double dt) override;

 private:
  size_t score_;
  bool is_jumping_;
  bool on_ground_;
};

}

}
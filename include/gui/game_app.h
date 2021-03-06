#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/audio/audio.h"
#include "cinder/gl/gl.h"
#include "core/game.h"
#include "gui/gui_constants.h"

using namespace game::core::constants;
using namespace game::gui::constants;

namespace game {

namespace gui {

class GameApp : public ci::app::App {
 public:
  GameApp();
  void draw() override;
  void update() override;
  void mouseMove(ci::app::MouseEvent event) override;
  void mouseDown(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

 private:
  /**
   * Helper function to manage which music played based on the game status.
   */
  void ManageMusic();
  /**
   * Helper function to draw the game, based on its status.
   */
  void DrawGame() const;
  /**
   * Helper function to draw the start screen.
   */
  void DrawStartScreen() const;
  /**
   * Helper function to draw the game while it is in progress.
   */
  void DrawGameInProgress() const;
  /**
   * Helper function to draw the game paused screen.
   */
  void DrawGamePaused() const;
  /**
   * Helper function to draw the game over screen.
   */
  void DrawGameOverScreen() const;
  /**
   * Helper function to draw a platform.
   *
   * @param platform The platform to draw
   */
  void DrawPlatform(const game::core::Platform& platform) const;
  /**
   * Helper function to draw a player.
   *
   * @param player The player to draw
   */
  void DrawPlayer(const game::core::Player& player) const;

  game::core::Game game_ = game::core::Game(kWindowSize);
  ci::audio::VoiceRef current_audio_;

  const ci::gl::Texture2dRef kLogoTex =
          ci::gl::Texture2d::create(
                  loadImage(ci::app::loadAsset(kLogoAssetFile)));
  const ci::gl::Texture2dRef kBackgroundTex =
          ci::gl::Texture2d::create(
                  loadImage(ci::app::loadAsset(kBackgroundAssetFile)));
  const ci::gl::Texture2dRef kBlockTex =
          ci::gl::Texture2d::create(
                  loadImage(ci::app::loadAsset(kBlockAssetFile)));
  const ci::gl::Texture2dRef kCharRightGroundTex =
          ci::gl::Texture2d::create(
                  loadImage(ci::app::loadAsset(kCharGroundRightAssetFile)));
  const ci::gl::Texture2dRef kCharLeftGroundTex =
          ci::gl::Texture2d::create(
                  loadImage(ci::app::loadAsset(kCharGroundLeftAssetFile)));
  const ci::gl::Texture2dRef kCharRightJumpTex =
          ci::gl::Texture2d::create(
                  loadImage(ci::app::loadAsset(kCharJumpRightAssetFile)));
  const ci::gl::Texture2dRef kCharLeftJumpTex =
          ci::gl::Texture2d::create(
                  loadImage(ci::app::loadAsset(kCharJumpLeftAssetFile)));
};

}

}
#include "Application.h"
#include "classes/TicTacToe.h"
#include "imgui/imgui.h"

namespace ClassGame {

//
// our global variables
//
TicTacToe *game = nullptr;
bool gameOver = false;
int gameWinner = -1;
bool aiEnabled = false;

//
// game starting point
// this is called by the main render loop in main.cpp
//
void GameStartUp() {
  game = new TicTacToe();
  game->setUpBoard();
}

//
// game render loop
// this is called by the main render loop in main.cpp
//
void RenderGame() {
  ImGui::DockSpaceOverViewport();

  // ImGui::ShowDemoWindow();

  if (!game)
    return;
  if (!game->getCurrentPlayer())
    return;

  ImGui::Begin("Settings");
  ImGui::Text("Current Player Number: %d",
              game->getCurrentPlayer()->playerNumber());
  ImGui::Text("Current Board State: %s", game->stateString().c_str());

  if (ImGui::Checkbox("AI Opponent", &aiEnabled)) {
    if (aiEnabled) {
      game->setAIPlayer(1);
    } else {
      game->getPlayerAt(1)->setAIPlayer(false);
    }
  }

  if (gameOver) {
    ImGui::Text("Game Over!");
    if (gameWinner == -1) {
      ImGui::Text("It's a Draw!");
    } else if (gameWinner == 0) {
      ImGui::Text("Winner: O (Blue)");
    } else {
      ImGui::Text("Winner: X (Red)");
    }
    if (ImGui::Button("Reset Game")) {
      game->stopGame();
      game->setUpBoard();
      if (aiEnabled) {
        game->setAIPlayer(1);
      }
      gameOver = false;
      gameWinner = -1;
    }
  }
  ImGui::End();

  ImGui::Begin("GameWindow");
  game->drawFrame();
  ImGui::End();
}

//
// end turn is called by the game code at the end of each turn
// this is where we check for a winner
//
void EndOfTurn() {
  Player *winner = game->checkForWinner();
  if (winner) {
    gameOver = true;
    gameWinner = winner->playerNumber();
  }
  if (game->checkForDraw()) {
    gameOver = true;
    gameWinner = -1;
  }
}

} // namespace ClassGame

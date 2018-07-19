// author: chris-scientist
// created at: 13/06/2018
// updated at: 05/07/2018

#include "MainController.h"

MainController::MainController(MainMenuView* aMainMenu, LevelMenuView* aLevelMenu, WinnerView* aWinnerView, PauseView* aPauseView, AboutView* anAboutView, CubeController* aCubeController) : mainMenu(aMainMenu), levelMenu(aLevelMenu), winnerView(aWinnerView), pauseView(aPauseView), aboutView(anAboutView), cubeController(aCubeController), indexItem(-1), level(10), pause(false) {
  
}

MainController::~MainController() {
  delete mainMenu;
  delete levelMenu;
  delete winnerView;
  delete pauseView;
  delete aboutView;
  delete cubeController;
}

// Lancer l'application
void MainController::run() {
  if(indexItem <= -1) {
    indexItem = mainMenu->paint();
  } else {
    switch(indexItem) {
      // -----------------------------------------------------------------------------------------
      case 0: // Lancer le jeu
        if((! cubeController->cubeIsFinished() && ! pause) || cubeController->getStartGame()) {
          if(gb.buttons.pressed(BUTTON_MENU)) {
            pause = true;
          } else {
            runGame();
          }
        } else if(pause) {
          pauseView->paint();
          if(gb.buttons.pressed(BUTTON_A)) {
            indexItem = -1;
            cubeController->setStartGame(true);
            pause = false;
          } else if(gb.buttons.pressed(BUTTON_B)) {
            pause = false;
          }
        } else {
          winnerView->paint();
          if(gb.buttons.pressed(BUTTON_A)) {
            indexItem = -1;
            cubeController->setStartGame(true);
          }
        }
      break;
      // -----------------------------------------------------------------------------------------
      case 1: // Choix niveau
        level = levelMenu->paint();
        indexItem = -1;
      break;
      // -----------------------------------------------------------------------------------------
      case 2: // A propos
        aboutView->paint();
        if(gb.buttons.pressed(BUTTON_A)) {
          indexItem = -1;
        }
      break;
      // -----------------------------------------------------------------------------------------
      default: // Retour au menu si le choix est incorrecte
        indexItem = -1;
    }
  }
}

// Lancer le jeu
void MainController::runGame() const {
  if(cubeController->getStartGame()) {
    // Mélanger le cube
    cubeController->mixCube(level);
    cubeController->setStartGame(false);
  }
  
  if(gb.buttons.pressed(BUTTON_A)) {
    // Si une rotation partiel est en cours
    // alors on remet à zéro l'axe de rotation,
    // on remet à zéro l'indice de la "demi" face à tourner
    // et on désactive la rotation partiel
    if(cubeController->haveToRotatePartialCube()) {
      cubeController->resetAxeRotation();
      cubeController->resetIndexPartialMove();
      cubeController->changeToRotatePartialCube(false);
    }
    // Modification de l'axe de rotation
    cubeController->changeAxeRotation();
    // Activation de la rotation du cube
    cubeController->changeToRotateCube(true);
  } else if(gb.buttons.pressed(BUTTON_B)) {
    // Si une rotation est en cours
    // alors on remet à zéro l'axe de rotation
    // et on désactive la rotation
    if(cubeController->haveToRotateCube()) {
      cubeController->resetAxeRotation();
      cubeController->changeToRotateCube(false);
    }
    // Modification de l'axe de rotation
    cubeController->changeAxeRotation();
    // Initalisation de l'indice de la "demi" face à tourner
    cubeController->initIndexPartialMove();
    // Activation de la rotation partial du cube
    cubeController->changeToRotatePartialCube(true);
  } else if(gb.buttons.pressed(BUTTON_LEFT)) {
    if(cubeController->haveToRotateCube()) {
      // Si une rotation est active
      // alors tourner le cube vers la gauche (selon l'axe)
      cubeController->rotateCubeToLeft();
    } else if(cubeController->haveToRotatePartialCube()) {
      // Si une rotation partielle est active
      // alors tourner le cube partiellement vers la gauche (selon l'axe et l'indice)
      cubeController->rotatePartialToLeft();
    }
  } else if(gb.buttons.pressed(BUTTON_RIGHT)) {
    if(cubeController->haveToRotateCube()) {
      // Si une rotation est active
      // alors tourner le cube vers la droite (selon l'axe)
      cubeController->rotateCubeToRight();
    } else if(cubeController->haveToRotatePartialCube()) {
      // Si une rotation partielle est active
      // alors tourner le cube partiellement vers la droite (selon l'axe et l'indice)
      cubeController->rotatePartialToRight();
    }
  } else if(gb.buttons.pressed(BUTTON_UP)) {
    if(cubeController->haveToRotatePartialCube()) {
      // Si une rotation partielle du cube est active
      // alors on décrémente l'indice de la "demi" face à tourner
      cubeController->changeIndexPartialMove(false);
    }
  } else if(gb.buttons.pressed(BUTTON_DOWN)) {
    if(cubeController->haveToRotatePartialCube()) {
      // Si une rotation partielle du cube est active
      // alors on incrémente l'indice de la "demi" face à tourner
      cubeController->changeIndexPartialMove(true);
    }
  }
  // Dessiner le cube
  cubeController->paint();
}


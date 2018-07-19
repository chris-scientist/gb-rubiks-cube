// author: chris-scientist
// created at: 27/04/2018
// updated at: 05/07/2018

#include <Gamebuino-Meta.h>

#include "MainController.h"
#include "CubeController.h"
#include "CubeModel.h"
#include "CubeView.h"
#include "MainMenuView.h"
#include "LevelMenuView.h"
#include "WinnerView.h"
#include "PauseView.h"
#include "AboutView.h"
#include "EColor.h"

MainController * mainController;

void setup() {
  // initialisé la gamebuino
  gb.begin();
  // initialisation des objets
  mainController = new MainController(new MainMenuView(), new LevelMenuView(), new WinnerView(), new PauseView(), new AboutView(), new CubeController(new CubeModel(), new CubeView()));
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  // effacer l'écran
  gb.display.clear();

  mainController->run();
  
}


// author: chris-scientist
// created at: 13/06/2018
// updated at: 05/07/2018
// description : contrôleur principale

#ifndef MAINCONTROLLER
#define MAINCONTROLLER

#include <Gamebuino-Meta.h>

#include "CubeController.h"
#include "MainMenuView.h"
#include "LevelMenuView.h"
#include "WinnerView.h"
#include "PauseView.h"
#include "AboutView.h"

class MainController {
  private:
    CubeController* cubeController;
    MainMenuView* mainMenu;
    LevelMenuView* levelMenu;
    WinnerView* winnerView;
    PauseView* pauseView;
    AboutView* aboutView;
    int indexItem;
    int level;
    bool pause;
  public:
    MainController(MainMenuView* aMainMenu, LevelMenuView* aLevelMenu, WinnerView* aWinnerView, PauseView* aPauseView, AboutView* anAboutView, CubeController* aCubeController);
    ~MainController();
    void run();
    void runGame() const;
};

#endif

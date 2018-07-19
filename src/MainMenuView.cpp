// author: chris-scientist
// updated at: 04/07/2018
// created at: 13/06/2018

#include "MainMenuView.h"

// Afficher le menu principale
int MainMenuView::paint() const {
  const char* items[] = {
    "Nouvelle partie",
    "Choix niveau",
    "A propos"
  };

  const uint8_t indexItem = gb.gui.menu("Menu", items);
  int choice = 0;
  if(items[indexItem] == "Choix niveau") {
    choice = 1;
  } else if(items[indexItem] == "A propos") {
    choice = 2;
  }
  return choice;
}


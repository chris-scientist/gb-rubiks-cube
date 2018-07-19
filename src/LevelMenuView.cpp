// author: chris-scientist
// created at: 04/07/2018

#include "LevelMenuView.h"

int LevelMenuView::paint() const {
  const char* items[] = {
    "Facile",
    "Moyen",
    "Difficile"
  };

  const uint8_t indexItem = gb.gui.menu("Niveau", items);
  int choice = 10;
  if(items[indexItem] == "Moyen") {
    choice = 20;
  } else if(items[indexItem] == "Difficile") {
    choice = 30;
  }
  return choice;
}


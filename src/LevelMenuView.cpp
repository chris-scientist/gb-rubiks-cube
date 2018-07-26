// author: chris-scientist
// created at: 04/07/2018

#include "LevelMenuView.h"

int LevelMenuView::paint() const {
  const char* items[] = {
    Lang::getEasy(),
    Lang::getMedium(),
    Lang::getHard()
  };

  const uint8_t indexItem = gb.gui.menu(Lang::getLevel(), items);
  int choice = 10;
  if(items[indexItem] == Lang::mediumFR || items[indexItem] == Lang::mediumEN) {
    choice = 20;
  } else if(items[indexItem] == Lang::hardFR || items[indexItem] == Lang::hardEN) {
    choice = 30;
  }
  return choice;
}


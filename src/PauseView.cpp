// author: chris-scientist
// created at: 04/07/2018

#include "PauseView.h"

void PauseView::paint() const {
  gb.display.setFontSize(2);
  gb.display.setColor(BROWN);
  gb.display.println();
  gb.display.println();
  gb.display.println("  Pause");
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.println();
  gb.display.println("(A) acceder au menu");
  gb.display.println("(B) reprendre partie");
}


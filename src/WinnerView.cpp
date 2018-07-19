// author: chris-scientist
// created at: 04/07/2018

#include "WinnerView.h"

void WinnerView::paint() const {
  gb.display.setColor(BROWN);
  gb.display.setFontSize(2);
  gb.display.println();
  gb.display.println();
  gb.display.println("  Gagne");
  gb.display.println();
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.print("(A) pour continuer");
}


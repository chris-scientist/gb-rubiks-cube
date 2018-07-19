// author: chris-scientist
// created at: 05/07/2018

#include "AboutView.h"

void AboutView::paint() const {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.println("   Rubik's cube");
  gb.display.setColor(WHITE);
  gb.display.println("   presente par");
  gb.display.setColor(BROWN);
  gb.display.println("  chris-scientist");
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.print("(A) acceder au menu");
}


// author: chris-scientist
// created at: 04/07/2018

#include "WinnerView.h"

void WinnerView::paint() const {
  bool isEnLang = Lang::isEnglishLanguage();
  
  gb.display.setColor(BROWN);
  if(isEnLang) {
    gb.display.setFontSize(1);
    gb.display.println();
    gb.display.println();
  } else {
    gb.display.setFontSize(2);
  }
  gb.display.println();
  gb.display.println();
  gb.display.println(Lang::getCongratulations());
  gb.display.println();
  if(isEnLang) {
    gb.display.println();
    gb.display.println();
  }
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.print(Lang::getPressToContinue());
}


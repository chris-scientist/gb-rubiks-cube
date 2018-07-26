// author: chris-scientist
// created at: 26/07/2018
// description : utilisé pour la tranduction

#ifndef LANG
#define LANG

#include <Gamebuino-Meta.h>

class Lang {
  private:
  public:
    static const char* aboutFR;
    static const char* aboutEN;
    static const char* choiceLevelFR;
    static const char* choiceLevelEN;
    static const char* congratulationsFR;
    static const char* congratulationsEN;
    static const char* createdByFR;
    static const char* createdByEN;
    static const char* easyFR;
    static const char* easyEN;
    static const char* getBackPartFR;
    static const char* getBackPartEN;
    static const char* goToMenuFR;
    static const char* goToMenuEN;
    static const char* hardFR;
    static const char* hardEN;
    static const char* levelFR;
    static const char* levelEN;
    static const char* mediumFR;
    static const char* mediumEN;
    static const char* newPartFR;
    static const char* newPartEN;
    static const char* pressToContinueFR;
    static const char* pressToContinueEN;

    static const bool isEnglishLanguage();
    static const char* getAbout();
    static const char* getChoiceLevel();
    static const char* getCongratulations();
    static const char* getCreatedBy();
    static const char* getEasy();
    static const char* getGetBackPart();  
    static const char* getGoToMenu();
    static const char* getHard();
    static const char* getLevel();
    static const char* getMedium();
    static const char* getNewPart();
    static const char* getPressToContinue();
};

#endif

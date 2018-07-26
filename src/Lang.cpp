// author: chris-scientist
// created at: 26/07/2018

#include "Lang.h"

// Initialisation des attributs statiques

const char* Lang::aboutFR = "A propos";
const char* Lang::aboutEN = "About";
const char* Lang::choiceLevelFR = "Choix niveau";
const char* Lang::choiceLevelEN = "Choice level";
const char* Lang::congratulationsFR = "  Gagne";
const char* Lang::congratulationsEN = "  Congratulations";
const char* Lang::createdByFR = "   presente par";
const char* Lang::createdByEN = "    created by";
const char* Lang::easyFR = "Facile";
const char* Lang::easyEN = "Easy";
const char* Lang::getBackPartFR = "(B) reprendre partie";
const char* Lang::getBackPartEN = "(B) get back part";
const char* Lang::goToMenuFR = "(A) acceder au menu";
const char* Lang::goToMenuEN = "(A) go to menu";
const char* Lang::hardFR = "Difficile";
const char* Lang::hardEN = "Hard";
const char* Lang::levelFR = "Niveau";
const char* Lang::levelEN = "Level";
const char* Lang::mediumFR = "Moyen";
const char* Lang::mediumEN = "Medium";
const char* Lang::newPartFR = "Nouvelle partie";
const char* Lang::newPartEN = "New part";
const char* Lang::pressToContinueFR = "(A) pour continuer";
const char* Lang::pressToContinueEN = "(A) to continue";

// Méthodes 

const bool Lang::isEnglishLanguage() {
  return (gb.language.getCurrentLang() == LANG_EN);
}

const char* Lang::getAbout() {
  const MultiLang aboutLang[] = {
    { LANG_EN, Lang::aboutEN },
    { LANG_FR, Lang::aboutFR }
  };

  return gb.language.get(aboutLang);
}

const char* Lang::getChoiceLevel() {
  const MultiLang choiceLevelLang[] = {
    { LANG_EN, Lang::choiceLevelEN },
    { LANG_FR, Lang::choiceLevelFR }
  };

  return gb.language.get(choiceLevelLang);
}

const char* Lang::getCongratulations() {
  const MultiLang congratulationsLang[] = {
    { LANG_EN, Lang::congratulationsEN },
    { LANG_FR, Lang::congratulationsFR }
  };

  return gb.language.get(congratulationsLang);
}

const char* Lang::getCreatedBy() {
  const MultiLang createdByLang[] = {
    { LANG_EN, Lang::createdByEN },
    { LANG_FR, Lang::createdByFR }
  };

  return gb.language.get(createdByLang);
}

const char* Lang::getEasy() {
  const MultiLang easyLang[] = {
    { LANG_EN, Lang::easyEN },
    { LANG_FR, Lang::easyFR }
  };

  return gb.language.get(easyLang);
}

const char* Lang::getGetBackPart() {
  const MultiLang getBackPartLang[] = {
    { LANG_EN, Lang::getBackPartEN },
    { LANG_FR, Lang::getBackPartFR }
  };

  return gb.language.get(getBackPartLang);
}

const char* Lang::getGoToMenu() {
  const MultiLang goToMenuLang[] = {
    { LANG_EN, Lang::goToMenuEN },
    { LANG_FR, Lang::goToMenuFR }
  };

  return gb.language.get(goToMenuLang);
}

const char* Lang::getHard() {
  const MultiLang hardLang[] = {
    { LANG_EN, Lang::hardEN },
    { LANG_FR, Lang::hardFR }
  };

  return gb.language.get(hardLang);
}

const char* Lang::getLevel() {
  const MultiLang levelLang[] = {
    { LANG_EN, Lang::levelEN },
    { LANG_FR, Lang::levelFR }
  };

  return gb.language.get(levelLang);
}

const char* Lang::getMedium() {
  const MultiLang mediumLang[] = {
    { LANG_EN, Lang::mediumEN },
    { LANG_FR, Lang::mediumFR }
  };

  return gb.language.get(mediumLang);
}

const char* Lang::getNewPart() {
  const MultiLang newPartLang[] = {
    { LANG_EN, Lang::newPartEN },
    { LANG_FR, Lang::newPartFR }
  };

  return gb.language.get(newPartLang);
}

const char* Lang::getPressToContinue() {
  const MultiLang pressToContinueLang[] = {
    { LANG_EN, Lang::pressToContinueEN },
    { LANG_FR, Lang::pressToContinueFR }
  };

  return gb.language.get(pressToContinueLang);
}


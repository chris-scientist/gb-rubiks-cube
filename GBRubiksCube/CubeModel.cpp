// author: chris-scientist
// created at: 27/04/2018
// updated at: 10/06/2018

#include "CubeModel.h"

// Initialiser le cube (le cube n'est pas mélangé)
CubeModel::CubeModel() : axeRotation(0), indexPartialMove(0), rotateCube(false), rotatePartialCube(false) {
  // initialiser les 6 faces du cube
  f1 = new FaceModel(EColor::White);
  f2 = new FaceModel(EColor::Blue);
  f3 = new FaceModel(EColor::Yellow);
  f4 = new FaceModel(EColor::Green);
  f5 = new FaceModel(EColor::Red);
  f6 = new FaceModel(EColor::Orange);
}

// Détruire le cube
CubeModel::~CubeModel() {
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  delete f5;
  delete f6;
}

// Changer l'axe de rotation
void CubeModel::changeAxeRotation() {
  if(axeRotation<3) {
    axeRotation++;
  } else {
    axeRotation = 0;
    // Réinitialiser les rotations
    rotateCube = false;
    rotatePartialCube = false;
  }
}

void CubeModel::resetAxeRotation() {
  axeRotation = 0;
}

void CubeModel::changeIndexPartialMove(bool const& isIncrement) {
  if(isIncrement && indexPartialMove<3) {
    indexPartialMove++;
  } else if(isIncrement) {
    indexPartialMove = 1;
  } else if(!isIncrement && indexPartialMove>1) {
    indexPartialMove--;
  } else if(!isIncrement) {
    indexPartialMove = 3;
  }
}

void CubeModel::resetIndexPartialMove() {
  indexPartialMove = 0;
}

void CubeModel::initIndexPartialMove() {
  indexPartialMove = 2;
}

// Rotation vers la gauche
void CubeModel::rotateToLeft() {
  cloneCube();
  switch(axeRotation) {
    case 1: // Rotation autour de l'axe Z
      rotateToLeftOnZ();
    break;
    case 2: // Rotation autour de l'axe X
      rotateToLeftOnX();
    break;
    case 3: // Rotation autour de l'axe Y
      rotateToLeftOnY();
    break;
  }
  uncloneCube();
}

// Rotation vers la gauche sur l'axe X
void CubeModel::rotateToLeftOnX() {
  // Initialisation des nouvelles faces 
  f1->changeAllSquare(cpyF6->getSquare(0,2), cpyF6->getSquare(1,2), cpyF6->getSquare(2,2), cpyF6->getSquare(0,1), cpyF6->getSquare(1,1), cpyF6->getSquare(2,1), cpyF6->getSquare(0,0), cpyF6->getSquare(1,0), cpyF6->getSquare(2,0));
  rotateWayAntiHoraire(f2, cpyF2);
  f3->changeAllSquare(cpyF5->getSquare(0,2), cpyF5->getSquare(1,2), cpyF5->getSquare(2,2), cpyF5->getSquare(0,1), cpyF5->getSquare(1,1), cpyF5->getSquare(2,1), cpyF5->getSquare(0,0), cpyF5->getSquare(1,0), cpyF5->getSquare(2,0));
  rotateWayHoraire(f4, cpyF4);
  f5->changeAllSquare(cpyF1->getSquare(0,2), cpyF1->getSquare(1,2), cpyF1->getSquare(2,2), cpyF1->getSquare(0,1), cpyF1->getSquare(1,1), cpyF1->getSquare(2,1), cpyF1->getSquare(0,0), cpyF1->getSquare(1,0), cpyF1->getSquare(2,0));
  f6->changeAllSquare(cpyF3->getSquare(0,2), cpyF3->getSquare(1,2), cpyF3->getSquare(2,2), cpyF3->getSquare(0,1), cpyF3->getSquare(1,1), cpyF3->getSquare(2,1), cpyF3->getSquare(0,0), cpyF3->getSquare(1,0), cpyF3->getSquare(2,0));
}

// Rotation vers la gauche sur l'axe Y
void CubeModel::rotateToLeftOnY() {
  // Suppression des faces 2,5
  delete f2;
  delete f5;
  // Initialisation des nouvelles faces
  f2 = new FaceModel(*cpyF6);
  f5 = new FaceModel(*cpyF2);
  rotateWayHoraire(f1, cpyF1);
  rotateWayAntiHoraire(f3, cpyF3);
  f4->changeAllSquare(cpyF5->getSquare(2,2), cpyF5->getSquare(2,1), cpyF5->getSquare(2,0), cpyF5->getSquare(1,2), cpyF5->getSquare(1,1), cpyF5->getSquare(1,0), cpyF5->getSquare(0,2), cpyF5->getSquare(0,1), cpyF5->getSquare(0,0));
  f6->changeAllSquare(cpyF4->getSquare(2,2), cpyF4->getSquare(2,1), cpyF4->getSquare(2,0), cpyF4->getSquare(1,2), cpyF4->getSquare(1,1), cpyF4->getSquare(1,0), cpyF4->getSquare(0,2), cpyF4->getSquare(0,1), cpyF4->getSquare(0,0));
}

// Rotation vers la gauche sur l'axe Z
void CubeModel::rotateToLeftOnZ() {
  // Suppression des faces 1 à 4
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  // Initialisation des nouvelles faces
  f1 = new FaceModel(*cpyF2);
  f2 = new FaceModel(*cpyF3);
  f3 = new FaceModel(*cpyF4);
  f4 = new FaceModel(*cpyF1);
  rotateWayAntiHoraire(f5, cpyF5);
  rotateWayHoraire(f6, cpyF6);
}

// Rotation vers la droite
void CubeModel::rotateToRight() {
  cloneCube();
  switch(axeRotation) {
    case 1: // Rotation autour de l'axe Z
      rotateToRightOnZ();
    break;
    case 2: // Rotation autour de l'axe X
      rotateToRightOnX();
    break;
    case 3: // Rotation autour de l'axe Y
      rotateToRightOnY();
    break;
  }
  uncloneCube();
}

// Rotation vers la droite sur l'axe X
void CubeModel::rotateToRightOnX() {
  // Initialisation des nouvelles faces
  f1->changeAllSquare(cpyF5->getSquare(2,0), cpyF5->getSquare(1,0), cpyF5->getSquare(0,0), cpyF5->getSquare(2,1), cpyF5->getSquare(1,1), cpyF5->getSquare(0,1), cpyF5->getSquare(2,2), cpyF5->getSquare(1,2), cpyF5->getSquare(0,2));
  rotateWayHoraire(f2, cpyF2);
  f3->changeAllSquare(cpyF6->getSquare(2,0), cpyF6->getSquare(1,0), cpyF6->getSquare(0,0), cpyF6->getSquare(2,1), cpyF6->getSquare(1,1), cpyF6->getSquare(0,1), cpyF6->getSquare(2,2), cpyF6->getSquare(1,2), cpyF6->getSquare(0,2));
  rotateWayAntiHoraire(f4, cpyF4);
  f5->changeAllSquare(cpyF3->getSquare(2,0), cpyF3->getSquare(1,0), cpyF3->getSquare(0,0), cpyF3->getSquare(2,1), cpyF3->getSquare(1,1), cpyF3->getSquare(0,1), cpyF3->getSquare(2,2), cpyF3->getSquare(1,2), cpyF3->getSquare(0,2));
  f6->changeAllSquare(cpyF1->getSquare(2,0), cpyF1->getSquare(1,0), cpyF1->getSquare(0,0), cpyF1->getSquare(2,1), cpyF1->getSquare(1,1), cpyF1->getSquare(0,1), cpyF1->getSquare(2,2), cpyF1->getSquare(1,2), cpyF1->getSquare(0,2));
}

// Rotation vers la droite sur l'axe Y
void CubeModel::rotateToRightOnY() {
  // Suppression des faces
  delete f2;
  delete f6;
  // Initialisation des nouvelles faces
  rotateWayAntiHoraire(f1, cpyF1);
  f2 = new FaceModel(*cpyF5);
  rotateWayHoraire(f3, cpyF3);
  f4->changeAllSquare(cpyF6->getSquare(2,2), cpyF6->getSquare(2,1), cpyF6->getSquare(2,0), cpyF6->getSquare(1,2), cpyF6->getSquare(1,1), cpyF6->getSquare(1,0), cpyF6->getSquare(0,2), cpyF6->getSquare(0,1), cpyF6->getSquare(0,0));
  f5->changeAllSquare(cpyF4->getSquare(2,2), cpyF4->getSquare(2,1), cpyF4->getSquare(2,0), cpyF4->getSquare(1,2), cpyF4->getSquare(1,1), cpyF4->getSquare(1,0), cpyF4->getSquare(0,2), cpyF4->getSquare(0,1), cpyF4->getSquare(0,0));
  f6 = new FaceModel(*cpyF2);
}

// Rotation vers la droite sur l'axe Z
void CubeModel::rotateToRightOnZ() {
  // Suppression des faces 1 à 4
  delete f1;
  delete f2;
  delete f3;
  delete f4;
  // Initialisation des nouvelles faces
  f1 = new FaceModel(*cpyF4);
  f2 = new FaceModel(*cpyF1);
  f3 = new FaceModel(*cpyF2);
  f4 = new FaceModel(*cpyF3);
  rotateWayHoraire(f5, cpyF5);
  rotateWayAntiHoraire(f6, cpyF6);
}

// Rotation partielle du cube vers la gauche
void CubeModel::rotatePartialToLeft() {
  cloneCube();
  switch(axeRotation) {
    case 1: // Rotation autour de l'axe Z
      rotatePartialToLeftOnZ();
    break;
    case 2: // Rotation autour de l'axe X
      rotatePartialToLeftOnX();
    break;
    case 3: // Rotation autour de l'axe Y
      rotatePartialToLeftOnY();
    break;
  }
  uncloneCube();
}

// Rotation partielle du cube vers la gauche sur l'axe X
void CubeModel::rotatePartialToLeftOnX() {
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // Rotation partielle de F1
      f1->setSquare(0, 0, cpyF6->getSquare(0, 2));
      f1->setSquare(0, 1, cpyF6->getSquare(1, 2));
      f1->setSquare(0, 2, cpyF6->getSquare(2, 2));
      // Rotation partielle de F3
      f3->setSquare(2, 0, cpyF5->getSquare(0, 0));
      f3->setSquare(2, 1, cpyF5->getSquare(1, 0));
      f3->setSquare(2, 2, cpyF5->getSquare(2, 0));
      // Rotation complète de F4
      rotateWayHoraire(f4, cpyF4);
      // Rotation partielle de F5
      f5->setSquare(0, 0, cpyF1->getSquare(0, 2));
      f5->setSquare(1, 0, cpyF1->getSquare(0, 1));
      f5->setSquare(2, 0, cpyF1->getSquare(0, 0));
      // Rotation partielle de F6
      f6->setSquare(0, 2, cpyF3->getSquare(2, 2));
      f6->setSquare(1, 2, cpyF3->getSquare(2, 1));
      f6->setSquare(2, 2, cpyF3->getSquare(2, 0));
    break;
    case 2: // Rotation de la partie centrale
      // Rotation partielle de F1
      f1->setSquare(1, 0, cpyF6->getSquare(0, 1));
      f1->setSquare(1, 1, cpyF6->getSquare(1, 1));
      f1->setSquare(1, 2, cpyF6->getSquare(2, 1));
      // Rotation partielle de F3
      f3->setSquare(1, 0, cpyF5->getSquare(0, 1));
      f3->setSquare(1, 1, cpyF5->getSquare(1, 1));
      f3->setSquare(1, 2, cpyF5->getSquare(2, 1));
      // Rotation partielle de F5
      f5->setSquare(0, 1, cpyF1->getSquare(1, 2));
      f5->setSquare(1, 1, cpyF1->getSquare(1, 1));
      f5->setSquare(2, 1, cpyF1->getSquare(1, 0));
      // Rotation partielle de F6
      f6->setSquare(0, 1, cpyF3->getSquare(1, 2));
      f6->setSquare(1, 1, cpyF3->getSquare(1, 1));
      f6->setSquare(2, 1, cpyF3->getSquare(1, 0));
    break;
    case 3: // Rotation de la partie inférieure
      // Rotation partielle de F1
      f1->setSquare(2, 0, cpyF6->getSquare(0, 0));
      f1->setSquare(2, 1, cpyF6->getSquare(1, 0));
      f1->setSquare(2, 2, cpyF6->getSquare(2, 0));
      // Rotation complète de F2
      rotateWayAntiHoraire(f2, cpyF2);
      // Rotation partielle de F3
      f3->setSquare(0, 0, cpyF5->getSquare(0, 2));
      f3->setSquare(0, 1, cpyF5->getSquare(1, 2));
      f3->setSquare(0, 2, cpyF5->getSquare(2, 2));
      // Rotation partielle de F5
      f5->setSquare(0, 2, cpyF1->getSquare(2, 2));
      f5->setSquare(1, 2, cpyF1->getSquare(2, 1));
      f5->setSquare(2, 2, cpyF1->getSquare(2, 0));
      // Rotation partielle de F6
      f6->setSquare(0, 0, cpyF3->getSquare(0, 2));
      f6->setSquare(1, 0, cpyF3->getSquare(0, 1));
      f6->setSquare(2, 0, cpyF3->getSquare(0, 0));
    break;
  }
}

// Rotation partielle du cube vers la gauche sur l'axe Y
void CubeModel::rotatePartialToLeftOnY() {
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // Rotation complète de F1
      rotateWayHoraire(f1, cpyF1);
      // Rotation partielle de F2
      f2->setSquare(0, 0, cpyF6->getSquare(0, 0));
      f2->setSquare(0, 1, cpyF6->getSquare(0, 1));
      f2->setSquare(0, 2, cpyF6->getSquare(0, 2));
      // Rotation partielle de F4
      f4->setSquare(2, 0, cpyF5->getSquare(0, 2));
      f4->setSquare(2, 1, cpyF5->getSquare(0, 1));
      f4->setSquare(2, 2, cpyF5->getSquare(0, 0));
      // Rotation partielle de F5
      f5->setSquare(0, 0, cpyF2->getSquare(0, 0));
      f5->setSquare(0, 1, cpyF2->getSquare(0, 1));
      f5->setSquare(0, 2, cpyF2->getSquare(0, 2));
      // Rotation partielle de F6
      f6->setSquare(0, 0, cpyF4->getSquare(2, 2));
      f6->setSquare(0, 1, cpyF4->getSquare(2, 1));
      f6->setSquare(0, 2, cpyF4->getSquare(2, 0));
    break;
    case 2: // Rotation de la partie centrale
      // Rotation partielle de F2
      f2->setSquare(1, 0, cpyF6->getSquare(1, 0));
      f2->setSquare(1, 1, cpyF6->getSquare(1, 1));
      f2->setSquare(1, 2, cpyF6->getSquare(1, 2));
      // Rotation partielle de F4
      f4->setSquare(1, 0, cpyF5->getSquare(1, 2));
      f4->setSquare(1, 1, cpyF5->getSquare(1, 1));
      f4->setSquare(1, 2, cpyF5->getSquare(1, 0));
      // Rotation partielle de F5
      f5->setSquare(1, 0, cpyF2->getSquare(1, 0));
      f5->setSquare(1, 1, cpyF2->getSquare(1, 1));
      f5->setSquare(1, 2, cpyF2->getSquare(1, 2));
      // Rotation partielle de F6
      f6->setSquare(1, 0, cpyF4->getSquare(1, 2));
      f6->setSquare(1, 1, cpyF4->getSquare(1, 1));
      f6->setSquare(1, 2, cpyF4->getSquare(1, 0));
    break;
    case 3: // Rotation de la partie inférieure
      // Rotation partielle de F2
      f2->setSquare(2, 0, cpyF6->getSquare(2, 0));
      f2->setSquare(2, 1, cpyF6->getSquare(2, 1));
      f2->setSquare(2, 2, cpyF6->getSquare(2, 2));
      // Rotation complète de F3
      rotateWayAntiHoraire(f3, cpyF3);
      // Rotation partielle de F4
      f4->setSquare(0, 0, cpyF5->getSquare(2, 2));
      f4->setSquare(0, 1, cpyF5->getSquare(2, 1));
      f4->setSquare(0, 2, cpyF5->getSquare(2, 0));
      // Rotation partielle de F5
      f5->setSquare(2, 0, cpyF2->getSquare(2, 0));
      f5->setSquare(2, 1, cpyF2->getSquare(2, 1));
      f5->setSquare(2, 2, cpyF2->getSquare(2, 2));
      // Rotation partielle de F6
      f6->setSquare(2, 0, cpyF4->getSquare(0, 2));
      f6->setSquare(2, 1, cpyF4->getSquare(0, 1));
      f6->setSquare(2, 2, cpyF4->getSquare(0, 0));
    break;
  }
}

// Rotation partielle du cube vers la gauche sur l'axe Z
void CubeModel::rotatePartialToLeftOnZ() {
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // Rotation partielle de F1
      f1->setSquare(0, 2, cpyF2->getSquare(0, 2));
      f1->setSquare(1, 2, cpyF2->getSquare(1, 2));
      f1->setSquare(2, 2, cpyF2->getSquare(2, 2));
      // Rotation partielle de F2
      f2->setSquare(0, 2, cpyF3->getSquare(0, 2));
      f2->setSquare(1, 2, cpyF3->getSquare(1, 2));
      f2->setSquare(2, 2, cpyF3->getSquare(2, 2));
      // Rotation partielle de F3
      f3->setSquare(0, 2, cpyF4->getSquare(0, 2));
      f3->setSquare(1, 2, cpyF4->getSquare(1, 2));
      f3->setSquare(2, 2, cpyF4->getSquare(2, 2));
      // Rotation partielle de F4
      f4->setSquare(0, 2, cpyF1->getSquare(0, 2));
      f4->setSquare(1, 2, cpyF1->getSquare(1, 2));
      f4->setSquare(2, 2, cpyF1->getSquare(2, 2));
      // Rotation complète de F6
      rotateWayHoraire(f6, cpyF6);
    break;
    case 2: // Rotation de la partie centrale
      // Rotation partielle de F1
      f1->setSquare(0, 1, cpyF2->getSquare(0, 1));
      f1->setSquare(1, 1, cpyF2->getSquare(1, 1));
      f1->setSquare(2, 1, cpyF2->getSquare(2, 1));
      // Rotation partielle de F2
      f2->setSquare(0, 1, cpyF3->getSquare(0, 1));
      f2->setSquare(1, 1, cpyF3->getSquare(1, 1));
      f2->setSquare(2, 1, cpyF3->getSquare(2, 1));
      // Rotation partielle de F3
      f3->setSquare(0, 1, cpyF4->getSquare(0, 1));
      f3->setSquare(1, 1, cpyF4->getSquare(1, 1));
      f3->setSquare(2, 1, cpyF4->getSquare(2, 1));
      // Rotation partielle de F4
      f4->setSquare(0, 1, cpyF1->getSquare(0, 1));
      f4->setSquare(1, 1, cpyF1->getSquare(1, 1));
      f4->setSquare(2, 1, cpyF1->getSquare(2, 1));
    break;
    case 3: // Rotation de la partie inférieure
      // Rotation partielle de F1
      f1->setSquare(0, 0, cpyF2->getSquare(0, 0));
      f1->setSquare(1, 0, cpyF2->getSquare(1, 0));
      f1->setSquare(2, 0, cpyF2->getSquare(2, 0));
      // Rotation partielle de F2
      f2->setSquare(0, 0, cpyF3->getSquare(0, 0));
      f2->setSquare(1, 0, cpyF3->getSquare(1, 0));
      f2->setSquare(2, 0, cpyF3->getSquare(2, 0));
      // Rotation partielle de F3
      f3->setSquare(0, 0, cpyF4->getSquare(0, 0));
      f3->setSquare(1, 0, cpyF4->getSquare(1, 0));
      f3->setSquare(2, 0, cpyF4->getSquare(2, 0));
      // Rotation partielle de F4
      f4->setSquare(0, 0, cpyF1->getSquare(0, 0));
      f4->setSquare(1, 0, cpyF1->getSquare(1, 0));
      f4->setSquare(2, 0, cpyF1->getSquare(2, 0));
      // Rotation complète de F5
      rotateWayAntiHoraire(f5, cpyF5);
    break;
  }
}

// Rotation partielle du cube vers la droite
void CubeModel::rotatePartialToRight() {
  cloneCube();
  switch(axeRotation) {
    case 1: // Rotation autour de l'axe Z
      rotatePartialToRightOnZ();
    break;
    case 2: // Rotation autour de l'axe X
      rotatePartialToRightOnX();
    break;
    case 3: // Rotation autour de l'axe Y
      rotatePartialToRightOnY();
    break;
  }
  uncloneCube();
}

// Rotation partielle du cube vers la droite sur l'axe X
void CubeModel::rotatePartialToRightOnX() {
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // Rotation partielle de F1
      f1->setSquare(0, 0, cpyF5->getSquare(2, 0));
      f1->setSquare(0, 1, cpyF5->getSquare(1, 0));
      f1->setSquare(0, 2, cpyF5->getSquare(0, 0));
      // Rotation partielle de F3
      f3->setSquare(2, 0, cpyF6->getSquare(2, 2));
      f3->setSquare(2, 1, cpyF6->getSquare(1, 2));
      f3->setSquare(2, 2, cpyF6->getSquare(0, 2));
      // Rotation complète de F4
      rotateWayAntiHoraire(f4, cpyF4);
      // Rotation partielle de F5
      f5->setSquare(0, 0, cpyF3->getSquare(2, 0));
      f5->setSquare(1, 0, cpyF3->getSquare(2, 1));
      f5->setSquare(2, 0, cpyF3->getSquare(2, 2));
      // Rotation partielle de F6
      f6->setSquare(0, 2, cpyF1->getSquare(0, 0));
      f6->setSquare(1, 2, cpyF1->getSquare(0, 1));
      f6->setSquare(2, 2, cpyF1->getSquare(0, 2));
    break;
    case 2: // Rotation de la partie centrale
      // Rotation partielle de F1
      f1->setSquare(1, 0, cpyF5->getSquare(2, 1));
      f1->setSquare(1, 1, cpyF5->getSquare(1, 1));
      f1->setSquare(1, 2, cpyF5->getSquare(0, 1));
      // Rotation partielle de F3
      f3->setSquare(1, 0, cpyF6->getSquare(2, 1));
      f3->setSquare(1, 1, cpyF6->getSquare(1, 1));
      f3->setSquare(1, 2, cpyF6->getSquare(0, 1));
      // Rotation partielle de F5
      f5->setSquare(0, 1, cpyF3->getSquare(1, 0));
      f5->setSquare(1, 1, cpyF3->getSquare(1, 1));
      f5->setSquare(2, 1, cpyF3->getSquare(1, 2));
      // Rotation partielle de F6
      f6->setSquare(0, 1, cpyF1->getSquare(1, 0));
      f6->setSquare(1, 1, cpyF1->getSquare(1, 1));
      f6->setSquare(2, 1, cpyF1->getSquare(1, 2));
    break;
    case 3: // Rotation de la partie inférieure
      // Rotation partielle de F1
      f1->setSquare(2, 0, cpyF5->getSquare(2, 2));
      f1->setSquare(2, 1, cpyF5->getSquare(1, 2));
      f1->setSquare(2, 2, cpyF5->getSquare(0, 2));
      // Rotation complète de F2
      rotateWayHoraire(f2, cpyF2);
      // Rotation partielle de F3
      f3->setSquare(0, 0, cpyF6->getSquare(2, 0));
      f3->setSquare(0, 1, cpyF6->getSquare(1, 0));
      f3->setSquare(0, 2, cpyF6->getSquare(0, 0));
      // Rotation partielle de F5
      f5->setSquare(0, 2, cpyF3->getSquare(0, 0));
      f5->setSquare(1, 2, cpyF3->getSquare(0, 1));
      f5->setSquare(2, 2, cpyF3->getSquare(0, 2));
      // Rotation partielle de F6
      f6->setSquare(0, 0, cpyF1->getSquare(2, 0));
      f6->setSquare(1, 0, cpyF1->getSquare(2, 1));
      f6->setSquare(2, 0, cpyF1->getSquare(2, 2));
    break;
  }
}

// Rotation partielle du cube vers la droite sur l'axe Y
void CubeModel::rotatePartialToRightOnY() {
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // Rotation complète de F1
      rotateWayAntiHoraire(f1, cpyF1);
      // Rotation partielle de F2
      f2->setSquare(0, 0, cpyF5->getSquare(0, 0));
      f2->setSquare(0, 1, cpyF5->getSquare(0, 1));
      f2->setSquare(0, 2, cpyF5->getSquare(0, 2));
      // Rotation partielle de F4
      f4->setSquare(2, 0, cpyF6->getSquare(0, 2));
      f4->setSquare(2, 1, cpyF6->getSquare(0, 1));
      f4->setSquare(2, 2, cpyF6->getSquare(0, 0));
      // Rotation partielle de F5
      f5->setSquare(0, 0, cpyF4->getSquare(2, 2));
      f5->setSquare(0, 1, cpyF4->getSquare(2, 1));
      f5->setSquare(0, 2, cpyF4->getSquare(2, 0));
      // Rotation partielle de F6
      f6->setSquare(0, 0, cpyF2->getSquare(0, 0));
      f6->setSquare(0, 1, cpyF2->getSquare(0, 1));
      f6->setSquare(0, 2, cpyF2->getSquare(0, 2));
    break;
    case 2: // Rotation de la partie centrale
      // Rotation partielle de F2
      f2->setSquare(1, 0, cpyF5->getSquare(1, 0));
      f2->setSquare(1, 1, cpyF5->getSquare(1, 1));
      f2->setSquare(1, 2, cpyF5->getSquare(1, 2));
      // Rotation partielle de F4
      f4->setSquare(1, 0, cpyF6->getSquare(1, 2));
      f4->setSquare(1, 1, cpyF6->getSquare(1, 1));
      f4->setSquare(1, 2, cpyF6->getSquare(1, 0));
      // Rotation partielle de F5
      f5->setSquare(1, 0, cpyF4->getSquare(1, 2));
      f5->setSquare(1, 1, cpyF4->getSquare(1, 1));
      f5->setSquare(1, 2, cpyF4->getSquare(1, 0));
      // Rotation partielle de F6
      f6->setSquare(1, 0, cpyF2->getSquare(1, 0));
      f6->setSquare(1, 1, cpyF2->getSquare(1, 1));
      f6->setSquare(1, 2, cpyF2->getSquare(1, 2));
    break;
    case 3: // Rotation de la partie inférieure
      // Rotation partielle de F2
      f2->setSquare(2, 0, cpyF5->getSquare(2, 0));
      f2->setSquare(2, 1, cpyF5->getSquare(2, 1));
      f2->setSquare(2, 2, cpyF5->getSquare(2, 2));
      // Rotation complète de F3
      rotateWayHoraire(f3, cpyF3);
      // Rotation partielle de F4
      f4->setSquare(0, 0, cpyF6->getSquare(2, 2));
      f4->setSquare(0, 1, cpyF6->getSquare(2, 1));
      f4->setSquare(0, 2, cpyF6->getSquare(2, 0));
      // Rotation partielle de F5
      f5->setSquare(2, 0, cpyF4->getSquare(0, 2));
      f5->setSquare(2, 1, cpyF4->getSquare(0, 1));
      f5->setSquare(2, 2, cpyF4->getSquare(0, 0));
      // Rotation partielle de F6
      f6->setSquare(2, 0, cpyF2->getSquare(2, 0));
      f6->setSquare(2, 1, cpyF2->getSquare(2, 1));
      f6->setSquare(2, 2, cpyF2->getSquare(2, 2));
    break;
  }
}

// Rotation partielle du cube vers la droite sur l'axe Z
void CubeModel::rotatePartialToRightOnZ() {
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // Rotation de F1
      f1->setSquare(0, 2, cpyF4->getSquare(0, 2));
      f1->setSquare(1, 2, cpyF4->getSquare(1, 2));
      f1->setSquare(2, 2, cpyF4->getSquare(2, 2));
      // Rotation de F2
      f2->setSquare(0, 2, cpyF1->getSquare(0, 2));
      f2->setSquare(1, 2, cpyF1->getSquare(1, 2));
      f2->setSquare(2, 2, cpyF1->getSquare(2, 2));
      // Rotation de F3
      f3->setSquare(0, 2, cpyF2->getSquare(0, 2));
      f3->setSquare(1, 2, cpyF2->getSquare(1, 2));
      f3->setSquare(2, 2, cpyF2->getSquare(2, 2));
      // Rotation de F4
      f4->setSquare(0, 2, cpyF3->getSquare(0, 2));
      f4->setSquare(1, 2, cpyF3->getSquare(1, 2));
      f4->setSquare(2, 2, cpyF3->getSquare(2, 2));
      // Rotation de F6
      rotateWayAntiHoraire(f6, cpyF6);
    break;
    case 2: // Rotation de la partie centrale
      // Rotation de F1
      f1->setSquare(0, 1, cpyF4->getSquare(0, 1));
      f1->setSquare(1, 1, cpyF4->getSquare(1, 1));
      f1->setSquare(2, 1, cpyF4->getSquare(2, 1));
      // Rotation de F2
      f2->setSquare(0, 1, cpyF1->getSquare(0, 1));
      f2->setSquare(1, 1, cpyF1->getSquare(1, 1));
      f2->setSquare(2, 1, cpyF1->getSquare(2, 1));
      // Rotation de F3
      f3->setSquare(0, 1, cpyF2->getSquare(0, 1));
      f3->setSquare(1, 1, cpyF2->getSquare(1, 1));
      f3->setSquare(2, 1, cpyF2->getSquare(2, 1));
      // Rotation de F4
      f4->setSquare(0, 1, cpyF3->getSquare(0, 1));
      f4->setSquare(1, 1, cpyF3->getSquare(1, 1));
      f4->setSquare(2, 1, cpyF3->getSquare(2, 1));
    break;
    case 3: // Rotation de la partie inférieure
      // Rotation de F1
      f1->setSquare(0, 0, cpyF4->getSquare(0, 0));
      f1->setSquare(1, 0, cpyF4->getSquare(1, 0));
      f1->setSquare(2, 0, cpyF4->getSquare(2, 0));
      // Rotation de F2
      f2->setSquare(0, 0, cpyF1->getSquare(0, 0));
      f2->setSquare(1, 0, cpyF1->getSquare(1, 0));
      f2->setSquare(2, 0, cpyF1->getSquare(2, 0));
      // Rotation de F3
      f3->setSquare(0, 0, cpyF2->getSquare(0, 0));
      f3->setSquare(1, 0, cpyF2->getSquare(1, 0));
      f3->setSquare(2, 0, cpyF2->getSquare(2, 0));
      // Rotation de F4
      f4->setSquare(0, 0, cpyF3->getSquare(0, 0));
      f4->setSquare(1, 0, cpyF3->getSquare(1, 0));
      f4->setSquare(2, 0, cpyF3->getSquare(2, 0));
      // Rotation de F5
      rotateWayHoraire(f5, cpyF5);
    break;
  }
}

// Rotation de la face dans le sens anti-horaire
void CubeModel::rotateWayAntiHoraire(FaceModel *face, FaceModel *cpyFace) {
  face->changeAllSquare(cpyFace->getSquare(0,2), cpyFace->getSquare(1,2), cpyFace->getSquare(2,2), cpyFace->getSquare(0,1), cpyFace->getSquare(1,1), cpyFace->getSquare(2,1), cpyFace->getSquare(0,0), cpyFace->getSquare(1,0), cpyFace->getSquare(2,0));
}

// Rotation de la face dans le sens horaire
void CubeModel::rotateWayHoraire(FaceModel *face, FaceModel *cpyFace) {
  face->changeAllSquare(cpyFace->getSquare(2,0), cpyFace->getSquare(1,0), cpyFace->getSquare(0,0), cpyFace->getSquare(2,1), cpyFace->getSquare(1,1), cpyFace->getSquare(0,1), cpyFace->getSquare(2,2), cpyFace->getSquare(1,2), cpyFace->getSquare(0,2));
}

// Mélanger le cube
void CubeModel::mix(int const& nbMove) {
  for(int i = 0 ; i < nbMove ; i++) {
    axeRotation = random(1, 4);
    indexPartialMove = random(1, 4);
    if(random(0,2) == 0) {
      rotatePartialToLeft();
    } else {
      rotatePartialToRight();
    }
  }
}

// Contrôler si la partie est finie
bool CubeModel::checkIfEnd() {
  if(f1->isFinish()) {
    if(f2->isFinish()) {
      if(f3->isFinish()) {
        if(f4->isFinish()) {
          if(f5->isFinish()) {
            return f6->isFinish();
          }
        }
      }
    }
  }
  return false;
}

// Copie de chacune des faces
void CubeModel::cloneCube() {
  cpyF1 = new FaceModel(*f1);
  cpyF2 = new FaceModel(*f2);
  cpyF3 = new FaceModel(*f3);
  cpyF4 = new FaceModel(*f4);
  cpyF5 = new FaceModel(*f5);
  cpyF6 = new FaceModel(*f6);
}

// Détruire les copies des faces
void CubeModel::uncloneCube() {
  delete cpyF1;
  delete cpyF2;
  delete cpyF3;
  delete cpyF4;
  delete cpyF5;
  delete cpyF6;
}

int CubeModel::getAxeRotation() const {
  return axeRotation;
}

int CubeModel::getIndexPartialMove() const {
  return indexPartialMove;
}

bool CubeModel::getRotateCube() const {
  return rotateCube;
}

bool CubeModel::getRotatePartialCube() const {
  return rotatePartialCube;
}

// Récupérer la face de droite
FaceModel* CubeModel::getFaceX() const {
  return f2;
}

// Récupérer la face de dessus
FaceModel* CubeModel::getFaceY() const {
  return f1;
}

// Récupérer la face de gauche
FaceModel* CubeModel::getFaceZ() const {
  return f5;
}

void CubeModel::setRotateCube(bool isRotateCube) {
  rotateCube = isRotateCube;
}

void CubeModel::setRotatePartialCube(bool isRotatePartialCube) {
  rotatePartialCube = isRotatePartialCube;
}


// author: chris-scientist
// created at: 27/04/2018
// updated at: 05/07/2018

#include "CubeController.h"

// Initialiser le contrôleur
CubeController::CubeController(CubeModel *aModel, CubeView *aView) : model(aModel), view(aView), startGame(true) {
  
}

// Détruire le contrôleur
CubeController::~CubeController() {
  delete model;
  delete view;
}

// Dessiner le cube
void CubeController::paint() const {
  view->paint(model->getFaceX(), model->getFaceY(), model->getFaceZ(), model->getAxeRotation(), model->getIndexPartialMove(), model->getRotateCube(), model->getRotatePartialCube());
}

void CubeController::changeToRotateCube(bool isRotateCube) {
  model->setRotateCube(isRotateCube);
}

void CubeController::changeToRotatePartialCube(bool isRotatePartialCube) {
  model->setRotatePartialCube(isRotatePartialCube);
}

void CubeController::changeAxeRotation() const {
  model->changeAxeRotation();
}

void CubeController::changeIndexPartialMove(bool const& isIncrement) {
  model->changeIndexPartialMove(isIncrement);
}

void CubeController::rotateCubeToLeft() const {
  model->rotateToLeft();
}

void CubeController::rotateCubeToRight() const {
  model->rotateToRight();
}

void CubeController::rotatePartialToLeft() const {
  model->rotatePartialToLeft();
}

void CubeController::rotatePartialToRight() const {
  model->rotatePartialToRight();
}

void CubeController::resetAxeRotation() const {
  model->resetAxeRotation();
}

void CubeController::resetIndexPartialMove() const {
  model->resetIndexPartialMove();
}

void CubeController::initIndexPartialMove() const {
  model->initIndexPartialMove();
}

bool CubeController::haveToRotateCube() const {
  return model->getRotateCube();
}

bool CubeController::haveToRotatePartialCube() const {
  return model->getRotatePartialCube();
}

// Contrôler si le cube est fini
bool CubeController::cubeIsFinished() const {
  return model->checkIfEnd();
}

bool CubeController::getStartGame() const {
  return startGame;
}

void CubeController::setStartGame(bool start) {
  startGame = start;
}

void CubeController::mixCube(const int& level) {
  // réinitialisation du cube
  delete model;
  model = new CubeModel();
  
  // mélanger le cube
  model->mix(level);
  
  // réinitialisation axes rotations
  resetAxeRotation();
  resetIndexPartialMove();
}


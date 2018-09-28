// author: chris-scientist
// created at: 23/04/2018
// updated at: 05/05/2018

#ifndef CUBECONTROLLER
#define CUBECONTROLLER

#include "CubeModel.h"
#include "CubeView.h"

class CubeController {
  private:
    CubeModel *model;
    CubeView *view;
    bool startGame;
  public:
    CubeController(CubeModel *aModel, CubeView *aView);
    ~CubeController();
    void paint() const;
    void changeToRotateCube(bool isRotateCube);
    void changeToRotatePartialCube(bool isRotatePartialCube);
    void changeAxeRotation() const;
    void changeIndexPartialMove(bool const& isIncrement);
    void rotateCubeToLeft() const;
    void rotateCubeToRight() const;
    void rotatePartialToLeft() const;
    void rotatePartialToRight() const;
    void resetAxeRotation() const;
    void resetIndexPartialMove() const;
    void initIndexPartialMove() const;
    bool haveToRotateCube() const;
    bool haveToRotatePartialCube() const;
    bool cubeIsFinished() const;
    bool getStartGame() const;
    void setStartGame(bool start);
    void mixCube(int const& level);
};

#endif

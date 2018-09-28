// author: chris-scientist
// created at: 27/04/2018
// updated at: 10/06/2018

#ifndef CUBEMODEL
#define CUBEMODEL

#include <Gamebuino-Meta.h>

#include "FaceModel.h"
#include "EColor.h"

class CubeModel {
  private:
    /*
     *    f1
     * f5 f2 f6
     *    f3
     *    f4
     */
     // Faces du cube
    FaceModel *f1;
    FaceModel *f2;
    FaceModel *f3;
    FaceModel *f4;
    FaceModel *f5;
    FaceModel *f6;
    // Copies des faces (utilisées pour toutes les rotations complètes ou partielles du cube)
    FaceModel *cpyF1;
    FaceModel *cpyF2;
    FaceModel *cpyF3;
    FaceModel *cpyF4;
    FaceModel *cpyF5;
    FaceModel *cpyF6;
    // Axe de rotation
    int axeRotation;
    // Indice de la "demi" face à tourner
    int indexPartialMove;
    // Indique si une rotation du cube est active
    bool rotateCube;
    // Indique si une rotation partielle du cube est active
    bool rotatePartialCube;
    // ------------------------------------------------------------------------------------
    // Méthodes privées
    void rotateToLeftOnX();
    void rotateToLeftOnY();
    void rotateToLeftOnZ();
    void rotateToRightOnX();
    void rotateToRightOnY();
    void rotateToRightOnZ();
    void rotatePartialToLeftOnX();
    void rotatePartialToLeftOnY();
    void rotatePartialToLeftOnZ();
    void rotatePartialToRightOnX();
    void rotatePartialToRightOnY();
    void rotatePartialToRightOnZ();
    void rotateWayAntiHoraire(FaceModel *face, FaceModel *cpyFace);
    void rotateWayHoraire(FaceModel *face, FaceModel *cpyFace);
    void cloneCube();
    void uncloneCube();
  public:
    // ------------------------------------------------------------------------------------
    // Méthodes publiques
    CubeModel();
    ~CubeModel();
    void changeAxeRotation();
    void resetAxeRotation();
    void changeIndexPartialMove(bool const& isIncrement);
    void resetIndexPartialMove();
    void initIndexPartialMove();
    void rotateToLeft();
    void rotateToRight();
    void rotatePartialToLeft();
    void rotatePartialToRight();
    void mix(int const& nbMove);
    bool checkIfEnd();
    int getAxeRotation() const;
    int getIndexPartialMove() const;
    bool getRotateCube() const;
    bool getRotatePartialCube() const;
    FaceModel* getFaceX() const;
    FaceModel* getFaceY() const;
    FaceModel* getFaceZ() const;
    void setRotateCube(bool isRotateCube);
    void setRotatePartialCube(bool isRotatePartialCube);
};

#endif

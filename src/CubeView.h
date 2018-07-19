// author: chris-scientist
// created at: 27/04/2018
// updated at: 05/05/2018

#ifndef CUBEVIEW
#define CUBEVIEW

#include <Gamebuino-Meta.h>

#include "EColor.h"
#include "FaceModel.h"

class CubeView {
  private:
    void drawSquareX(int const& x, int const& y, EColor const& aColor) const;
    void drawFaceX(FaceModel *const xFace) const;
    void drawSquareY(int const& x, int const& y, EColor const& aColor) const;
    void drawFaceY(FaceModel *const yFace) const;
    void drawSquareZ(int const& x, int const& y, EColor const& aColor) const;
    void drawFaceZ(FaceModel *const zFace) const;
    void drawRotationX() const;
    void drawRotationY() const;
    void drawRotationZ() const;
    void drawPartialRotationX(int const& indexPartialMove) const;
    void drawPartialRotationY(int const& indexPartialMove) const;
    void drawPartialRotationZ(int const& indexPartialMove) const;
    void changeColor(EColor const& aColor) const;
  public:
    void paint(FaceModel *const xFace, FaceModel *const yFace, FaceModel *const zFace, int const& axeRotation, int const& indexPartialMove, bool const& isRotateCube, bool const& isRotatePartialCube) const;
};

#endif

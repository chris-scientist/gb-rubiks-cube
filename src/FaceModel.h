// author: chris-scientist
// created at: 27/04/2018
// updated at: 10/06/2018
// description : représente une face du cube

#ifndef FACEMODEL
#define FACEMODEL

#include "EColor.h"

class FaceModel {
  private:
    EColor face[3][3];
  public:
    FaceModel(EColor aColor);
    FaceModel(EColor a, EColor b, EColor c, EColor d, EColor e, EColor f, EColor g, EColor h, EColor i);
    FaceModel(FaceModel const& aFace);
    bool isFinish();
    EColor getSquare(int const& l, int const& c) const;
    void setSquare(int const& l, int const& c, EColor const& color);
    void changeAllSquare(EColor a, EColor b, EColor c, EColor d, EColor e, EColor f, EColor g, EColor h, EColor i);
};

#endif

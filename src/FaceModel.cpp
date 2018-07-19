// author: chris-scientist
// created at: 27/04/2018
// updated at: 10/06/2018

#include "FaceModel.h"

// Initialisation d'une face mono-chrome
FaceModel::FaceModel(EColor aColor) {
  for(int l=0 ; l<3 ; l++) {
    for(int c=0 ; c<3 ; c++) {
      face[l][c] = aColor;
    }
  }
}

// Initialisation d'une face à différente couleur
FaceModel::FaceModel(EColor a, EColor b, EColor c, EColor d, EColor e, EColor f, EColor g, EColor h, EColor i) {
  face[0][0] = a;
  face[0][1] = b;
  face[0][2] = c;
  face[1][0] = d;
  face[1][1] = e;
  face[1][2] = f;
  face[2][0] = g;
  face[2][1] = h;
  face[2][2] = i;
}

FaceModel::FaceModel(FaceModel const& aFace) {
  for(int l=0 ; l<3 ; l++) {
    for(int c=0 ; c<3 ; c++) {
      face[l][c] = aFace.getSquare(l, c);
    }
  }
}

// Contrôler si la face est finie
bool FaceModel::isFinish() {
  return face[0][0] == face[0][1] && face[0][0] == face[0][2] &&
    face[0][0] == face[1][0] && face[0][0] == face[1][1] && face[0][0] == face[1][2] &&
    face[0][0] == face[2][0] && face[0][0] == face[2][1] && face[0][0] == face[2][2];
}

// Récupérer la couleur d'un carré de la face
EColor FaceModel::getSquare(int const& l, int const& c) const {
  if((l>=0 && l<3) && (c>=0 && c<3)) {
    return face[l][c];
  }
  return EColor::NAC;
}

void FaceModel::setSquare(int const& l, int const& c, EColor const& color) {
  face[l][c] = color;
}

// Changer les couleurs de toutes la face
void FaceModel::changeAllSquare(EColor a, EColor b, EColor c, EColor d, EColor e, EColor f, EColor g, EColor h, EColor i) {
  face[0][0] = a;
  face[0][1] = b;
  face[0][2] = c;
  face[1][0] = d;
  face[1][1] = e;
  face[1][2] = f;
  face[2][0] = g;
  face[2][1] = h;
  face[2][2] = i;
}


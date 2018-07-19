// author: chris-scientist
// created at: 27/04/2018
// updated at: 05/05/2018

#include "CubeView.h"

// Dessiner les 3 faces visibles du cube
void CubeView::paint(FaceModel *const xFace, FaceModel *const yFace, FaceModel *const zFace, int const& axeRotation, int const& indexPartialMove, bool const& isRotateCube, bool const& isRotatePartialCube) const {
  // Dessiner les faces visibles du cube
  drawFaceX(xFace);
  drawFaceY(yFace);
  drawFaceZ(zFace);
  
  if(isRotateCube) {
    // Dessiner les flèches de rotation du cube
    switch(axeRotation) {
      case 1: // Rotation autour de l'axe Z
        drawRotationZ();
      break;
      case 2: // Rotation autour de l'axe X
        drawRotationX();
      break;
      case 3: // Rotation autour de l'axe Y
        drawRotationY();
      break;
    }
  } else if(isRotatePartialCube) {
    // Dessiner les flèches de rotation partielle du cube
    switch(axeRotation) {
      case 1: // Rotation autour de l'axe Z
        drawPartialRotationZ(indexPartialMove);
      break;
      case 2: // Rotation autour de l'axe X
        drawPartialRotationX(indexPartialMove);
      break;
      case 3: // Rotation autour de l'axe Y
        drawPartialRotationY(indexPartialMove);
      break;
    }
  }
}

// Modifier la couleur
void CubeView::changeColor(EColor const& aColor) const {
  Color color = BLACK;
  if(aColor == EColor::White) {
    color = WHITE;
  } else if(aColor == EColor::Blue) {
    color = BLUE;
  } else if(aColor == EColor::Red) {
    color = RED;
  } else if(aColor == EColor::Orange) {
    color = ORANGE;
  } else if(aColor == EColor::Green) {
    color = GREEN;
  } else if(aColor == EColor::Yellow) {
    color = YELLOW;
  }
  gb.display.setColor(color);
}

// Dessiner la face de droite
void CubeView::drawFaceX(FaceModel *const xFace) const {
  for(int c=0 ; c<3 ; c++) {
    int x = 41;
    x += (6*c);
    for(int l=0 ; l<3 ; l++) {
      int y = 38;
      y -= (5*c);
      y += (6*l);
      EColor color = xFace->getSquare(l, c);
      drawSquareX(x, y, color);
    }
  }
}

// Dessiner un carré de la face de droite
void CubeView::drawSquareX(int const& x, int const& y, EColor const& aColor) const {
  changeColor(aColor);
  gb.display.fillRect(x, y, 1, 4);
  gb.display.fillRect(x+1, y-1, 1, 4);
  gb.display.fillRect(x+2, y-2, 1, 4);
  gb.display.fillRect(x+3, y-3, 1, 4);
}

// Dessiner la face de dessus
void CubeView::drawFaceY(FaceModel *const yFace) const {
  for(int l=0 ; l<3 ; l++) {
    for(int c=0 ; c<3 ; c++) {
      int y = 22;
      int x = 24;
      x += (l+c)*6;
      if(l!=c) {
        if(l==0) {
          y -= c*5;
        } else if(c==0) {
          y += l*5;
        } else if(l==2) {
          y += 5;
        } else if(c==2) {
          y -= 5;
        }
      }
      EColor color = yFace->getSquare(l, c);
      drawSquareY(x, y, color);
    }
  }
}

// Dessiner un carré de la face de dessus
void CubeView::drawSquareY(int const& x, int const& y, EColor const& aColor) const {
  changeColor(aColor);
  gb.display.fillRect(x, y, 1, 1);
  gb.display.fillRect(x+1, y-1, 1, 3);
  gb.display.fillRect(x+2, y-2, 1, 5);
  gb.display.fillRect(x+3, y-3, 2, 7);
  gb.display.fillRect(x+5, y-2, 1, 5);
  gb.display.fillRect(x+6, y-1, 1, 3);
  gb.display.fillRect(x+7, y, 1, 1);
}

// Dessiner la face de gauche
void CubeView::drawFaceZ(FaceModel *const zFace) const {
  for(int l=0 ; l<3 ; l++) {
    for(int c=0 ; c<3 ; c++) {
      int x = 23;
      int y = 25;
      x += (c*6);
      y += (6*l);
      y += (5*c);
      EColor color = zFace->getSquare(l, c);
      drawSquareZ(x, y, color);
    }
  }
}

// Dessiner un carré de la face de gauche
void CubeView::drawSquareZ(int const& x, int const& y, EColor const& aColor) const {
  changeColor(aColor);
  gb.display.fillRect(x, y, 1, 4);
  gb.display.fillRect(x+1, y+1, 1, 4);
  gb.display.fillRect(x+2, y+2, 1, 4);
  gb.display.fillRect(x+3, y+3, 1, 4);
}

// Dessiner les flèches indiquant une rotation sur l'axe X
void CubeView::drawRotationX() const {
  gb.display.setColor(BROWN);
  // flèche haute
  gb.display.fillTriangle(43, 7, 56, 7, 56, 20);
  // flèche basse
  gb.display.fillTriangle(23, 43, 36, 56, 23, 56);
}

// Dessiner les flèches indiquant une rotation sur l'axe Y
void CubeView::drawRotationY() const {
  gb.display.setColor(BROWN);
  // flèche droite
  gb.display.fillTriangle(59, 24, 66, 31, 59, 38);
  // flèche gauche
  gb.display.fillTriangle(20, 25, 20, 39, 13, 32);
}

// Dessiner les flèches indiquant une rotation sur l'axe Z
void CubeView::drawRotationZ() const {
  gb.display.setColor(BROWN);
  // flèche haute
  gb.display.fillTriangle(23, 20, 23, 6, 37, 6);
  // flèche basse
  gb.display.fillTriangle(43, 55, 56, 42, 56, 55);
}

// Dessiner les flèches indiquant une rotation partielle sur l'axe X
void CubeView::drawPartialRotationX(int const& indexPartialMove) const {
  gb.display.setColor(BROWN);
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // flèche haute
      gb.display.fillTriangle(42, 7, 45, 7, 45, 10);
      // flèche basse
      gb.display.fillTriangle(22, 43, 22, 46, 25, 46);
    break;
    case 2: // Rotation de la partie centrale
      // flèche haute
      gb.display.fillTriangle(48, 12, 51, 12, 51, 15);
      // flèche basse
      gb.display.fillTriangle(28, 48, 28, 51, 31, 51);
    break;
    case 3: // Rotation de la partie inférieure
      // flèche haute
      gb.display.fillTriangle(54, 18, 57, 18, 57, 21);
      // flèche basse
      gb.display.fillTriangle(34, 53, 34, 56, 37, 56);
    break;
  }
}

// Dessiner les flèches indiquant une rotation partielle sur l'axe Y
void CubeView::drawPartialRotationY(int const& indexPartialMove) const {
  gb.display.setColor(BROWN);
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // flèche droite
      gb.display.fillTriangle(59, 23, 59, 27, 61, 25);
      // flèche gauche
      gb.display.fillTriangle(20, 24, 20, 28, 18, 26);
    break;
    case 2: // Rotation de la partie centrale
      // flèche droite
      gb.display.fillTriangle(59, 29, 59, 33, 61, 31);
      // flèche gauche
      gb.display.fillTriangle(20, 30, 20, 34, 18, 32);
    break;
    case 3: // Rotation de la partie inférieure
      // flèche droite
      gb.display.fillTriangle(59, 35, 59, 39, 61, 37);
      // flèche gauche
      gb.display.fillTriangle(20, 36, 20, 40, 18, 38);
    break;
  }
}

// Dessiner les flèches indiquant une rotation partielle sur l'axe Z
void CubeView::drawPartialRotationZ(int const& indexPartialMove) const {
  gb.display.setColor(BROWN);
  switch(indexPartialMove) {
    case 1: // Rotation de la partie supérieure
      // flèche haute
      gb.display.fillTriangle(37, 7, 34, 7, 34, 10);
      // flèche basse
      gb.display.fillTriangle(57, 42, 57, 45, 54, 45);
    break;
    case 2: // Rotation de la partie centrale
      // flèche haute
      gb.display.fillTriangle(31, 12, 28, 12, 28, 15);
      // flèche basse
      gb.display.fillTriangle(51, 47, 51, 50, 48, 50);
    break;
    case 3: // Rotation de la partie inférieure
      // flèche haute
      gb.display.fillTriangle(26, 17, 23, 17, 23, 20);
      // flèche basse
      gb.display.fillTriangle(45, 53, 45, 56, 42, 56);
    break;
  }
}



#include "ChessObject.h"

ChessObject::ChessObject(char c, string s) {
  color = c;
  label = s;
}

char ChessObject::getColor() {
  return color;
}

char ChessObject::getLabel() {
  return label;
}

void ChessObject::setColor(char c) {
  color = c;
}

void ChessObject::setLabel(string s) {
  label = s;
}

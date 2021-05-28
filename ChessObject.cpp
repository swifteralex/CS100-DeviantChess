#include "ChessObject.h"

ChessObject::ChessObject(char c, const std::string& s) {
  color = c;
  label = s;
}

char ChessObject::getColor() const {
  return color;
}

std::string ChessObject::getLabel() const {
  return label;
}

void ChessObject::setColor(char c) {
  color = c;
}

void ChessObject::setLabel(const std::string& s) {
  label = s;
}
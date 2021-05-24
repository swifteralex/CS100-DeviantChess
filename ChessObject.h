#ifndef CHESSOBJECT_H
#define CHESSOBJECT_H

#include <string>

class ChessObject {
  
protected:
  char color;
  std::string label;

public:
  ChessObject(char,const std::string&);

  char getColor() const;
  
  std::string getLabel() const;
  
  void setColor(char);

  void setLabel(const std::string&);
};

#endif

#ifndef CHESSOBJECT_H
#define CHESSOBJECT_H


class ChessObject {
  
private:
  char color;
  string label;

public:
  ChessObject(char,string);

  char getColor();
  
  string getLabel();
  
  void setColor(char);

  void setLabel(string);


#endif

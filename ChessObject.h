#ifndef CHESSOBJECT_H
#define CHESSOBJECT_H


class ChessObject {
private:
char color;
char pieceName;

public:
ChessObject(char);

char getColor() const;

char getPieceName() const;


#endif

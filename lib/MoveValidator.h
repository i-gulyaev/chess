#ifndef _MOVEVALIDATOR_H_
#define _MOVEVALIDATOR_H_

#include <Move.h>
#include <Board.h>
#include <Square.h>

namespace chess {
class MoveValidator
{
public:
    MoveValidator(const Board&);

    bool validate(const Move&);
    bool validate(Square, Square);

private:
    bool validateKing(Square, Square);
    bool validateQueen(Square, Square);
    bool validateBishop(Square, Square);
    bool validateRook(Square, Square);
    bool validateKnight(Square, Square);
    bool validatePawn(Square, Square);

    bool isPathFree(Square from, Square to) const;
    const Board& board;
};

} // chess

#endif /* _MOVEVALIDATOR_H_ */

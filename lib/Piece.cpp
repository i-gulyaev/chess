#include <Piece.h>
#include <Board.h>
#include <Pawn.h>

namespace chess {

PiecePtr IPiece::createPiece(char symbol, Square square)
{

    switch (symbol) {
    case 'P': return PiecePtr(new Pawn(WHITE, square));
    case 'p': return PiecePtr(new Pawn(BLACK, square));
    default :return PiecePtr(new NullPiece(WHITE, square));
    }
}

PiecePtr IPiece::createPiece(Type type, Color color, Square square)
{
    switch(type) {
    case PAWN: return PiecePtr(new Pawn(color, square));
    default :return PiecePtr(new NullPiece(color, square));
    }
}

} // chess

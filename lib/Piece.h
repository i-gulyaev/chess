#ifndef _PIECE_H_
#define _PIECE_H_

#include <cctype>

namespace chess {

enum Side
{
    WHITE,
    BLACK,
    NONE
};

enum Type
{
    KING,
    QUEEN,
    BISHOP,
    ROOK,
    KNIGHT,
    PAWN,
    INVALID
};


class Piece
{
public:
    Piece()
        : type(INVALID),
          side(NONE) {}
    Piece(Type type, Side side)
        : type(type),
          side(side) {
        toSymbol();
    }
    Piece(char symbol) {
        fromSymbol(symbol);
    }

    void fromSymbol(char symbol) {
        side = islower(symbol) ? BLACK : WHITE;
        type = symbolToType(tolower(symbol));
    }

    Type type;
    Side side;
    char symbol;

private:
    Type symbolToType(int c) {
        switch(c) {
        case 'k': return KING;
        case 'q': return QUEEN;
        case 'b': return BISHOP;
        case 'r': return ROOK;
        case 'n': return KNIGHT;
        case 'p': return PAWN;
        default: return INVALID;
        }
    }

    void toSymbol() {
        switch(type) {
        case KING: symbol = 'k'; break;
        case QUEEN: symbol = 'q'; break;
        case BISHOP: symbol = 'b'; break;
        case ROOK: symbol = 'r'; break;
        case KNIGHT: symbol = 'n'; break;
        case PAWN: symbol = 'p'; break;
        default: symbol = ' '; break;
        }
        if (side == WHITE) symbol = toupper(symbol);
    }
};


} // chess

#endif /* _PIECE_H_ */

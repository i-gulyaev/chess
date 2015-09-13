#ifndef _BOARD_H_
#define _BOARD_H_

#include <Piece.h>
#include <Move.h>

#include <memory>
#include <vector>
#include <ostream>


namespace chess {

class Board
{
public:
    Board();
    virtual ~Board();
    
    void initialize();
    void move(const Move&);
    void move(Square from, Square to);
    void removePieceAt(Square pos);
    bool pieceAt(Square pos, Piece& piece) const;
    Piece pieceAt(Square pos) const;
    bool isSquareEmpty(Square pos) const;

    void setPieceAt(Square pos, const Piece& piece);

    void toStream(std::ostream& os) const;
    void reset();


private:
    using PieceVector = std::vector<char>;
    PieceVector m_board;
};

std::ostream& operator<<(std::ostream& os, const Board& board);

} // chess

#endif /* _BOARD_H_ */

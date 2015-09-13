
#include <Board.h>

#include <utility>
#include <iostream>

namespace
{
const int BOARD_SIZE = 64;
const char EMPTY_SQUARE = ' ';
}

namespace chess {

Board::Board()
    : m_board(BOARD_SIZE, EMPTY_SQUARE)
{

}

Board::~Board()
{

}

void Board::reset()
{
    m_board.assign(BOARD_SIZE, EMPTY_SQUARE);
}

void Board::initialize()
{
    m_board.clear();
    m_board.resize(BOARD_SIZE);
    
    const char* initialPosition = 
        "RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr";
    m_board.assign(initialPosition, initialPosition+BOARD_SIZE);
}

void Board::move(const Move& m)
{
    std::swap(m_board[m.from], m_board[m.to]);
}

void Board::move(Square from, Square to)
{
    std::swap(m_board[from], m_board[to]);
}

bool Board::pieceAt(Square pos, Piece& piece) const
{
    if (m_board[pos] == EMPTY_SQUARE) return false;
    piece.fromSymbol(m_board[pos]);
    return true;
}

Piece Board::pieceAt(Square pos) const
{
    Piece piece(m_board[pos]);
    return piece;
}

void Board::setPieceAt(Square pos, const Piece& piece)
{
    m_board[pos] = piece.symbol;
}

void Board::removePieceAt(Square pos)
{
    m_board[pos] = EMPTY_SQUARE;
}

bool Board::isSquareEmpty(Square pos) const
{
    return m_board[pos] == EMPTY_SQUARE;
}

void Board::toStream(std::ostream& os) const
{
    int counter = 1;
    for (const auto& square : m_board) {
        os << square;
        if (!(counter % ROW_SIZE)) os << "\n";
        ++counter;
    }
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    board.toStream(os);
    return os;
}

} // chess 

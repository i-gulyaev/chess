
#include <MoveValidator.h>
#include <iostream>

namespace chess {

MoveValidator::MoveValidator(const Board& b)
    : board(b)
{
}

bool MoveValidator::validate(const Move& move)
{
    return validate(move.from, move.to);
}

bool MoveValidator::validate(Square from, Square to)
{
    auto piece = board.pieceAt(from);
    switch (piece.type) {
    case KING: return validateKing(from, to);
    case QUEEN: return validateQueen(from, to);
    case BISHOP: return validateBishop(from, to);
    case ROOK: return validateRook(from, to);
    case KNIGHT: return validateKnight(from, to);
    case PAWN: return validatePawn(from, to);
    default: return false;
    }
}


bool MoveValidator::validateKing(Square from, Square to)
{
    return from != to
        && !board.isSquareEmpty(from)
        && abs(SquareUtils::getRank(from) - SquareUtils::getRank(to)) <= 1
        && abs(SquareUtils::getFile(from) - SquareUtils::getFile(to)) <= 1
        && (board.isSquareEmpty(to)
            || board.pieceAt(to).side != board.pieceAt(from).side);
}

bool MoveValidator::validateQueen(Square from, Square to)
{
    return validateBishop(from, to) || validateRook(from, to);
}

bool MoveValidator::validateBishop(Square from, Square to)
{
    return from != to
        && (abs(SquareUtils::getRank(from) - SquareUtils::getRank(to))
            == abs(SquareUtils::getFile(from) - SquareUtils::getFile(to)))
        && isPathFree(from, to)
        && (board.isSquareEmpty(to) || board.pieceAt(to).side != board.pieceAt(from).side);
}

bool MoveValidator::validateRook(Square from, Square to)
{
    return from != to
        && (SquareUtils::getRank(from) == SquareUtils::getRank(to)
            || SquareUtils::getFile(from) == SquareUtils::getFile(to))
        && isPathFree(from, to)
        && (board.isSquareEmpty(to) || board.pieceAt(to).side != board.pieceAt(from).side);
}

bool MoveValidator::validateKnight(Square from, Square to)
{
    return from != to
        && ((abs(SquareUtils::getRank(from) - SquareUtils::getRank(to)) == 1
             && abs(SquareUtils::getFile(from) - SquareUtils::getFile(to)) == 2)
            || (abs(SquareUtils::getRank(from) - SquareUtils::getRank(to)) == 2
                && abs(SquareUtils::getFile(from) - SquareUtils::getFile(to)) == 1))
        && (board.isSquareEmpty(to) || board.pieceAt(to).side != board.pieceAt(from).side);
}

bool MoveValidator::validatePawn(Square from, Square to)
{
    auto currentPiece = board.pieceAt(from);
    
    auto result = false;
    if (currentPiece.side == WHITE) {
        // capture
        if (!board.isSquareEmpty(to)) {
            result =  ((SquareUtils::getRank(to) - SquareUtils::getRank(from) == 1)
                       && (abs(SquareUtils::getFile(to) - SquareUtils::getFile(from)) == 1)
                       && board.pieceAt(to).side != currentPiece.side);
        }
        else if (SquareUtils::getFile(from) == SquareUtils::getFile(to)) {
            if (to - from == ROW_SIZE) {
                result = true;
            }
            else if ((to - from == 2 * ROW_SIZE) && SquareUtils::getRank(from) == 1) {
                result = true;
            }
        }
    }
    else {
        // capture
        if (!board.isSquareEmpty(to)) {
            result =  ((SquareUtils::getRank(from) - SquareUtils::getRank(to) == 1)
                       && (abs(SquareUtils::getFile(to) - SquareUtils::getFile(from)) == 1)
                       && board.pieceAt(to).side != currentPiece.side);
        }
        else if (SquareUtils::getFile(from) == SquareUtils::getFile(to)) {
            if (from - to == ROW_SIZE) {
                result = true;
            }
            else if ((from - to == 2 * ROW_SIZE) && SquareUtils::getRank(from) == 6) {
                result = true;
            }
        }
    }
    return (to != from) && result;
}

bool MoveValidator::isPathFree(Square from, Square to) const
{
    int square = from > to ? to : from;
    int targetSquare = from > to ? from : to;

    auto summand = 0;
    // horizonatl move
    if (abs(from - to) < ROW_SIZE) {
        summand = 1;
    }
    //vertical move
    else if (SquareUtils::getFile(from) == SquareUtils::getFile(to)) {
        summand = ROW_SIZE;
    }
    // other
    else {
        summand = ROW_SIZE;
        summand += abs(square - targetSquare) % (ROW_SIZE + 1) ? -1: 1;
    }

    square += summand;
    for (; square < targetSquare; square = square + summand) {
        if (!board.isSquareEmpty(static_cast<Square>(square))) {
            return false;
        }
    }
    return true;
}

} // chess

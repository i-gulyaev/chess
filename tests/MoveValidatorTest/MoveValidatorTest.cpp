#include <QtTest/QtTest>

#include <Board.h>
#include <MoveValidator.h>

#include <iostream>

using namespace chess;

class MoveValidatorTest : public QObject
{
    Q_OBJECT

private slots:
    void validateKingMove() {
        Board board;

        board.setPieceAt(E2, Piece(KING, WHITE));
        board.setPieceAt(E3, Piece(PAWN, WHITE));
        board.setPieceAt(F3, Piece(PAWN, BLACK));

        std::cout << board;
        
        MoveValidator mv(board);
        
        QCOMPARE(mv.validate(E1, E2), false);
        QCOMPARE(mv.validate(E2, E4), false);
        QCOMPARE(mv.validate(E2, E2), false);
        
        // White pawn on E3
        QCOMPARE(mv.validate(E2, E3), false);

        QCOMPARE(mv.validate(E2, E1), true);
        QCOMPARE(mv.validate(E2, D3), true);
        QCOMPARE(mv.validate(E2, F3), true);
        QCOMPARE(mv.validate(E2, D2), true);
        QCOMPARE(mv.validate(E2, F2), true);
        QCOMPARE(mv.validate(E2, D1), true);
        QCOMPARE(mv.validate(E2, F1), true);
    }

    void validateRookMove() {
        Board board;
        board.setPieceAt(E4, Piece(ROOK, WHITE));
        board.setPieceAt(E2, Piece(PAWN, WHITE));
        board.setPieceAt(B4, Piece(PAWN, BLACK));
        std::cout << board;

        MoveValidator mv(board);

        QCOMPARE(mv.validate(E4, E2), false);
        QCOMPARE(mv.validate(E4, E1), false);
        QCOMPARE(mv.validate(E4, A4), false);
        QCOMPARE(mv.validate(E4, D3), false);
 
        QCOMPARE(mv.validate(E4, E6), true);
        QCOMPARE(mv.validate(E4, E3), true);
        QCOMPARE(mv.validate(E4, B4), true);
        QCOMPARE(mv.validate(E4, H4), true);
    }

    void validateBishopMove() {
        Board board;
        board.setPieceAt(E4, Piece(BISHOP, WHITE));
        board.setPieceAt(C2, Piece(PAWN, WHITE));
        board.setPieceAt(B7, Piece(PAWN, BLACK));
        std::cout << board;

        MoveValidator mv(board);

        QCOMPARE(mv.validate(E4, B2), false);
        QCOMPARE(mv.validate(E4, C2), false);
        QCOMPARE(mv.validate(E4, A8), false);

        QCOMPARE(mv.validate(E4, D4), false);
        QCOMPARE(mv.validate(E4, E8), false);

        QCOMPARE(mv.validate(E4, B7), true);
        QCOMPARE(mv.validate(E4, G2), true);
        QCOMPARE(mv.validate(E4, G6), true);
        QCOMPARE(mv.validate(E4, D3), true);

    }

    void validateKnightMove() {
        Board board;
        board.setPieceAt(E4, Piece(KNIGHT, WHITE));
        board.setPieceAt(D6, Piece(PAWN, WHITE));
        board.setPieceAt(G3, Piece(PAWN, BLACK));
        std::cout << board;

        MoveValidator mv(board);

        QCOMPARE(mv.validate(E4, D2), true);
        QCOMPARE(mv.validate(E4, C3), true);
        QCOMPARE(mv.validate(E4, F2), true);
        QCOMPARE(mv.validate(E4, G3), true);
        QCOMPARE(mv.validate(E4, G5), true);
        QCOMPARE(mv.validate(E4, F6), true);
        QCOMPARE(mv.validate(E4, D6), false);
        QCOMPARE(mv.validate(E4, C5), true);

        QCOMPARE(mv.validate(E4, E6), false);
        QCOMPARE(mv.validate(E4, D5), false);
    }

    void validatePawnMove() {
        Board board;
        board.setPieceAt(E2, Piece(PAWN, WHITE));
        board.setPieceAt(D3, Piece(PAWN, WHITE));
        board.setPieceAt(F3, Piece(PAWN, BLACK));
        std::cout << board;
 
        MoveValidator mv(board);
        QCOMPARE(mv.validate(E2, E3), true);
        QCOMPARE(mv.validate(E2, E4), true);
        QCOMPARE(mv.validate(E2, D3), false);
        QCOMPARE(mv.validate(E2, F3), true);

        QCOMPARE(mv.validate(E2, E1), false);
        QCOMPARE(mv.validate(D3, C4), false);
        QCOMPARE(mv.validate(E2, E5), false);
        
        board.setPieceAt(E4, Piece(PAWN, WHITE));
        board.setPieceAt(E5, Piece(PAWN, BLACK));
        QCOMPARE(mv.validate(E4, E5), false);

    }
};


QTEST_MAIN(MoveValidatorTest)
#include "MoveValidatorTest.moc"

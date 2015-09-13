#ifndef _CHESSTYPES_H_
#define _CHESSTYPES_H_

#include <QtQml>

#include <Piece.h>

class PieceType : public QObject
{
    Q_OBJECT

public:
    
    enum Type {
        PAWN = chess::PAWN,
        ROOK = chess::ROOK,
        KNIGHT = chess::KNIGHT,
        BISHOP = chess::BISHOP,
        QUEEN = chess::QUEEN,
        KING = chess::KING
    };

    Q_ENUMS(Type)

    static void declareQml() {
        qmlRegisterType<PieceType>("PieceType", 1, 0, "PieceType");
    }
};

class PieceColor : public QObject
{
    Q_OBJECT
public:
    
    enum Color {
        WHITE = chess::WHITE,
        BLACK = chess::BLACK
    };
    Q_ENUMS(Color)

    static void declareQml() {
        qmlRegisterType<PieceColor>("PieceColor", 1, 0, "PieceColor");
    }
    
};


#endif /* _CHESSTYPES_H_ */

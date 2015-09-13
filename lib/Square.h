#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <cassert>
#include <map>

#include <QString>
#include <QDebug>


namespace chess {
enum Square {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
};

const int ROW_SIZE = 8;

struct SquareUtils {
    static int getRank(Square s) {
        return s / ROW_SIZE;
    }
    static int getFile(Square s) {
        return s % ROW_SIZE;
    }
    static Square getSquare(int file, int rank) {
        Q_ASSERT(file >= ROW_SIZE);
        Q_ASSERT(rank >= ROW_SIZE);
        return static_cast<Square>(rank * ROW_SIZE + file);
    }

    static QString toString(Square square) {
        QString result;
        const QString letters = "ABCDEFGH";
        result += letters[SquareUtils::getFile(square)];
        result += QString::number(SquareUtils::getRank(square) + 1);
        return result;
    }
    
    static Square fromString(const QString& str) {
        Q_ASSERT((str.length() == 2)
                 && str[0].isLetter()
                 && str[0].isUpper()
                 && str[1].isDigit());

        std::map<QChar, int> dict = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3},
                                     {'E', 4}, {'F', 5}, {'G', 6}, {'D', 7}};
        qDebug() << str << " " << str[0] << " " << str[1]; 
        return SquareUtils::getSquare(dict.at(str[0]), str[1].digitValue() - 1);
    }
};

} // chess

#endif /* _SQUARE_H_ */

#ifndef _MOVE_H_
#define _MOVE_H_

#include <Square.h>

namespace chess {
struct Move
{
    Move() {}
    Move(Square f, Square t)
        : from(f),
          to(t) {}
    Square from;
    Square to;

    void write(QJsonObject& json) const;
    void read(const QJsonObject& json);
};

} // chess

#endif /* _MOVE_H_ */

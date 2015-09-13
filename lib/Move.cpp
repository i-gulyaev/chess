#include <Move.h>
#include <Square.h>
#include <QJsonObject>


namespace chess {

void Move::write(QJsonObject& json) const
{
    json["from"] = SquareUtils::toString(from);
    json["to"] = SquareUtils::toString(to);
}


void Move::read(const QJsonObject& json)
{
    from = SquareUtils::fromString(json["from"].toString());
    to = SquareUtils::fromString(json["to"].toString());
}

} // chess

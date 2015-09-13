#include <GameEngine.h>

#include <QString>
#include <QFile>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


namespace
{

bool isSquare(int pos)
{
    return pos >= chess::A1 && pos <= chess::H8;
}

enum {
    INVALID_POSITION = -1
};

}

namespace chess {

GameEngine::GameEngine()
    : board(),
      moveValidator(board),
      currentTurn(WHITE),
      history(),
      fromPosition(INVALID_POSITION)
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::startGame()
{
    board.initialize();
    history.clear();
}

void GameEngine::stopGame()
{
    board.reset();
}

bool GameEngine::saveGame(const QString& filename) const
{
    QFile saveFile(QUrl(filename).toLocalFile());
    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << filename;
        return false;
    }

    QJsonArray moves;
    for (const auto& move : history) {
        QJsonObject obj;
        move.write(obj);
        moves.append(obj);
    }
    QJsonObject gameObject;
    gameObject["moves"] = moves;
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
    return true;
}

bool GameEngine::loadGame(const QString& filename)
{
    QFile loadFile(QUrl(filename).toLocalFile());
    if (!loadFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << filename;
        return false;
    }

    QByteArray data = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(data));

    history.clear();
    
    QJsonArray moves = loadDoc.object()["moves"].toArray();
    for (const auto& item : moves) {
        Move move;
        move.read(item.toObject());
        history.push_back(move);
    }

    loadFile.close();
    return true;
}

bool GameEngine::move(const Move& move)
{
    if (moveValidator.validate(move)) {
        // capture
        if (!board.isSquareEmpty(move.to)) {
            board.removePieceAt(move.to);
        }
        board.move(move);
        history.push_back(move);
        alternateTurn();
        return true;
    }
    return false;
}

bool GameEngine::select(int from)
{
    if (isSquare(from)
        && !board.isSquareEmpty(static_cast<Square>(from))
        && (board.pieceAt(static_cast<Square>(from)).side == currentTurn)) {
        fromPosition = from;
        return true;
    }
    else {
        return false;
    }
}

bool GameEngine::moveTo(int to)
{
    return isSquare(static_cast<Square>(to)) && move(Move(static_cast<Square>(fromPosition), static_cast<Square>(to)));
}

void GameEngine::alternateTurn()
{
    currentTurn = 
        currentTurn == Side::WHITE ? Side::BLACK : Side::WHITE;
}

Side GameEngine::getCurrentTurn()
{
    return currentTurn;
}

void GameEngine::nextMove()
{
    
}

void GameEngine::prevMove()
{

}

Moves GameEngine::getMoves() const
{
    return history;
}

} // chess

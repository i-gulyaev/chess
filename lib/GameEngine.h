#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include <Board.h>
#include <MoveValidator.h>


class QString;

namespace chess {

using Moves = std::vector<Move>;

class GameEngine
{
public:
    GameEngine();
    virtual ~GameEngine();
                             
public:
    
    bool select(int);
    bool moveTo(int);
    bool move(const Move&);

    void startGame();
    void stopGame();
    bool saveGame(const QString& filename) const;
    bool loadGame(const QString& filename);

    void nextMove();
    void prevMove();

    Side getCurrentTurn();

    Moves getMoves() const;

private:
    void alternateTurn();

    Board board;
    MoveValidator moveValidator;
    Side currentTurn;
    Moves history;
    int fromPosition;
    
};

} // chess

#endif /* _GAMEENGINE_H_ */

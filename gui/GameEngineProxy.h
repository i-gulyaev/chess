#ifndef _GAMEENGINEPROXY_H_
#define _GAMEENGINEPROXY_H_


#include <QtQml>
#include <GameEngine.h>


class GameEngineProxy : public QObject
{
    Q_OBJECT
public:

    Q_INVOKABLE int startGame();
    Q_INVOKABLE int stopGame();
    Q_INVOKABLE bool loadGame(const QString& fileName);
    Q_INVOKABLE bool saveGame(const QString& fileName);
    Q_INVOKABLE int prevMove();
    Q_INVOKABLE int nextMove();
    Q_INVOKABLE bool select(int position, int type, int color);
    Q_INVOKABLE bool moveTo(int position);


private:

    chess::GameEngine gameEngine;
};

#endif /* _GAMEENGINEPROXY_H_ */

#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <QtQml>

class GameState : public QObject
{
    Q_OBJECT

public:

    enum State {
        IDLE,
        PLAY,
        VIEW
    };

    Q_ENUMS(State)

    static void declareQml() {
        qmlRegisterType<GameState>("GameState", 1, 0, "GameState");
    }
};



#endif /* _GAMESTATE_H_ */

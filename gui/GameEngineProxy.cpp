#include <GameEngineProxy.h>
#include <GameState.h>

#include <QDebug>

int GameEngineProxy::startGame()
{
    qDebug() << __PRETTY_FUNCTION__ << "\n";
    gameEngine.startGame();
    return 0;
}

int GameEngineProxy::stopGame()
{
    qDebug() << __PRETTY_FUNCTION__ << "\n";
    gameEngine.stopGame();
    return 0;
}


bool GameEngineProxy::loadGame(const QString& fileName)
{
    return gameEngine.loadGame(fileName);
}

bool GameEngineProxy::saveGame(const QString& fileName)
{
    return gameEngine.saveGame(fileName);
}

int GameEngineProxy::prevMove()
{
    qDebug() << __PRETTY_FUNCTION__ << "\n";
    return 0;
}

int GameEngineProxy::nextMove()
{
    qDebug() << __PRETTY_FUNCTION__ << "\n";
    return 0;
}


bool GameEngineProxy::select(int position, int type, int color)
{
    qDebug() << __PRETTY_FUNCTION__ << "\n";
    qDebug() << "select pos: " << position << " type: " << type << "color: " << color << "\n";
    
    return gameEngine.select(position);
        
}

bool GameEngineProxy::moveTo(int position)
{
    qDebug() << __PRETTY_FUNCTION__ << "\n";
    qDebug() << "move to pos: " << position << "\n";
    
    return gameEngine.moveTo(position);
}

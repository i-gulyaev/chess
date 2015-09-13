#include <QtTest/QtTest>

#include <GameEngine.h>

class GameEngineTest : public QObject
{
    Q_OBJECT

private slots:
    void testSaveGame() {
        using namespace chess;
        GameEngine ge;
        ge.startGame();
        ge.move(Move(E2, E4));
        ge.move(Move(E7, E5));
        ge.move(Move(G1, F3));
        ge.saveGame("file:///tmp/game.save");
        ge.loadGame("file:///tmp/game.save");
        auto moves = ge.getMoves();

        QCOMPARE(moves[0].from, E2);
        QCOMPARE(moves[0].to, E4);
        QCOMPARE(moves[1].from, E7);
        QCOMPARE(moves[1].to, E5);
        QCOMPARE(moves[2].from, G1);
        QCOMPARE(moves[2].to, F3);
    }
};


QTEST_MAIN(GameEngineTest)
#include "GameEngineTest.moc"

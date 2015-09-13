#include <QGuiApplication>
#include <QQuickView>

#include <GameState.h>
#include <GameEngineProxy.h>
#include <ChessTypes.h>


int main(int argc, char *argv[]) {
     QGuiApplication app(argc, argv);
     QQuickView view;

     GameState::declareQml();
     PieceType::declareQml();
     PieceColor::declareQml();

     GameEngineProxy game;

     view.rootContext()->setContextProperty("gameEngine", &game);
     view.setSource(QUrl::fromLocalFile("main.qml"));
     view.show();

     return app.exec();
 }

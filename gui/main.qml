import QtQuick 2.0
import QtQuick.Controls 1.0
import GameState 1.0

Item {
    width: 600
    height: 700
     
    ChessBoard {
        id: chessBoard
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: bottomBar.top
        }
    }
    BottomBar {
        id: bottomBar
    }
    
}

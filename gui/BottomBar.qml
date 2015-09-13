import QtQuick 2.2
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.1
import GameState 1.0

ToolBar {
    id: bottomBar
    anchors {
        left: parent.left
        right: parent.right
        bottom: parent.bottom
    }
    height: buttonRow.height * 1.2

    RowLayout {
        id: buttonRow
        spacing: 6
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width

        Button {
            id: startStopButton
            text: "Start Game"
            anchors.verticalCenter: parent.verticalCenter
            Layout.fillWidth: true
            onClicked: {
                if (chessBoard.gameState != GameState.PLAY) {
                    console.log("start game")
                    chessBoard.startGame()
                    text = "Stop Game"
                    saveLoadButton.text = "Save Game"
                }
                else if (chessBoard.gameState == GameState.PLAY) {
                    console.log("game stopped")
                    chessBoard.stopGame()
                    text = "Start Game"
                    saveLoadButton.text = "Load Game"
                }
            }
        }

        Button {
            id: prevButton
            text: "Prev move"
            enabled: chessBoard.gameState === GameState.VIEW
            anchors.verticalCenter: parent.verticalCenter
            Layout.fillWidth: true
            onClicked: {
                chessBoard.prevMove();
            }
        }

        Button {
            id: nextButton
            text: "Next move"
            enabled: chessBoard.gameState === GameState.VIEW
            anchors.verticalCenter: parent.verticalCenter
            Layout.fillWidth: true
            onClicked: {
                chessBoard.nextMove()
            }
        }

        Button {
            id: saveLoadButton
            text: "Load Game"
            anchors.verticalCenter: parent.verticalCenter
            Layout.fillWidth: true
            onClicked: {
                if (chessBoard.gameState != GameState.PLAY) {
                    console.log("Load Game")
                    loadFileDialog.open()
                }
                else if (chessBoard.gameState == GameState.PLAY) {
                    console.log("Save game")
                    saveFileDialog.open()
                }
            }
        }
    }

    FileDialog {
        id: saveFileDialog
        title: "Save game"
        selectMultiple: false
        selectFolder: false
        onAccepted: {
            chessBoard.saveGame(saveFileDialog.fileUrls)
        }
    }

    FileDialog {
        id: loadFileDialog
        title: "Load game"
        selectMultiple: false
        selectFolder: false
        selectExisting: true
        onAccepted: {
            chessBoard.loadGame(loadFileDialog.fileUrls)
        }
    }
}

import QtQuick 2.0
import PieceType 1.0
import PieceColor 1.0

Rectangle {
    id: chessPiece

    property int pieceType: PieceType.PAWN
    property int pieceColor: PieceColor.WHITE
    property int position: 0

    width: chessBoard.width / 8
    height: chessBoard.height / 8
    color: "transparent"
    
    Image {
        id: pieceImage
        anchors.fill: parent
        width: parent.width
        height: parent.height
    }
    
    MouseArea {
        anchors.fill: parent
        onClicked: {
            chessBoardGrid.selected(chessPiece)
        }
    }

    function showBorder() {
        chessPiece.border.width = 4
        chessPiece.border.color = 'black'
    }

    function hideBorder() {
        chessPiece.border.width = 0
        chessPiece.border.color = ''
    }

    function setImage(color, type) {
        console.log("set image")
        var prefix = "../res/"
        var suffix = ".png"
        
        var colorStr = color === PieceColor.WHITE ? "white" : "black"
        var typeStr = "pawn"
        switch (type) {
        case PieceType.PAWN: typeStr = "pawn"; break
        case PieceType.ROOK: typeStr = "rook"; break
        case PieceType.KNIGHT: typeStr = "knight"; break
        case PieceType.BISHOP: typeStr = "bishop"; break
        case PieceType.QUEEN: typeStr = "queen"; break
        case PieceType.KING: typeStr = "king"; break
        }
        pieceImage.source = prefix + colorStr + "_" + typeStr + suffix
    }

    function setPosition(pos) {
        console.log("pos: " + pos)
        position = pos
        chessPiece.x = chessBoardCells.itemAt(pos).x
        chessPiece.y = chessBoardCells.itemAt(pos).y
        
        console.log("position x: " + chessPiece.x + ", y: " + chessPiece.y)
    }

    function initialize(pos, color, type) {
        pieceType = type
        pieceColor = color
        setPosition(pos)
        setImage(color, type)
    }

    function hide() {
        z = -1
    }
}

import QtQuick 2.0
import GameState 1.0
import PieceType 1.0
import PieceColor 1.0

Rectangle {
    id: chessBoard
    
    property int gameState: GameState.IDLE
    property var selectedPiece: null
    property var pieces: []

    Grid {
        id: chessBoardGrid
        columns: 8
        rows: 8
        width: parent.width

        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            top: parent.top
        }

        signal clicked(int square)
        signal selected(var piece)

        Repeater {
            id: chessBoardCells
            model: 64
            Rectangle {
                width: chessBoard.width / 8
                height: chessBoard.height / 8
                color: ((Math.floor(index / 8) % 2) === 0)
                    ?
                    (index % 2  === 1 ? "#D18B47" : "#FFCE9E")
                    :
                (index % 2  === 0 ? "#D18B47" : "#FFCE9E")
                
                MouseArea {
                    anchors.fill: parent
                    onClicked: chessBoardGrid.clicked(index)
                }
            }
        }

        onClicked: {
            if (selectedPiece != null) {
                if (gameEngine.moveTo(square)) {
                    selectedPiece.hideBorder()
                    selectedPiece.setPosition(square)

                }
            }
            selectedPiece = null
        }

        onSelected: {
            if ((selectedPiece != null) && (selectedPiece.pieceColor != piece.pieceColor)) {
                // possible capture
                if (gameEngine.moveTo(piece.position)) {
                    console.log("capture " + piece.pieceType + " at pos " + piece.position)
                    selectedPiece.hideBorder()
                    selectedPiece.setPosition(piece.position)
                    piece.hide()
                    selectedPiece = null
                }
            }
            else if (gameEngine.select(piece.position, piece.pieceType, piece.pieceColor)) {
                piece.showBorder()
                if (selectedPiece != null) selectedPiece.hideBorder()
                selectedPiece = piece
            }
        }
    }

    function createPiece(pos, color, type) {
        var component = Qt.createComponent("ChessPiece.qml")
        var pieceObj = component.createObject(chessBoard)
        pieceObj.initialize(pos, color, type)
        return pieceObj;
        
    }

    function initialize() {
        console.log("Initialize board")
        pieces.push(createPiece(0, PieceColor.WHITE, PieceType.ROOK))
        pieces.push(createPiece(1, PieceColor.WHITE, PieceType.KNIGHT))
        pieces.push(createPiece(2, PieceColor.WHITE, PieceType.BISHOP))
        pieces.push(createPiece(3, PieceColor.WHITE, PieceType.QUEEN))
        pieces.push(createPiece(4, PieceColor.WHITE, PieceType.KING))
        pieces.push(createPiece(5, PieceColor.WHITE, PieceType.BISHOP))
        pieces.push(createPiece(6, PieceColor.WHITE, PieceType.KNIGHT))
        pieces.push(createPiece(7, PieceColor.WHITE, PieceType.ROOK))

        for (var i = 8; i < 16; i++) {
            pieces.push(createPiece(i, PieceColor.WHITE, PieceType.PAWN))
        }

        for (var i = 48; i < 56; i++) {
            pieces.push(createPiece(i, PieceColor.BLACK, PieceType.PAWN))
        }

        pieces.push(createPiece(56, PieceColor.BLACK, PieceType.ROOK))
        pieces.push(createPiece(57, PieceColor.BLACK, PieceType.KNIGHT))
        pieces.push(createPiece(58, PieceColor.BLACK, PieceType.BISHOP))
        pieces.push(createPiece(59, PieceColor.BLACK, PieceType.QUEEN))
        pieces.push(createPiece(60, PieceColor.BLACK, PieceType.KING))
        pieces.push(createPiece(61, PieceColor.BLACK, PieceType.BISHOP))
        pieces.push(createPiece(62, PieceColor.BLACK, PieceType.KNIGHT))
        pieces.push(createPiece(63, PieceColor.BLACK, PieceType.ROOK))

        selectedPiece = null
    }

    function startGame() {
        initialize()
        gameState = GameState.PLAY
        gameEngine.startGame()
    }
    
    function stopGame() {
        for (var i = 0; i < pieces.length; i++) {
            if (pieces[i] != null) {
                pieces[i].destroy()
                pieces[i] = null
            }
        }
        gameState = GameState.IDLE
        gameEngine.stopGame()
    }

    function loadGame(filename) {
        initialize()
        gameState = GameState.VIEW
        gameEngine.loadGame(filename)
    }
    
    function saveGame(filename) {
        gameEngine.saveGame(filename)
    }

    function nextMove() {
        console.log("next move")
        gameEngine.nextMove()
    }

    function prevMove() {
        console.log("prev move")
        gameEngine.prevMove()
    }
}


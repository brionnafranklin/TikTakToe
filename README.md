| Brionna Franklin|
| :---              |
| s198017          |
| Assessment 3 - TikTakToe|
| TikTakToe Documentation |

## I. Requirements

1. **Description of Problem**: For this assessment item, you are tasked with making a console-based tic-tac-toe game.

    - **Name**: TikTakToe

    - **Problem Statement**: This is a two-player game on a 3x3 board. One player uses ‘X’ tokens while the other uses ‘O’. The players take turns selecting one of the empty 3x3 squares to place their piece. The game continues until one player has 3 tokens in a row (vertical, horizontal, or diagonal), in which case they are the winner, or there are no empty spaces left which results in a draw.
    The Game must be implemented using 2-dimensional arrays, but you are otherwise free to implement it however you wish.

    - **Problem Specifications**:

    - Your game must be console based (text only)
    - Your game must be two-player (PVP)
    - If you would like to make an AI player, this should be added done as an additional feature (an AI player is not a requirement)
    - The 3x3 game board should be represented internally as a 2D array.
    - When a player places an ‘x’ or ‘o’ on the board, the player’s move should be stored in the corresponding location in the 2D array.
    - If you want to change the size of the game board, this should be implemented as an additional game mode (a 3x3 game board must be implemented).
    - Each move must be input via the command line and validated.
    - An invalid move or incorrect data should result in an appropriate error message.
    - Your game must execute without crashing. Upon shutdown all memory must be correctly deallocated (no memory leaks).
    - This point may not require direct action if you are only using the language features you have learnt up to this point. Please consult with your teacher if you have concerns.

2. **Input Information**:

    - pressing 1-7 on the key pad allows the current player to place their token in the coorisponding tile on the board.

3. **Output Information**:

    - **Board**: prints the board to the console and displays all tiles.
    - **Player Input Message**: outputs a message that asks the current player for input.
    - **Win**: when a player wins, a message is displayed that states which player won.
    - **loose**: When the board no longer has any empty tiles, a message is displayed that states both players lost.

## II. Design

1. _System Architecture_
|
|:-----------
Game Function Diagram
|
![User Interface gif](https://i.imgur.com/6Koh2Ai.png)

2. Object Information

    **File**: TikTakToe.cpp

        Description: Starts when the program runs

            Operations:

                -Name: main
                Description: main function; Starts when the program runs
                Type: void
                Visibility: private

    **File**: Game.h

        Description: declares everything within the game class

            Attributes:

                -Name: Game
                Description: declares the default constructer for game
                Type: constructer
                Visibility: public

                -Name: Game
                Description: declares the default deconstructer for game
                Type: deconstructer
                Visibility: public

                -Name: startup
                Description: declares the default deconstructer for game
                Type: bool
                Visibility: public

                -Name: draw
                Description: declares the draw function
                Type: void
                Visibility: public

                -Name: update
                Description: declares the update function
                Type: void
                Visibility: public

                -Name: isGameOver
                Description: declares the isGameOver bool
                Type: bool
                Visibility: public

                -Name: getInput
                Description: declares the getInput bool
                Type: bool
                Visibility: public

                -Name: playerNumController
                Description: declares the playerNumController bool
                Type: bool
                Visibility: public

                -Name: checkForWin
                Description: declares the checkForWin bool
                Type: bool
                Visibility: public

                -Name: checkForTie
                Description: declares the checkForTie bool
                Type: bool
                Visibility: public

                -Name: initializeBoard
                Description: declares the initializeBoard function
                Type: void
                Visibility: private

                -Name: drawBoard
                Description: declares the drawBoard function
                Type: void
                Visibility: private

                -Name: m_gameOver
                Description: declares the m_gameOver bool
                Type: bool
                Visibility: private

                -Name: m_board[BOARD_HEIGHT][BOARD_WIDTH]
                Description: declares m_board (the variable used for the board) as a constant character
                Type: const char*
                Visibility: private

                -Name: m_playerNum
                Description: declares the m_playerNum bool
                Type: bool
                Visibility: private

    **File**: Game.cpp

        Description: where all functions are defined

            Operations:

                -Name: Game
                Description: default constructer for game
                Type: constucter
                Visibility: public

                -Name: Game
                Description: default deconstructer for game
                Type: deconstructer
                Visibility: public

                -Name: startUp
                Description: runs once when the game starts
                Type: bool
                Visibility: public

                -Name: draw
                Description: clears the outdated board and replaces it with one with the correct tiles
                Type: void
                Visibility: public

                -Name: update
                Description: starts a new turn and waits before updating
                Type: void
                Visibility: public

                -Name: initializeBoard
                Description: draws the board the first time
                Type: void
                Visibility: private

                -Name: drawBoard
                Description: draws each tile of the board
                Type: void
                Visibility: private

                -Name: isGameOver
                Description: draws each tile of the board
                Type: bool
                Visibility: public

                -Name: getInput
                Description: takes a player's input and places their tile in the coorisponding cooridinent. then determines if there is a winner or a tie after
                Type: bool
                Visibility: public

                -Name: playerNumController
                Description: changes which player's turn it is
                Type: bool
                Visibility: public

                -Name: checkForWin
                Description: checks to see if a player has 3 connecting tokens
                Type: bool
                Visibility: public

                -Name: checkForTie
                Description: checks to see if the game can continue or if the board is full
                Type: bool
                Visibility: public

    **File**: GameDefines.h

        Description: declares constant varibles

            Attributes:

                -Name: INDENT
                Description: declares INDENT as a constant character
                Type: const char* const
                Visibility: private

                -Name: EMPTY_TILE
                Description: declares EMPTY_TILE as a constant character
                Type: const char* const
                Visibility: private

                -Name: PLAYER1_TILE
                Description: declares PLAYER1_TILE as a constant character
                Type: const char* const
                Visibility: private

                -Name: PLAYER2_TILE
                Description: declares PLAYER2_TILE as a constant character
                Type: const char* const
                Visibility: private

                -Name: BOARD_WIDTH
                Description: declares BOARD_WIDTH as a constant integer
                Type: const int
                Visibility: private

                -Name: BOARD_HEIGHT
                Description: declares BOARD_HEIGHT as a constant integer
                Type: const int
                Visibility: private

                -Name: EMPTY
                Description: declares EMPTY as a constant integer
                Type: const int
                Visibility: private

                -Name: PLAYER1
                Description: declares PLAYER1 as a constant integer
                Type: const int
                Visibility: private

                -Name: PLAYER2
                Description: declares PLAYER2 as a constant integer
                Type: const int
                Visibility: private

    **File**: Point2D.h

        Description: creates a point using two inegers: x and y

            Attributes:

                -Name: Point2D
                Description: creates a point using two inegers: x and y
                Type: structs
                Visibility: private

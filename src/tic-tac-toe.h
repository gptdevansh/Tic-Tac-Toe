// Header for Game logic
// tic-tac-toe.h

#include<iostream>
#include<vector>
#ifndef TIC-TAC-TOE_H
#define TIC-TAC-TOE_H

class TicTacToe {
private:
    // 2D vector to represent the game board
    std::vector<std::vector<char>> board;
    char currentPlayer; // Tracks the current player ('X' or 'O')

public:
    // Constructor to initialize the game
    TicTacToe() {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' ')); // Initialize the board with spaces
        currentPlayer = 'X'; // Set the starting player to 'X'
    }

    // Function to display the current state of the board
    void displayBoard() {
        std::cout << "Current Board:\n";
        for (const auto& row : board) {
            for (const auto& cell : row) {
                std::cout << cell << '|'; // Print each cell followed by a '|'
            }
            std::cout << "\n-----\n"; // Separator for rows
        }
    }

    // Function to place a mark on the board
    bool placeMark(int row, int col) {
        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            return false; // Invalid move
        }
        board[row][col] = currentPlayer; // Place the current player's mark
        return true; // Move successful
    }

    // Function to check if the current player has won
    bool checkWin() {
        // Check all rows and columns for a win
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true; // Winning condition met
            }
        }
        // Check both diagonals for a win
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true; // Winning condition met
        }
        return false; // No win
    }

    // Function to switch players
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Alternate between 'X' and 'O'
    }

    // Main game loop
    void playGame() {
        int row, col; // Variables to hold the player's input
        for (int turns = 0; turns < 9; ++turns) { // Allow up to 9 turns (maximum moves)
            displayBoard(); // Display the current board
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col; // Get input from the player
            if (placeMark(row, col)) { // Attempt to place the mark
                if (checkWin()) { // Check for a win
                    displayBoard(); // Show final board
                    std::cout << "Player " << currentPlayer << " wins!\n"; // Announce winner
                    return; // End game
                }
                switchPlayer(); // Switch to the other player
            }
        }
        displayBoard(); // Show final board if no winner
        std::cout << "It's a draw!\n"; // Announce draw
    }
};
#endif 
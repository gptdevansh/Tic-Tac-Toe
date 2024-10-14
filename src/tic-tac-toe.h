// Header for Game logic
// tic_tac_toe.h

#include<iostream>
#include<vector>
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

// Initialize Board
void initialize_board(std::vector<char> &board){
    board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
}

// Display Board
void display_board(const std::vector<char>& board){
    std::cout<<" "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<std::endl;
    std::cout<<"---|---|---"<<std::endl;
    std::cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<std::endl;
    std::cout<<"---|---|---"<<std::endl;
    std::cout<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<std::endl;
}

// Check For win
bool check_win(const std::vector<char> &board, char player){
    // win condition
    const int win_conditions[8][3] = {
        {0,1,2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}    
        };

    for(const auto &condition : win_conditions){
        if(board[condition[0]] == player && 
           board[condition[1]] == player &&
           board[condition[2]] == player){
            return true;
        }
    }   
    return false; 
}

// Check for draw
bool check_draw(const std::vector<char> &board){
    for(char cell : board){
        if(cell != 'X' && cell != '0'){
            return false;
        }
    }
    return true;
}

#endif 
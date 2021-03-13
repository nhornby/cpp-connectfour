//  state.cpp
//  Created by Nolan Hornby on 3/7/21.

#include "state.hpp"

// --------------------------------------------------
//             Board State Definition
// --------------------------------------------------

State::State(int w, int h, int c) {
    WIDTH = w;
    HEIGHT = h;
    CONNECT = c;
    board = new int[WIDTH * HEIGHT];
    fill = new int[WIDTH];
    board_reset();
}
State::~State() {
    delete [] board;
    board = nullptr;
    delete [] fill;
    fill = nullptr;
}

bool State::board_push(int column, int player) {
    if(column <= 0 || column > WIDTH) { return false; }
    if(fill[column - 1] == HEIGHT) { return false; }
    if(player == 0) { return false; }
    
    board[WIDTH * (HEIGHT - fill[column - 1] - 1) + column - 1] = player;
    fill[column - 1]++;
    past_moves.push_back(column);
    
    return true;
}
bool State::board_pop() {
    if(past_moves.size() == 0) { return false; }
    int column = past_moves[past_moves.size() - 1];
    
    board[WIDTH * (HEIGHT - fill[column - 1]) + column - 1] = 0;
    fill[column - 1]--;
    past_moves.pop_back();
    
    return true;
}
void State::board_output() const {
    for(int i=0;i<WIDTH*HEIGHT;i++) {
        if(i%WIDTH == 0) { std::cout << "\n" << LEFTBUFFER; }
            if(board[i] == 0) { std::cout << EMPTYSPACE << " "; }
        else if(board[i] == 1) { std::cout << P1 << " "; }
        else if(board[i] == 2) { std::cout << P2 << " "; }
    }
    std::cout << "\n" << LEFTBUFFER;
    for(int i=0;i<WIDTH;i++) { std::cout << "--"; }
    std::cout << "\n" << LEFTBUFFER;
    for(int i=0;i<WIDTH;i++) { std::cout << (i+1) << " "; }
    std::cout << "\n" << LEFTBUFFER << std::endl;
}
int State::board_ninarow() const {
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            int elem = board[WIDTH*row + col];
            if(elem == 0) {continue;}
            
            if(col <= WIDTH-CONNECT)
            {
                for(int i=1;i<CONNECT;i++) {
                    if(elem != board[WIDTH*row + col + i]) { break; }
                    if(i == CONNECT-1) {return elem;}
                }
            }
            if(row <= HEIGHT-CONNECT)
            {
                for(int i=1;i<CONNECT;i++) {
                    if(elem != board[WIDTH*(row+i) + col]) { break; }
                    if(i == CONNECT-1) {return elem;}
                }
            }
            if(row <= HEIGHT-CONNECT && col <= WIDTH-CONNECT) {
                for(int i=1;i<CONNECT;i++) {
                    if(elem != board[WIDTH*(row+i) + col+i]) { break; }
                    if(i == CONNECT-1) {return elem;}
                }
            }
            if(row >= CONNECT-1 && col <= WIDTH-CONNECT) {
                for(int i=1;i<CONNECT;i++) {
                    if(elem != board[WIDTH*(row-i) + col+i]) { break; }
                    if(i == CONNECT-1) {return elem;}
                }
            }
        }
    }
    return 0;
}
int State::board_column_fill(int column) const {
    if(column <= 0 || column > WIDTH) { return HEIGHT; }
    
    return fill[column - 1];
}
bool State::board_full() const {
    for(int i=1;i<=WIDTH;i++) {
        if(board_column_fill(i) < HEIGHT) { return false; }
    }
    return true;
}
void State::board_reset() {
    for(int i=0;i<WIDTH;i++) { fill[i] = 0; }
    for(int i=0;i<WIDTH*HEIGHT;i++) { board[i] = 0;}
}

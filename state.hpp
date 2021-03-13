//  state.hpp
//  Created by Nolan Hornby on 3/7/21.

#ifndef state_hpp
#define state_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

// --------------------------------------------------
//             Game and Output Details
// --------------------------------------------------

#define LEFTBUFFER "              "
#define EMPTYSPACE "."
#define P1 "\u25cb"
#define P2 "\u25cf"

// --------------------------------------------------
//             Board State Declaration
// --------------------------------------------------

class State {
private:
    int WIDTH;
    int HEIGHT;
    int CONNECT;
public:
    State(int w, int h, int c);
    ~State();
    
    bool board_push(int column, int player);
    bool board_pop();
    void board_output() const;
    int board_ninarow() const;
    int board_column_fill(int column) const;
    bool board_full() const;
    void board_reset();
    
    int width() const { return WIDTH; }
    int height() const { return HEIGHT; }
    int connect() const { return CONNECT; }
private:
    std::vector<int> past_moves;
    int * fill;
    int * board;
};

#endif /* state_hpp */

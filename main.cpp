//
//  main.cpp
//  c-c4
//
//  Created by Nolan Hornby on 3/7/21.
//

#include "player.hpp"
#include "state.hpp"
#include "handler.hpp"

int main(int argc, char * argv[])
{
    // Init
    srand(static_cast<unsigned int>(time(NULL)));
    Handler h(argc, argv);
    State s(h.columns, h.rows, h.connect);
    Player * p1 = Player_generator("Player 1", h.p1strat, 1);
    Player * p2 = Player_generator("Player 2", h.p2strat, 2);
    Player * c = p1;
    
    // Game Loop
    s.board_output();
    while(s.board_ninarow() == 0 && !s.board_full()) {
        int move = c->get_move(s);
        if(s.board_push(move, c->get_number())) { (c->get_number() == 1) ? c = p2 : c = p1; }
        s.board_output();
    }
    
    
    // Display Winner
    if(s.board_ninarow() != 0) {
        (c->get_number() == 1) ? c = p2 : c = p1;
        std::cout << LEFTBUFFER << "Game Over.\n";
        std::cout << LEFTBUFFER << "Player " << c->get_name() << " wins.\n\n\n";
    } else {
        std::cout << LEFTBUFFER << "Game Over.\n";
        std::cout << LEFTBUFFER << "Draw.\n\n\n";
    }
    
    
    delete p1;
    delete p2;
}

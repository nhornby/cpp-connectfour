//
//  player.cpp
//  c-c4
//
//  Created by Nolan Hornby on 3/8/21.
//

#include "player.hpp"

// --------------------------------------------------
//              Human Player Definition
// --------------------------------------------------

HumanPlayer::HumanPlayer(const std::string & name_in, int n_in) : name(name_in), number(n_in) {}
int HumanPlayer::get_move(State & s) const {
    std::cout << "Player " << name << ", enter a column: ";
    int column;
    std::cin >> column;
    std::cout << "\n";
    return column;
}

// --------------------------------------------------
//              Random Player Definition
// --------------------------------------------------

RandomPlayer::RandomPlayer(const std::string & name_in, int n_in) : name(name_in), number(n_in) {}
int RandomPlayer::get_move(State & s) const { return rand() % s.width() + 1; }

// --------------------------------------------------
//                AI Player Definition
// --------------------------------------------------

AIPlayer::AIPlayer(const std::string & name_in, int n_in) : name(name_in), number(n_in) {
    opposite = (number == 1) ? 2 : 1;
}
int AIPlayer::get_move(State & s) const {
    
    // Initialize best moves and best score
    std::vector<int> bestCols;
    double maxScore = -1000000;
    
    // For each possible column
    for(int i=1;i<=s.width();i++) {
        if(s.board_column_fill(i) == s.height()) { continue; }
        
        // Try the move
        s.board_push(i, number);
        double score = minimax(s, false, -1000000, 1000000, LOOKAHEAD);
        s.board_pop();
        
        // If it's equal to the previous best, add it to best moves
        // If it's better than the previous best, clear the previous moves before adding it
        if(score >= maxScore) {
            if(score > maxScore) {
                maxScore = score;
                bestCols.clear();
            }
            bestCols.push_back(i);
        }
    }
    
    // Return a random move from "best moves"
    if(bestCols.size() > 1) { return bestCols[rand() % bestCols.size()]; }
    else { return bestCols[0]; }
}
double AIPlayer::minimax(State & s, bool isMax, double alpha, double beta, int depth) const {
    if(depth == 0) { return 0; }
    
    if(s.board_ninarow() == number) { return isMax ? -10*depth : 10*depth; }
    if(s.board_ninarow() == opposite) { return isMax ? -10*depth : 10*depth; }
    
    if(!isMax) {
        for(int i=1;i<=s.width();i++) {
            if(s.board_column_fill(i) >= s.height()) { continue; }
            
            s.board_push(i, opposite);
            beta = std::min(beta, minimax(s, !isMax, alpha, beta, depth-1));
            s.board_pop();
            if(beta <= alpha) { return beta; }
        }
        return beta;
    }
    else {
        for(int i=1;i<=s.width();i++) {
            if(s.board_column_fill(i) >= s.height()) { continue; }
            
            s.board_push(i, number);
            alpha = std::max(alpha, minimax(s, !isMax, alpha, beta, depth-1));
            s.board_pop();
            if(beta <= alpha) { return alpha; }
        }
        return alpha;
    }
}

// --------------------------------------------------
//                  Helper Definition
// --------------------------------------------------

Player * Player_generator(const std::string & name, const std::string & strategy, int number) {
    if(strategy == "Human") { return new HumanPlayer(name, number); }
    if(strategy == "Random") { return new RandomPlayer(name, number); }
    if(strategy == "AI") { return new AIPlayer(name, number); }
    
    std::cout << "Unknown player strategy." << std::endl;
    return nullptr;
}

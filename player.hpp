//
//  player.hpp
//  c-c4
//
//  Created by Nolan Hornby on 3/8/21.
//

#ifndef player_hpp
#define player_hpp

#include <string>
#include <iostream>
#include <cmath>
#include "state.hpp"

// --------------------------------------------------
//                  Player Details
// --------------------------------------------------

#define LOOKAHEAD 10

// --------------------------------------------------
//                Player Declaration
// --------------------------------------------------

class Player {
public:
    virtual const std::string & get_name() const = 0;
    virtual int get_number() const = 0;
    virtual int get_move(State & s) const = 0;
    virtual ~Player() {}
};

// --------------------------------------------------
//             Human Player Declaration
// --------------------------------------------------

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string & name_in, int n_in);
    const std::string & get_name() const { return name; }
    int get_number() const { return number; }
    int get_move(State & s) const;
private:
    std::string name;
    int number;
};

// --------------------------------------------------
//             Random Player Declaration
// --------------------------------------------------

class RandomPlayer : public Player {
public:
    RandomPlayer(const std::string & name_in, int n_in);
    const std::string & get_name() const { return name; }
    int get_number() const { return number; }
    int get_move(State & s) const;
private:
    std::string name;
    int number;
};

// --------------------------------------------------
//                AI Player Declaration
// --------------------------------------------------

class AIPlayer : public Player {
public:
    AIPlayer(const std::string & name_in, int n_in);
    const std::string & get_name() const { return name; }
    int get_number() const { return number; }
    int get_move(State & s) const;
private:
    std::string name;
    int number;
private:
    double minimax(State & s, bool max, double a, double b, int depth) const;
    int opposite;       // enemy number
};

// --------------------------------------------------
//                  Helper Functions
// --------------------------------------------------

Player * Player_generator(const std::string & name, const std::string & strategy, int number);

#endif /* player_hpp */

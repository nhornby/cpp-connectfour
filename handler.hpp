//
//  handler.hpp
//  c-c4
//
//  Created by Nolan Hornby on 3/13/21.
//

#ifndef handler_hpp
#define handler_hpp

#include <stdio.h>
#include <iostream>
#include <getopt.h>
#include <string>

// --------------------------------------------------
//             Arg Handler Declaration
// --------------------------------------------------

class Handler {
public:
    Handler(int argc, char *argv[]);
private:
    void handler_assign(int argc, char *argv[]);
    void handler_help(const char * prog) const;
public:
    int columns = 7;
    int rows = 6;
    int connect = 4;
    std::string p1strat = "Human";
    std::string p2strat = "Human";
};

#endif /* handler_hpp */

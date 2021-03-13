//
//  handler.cpp
//  c-c4
//
//  Created by Nolan Hornby on 3/13/21.
//

#include "handler.hpp"

// --------------------------------------------------
//               Arg Handler Definition
// --------------------------------------------------

Handler::Handler(int argc, char *argv[]) {
    handler_assign(argc, argv);
}
void Handler::handler_assign(int argc, char *argv[]) {
    opterr = false;
    int choice;
    int option_index = 0;
    option long_options[] = {
        {"rows", required_argument, nullptr, 'r'},
        {"columns", required_argument, nullptr, 'c'},
        {"connect", required_argument, nullptr, 'n'},
        {"player1", required_argument, nullptr, '1'},
        {"player2", required_argument, nullptr, '2'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, '\0'}};
    
    while ((choice = getopt_long(argc, argv, "r:c:n:1:2:h", long_options, &option_index)) != -1) {
             if(choice == 'r') { rows = atoi(optarg); }
        else if(choice == 'c') { columns = atoi(optarg); }
        else if(choice == 'n') { connect = atoi(optarg); }
        else if(choice == '1') { p1strat = std::string(optarg); }
        else if(choice == '2') { p2strat = std::string(optarg); }
        else if(choice == 'h') { handler_help(argv[0]); exit(0); }
        else {
            std::cout << "Unknown command line option." << std::endl;
            exit(1);
        }
    }
}
void Handler::handler_help(const char * prog) const {
    std::cout << "Usage: " << prog << " -r|-c|-n|-1|-2|-h" << std::endl;
    
    std::cout << "Arguments:" << std::endl;
    std::cout << "  --rows [int]         |  -r" << std::endl;
    std::cout << "  --columns [int]      |  -c" << std::endl;
    std::cout << "  --connect [int]      |  -n" << std::endl;
    std::cout << "  --player1 [string]   |  -1" << std::endl;
    std::cout << "  --player2 [string]   |  -2" << std::endl;
    std::cout << "  --help               |  -h" << std::endl;
}

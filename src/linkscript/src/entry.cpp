#include "entry.h"


void run(Runtime& runtime , const std::string& source, bool isDebug) {
    try {
        Lexer lexer(source);
        auto tokens = lexer.tokenize();
        Parser parser(tokens);
        auto program = parser.parse(); 
        
        if (isDebug) {
            std::cout << "\n--- DEBUG: AST STRUCTURE ---\n";
            program->print();
            std::cout << "----------------------------\n";
        }

        runtime.execute(std::move(program)); 

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

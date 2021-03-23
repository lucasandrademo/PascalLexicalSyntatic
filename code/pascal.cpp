//Alunos Lucas Machado de Oliveira Andrade e Bruno Rocha Ribeiro

#include <cstdio>
#include <iostream>
#include "lexical/LexicalAnalysis.h"
#include "syntatic/SyntaticAnalysis.h"

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "Usage: " << argv[0] << " [pascal program]" << std::endl;
        exit(1);
    }

    try{
        Lexeme lex;
        LexicalAnalysis l(argv[1]);
        SyntaticAnalysis s(l);

        s.start();

    } catch(const std::string& error) {
        std::cerr << error << std::endl;
    }

    return 0;
}

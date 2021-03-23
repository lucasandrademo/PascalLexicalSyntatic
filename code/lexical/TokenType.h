//Alunos Lucas Machado de Oliveira Andrade e Bruno Rocha Ribeiro

#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H


#include <string>

enum TokenType {
    // to do virgula

    // Specials
	TT_UNEXPECTED_EOF = -2,
	TT_INVALID_TOKEN  = -1,
	TT_END_OF_FILE    =  0,

	// Symbols
    TT_COMA,          // ,
	TT_SEMICOLON,     // ;
	TT_ASSIGN,        // :=
    TT_DOT,
    TT_TWODOT,

	// Logic operators
	TT_EQUAL,         // =
	TT_NOT_EQUAL,     // <>
	TT_LOWER,         // <
	TT_LOWER_EQUAL,   // <=
	TT_GREATER,       // >
	TT_GREATER_EQUAL, // >=
    TT_NOT,           // not

    // Conectores
    TT_AND,           // and
    TT_OR,            // or

	// Arithmetic operators
	TT_ADD,           // +
	TT_SUB,           // -
	TT_MUL,           // *
	TT_DIV,           // /
	TT_MOD,           // %

	// Keywords
	TT_ATRIBUICAO,    // atribuicão
    TT_BEGIN,
    TT_END,
    TT_UNTIL,
    TT_THEN,
    TT_PROGRAM,
    TT_IF,            // if
    TT_ELSE,
    TT_CASE,          // case
	TT_WHILE,         // while
    TT_REPEAT,        // repetir
    TT_FOR,           // for
    TT_WRITE,         // imprimir na tela
    TT_WRITELN,       // imprimir na tela
    TT_READLN,        // ler do teclado
    TT_DO,
    TT_TO,
    TT_STARTPAR,
    TT_ENDPAR,
    TT_ID,
    TT_OF,

	// Others
	TT_CONST,         // constante
    TT_LIT_REAL,      // literal real
    TT_LIT_STRING,    // literal String
    TT_LIT_INTEIRO,   // literal inteiro
	TT_VAR            // variable
};

inline std::string tt2str(enum TokenType type) {

    switch (type){

        // Specials
	    case TT_UNEXPECTED_EOF:
            return "UNEXPECTED_EOF";
	    case TT_INVALID_TOKEN:
            return "INVALID_TOKEN";
	    case TT_END_OF_FILE:
            return "END_OF_FILE";

	    // Symbols
        case TT_COMA:
            return "COMA";
	    case TT_SEMICOLON:     // ;
            return "SEMICOLON";
	    case TT_ASSIGN:        // :=
            return "ASSIGN";
        case TT_DOT:
            return "DOT";
        case TT_TWODOT:
            return "TWODOT";

	    // Logic operators
	    case TT_EQUAL:         // =
            return "EQUAL";
	    case TT_NOT_EQUAL:     // <>
            return "NOT_EQUAL";
	    case TT_LOWER:         // <
            return "LOWER";
	    case TT_LOWER_EQUAL:   // <=
            return "LOWER_EQUAL";
    	case TT_GREATER:       // >
            return "GREATER";
	    case TT_GREATER_EQUAL: // >=
            return "GREATER_EQUAL";
        case TT_NOT:           // not
            return "NOT";

        // Conectores
        case TT_AND:           // and
            return "AND";
        case TT_OR:            // or
            return "OR";

	    // Arithmetic operators
	    case TT_ADD:           // +
            return "ADD";
	    case TT_SUB:           // -
            return "SUB";
	    case TT_MUL:           // *
            return "MUL";
	    case TT_DIV:           // /
            return "DIV";
	    case TT_MOD:           // %
            return "MOD";

	    // Keywords
	    case TT_ATRIBUICAO:    // atribuicão
            return "ATRIBUICAO";
        case TT_BEGIN:
            return "BEGIN";
        case TT_END:
            return "END";
        case TT_UNTIL:
            return "UNTIL";
        case TT_THEN:
            return "THEN";
        case TT_PROGRAM:
            return "PROGRAM";
        case TT_IF:            // if
            return "IF";
        case TT_ELSE:
            return "ELSE";
        case TT_CASE:          // case
            return "CASE";
	    case TT_WHILE:         // while
            return "WHILE";
        case TT_REPEAT:        // repetir
            return "REPEAT";
        case TT_FOR:           // for
            return "FOR";
        case TT_WRITE:         // imprimir na tela
            return "WRITE";
        case TT_WRITELN:       // imprimir na tela
            return "WRITELN";
        case TT_READLN:        // ler do teclado
            return "READLN";
        case TT_DO:
            return "DO";
        case TT_TO:
            return "TO";
        case TT_STARTPAR:
            return "STARTPAR";
        case TT_ENDPAR:
            return "ENDPAR";
        case TT_ID:
            return "ID";
        case TT_OF:
            return "OF";

	    // Others
	    case TT_CONST:         // constante
            return "CONST";
        case TT_LIT_REAL:      // literais
            return "REAL";
        case TT_LIT_STRING:    // string
            return "STRING";
        case TT_LIT_INTEIRO:
            return "INTEIRO";
	    case TT_VAR:           // variable
            return "VAR";

        default:
            throw std::string("invalid tolkien type");
    }
}

#endif

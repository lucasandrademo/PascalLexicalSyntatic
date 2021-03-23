//Alunos Lucas Machado de Oliveira Andrade e Bruno Rocha Ribeiro

#include "SymbolTable.h"

SymbolTable::SymbolTable() {

	// Symbols
	m_symbols[","] = TT_COMA;
	m_symbols[";"] = TT_SEMICOLON;
	m_symbols[":="] = TT_ASSIGN;
	m_symbols["."] = TT_DOT;
	m_symbols[":"] = TT_TWODOT;

	// Logic operators
	m_symbols["="] = TT_EQUAL;
	m_symbols["<>"] = TT_NOT_EQUAL;
	m_symbols["<"] = TT_LOWER;
	m_symbols["<="] = TT_LOWER_EQUAL;
	m_symbols[">"] = TT_GREATER;
	m_symbols[">="] = TT_GREATER_EQUAL;
    m_symbols["not"] = TT_NOT;

    // Conectors
    m_symbols["and"] = TT_AND;
    m_symbols["or"] = TT_OR;

	// Arithmetic operators
	m_symbols["+"] = TT_ADD;
	m_symbols["-"] = TT_SUB;
	m_symbols["*"] = TT_MUL;
	m_symbols["/"] = TT_DIV;
	m_symbols["%"] = TT_MOD;

	// Keywords
	m_symbols["atribuicao"] = TT_ATRIBUICAO;
	m_symbols["begin"] = TT_BEGIN;
	m_symbols["end"] = TT_END;
	m_symbols["until"] = TT_UNTIL;
	m_symbols["then"] = TT_THEN;
	m_symbols["program"] = TT_PROGRAM;
    m_symbols["if"] = TT_IF;
	m_symbols["else"] = TT_ELSE;
    m_symbols["case"] = TT_CASE;
	m_symbols["while"] = TT_WHILE;
    m_symbols["repeat"] = TT_REPEAT;
    m_symbols["for"] = TT_FOR;
	m_symbols["write"] = TT_WRITE;
	m_symbols["writeln"] = TT_WRITE;
	m_symbols["readln"] = TT_READLN;
	m_symbols["do"] = TT_DO;
	m_symbols["to"] = TT_TO;
	m_symbols["("] = TT_STARTPAR;
	m_symbols[")"] = TT_ENDPAR;
	m_symbols["const"] = TT_CONST;
	m_symbols["var"] = TT_VAR;
	m_symbols["of"] = TT_OF;

}

SymbolTable::~SymbolTable() {
}

bool SymbolTable::contains(const std::string& token) const {
	return m_symbols.find(token) != m_symbols.end();
}

enum TokenType SymbolTable::find(const std::string& token) {
	return this->contains(token) ? m_symbols[token] : TT_ID;
}

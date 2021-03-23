//Alunos Lucas Machado de Oliveira Andrade e Bruno Rocha Ribeiro

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SyntaticAnalysis.h"

SyntaticAnalysis::SyntaticAnalysis(LexicalAnalysis& lex):
    m_lex(lex), m_current(lex.nextToken()){

    }
SyntaticAnalysis::~SyntaticAnalysis(){

}

void SyntaticAnalysis::start(){
	procProgram();
	eat(TT_END_OF_FILE);
}

void SyntaticAnalysis::advance() {
    m_current = m_lex.nextToken();
}

void SyntaticAnalysis::eat(enum TokenType type){
	 std::cout << "Expected (...," << tt2str(type)
                << "), found (\"" + m_current.token << "\", "
                << tt2str(m_current.type) << ")" << std::endl;
    if(type == m_current.type){
        advance();
    }else{
        showError();
    }

}

void SyntaticAnalysis::showError() {
	std::cout << std::setw(2) << std::setfill('0') << m_lex.line() << ":";

	switch (m_current.type) {
	 	case TT_INVALID_TOKEN:
	 		std::cout << "Lexema inválido [" << m_current.token << "]" << std::endl;
	 		break;
	 	case TT_UNEXPECTED_EOF:
	 	case TT_END_OF_FILE:
	 		std::cout << "Fim de arquivo inesperado" << std::endl;
	 		break;
	 	default:
	 		std::cout << "Lexema não esperado [" << m_current.token << "]" << std::endl;
	 		break;
	 }

    exit(1);
}

void SyntaticAnalysis::procProgram() {
	eat (TT_PROGRAM);
	eat(TT_ID);
	eat(TT_SEMICOLON);
	if(m_current.type == TT_CONST){
		eat(TT_CONST);
		procConst();
		while(m_current.type == TT_ID){
			procConst();
		}
	}
	if(m_current.type == TT_VAR){
		eat(TT_VAR);
		procVar();
		while(m_current.type == TT_ID){
			procVar();
		}
	}
	procBlock();
	eat(TT_DOT);
}

void SyntaticAnalysis::procConst() {
	eat(TT_ID);
	eat(TT_EQUAL);
	procValue();
	eat(TT_SEMICOLON);

}

void SyntaticAnalysis::procVar() {
	eat(TT_ID);
	while(m_current.type == TT_COMA){
        eat(TT_COMA);
        eat(TT_ID);
    }
	if(m_current.type == TT_EQUAL){
		eat(TT_EQUAL);
        procValue();
	}
	eat(TT_SEMICOLON);
}

void SyntaticAnalysis::procBody() {
	if(m_current.type == TT_BEGIN){
		procBlock();
	}else{
        procCmd();
	}
}

void SyntaticAnalysis::procBlock() {
	eat(TT_BEGIN);
	if(m_current.type == TT_ID || m_current.type == TT_IF
		  || m_current.type == TT_CASE || m_current.type == TT_WHILE
		  || m_current.type == TT_FOR || m_current.type == TT_REPEAT
		  || m_current.type == TT_WRITE || m_current.type == TT_READLN){
        procCmd();
        while(m_current.type == TT_SEMICOLON){
            eat(TT_SEMICOLON);
            procCmd();
        }
	}
	eat(TT_END);
}

void SyntaticAnalysis::procCmd() {
	if(m_current.type == TT_ID){
		procAssign();
	}else if(m_current.type == TT_IF){
		procIf();
	}else if(m_current.type == TT_CASE){
		procCase();
	}else if(m_current.type == TT_WHILE){
		procWhile();
	}else if(m_current.type == TT_FOR){
		procFor();
	}else if(m_current.type == TT_WRITE){
		procWrite();
	}else if(m_current.type == TT_REPEAT){
		procRepeat();
	}else if(m_current.type == TT_READLN){
		procRead();
	}else{
		showError();
	}
}

void SyntaticAnalysis::procAssign(){
	eat(TT_ID);
	eat(TT_ASSIGN);
	procExpr();
}

void SyntaticAnalysis::procIf(){
	eat(TT_IF);
	procBoolexpr();
	eat(TT_THEN);
	procBody();
	if(m_current.type == TT_ELSE){
		eat(TT_ELSE);
		procBody();
	}
}

void SyntaticAnalysis::procCase(){
	eat(TT_CASE);
	procExpr();
	eat(TT_OF);
	while(m_current.type == TT_LIT_INTEIRO || m_current.type == TT_LIT_REAL
		 || m_current.type == TT_LIT_STRING){
		procValue();
		eat(TT_TWODOT);
		procBody();
		eat(TT_SEMICOLON);
		}
	if(m_current.type == TT_ELSE){
		eat(TT_ELSE);
		procBody();
		eat(TT_SEMICOLON);
	}
	eat(TT_END);
}

void SyntaticAnalysis::procWhile(){
	eat(TT_WHILE);
	procBoolexpr();
	eat(TT_DO);
	procBody();
}

void SyntaticAnalysis::procRepeat(){
	eat(TT_REPEAT);
		if(m_current.type == TT_ID || m_current.type == TT_IF
		  || m_current.type == TT_CASE || m_current.type == TT_WHILE
		  || m_current.type == TT_FOR || m_current.type == TT_REPEAT
		  || m_current.type == TT_WRITE || m_current.type == TT_READLN){
		procCmd();
		while(m_current.type == TT_SEMICOLON){
			eat(TT_SEMICOLON);
			procCmd();
		}
	}
	eat(TT_UNTIL);
	procBoolexpr();
}

void SyntaticAnalysis::procFor(){
	eat(TT_FOR);
	eat(TT_ID);
	eat(TT_ASSIGN);
	procExpr();
	eat(TT_TO);
	procExpr();
	eat(TT_DO);
	procBody();
}

void SyntaticAnalysis::procWrite(){
	if(m_current.type == TT_WRITE){
		eat(TT_WRITE);
	}else{
		eat(TT_WRITELN);
	}
	eat(TT_STARTPAR);
	if(m_current.type == TT_LIT_INTEIRO || m_current.type == TT_LIT_REAL
		 || m_current.type == TT_LIT_STRING || m_current.type == TT_ID
		 || m_current.type == TT_STARTPAR){
		procExpr();
		while(m_current.type == TT_COMA){
			eat(TT_COMA);
			procExpr();
		}
	}
	eat(TT_ENDPAR);
}

void SyntaticAnalysis::procRead(){
	eat(TT_READLN);
	eat(TT_STARTPAR);
	eat(TT_ID);
	while(m_current.type == TT_COMA){
		eat(TT_COMA);
		eat(TT_ID);
	}
	eat(TT_ENDPAR);
}

void SyntaticAnalysis::procBoolexpr(){
	if(m_current.type == TT_NOT){
		eat(TT_NOT);
	}
	procCmpexpr();
	if(m_current.type == TT_AND){
		eat(TT_AND);
		procBoolexpr();
	}else if(m_current.type == TT_OR){
		eat(TT_OR);
		procBoolexpr();
	}
}

void SyntaticAnalysis::procCmpexpr(){
	procExpr();
	if(m_current.type == TT_EQUAL){
		eat(TT_EQUAL);
	}else if(m_current.type == TT_NOT_EQUAL){
		eat(TT_NOT_EQUAL);
	}else if(m_current.type == TT_GREATER){
		eat(TT_GREATER);
	}else if(m_current.type == TT_LOWER){
		eat(TT_LOWER);
	}else if(m_current.type == TT_GREATER_EQUAL){
		eat(TT_GREATER_EQUAL);
	}else if(m_current.type == TT_LOWER_EQUAL){
		eat(TT_LOWER_EQUAL);
	}else{
		showError();
	}
	procExpr();
}

void SyntaticAnalysis::procExpr(){
	procTerm();
	while(m_current.type == TT_ADD){
		eat(TT_ADD);
		procTerm();
	}
	while(m_current.type == TT_SUB){
		eat(TT_SUB);
		procTerm();
	}
}

void SyntaticAnalysis::procTerm(){
	procFactor();
	while(m_current.type == TT_MUL || m_current.type == TT_DIV
	  || m_current.type == TT_MOD){
		advance();
		procFactor();
	}
}

void SyntaticAnalysis::procFactor(){
	if(m_current.type == TT_LIT_INTEIRO || m_current.type == TT_LIT_REAL
	  || m_current.type == TT_LIT_STRING){
		procValue();
	}else if(m_current.type == TT_ID){
		eat(TT_ID);
	}else if(m_current.type == TT_STARTPAR){
		eat(TT_STARTPAR);
		procExpr();
		eat(TT_ENDPAR);
	}else{
		showError();
	}

}

void SyntaticAnalysis::procValue(){
	if(m_current.type == TT_LIT_INTEIRO){
		eat(TT_LIT_INTEIRO);
	}else if(m_current.type == TT_LIT_REAL){
		eat(TT_LIT_REAL);
	}else if(m_current.type == TT_LIT_STRING){
		eat(TT_LIT_STRING);
	}else{
		showError();
	}
}

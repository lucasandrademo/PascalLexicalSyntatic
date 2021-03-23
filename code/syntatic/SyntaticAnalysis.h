//Alunos Lucas Machado de Oliveira Andrade e Bruno Rocha Ribeiro

#ifndef SYNTATIC_ANALYSIS_H
#define SYNTATIC_ANALYSIS_H

#include "../lexical/LexicalAnalysis.h"

class SyntaticAnalysis{

    public:
    	SyntaticAnalysis(LexicalAnalysis& m_lex);
		virtual ~SyntaticAnalysis();

		void start();

    private:
		LexicalAnalysis& m_lex;
		Lexeme m_current;

        void advance();
		void eat(enum TokenType type);
		void showError();

		void procProgram();
		void procConst();
		void procVar();
		void procBody();
		void procBlock();
		void procCmd();
		void procAssign();
		void procIf();
		void procCase();
		void procWhile();
		void procRepeat();
		void procFor();
		void procWrite();
		void procRead();
		void procBoolexpr();
		void procCmpexpr();
		void procExpr();
		void procTerm();
		void procFactor();
		void procValue();


};

#endif

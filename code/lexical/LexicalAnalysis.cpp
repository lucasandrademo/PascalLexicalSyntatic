//Alunos Lucas Machado de Oliveira Andrade e Bruno Rocha Ribeiro

#include <iostream>

#include <string>
#include <cctype>
#include "LexicalAnalysis.h"

LexicalAnalysis::LexicalAnalysis(const char* filename) : m_line(1) {
	m_input = fopen(filename, "r");
}

LexicalAnalysis::~LexicalAnalysis() {
	if (m_input != nullptr)
		fclose(m_input);
}

Lexeme LexicalAnalysis::nextToken() {
	int state;
	Lexeme lex;

	state = 1;
	while (state != 12 && state != 13) {
		int c = fgetc(m_input);


		//std::cout << "[" << state << ", " << c << " (" << (char) c << ")]" << std::endl;

		switch (state) {
			case 1:
				if (c == ' ' || c == '\t' || c == '\r') {
					state = 1;
				} else if (c == '\n') {
					m_line++;
					state = 1;
				} else if (c == '(') {
					lex.token += (char) c;
					state = 2;
				} else if (c == '<') {
					lex.token += (char) c;
					state = 5;
				} else if (c == '>') {
					lex.token += (char) c;
					state = 6;
				} else if (c == ':') {
					lex.token += (char) c;
					state = 7;
				} else if (c == '.'|| c == ',' || c == ';' ||
				 c == '=' || c == '+' || c == '-' || c == '*' ||
				 c == '/' || c == '%' || c == ')') {
					lex.token += (char) c;
					state = 12;
				} else if (c == '_' || isalpha(c)) {
					lex.token += (char) c;
					state = 8;
				} else if (isdigit(c)) {
					lex.token += (char) c;
					state = 9;
				}else if (c == '\'') {
					lex.token += (char) c;
					state = 11;
				} else {
					if (c == -1) {
						lex.type = TT_END_OF_FILE;
						state = 13;
					} else {
						lex.token += (char) c;
						lex.type = TT_INVALID_TOKEN;
						state = 13;
					}
				}
				break;
			case 2:
				if (c == '*') {
					state = 3;
				} else {
					if (c != -1)
						ungetc(c, m_input);
					state = 12;
				}

				break;
			case 3:
				if (c == '*') {
					state = 4;
				}else {
					state = 3;
				}

				break;
			case 4:
				if (c == ')') {
					lex.token.pop_back();
					state = 1;
				} else if (c == '*') {
					state = 4;
				}else {
					state = 3;
				}

				break;
			case 5:
				if (c == '>' || c == '=') {
					lex.token += (char) c;
					state = 12;
				} else {
					if (c != -1)
						ungetc(c, m_input);

					state = 12;
				}

				break;
			case 6:
				if (c == '=') {
					lex.token += (char) c;
					state = 12;
				} else {
					if (c != -1)
						ungetc(c, m_input);

					state = 12;
				}

				break;

			case 7:
				if (c == '=') {
					lex.token += (char) c;
					state = 12;
				} else {
					if (c != -1)
						ungetc(c, m_input);

					state = 12;
				}
				break;
			case 8:
				if (c == '_' || isalpha(c) || isdigit(c)) {
					lex.token += (char) c;
					state = 8;
				} else {
					if (c != -1)
						ungetc(c, m_input);

					state = 12;
				}
				break;
			case 9:
				if (isdigit(c)) {
					lex.token += (char) c;
					state = 9;
				} else if (c == '.') {
					lex.token += (char) c;
					state = 10;
				}else {
					if (c != -1)
						ungetc(c, m_input);

					lex.type = TT_LIT_INTEIRO;
					state = 13;
				}

				break;
			case 10:
				if (isdigit(c)) {
					lex.token += (char) c;
					state = 10;
				}else {
					if (c != -1)
						ungetc(c, m_input);

					lex.type = TT_LIT_REAL;
					state = 13;
				}

				break;
			case 11:
				if (c == '\'') {
					lex.token += (char) c;
					lex.type = TT_LIT_STRING;
					state = 13;

				}
				else if(c != '\''){
					lex.token += (char) c;
					state = 11;
				}

				break;

			default:
				throw std::string("Invalid State");
			}
	}
	if (state == 12)
		lex.type = m_st.find(lex.token);

	return lex;

}

#include <iostream>
#include "FST.h"
#include "Lex_Analyzer.h"
#include "In.h"
#include "Parm.h"
#include "Log.h"








 LA::Word_array LA::Create_word_array(const char* s) {

	 LA::Word_array array = {};

	int j = 0;
	int k = 0;
	int i = 0;
	if (s[i] == ' ') i++;
	int nwords = 0;

	// подсчет слов входной строки.
	for (int x = i; x <= strlen(s); x++) {
		if (s[x] == '+' || s[x] == '-' || s[x] == '*' || s[x] == '/' || s[x] == '(' || s[x] == ')' || s[x] == '{' || s[x] == '}' || s[x] == ',' || s[x] == ';' || s[x] == '+' || s[x] == '=') {
			if (s[x-1] != '+' && s[x-1] != '-' && s[x-1] != '*' && s[x-1] != '/' && s[x-1] != '(' && s[x-1] != ')' && s[x-1] != '{' && s[x-1] != '}' && s[x-1] != ',' && s[x-1] !=' ' && s[x-1] != '\n' && s[x - 1] != ';' && s[x - 1] != '=')
			nwords += 2;
			else nwords++;
		}
			
		else if ((s[x] == ' ' || s[x] == '\n') && s[x + 1] != '\0')
		{
			if (s[x - 1] != '+' && s[x - 1] != '-' && s[x - 1] != '*' && s[x - 1] != '/' && s[x - 1] != '(' && s[x - 1] != ')' && s[x - 1] != '{' && s[x - 1] != '}' && s[x - 1] != ',' && s[x - 1] != ' ' && s[x - 1] != '\n' && s[x - 1] != ';' && s[x - 1] != '=')
				nwords += 1;
		}
		else if (s[x] == '\'') {
			x++;
			while (s[x] != '\'') x++;
		}
		else if (s[x] == '\0') {
			if (s[x - 1] != '+' && s[x - 1] != '-' && s[x - 1] != '*' && s[x - 1] != '/' && s[x - 1] != '(' && s[x - 1] != ')' && s[x - 1] != '{' && s[x - 1] != '}' && s[x - 1] != ',' && s[x - 1] != ' ' && s[x - 1] != '\n' && s[x - 1] != ';' && s[x - 1] != '=')
				nwords += 1;
			break;
		}
	}

	// подсчет символов в каждом слове.
	int *letters = new int[nwords];
	int count = 0;
	int index = 0;
	for (int x = i; x < strlen(s) + 1; x++) {
		count++;
		if (s[x] == '+' || s[x] == '+' || s[x] == '-' || s[x] == '*' || s[x] == '/' || s[x] == '(' || s[x] == ')' || s[x] == '{' || s[x] == '}' || s[x] == ','  || s[x] == '=') {
			letters[index] = count - 1;
			count = 0;
			index++;
			letters[index] = 1;
			index++;
		}

		if (s[x] == ' ' || s[x] == '\0') {
			letters[index] = count - 1;
			count = 0;
			index++;
		}

		if (s[x] == '\'') {
			count = 1;
			x++;
			while (s[x] != '\'') {
				count++;
				x++;
			}
			letters[index] = count;
			count = 0;
			index++;
		}

	}

	array.sn = new int[nwords]; // номера строк каждого слова

	// выделение памяти под массив слов
	char ** word_array = new char *[nwords];
	for (int z = 0; z < nwords; z++)
		word_array[z] = new char(letters[z] + 1);

	int ns = 1; // номер строки

	// заполнение массива слов
	for (i; i <= strlen(s); i++) {

		if (s[i] == '\'') {
			word_array[k][j] = s[i];
			j++;
			i++;
			while (s[i] != '\'') {
				word_array[k][j] = s[i];
				j++;
				i++;
			}
			word_array[k][j++] = s[i];
			word_array[k][j] = '\0';
		}

		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == ',' || s[i] == ';' || s[i] == '=') {
			if (s[i - 1] != '+' && s[i - 1] != '-' && s[i - 1] != '*' && s[i - 1] != '/' && s[i - 1] != '(' && s[i - 1] != ')' && s[i - 1] != '{' && s[i - 1] != '}' && s[i - 1] != ',' && s[i - 1] != ';' && s[i - 1] != '\n' && s[i - 1] != ' ' && s[i - 1] != '=') {
				array.sn[k] = ns;
				word_array[k][j] = '\0';
				k++;
			}
			
			j = 0;
			array.sn[k] = ns;
			word_array[k][j] = s[i];
			word_array[k][j + 1] = '\0';
			k++;
		}
		else if (s[i] == ' ') {
			if (s[i - 1] != '+' && s[i - 1] != '-' && s[i - 1] != '*' && s[i - 1] != '/' && s[i - 1] != '(' && s[i - 1] != ')' && s[i - 1] != '{' && s[i - 1] != '}' && s[i - 1] != ',' && s[i - 1] != ';' && s[i - 1] != '\n' && s[i - 1] != ' ' && s[i - 1] != '=') {
				array.sn[k] = ns;
				word_array[k][j] = '\0';
				k++;
			}
			
			j = 0;
		}
		else if (s[i] == '\n') {
			if (s[i - 1] != '+' && s[i - 1] != '-' && s[i - 1] != '*' && s[i - 1] != '/' && s[i - 1] != '(' && s[i - 1] != ')' && s[i - 1] != '{' && s[i - 1] != '}' && s[i - 1] != ',' && s[i - 1] != ';' && s[i - 1] != '\n' && s[i - 1] != ' ' && s[i - 1] != '=') {
				array.sn[k] = ns;
				word_array[k][j] = '\0';
				k++;
			}
			ns++;
			j = 0;
		}
		else if (s[i] == '\0') {
			if (s[i - 1] != '+' && s[i - 1] != '-' && s[i - 1] != '*' && s[i - 1] != '/' && s[i - 1] != '(' && s[i - 1] != ')' && s[i - 1] != '{' && s[i - 1] != '}' && s[i - 1] != ',' && s[i - 1] != ';' && s[i - 1] != '\n' && s[i - 1] != ' ' && s[i - 1] != '=') {
				array.sn[k] = ns;
				word_array[k][j] = '\0';
				k++;
			}
			j = 0;
		}
		else {
			word_array[k][j] = s[i];
			j++;
		}


	}
	array.array = word_array;
	array.n = nwords;
	


	return array;
}

const char*  LA::del_extra(const char* s){
	

	char* text = new char[strlen(s)+1];
	int j = 0;
	for (int i = 0; i <= strlen(s); i++) {

		if (s[i] == ' ') {
			while (s[i] == ' ') i++;
			if (s[i] != '\n' && s[i] != '\0') text[j++] = s[i-1];
		}

		if (s[i] == '\n' && s[i + 1] == '\0') i++;

		if (s[i] == '\n' && (s[i + 1] == ' ' || s[i + 1] == '\n')) {
			text[j++] = s[i];
			i++;
			while (s[i] == ' ' || s[i] == '\n') i++;
		}
		text[j] = s[i];
		j++;
	}
	text[j] = '\0';
	return text;
}



LT::LexTable LA::Lex_analyz(const char *s) {

	const char* text = LA::del_extra(s);
	LA::Word_array word_array = LA::Create_word_array(text);
	char ** words = word_array.array;
	int nwords = word_array.n;
	LT::LexTable LexTable = LT::Create();
	IT::IdTable  idtable = IT::Create();
	LA::Machines machines[21] = {

		{LEX_INTEGER   , FST::FST GRAPH_integer        },
		{LEX_STRING    , FST::FST GRAPH_string         },
		{LEX_PRINT     , FST::FST GRAPH_print          },
		{LEX_FUNCTION  , FST::FST GRAPH_function       },
		{LEX_DECLARE   , FST::FST GRAPH_declare        },
		{LEX_MAIN      , FST::FST GRAPH_main           },
		{LEX_RETURN    , FST::FST GRAPH_return         },
		{LEX_COMMA     , FST::FST GRAPH_COMMA          },
		{LEX_LEFTHESIS , FST::FST GRAPH_LEFTHESIS      },
		{LEX_RIGHTHESIS, FST::FST GRAPH_RIGHTHESIS     },
		{LEX_LEFTBRACE , FST::FST GRAPH_LEFTBRCE       },
		{LEX_BRACELET  , FST::FST GRAPH_BRACELET       },
		{LEX_DIRSLASH  , FST::FST GRAPH_DIRSLASH       },
		{LEX_MINUS     , FST::FST GRAPH_MINUS          },
		{LEX_PLUS      , FST::FST GRAPH_PLUS           },
		{LEX_SEMICOLON , FST::FST GRAPH_SEMICOLON      },
		{LEX_STAR      , FST::FST GRAPH_START          },
		{LEX_EQUAL     , FST::FST GRAPH_EQUAL          },
		{LEX_ID		   , FST::FST GRAPH_id             },
		{LEX_LITERAL   , FST::FST GRAPH_integer_literal},
		{LEX_LITERAL   , FST::FST GRAPH_string_literal },
		
	};
	int indexLT = 0;
	bool flag = 0;
	for (int i = 0; i < nwords; i++) {
		flag = 0;

		for (int j = 0; j < 21; j++) {
			if (FST::execute(machines[j].machine, words[i])) {
				indexLT++;
				flag = 1;
				std::cout << machines[j].lexema;

				// добавить в таблицу лексем.
				LT::Entry lt = {machines[j].lexema , word_array.sn[i], indexLT};
				LT::Add(LexTable, lt);

				if (machines[j].lexema == 'i') {
					
				}


				break;
				
			}
		}
		if (flag == 0) {
			//выдать ошибку
			
			Error::ERROR error = Error::geterrorin(113, word_array.sn[i], -1);
			throw error;

			break;
		}   
	}
	return LexTable; 
 }

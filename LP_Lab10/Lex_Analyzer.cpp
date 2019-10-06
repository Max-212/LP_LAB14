#include <iostream>
#include "FST.h"
#include "Lex_Analyzer.h"
#include "In.h"
#include "Parm.h"
#include "Log.h"




//#define GRAPH_ID "",3, FST::NODE(26, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
//FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
//FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
//FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
//FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
//FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
//FST::RELATION('y', 1), FST::RELATION('z', 1) ) ,\
//FST::NODE(52, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
//FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
//FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
//FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
//FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
//FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
//FST::RELATION('y', 1), FST::RELATION('z', 1), \
//FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), \
//FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2), \
//FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
//FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), \
//FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2), \
//FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
//FST::RELATION('y', 2), FST::RELATION('z', 2)) ,\
//FST::NODE()
//#define GRAPH_LITERAL "",3, FST::NODE(1, FST::RELATION('\"', 1)), \
//FST::NODE(153, \
//FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
//FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
//FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
//FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
//FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
//FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
//FST::RELATION('y', 1), FST::RELATION('z', 1), \
//FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), \
//FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), \
//FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1), \
//FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), \
//FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1), \
//FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), \
//FST::RELATION('Y', 1), FST::RELATION('Z', 1), \
//FST::RELATION('А', 1), FST::RELATION('Б', 1), FST::RELATION('В', 1), FST::RELATION('Г', 1), \
//FST::RELATION('Д', 1), FST::RELATION('Е', 1), FST::RELATION('Ё', 1), FST::RELATION('Ж', 1), \
//FST::RELATION('З', 1), FST::RELATION('И', 1), FST::RELATION('Й', 1), FST::RELATION('Л', 1), \
//FST::RELATION('М', 1), FST::RELATION('Н', 1), FST::RELATION('О', 1), FST::RELATION('П', 1), \
//FST::RELATION('Р', 1), FST::RELATION('С', 1), FST::RELATION('Т', 1), FST::RELATION('У', 1), \
//FST::RELATION('Ф', 1), FST::RELATION('Х', 1), FST::RELATION('Ц', 1), FST::RELATION('Ч', 1), \
//FST::RELATION('Ш', 1), FST::RELATION('Щ', 1), FST::RELATION('Ъ', 1), FST::RELATION('Ы', 1), \
//FST::RELATION('Ь', 1), FST::RELATION('Э', 1), \
//
//FST::RELATION('Ю', 1), FST::RELATION('Я', 1), \
//FST::RELATION('К', 1), \
//FST::RELATION('а', 1), FST::RELATION('б', 1), FST::RELATION('в', 1), FST::RELATION('г', 1), \
//FST::RELATION('д', 1), FST::RELATION('е', 1), FST::RELATION('ё', 1), FST::RELATION('ж', 1), \
//FST::RELATION('з', 1), FST::RELATION('и', 1), FST::RELATION('й', 1), FST::RELATION('л', 1), \
//FST::RELATION('м', 1), FST::RELATION('н', 1), FST::RELATION('о', 1), FST::RELATION('п', 1), \
//FST::RELATION('р', 1), FST::RELATION('с', 1), FST::RELATION('т', 1), FST::RELATION('у', 1), \
//FST::RELATION('ф', 1), FST::RELATION('ч', 1), FST::RELATION('ц', 1), FST::RELATION('ч', 1), \
//FST::RELATION('ш', 1), FST::RELATION('щ', 1), FST::RELATION('ъ', 1), FST::RELATION('ы', 1), \
//FST::RELATION('ь', 1), FST::RELATION('э', 1), FST::RELATION('ю', 1), FST::RELATION('я', 1), \
//FST::RELATION('к', 1), \
//FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
//FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
//FST::RELATION('8', 1), FST::RELATION('9', 1), \
//FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1), \
//FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1), \
//FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1), \
//FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1), \
//FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('#', 1), FST::RELATION('&', 1), \
//FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1), \
//FST::RELATION('\"', 2)), \
//FST::NODE()
//
//#define GRAPH_INTEGER "",8,\
//FST::NODE(1, FST::RELATION('i', 1)),\
//FST::NODE(1, FST::RELATION('n', 2)),\
//FST::NODE(1, FST::RELATION('t', 3)),\
//FST::NODE(1, FST::RELATION('e', 4)),\
//FST::NODE(1, FST::RELATION('g', 5)), \
//FST::NODE(1, FST::RELATION('e', 6)), \
//FST::NODE(1, FST::RELATION('r', 7)),\
//FST::NODE()
//#define GRAPH_STRING "",7, \
//FST::NODE(1, FST::RELATION('s', 1)), \
//FST::NODE(1, FST::RELATION('t', 2)), \
//FST::NODE(1, FST::RELATION('r', 3)), \
//FST::NODE(1, FST::RELATION('i', 4)), \
//FST::NODE(1, FST::RELATION('n', 5), \
//FST::NODE(1, FST::RELATION('g', 6)), \
//FST::NODE())
//#define GRAPH_PRINT "",6,\
//FST::NODE(1, FST::RELATION('p', 1)),\
//FST::NODE(1, FST::RELATION('r', 2)),\
//FST::NODE(1, FST::RELATION('i', 3)),\
//FST::NODE(1, FST::RELATION('n', 4)),\
//FST::NODE(1, FST::RELATION('t', 5)), \
//FST::NODE()
//#define GRAPH_FUNCTION "",9,\
//FST::NODE(1, FST::RELATION('f', 1)),\
//FST::NODE(1, FST::RELATION('u', 2)),\
//FST::NODE(1, FST::RELATION('n', 3)),\
//FST::NODE(1, FST::RELATION('c', 4)),\
//FST::NODE(1, FST::RELATION('t', 5)),\
//FST::NODE(1, FST::RELATION('i', 6)),\
//FST::NODE(1, FST::RELATION('o', 7)),\
//FST::NODE(1, FST::RELATION('n', 8)),\
//FST::NODE()
//#define GRAPH_MAIN "",5,\
//FST::NODE(1, FST::RELATION('m', 1)),\
//FST::NODE(1, FST::RELATION('a', 2)),\
//FST::NODE(1, FST::RELATION('i', 3)),\
//FST::NODE(1, FST::RELATION('n', 4)),\
//FST::NODE()
//#define GRAPH_DECLARE "",8,\
//FST::NODE(1, FST::RELATION('d', 1)),\
//FST::NODE(1, FST::RELATION('e', 2)),\
//FST::NODE(1, FST::RELATION('c', 3)),\
//FST::NODE(1, FST::RELATION('l', 4)),\
//FST::NODE(1, FST::RELATION('a', 5)),\
//FST::NODE(1, FST::RELATION('r', 6)),\
//FST::NODE(1, FST::RELATION('e', 7)),\
//FST::NODE()
//#define GRAPH_RETURN "",7,\
//FST::NODE(1, FST::RELATION('r', 1)),\
//FST::NODE(1, FST::RELATION('e', 2)),\
//FST::NODE(1, FST::RELATION('t', 3)),\
//FST::NODE(1, FST::RELATION('u', 4)),\
//FST::NODE(1, FST::RELATION('r', 5)),\
//FST::NODE(1, FST::RELATION('n', 6)),\
//FST::NODE()
//#define GRAPH_INTEGER_LITERAL "",3,\
//FST::NODE(9, FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
//FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
//FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('1', 1)),\
//FST::NODE(18, FST::RELATION('1', 1),
//
//	FST::RELATION('2', 1), \
//	FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), \
//	FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('1', 1), \
//	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
//	FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), \
//	FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('1', 2)), \
//	FST::NODE()
//#define GRAPH_SEMICOLON "",2,FST::NODE(1, FST::RELATION(';', 1)),\
//FST::NODE()
//#define GRAPH_COMMA "",2,FST::NODE(1, FST::RELATION(',', 1)),\
//FST::NODE()
//#define GRAPH_LEFTBRCE "",2,FST::NODE(1, FST::RELATION('{', 1)),\
//FST::NODE()
//#define GRAPH_BRACELET "",2,FST::NODE(1, FST::RELATION('}', 1)),\
//FST::NODE()
//#define GRAPH_LEFTHESIS "",2,FST::NODE(1, FST::RELATION('(', 1)),\
//FST::NODE()
//#define GRAPH_RIGHTHESIS "",2,FST::NODE(1, FST::RELATION(')', 1)),\
//FST::NODE()
//#define GRAPH_PLUS "",2,FST::NODE(1, FST::RELATION('+', 1)),\
//FST::NODE()
//#define GRAPH_MINUS "",2,FST::NODE(1, FST::RELATION('-', 1)),\
//FST::NODE()
//#define GRAPH_START "",2,FST::NODE(1, FST::RELATION('*', 1)),\
//FST::NODE()
//#define GRAPH_DIRSLASH "",2,FST::NODE(1, FST::RELATION('/', 1)),\
//FST::NODE()



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
	LT::LexTable LexTable = LT::Create(LT_MAXSIZE);

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








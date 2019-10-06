#include <cwchar>
#include <iostream>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"
#include "LT.h"
#include "Lex_Analyzer.h"

using namespace std;


int wmain(int argc, wchar_t* argv[]) {

	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INTLOG;
	try
	{	
		  
		//Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog((wchar_t *)L"C:\\Лабы\\ЯП\\Лаба14\\LP_Lab14\\тесты\\log.log");
		//wcout << "-in:" << parm.in << ", -out" << parm.out << ", -log: " << parm.log << endl;
		In::IN in = In::getin((wchar_t *)L"C:\\Лабы\\ЯП\\Лаба14\\LP_Lab14\\тесты\\test1.txt");
				
		
		LT::LexTable LexTable = LA::Lex_analyz((const char*)in.text);

		cout << "\n----------------------------|\n";
		cout << " № | лексема | номер строки |\n" ;
		cout << "----------------------------|\n";

		for(int i = 0; i < LexTable.size; i++) {
			cout << " " << LexTable.table[i].idxTI << " |    " << LexTable.table[i].lexema << "    |      " << LexTable.table[i].sn << "       |\n";
		}



		

		/*Log::WriteLine(log, "Тест:", "без ошибок", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		*/
		Log::WriteIn(log, in);
		Log::Close(log);
		
	}
	catch (Error::ERROR error) {
		
		cout << "Ошибка " << error.id << ": " << error.message << ", строка " << error.inext.line << ",позиция " << error.inext.col << std::endl;
		Log::WriteError(log, error);
		system("pause");
	}
	system("pause");
}



// LP_Lab10.exe -in:C:\Лабы\ЯП\Лаба14\LP_Lab14\тесты\test1.txt
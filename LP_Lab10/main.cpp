#include <cwchar>
#include <iostream>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"

using namespace std;

int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INTLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out" << parm.out << ", -log: " << parm.log << endl;
		
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест:", "без ошибок", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e) {
		cout << e.message << endl;
		Log::WriteError(log, e);
		cout << e.message << endl;
	}
	system("pause");
}

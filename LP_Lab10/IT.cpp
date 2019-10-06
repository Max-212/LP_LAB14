#include "IT.h";

using namespace IT;

IdTable IT::Create() {
	
	IdTable IdTable = {};
	IdTable.maxsize = TI_MAXSIZE;
	IdTable.size = 0;
	IdTable.table = new Entry[IdTable.maxsize];

	return IdTable;
}

void IT::Add(IdTable& idtable, Entry entry) {

	idtable.table[idtable.size] = entry;
	idtable.size++;
}

void IT::Delete(IdTable& idtable) {
	
	IdTable temp = {};
	idtable = temp;
	
}

Entry IT::GetEntry(IdTable &idtable, int n) {

	return idtable.table[n];
}
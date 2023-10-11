#include <iostream>


using namespace std;


struct NOD {
	int info;
	NOD* urm;
};



NOD* initializare(int info) {
	NOD* NOU = new NOD;
	NOU->urm = NULL;
	NOU->info = info;
	return NOU;
}


NOD* ENQUEUE(NOD* PRIM, int info) {
	if (PRIM == NULL) {
		PRIM = new NOD;
		PRIM->info = info;
		PRIM->urm = NULL;
	}
	else {
		NOD* NOU = new NOD;
		NOU->info = info;
		NOU->urm = PRIM;
		PRIM = NOU;
	}

	return PRIM;
}


NOD* DEQUEUE(NOD* PRIM) {
	if (PRIM == NULL) {
		cout << "Eroare – lista vida";
	}
	else {
		NOD* temp = PRIM;
		while (temp->urm->urm != NULL)
		{
			temp = temp->urm;
		}
		NOD* pen = temp;
		NOD* ult = pen->urm;
		pen->urm = NULL;
		cout << ult->info;
		delete ult;

	}
	return PRIM;
}
void ISEMPTY(NOD* PRIM) {
	if (PRIM == NULL) {
		cout <<endl << "Lista vida!" << endl;
	}
	else {
		cout <<endl<< "Lista exista!" << endl;
	}
}

int main()
{
	struct NOD* PRIM = NULL;
	ISEMPTY(PRIM);
	PRIM = ENQUEUE(PRIM, 7);
	PRIM = ENQUEUE(PRIM, 4);
	PRIM = ENQUEUE(PRIM, 3);
	PRIM = DEQUEUE(PRIM);
	ISEMPTY(PRIM);


	return 0;
}
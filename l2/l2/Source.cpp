
#include <iostream>


using namespace std;


struct NOD{
	int info;
	NOD* urm;
};



NOD* initializare(int info) {
	NOD* NOU = new NOD;
	NOU->urm = NULL;
	NOU->info = info;
	return NOU;
}


NOD* ins_inceput(NOD* PRIM, int info) {
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

NOD* ins_sfarsit(NOD* PRIM, int info) {
	
	if (PRIM == NULL) {
		PRIM = new NOD;
		PRIM->info = info;
		PRIM->urm = NULL;
	}
	else {
		NOD* temp = PRIM;
		while (temp->urm != NULL)
		{
			temp = temp->urm;
		}
		NOD* NOU = new NOD;
		NOU->info = info;
		NOU->urm = NULL;
		temp->urm = NOU;
	}
	return PRIM;
}

NOD* ins_interior(NOD* PRIM, int info, int d) {
	

	if (PRIM == NULL) {
		PRIM = new NOD;
		PRIM->info = info;
		PRIM->urm = NULL;
	}
	else {
		NOD* temp = PRIM;

		while (temp->info != d)
		{
			temp = temp->urm;
		}
		
		NOD* NOU = new NOD;
		NOU->info = info;
		NOU->urm = temp->urm;
		temp->urm = NOU;
		
		
	}
	return PRIM;
}

NOD* st_inceput(NOD* PRIM) {
	if (PRIM == NULL) {
		cout << "Eroare – lista vida";
	}
	else {
		NOD* temp = PRIM;
		PRIM = temp->urm;
		temp->urm = NULL;
		delete temp;
	}
	return PRIM;
}
NOD* st_final(NOD* PRIM) {
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
		delete ult;

	}
	return PRIM;
}
NOD* st_interior(NOD* PRIM, int d) {
	if (PRIM == NULL) {
		cout << "Eroare – lista vida";
	}
	else {
		NOD* temp = PRIM;
		while (temp->info != d) {
			temp = temp->urm;
		}
		NOD* dupa = temp;
		NOD* sterg = temp->urm;
		dupa->urm = temp->urm->urm;
		sterg->urm = NULL;
		
		delete sterg;
	}
	return PRIM;
}



NOD* info_cautare(NOD* PRIM, int info) {
	NOD* temp = PRIM;
	
	if (PRIM == NULL) {
		cout << "Eroare - Informatia nu exista";
	}
	else {
		while (PRIM != NULL) {
			if (temp->info == info) {
				NOD* adresa = temp;
				return temp;
			}
			else {
				temp = temp->urm;
			}
		}
	}
	return NULL;
}


NOD* actualizare(NOD* PRIM, int info_cautat, int info_nou) {
	NOD* temp = info_cautare(PRIM, info_cautat);
	if (temp == NULL) {
		cout << "Eroare - Informatia nu exista";
	}
	else {
		temp->info = info_nou;
	}
	return PRIM;
}

NOD* ordonare(NOD* PRIM, int i) {
	NOD* temp = PRIM;
	
	int mem;
	if (i == 0) {
		while (temp->urm != NULL && temp->info < temp->urm->info)
		{
			temp = temp->urm;
		}

		while (temp->urm != NULL && temp->info > temp->urm->info)
		{
			mem = temp->info;
			temp->info = temp->urm->info;
			temp->urm->info = mem;
			temp = temp->urm;
			while (temp->urm != NULL && temp->info < temp->urm->info) {
				temp = temp->urm;
			}
			if (temp->urm == NULL) {
				temp = PRIM;
			}
			while (temp->urm != NULL && temp->info < temp->urm->info) {
				temp = temp->urm;
			}
		}
	}
	else if (i ==1)
	{
		while (temp->urm != NULL && temp->info > temp->urm->info)
		{
			temp = temp->urm;
		}

		while (temp->urm != NULL && temp->info < temp->urm->info)
		{
			mem = temp->info;
			temp->info = temp->urm->info;
			temp->urm->info = mem;
			temp = temp->urm;
			while (temp->urm != NULL && temp->info > temp->urm->info) {
				temp = temp->urm;
			}
			if (temp->urm == NULL) {
				temp = PRIM;
			}
			while (temp->urm != NULL && temp->info > temp->urm->info) {
				temp = temp->urm;
			}
		}
	}
	return PRIM;
}

void min(NOD* PRIM) {
	
	NOD* temp = PRIM;
	int minim = temp->info;
	while (temp != NULL) {
		if (temp->info < minim) {
			minim = temp->info;
		}
		temp = temp->urm;
	}
	cout << "Valoarea minima din lista este: " << minim << endl;
}
void max(NOD* PRIM) {
	NOD* temp = PRIM;
	int maxim = temp->info;
	while (temp != NULL) {
		if (temp->info > maxim) {
			maxim = temp->info;
		}
		temp = temp->urm;
	}
	cout << "Valoarea maxima din lista este: " << maxim << endl;
}

NOD* traversare(NOD* PRIM) {
	NOD* temp = PRIM;
	if (temp == NULL) {
		cout << "Eroare - Informatia nu exista";
	}
	else {
		while (temp != NULL) {
			cout << temp->info;
			temp = temp->urm;
			
		}
	}
	return PRIM;
}


int main()
{
	struct NOD* PRIM = NULL;
	
	
	PRIM = ins_inceput(PRIM, 9);
	PRIM = ins_inceput(PRIM, 5);
	PRIM = ins_inceput(PRIM, 1);
	PRIM = ins_inceput(PRIM, 4);
	PRIM = ins_inceput(PRIM, 7);
	PRIM = ins_inceput(PRIM, 8);
	PRIM = ins_sfarsit(PRIM, 0);
	PRIM = ins_interior(PRIM, 3, 5);
	//PRIM = st_inceput(PRIM);
	//PRIM = st_final(PRIM);
	//PRIM = st_interior(PRIM, 3);
	//PRIM = actualizare(PRIM, 3, 9);
	//PRIM = info_cautare(PRIM, 5);
	//PRIM = ordonare(PRIM, 0);//0 = crescator, 1 = descrescator
	min(PRIM);
	max(PRIM);

	PRIM = traversare(PRIM);





	return 0;
}
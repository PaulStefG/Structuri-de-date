
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


NOD* PUSH(NOD* PRIM, int info) {
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
NOD* POP(NOD* PRIM) {
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

int PEEK(NOD* PRIM) {
	int i;
	if (PRIM == NULL) {
		cout << "Lista vida!";
		return 0;
	}
	else {
		i = PRIM->info;
		//cout << PRIM->info << " ";
	}
	return i;
}

void ISEMPTY(NOD* PRIM) {
	if (PRIM == NULL) {
		cout << "Lista vida!";
	}
	else {
		cout << "Lista exista!";
	}
}
//fie 2 nr n1 n2 reprezentat sub forma unor stive sa se implementeze op de adunare a celor 2 numere folosind stivele
int main()
{
	struct NOD* stiva1 = NULL;
	struct NOD* stiva2 = NULL;
	int d=0, s=0, sf=0, i=1;

	stiva1 = PUSH(stiva1, 1);
	stiva1 = PUSH(stiva1, 2);
	stiva1 = PUSH(stiva1, 3);
	stiva1 = PUSH(stiva1, 4);
	stiva2 = PUSH(stiva2, 5);
	stiva2 = PUSH(stiva2, 6);
	stiva2 = PUSH(stiva2, 7);
	stiva2 = PUSH(stiva2, 8);
	
	while (stiva1 != NULL || stiva2 != NULL) {
		s = PEEK(stiva1) + PEEK(stiva2);
		cout << endl << s;
		
		if (s > 9) {
			
			s = s % 10;
			
			sf =(s + d) * i + sf;
			d = 1;
		}
		else {
			
			sf =(s + d)*i + sf;
			d = 0;
		}
		
		i = i * 10;
		stiva1 = POP(stiva1);
		stiva2 = POP(stiva2);
	}
	if (d == 1) {
		sf = i + sf;
	}
	cout << endl  << sf << endl;


	return 0;
}
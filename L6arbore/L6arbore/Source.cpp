#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

using namespace std;


struct nod {
	int info;
	
	nod* st, * dr;
};
void Inserare(nod*& R, int x)
{
	if (R != NULL)
	{
		if (R->info == x)
			return;
		else {
			if (R->info > x) {
				Inserare(R->st, x);
				
			}
			else {
				Inserare(R->dr, x);
				
			}
		}
	}
	else
	{
		
		R = new nod;
		R->info = x;
		R->st = NULL;
		R->dr = NULL;
	}
}
void cautare(nod*& R, const int element) {
	if (R == NULL) {
		cout << "Lista vida." << endl;
	}
	else {
		if (R->info == element) {
			cout << "Info gasit: "<< R->info<< endl;
		}
		else {
			if (R->info > element)
				cautare(R->st, element);
			else
				cautare(R->dr, element);
		}
	}
}
void actualizare(nod*& R, const int info, const int element) {
	if (R == NULL) {
		cout << "Lista vida.";
	}
	else {
		if (R->info == info) {
			R->info = element;
		}
		else {
			if (R->info > info)
				actualizare(R->st, info, element);
			else
				actualizare(R->dr, info, element);
		}
	}
}

void StergAux(nod*& p, nod*& R)
{
	// R - nodul care trebuie sters
	// p - pointer cu care identificăm nodul cel mai din dreapta
	if (p->dr)
		StergAux(p->dr, R);
	else
	{
		R->info = p->info;
		nod* aux = p;
		p = p->st;
		delete aux;
	}
}

void Stergere(nod*& R, int x)
{
	if (R != NULL)
	{
		if (R->info == x)
		{
			// nodul trebuie șters
			if (R->st == NULL && R->dr == NULL)
			{
				delete R;
				R = NULL;
			}
			else
				if (R->dr == NULL)
				{
					nod* aux = R;
					R = R->st;
					delete aux;
				}
				else
					if (R->st == NULL)
					{
						nod* aux = R;
						R = R->dr;
						delete aux;
					}
					else
						StergAux(R->st, R);
		}
		else
			if (R->info > x)
				Stergere(R->st, x);
			else
				Stergere(R->dr, x);
	}
	else
		return; // valoarea x nu apare în arbore
}
int height(nod*& R) {
	if (R == NULL) {
		return 0;
	}
	else {
		int stH = height(R->st);
		int drH = height(R->dr);
		if (stH >= drH) {
			
			return(stH + 1);
		}
		
		else {
			return(drH + 1);
		}
		
	}
	
}



void Afisare(nod* R, int i)
{//1 = ordine, 2 = precomanda, 3= postordine
	if (R != NULL)
	{
		
		if (i == 1) {
			
			Afisare(R->st, 1);
			cout << R->info << " ";
			Afisare(R->dr, 1);
			
		}
		if (i == 2) {
			cout << R->info << " ";
			Afisare(R->st, 2);
			Afisare(R->dr, 2);
			
		}
		if (i == 3) {
			Afisare(R->st, 3);
			Afisare(R->dr, 3);
			cout << R->info << " ";
			
		}
		
	}
}
int main() {
	
	struct nod* R = NULL;
	Inserare(R, 7);
	Inserare(R, 8);
	Inserare(R, 9);
	Inserare(R, 6);
	Inserare(R, 4);
	Inserare(R, 2);
	Inserare(R, 1);
	Inserare(R, 5);
	Inserare(R, 12);
	Inserare(R, 22);
	Inserare(R, 25);
	Inserare(R, 28);
	Inserare(R, 3);
	Inserare(R, 36);
	Inserare(R, 0);
	cautare(R, 4);
	Afisare(R, 1);
	cout << endl << height(R);
	
	
	cout << endl;
	Afisare(R, 2);
	cout << endl;
	Afisare(R, 3);
	cout << endl;
	Stergere(R, 4);
	cout << endl;
	Afisare(R, 1);
	cout << endl;
	actualizare(R, 5, 0);
	Afisare(R, 1);
	
	return 0;
}
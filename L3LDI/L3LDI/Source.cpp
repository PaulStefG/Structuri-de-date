#include <iostream>

using namespace std;

// Definire Structura NOD, pentru LDI vom avea doua legaturi, urmatorul element si precedentul.
struct Nod {
	int info;
	struct Nod* succ; //succesor
	struct Nod* pred; //predecesor
};

// Definire Structure Pentru Lista. Definim o alta structura pentru ca lista dublu inlantuita are 2 noduri, front si end.

struct LDI {
	struct Nod* front;
	struct Nod* end;
};

// Initializem structura de lista, care contine 2 noduri, inceput si sfarsit.
// La LDI mereu pastram adresa primului si ultimului element
LDI* initializareLista()
{
	LDI* lista = new LDI;

	
	lista->front = NULL;
	//lista->front->succ = NULL;
	//lista->front->pred = NULL;
	
	lista->end = NULL;
	//lista->end->succ = NULL;
	//lista->end->pred = NULL;
	return lista;
}

// Initializare pentru un singur nod.
Nod* init(const int info) {

	// Alocare Dinamica pentru un NOD nou.
	Nod* nodNou = new Nod;

	// Setare informatie in NOD nou.
	nodNou->info = info;

	// Setare urmatorul si precedentul nod (NULL, la creare nu avem urmatorul NOD) deci il setam pe NULL. 
	nodNou->succ = NULL;
	nodNou->pred = NULL;

	// Functia returneaza noul NOD.
	return nodNou;
}


LDI* inserareInceput(LDI* lista, const int info)
{
	Nod* nodNou = init(info);

	if (lista->front == NULL)
	{
		lista->front = lista->end = nodNou;
	}
	else
	{
		nodNou->succ = lista->front;
		lista->front->pred = nodNou;
		lista->front = nodNou;

	}
	return lista;

}

LDI* inserareSfarsit(LDI* lista, const int info)
{
	Nod* nodNou = init(info);

	if (lista->front == NULL)
	{
		lista->front = lista->end = nodNou;
	}
	else {
		
		Nod* temp = lista->front;
		while (temp->succ != NULL) {
			temp = temp->succ;
		}
		nodNou->succ = NULL;
		nodNou->pred = temp;
		lista->end->succ = nodNou;
		lista->end = nodNou;
		
		
	}

	return lista;
}

LDI* inserareDupa(LDI* lista, const int info, const int element)
{
	Nod* nodNou = init(info);
	if (lista->front == NULL)
	{
		cout << "Lista este goala!";
	}
	else {
		Nod* temp = lista->front;
		
			while (temp->succ != NULL && temp->info != element) {

				temp = temp->succ;

			}
			if (temp != NULL) {
				
				nodNou->succ = temp;
				if (temp->succ != NULL) {
					nodNou->succ = temp->succ;
					temp->succ = nodNou;
					nodNou->pred = temp;
					nodNou->succ->pred = nodNou;
					
				}
				
			}
		
	}
	return lista;
}


LDI* inserareInainte(LDI* lista, const int info, const int element)
{

	Nod* nodNou = init(info);
	if (lista->front == NULL)
	{
		lista->front = lista->end = nodNou;
	}
	else {
		Nod* temp = lista->front;
		while (temp->succ != NULL && temp->succ ->info != element) {
			temp = temp->succ;
		}
		if (temp->succ != NULL) {
			nodNou->succ = temp->succ;
			nodNou->pred = temp;
			nodNou->succ->pred = nodNou;
			temp->succ = nodNou;
			
		}
	}
	return lista;

}

LDI* stergereInceput(LDI* lista)
{
	if (lista->front == NULL)
	{
		cout << "Lista este goala!";
		return NULL;
	}
	else
	{
		Nod* temp = lista->front;

		lista->front = lista->front->succ;
		lista->front->pred = NULL;

		delete[] temp;
	}

	return lista;
}

LDI* stergereSfarsit(LDI* lista)
{
	if (lista->front == NULL)
	{
		cout << "Lista este goala!";
		return NULL;
	}
	else
	{
		Nod* temp = lista->front;
		while (temp->succ->succ != NULL) {
			temp = temp->succ;
		}
		Nod* sterg = temp->succ;
		temp->succ = NULL;
		sterg->pred = NULL;
		lista->end = temp;
		delete[] sterg;
	}

	return lista;
}

LDI* stergereMijloc(LDI* lista, const int element)
{
	if (lista->front == NULL)
	{
		cout << "Lista este goala!";
		return NULL;
	}
	else {
		Nod* temp = lista->front;
		while (temp->info != element) {
			temp = temp->succ;
		}
		Nod* sterg = temp;
		temp->pred->succ = sterg->succ;
		sterg->succ->pred = sterg->pred;
		
		delete[] sterg;
	}

	return lista;
}



void cautare(LDI* lista, const int element)
{
	
	if (lista->front == NULL)
	{
		cout << "Lista este goala!";
		
	}
	else {
		Nod* temp = lista->front;
		while (temp->info != element) {
			temp = temp->succ;
		}
		cout << "Elementul cautat este: " << temp->info << endl;
	}


}

LDI* actualizare(LDI* lista, const int element, int element_nou)
{
	if (lista->front == NULL)
	{
		cout << "Lista este goala!";

	}
	else {
		Nod* temp = lista->front;
		while (temp->info != element) {
			temp = temp->succ;
		}
		temp->info = element_nou;
	}

	return lista;
}

void numarDeElemente(LDI* lista) {
	Nod* temp = lista->front;
	int nr = 1;
	if (temp == NULL) {
		cout << "Lista nu exista." << endl;
	}
	while (temp->succ != NULL) {
		nr++;
		temp = temp->succ;
	}
	cout << "Numarul de elemente in lista este: " << nr << endl;
}

// De la  stanga la dreapta (inceput -> Sfrasit)

void parcurgereStanga(LDI* lista) {
	if (lista->front == NULL)
	{
		cout << "Lista e goala";
	}
	Nod* temp = lista->front;

	while (temp!= NULL)
	{

		cout << temp->info << " ";
		temp = temp->succ;
	}
	cout << endl;
}

LDI* ordonare(LDI* lista, int CD) {
	Nod* temp = lista->front;
	int mem;
	if (temp == NULL) {
		cout << "Eroare – lista vida";
	}
	else {
		if (CD == 0) {
			while (temp->succ !=NULL && temp->info < temp->succ->info)
			{
				temp = temp->succ;
			}
			while (temp->succ != NULL && temp->info > temp->succ->info) {
				mem = temp->info;
				temp->info = temp->succ->info;
				temp->succ->info = mem;
				temp = temp->succ;
				while (temp->succ != NULL && temp->info < temp->succ->info) {
					temp = temp->succ;
				}
				if (temp->succ == NULL) {
					temp = lista->front;
				}
				while (temp->succ != NULL && temp->info < temp->succ->info) {
					temp = temp->succ;
				}
			}
		}
		else if (CD == 1) {
			while (temp->succ != NULL && temp->info > temp->succ->info)
			{
				temp = temp->succ;
			}
			while (temp->succ != NULL && temp->info < temp->succ->info) {
				mem = temp->info;
				temp->info = temp->succ->info;
				temp->succ->info = mem;
				temp = temp->succ;
				while (temp->succ != NULL && temp->info > temp->succ->info) {
					temp = temp->succ;
				}
				if (temp->succ == NULL) {
					temp = lista->front;
				}
				while (temp->succ != NULL && temp->info > temp->succ->info) {
					temp = temp->succ;
				}
			}
		}
	}
	return lista;
}

LDI* swap(LDI* lista, int p, int d) {

	Nod* temp1 = lista->front;
	Nod* temp2 = lista->front;
	int mem;
	if (temp1 == NULL) {
		cout << "Eroare – lista vida";
	}
	else {
		while (temp1->info != p) {
			temp1 = temp1->succ;
		}
		mem = temp1->info;
		while (temp2->info != d) {
			temp2 = temp2->succ;
		}
		temp1->info = temp2->info;
		temp2->info = mem;
	}



	return lista;
}

// De la  dreata la stanga (sfarsit -> inceput)
void parcurgereDreapta(LDI* lista) {

	if (lista->end == NULL)
	{
		cout << "Lista e goala";
	}

	Nod* temp = lista->end;

	while (temp != NULL)
	{
		cout << temp->info << " ";
		temp = temp->pred;
	}
	cout << endl;
}

LDI* sortare(LDI* lista)
{


	return lista;
}



int main() {

	// Alocam memorie pentru structa de lista.
	LDI* lista = initializareLista();
	lista = inserareInceput(lista, 8);
	lista = inserareInceput(lista, 5);
	lista = inserareInceput(lista, 3);
	lista = inserareSfarsit(lista, 9);
	lista = inserareSfarsit(lista, 7);
	lista = inserareDupa(lista, 2, 9);
	lista = inserareInainte(lista, 31, 2);
	lista = stergereInceput(lista);
	lista = stergereSfarsit(lista);
	lista = stergereMijloc(lista, 9);

	numarDeElemente(lista);
	cautare(lista, 31);
	lista = actualizare(lista, 8, 1);
	lista = ordonare(lista, 0);//0 = crescator, 1 = descrescator
	lista = swap(lista, 1, 5);


	parcurgereStanga(lista);
	parcurgereDreapta(lista);


	return 0;
}
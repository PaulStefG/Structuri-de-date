// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;


struct str_vector {
	int* v;
	int max = 0;
	int elem = 0;
};

str_vector* initializare(str_vector* vect, int max)
{
	if (vect == NULL)
	{
		cout << "Vector inexistent, a fost alocat" << endl;
		vect = new str_vector[1];
		vect->v = new int[max]();
		vect->max = max;
	}
	else
	{
		vect->v = new int[max];
		vect->max = max;
		vect->elem = 0;
	}
	return vect;
}

str_vector* inserare_inceput(str_vector* vect, int element_nou)
{
	if (vect != NULL) {
		for (int i = vect->elem + 1; i >= 1; i--) {
			vect->v[i] = vect->v[i - 1];
		}
		vect->v[0] = element_nou;
		vect->elem++;
	}

	return vect;
}
str_vector* inserare_sfarsit(str_vector* vect, int element_nou)
{
	if (vect != NULL) {

		vect->v[vect->elem] = element_nou;
		vect->elem++;
	}

	return vect;

}

str_vector* inserare_mijloc(str_vector* vect, int element_nou, int index)
{
	if (vect == NULL)
	{
		cout << "Vectorul nu exista" << endl;
		return NULL;
	}
	else
	{
		if (vect->elem == vect->max)
		{
			cout << "Vectorul este plin";
			return vect;
		}
		if (index >= vect->max)
		{
			cout << "Indexul depasaeste nr maxim de elemente";
			return vect;
		}
		for (int i = vect->elem; i > index; i--) {
			vect->v[i] = vect->v[i - 1];
		}
		vect->v[index] = element_nou;
		vect->elem++;
	}
	return vect;
}



str_vector* stergere_inceput(str_vector* vect)
{
	if (vect != NULL) {
		for (int i = vect->elem + 1; i >= 1; i--) {
			vect->v[i] = vect->v[i - 1];
		}
		vect->elem--;
	}
	return vect;
}

str_vector* stergere_sfarsit(str_vector* vect)
{

	if (vect != NULL) {

		vect->elem--;
	}

	return vect;

}

str_vector* stergere_mijloc(str_vector* vect, int index)
{
	if (vect != NULL) {
		for (int i = index; i < vect->elem; i++) {
			vect->v[i] = vect->v[i + 1];
		}
		vect->elem--;
	}

	return vect;

}

void afisare(str_vector* vect)
{
	if (vect == NULL)
	{
		cout << "Vectorul nu exista";
		return;
	}
	else
	{
		for (int i = 0; i < vect->elem; i++)
		{
			cout << vect->v[i] << " ";
		}
	}

}
str_vector* sortare_CrDe(str_vector* vect, int sortare) {
	if (vect != NULL) {
		int s = sortare;
		if (s == 1) {
			for (int i = 0; i < vect->elem - 1; i++)
			{
				for (int j = i + 1; j < vect->elem; j++)
				{
					if (vect->v[i] > vect->v[j])
					{
						int aux = vect->v[i];
						vect->v[i] = vect->v[j];
						vect->v[j] = aux;
					}
				}
			}
		}
		else if (s == 0)
		{
			for (int i = 0; i <= vect->elem - 2; i++)
			{
				for (int j = i + 1; j <= vect->elem - 1; j++)
				{
					if (vect->v[i] < vect->v[j])
					{
						int schimb = vect->v[i];
						vect->v[i] = vect->v[j];
						vect->v[j] = schimb;
					}
				}

			}
		}
	}
	return vect;
}

int main()
{
	int max = 20;
	int sortareCD = 1;  //1 - Crescator , 0 - Descrescator
	struct str_vector* vect = new str_vector;
	vect = initializare(vect, max);
	vect = inserare_inceput(vect, 5);
	vect = inserare_inceput(vect, 4);
	vect = inserare_inceput(vect, 5);
	vect = inserare_sfarsit(vect, 6);
	vect = inserare_mijloc(vect, 7, 1);
	vect = inserare_mijloc(vect, 8, 3);
	//vect = stergere_inceput(vect);
	//vect = stergere_sfarsit(vect);
	//vect = stergere_mijloc(vect, 3);
	vect = inserare_sfarsit(vect, 3);
	vect = inserare_sfarsit(vect, 2);
	//vect = sortare_CrDe(vect, sortareCD);
	
	afisare(vect);


	return 0;
}
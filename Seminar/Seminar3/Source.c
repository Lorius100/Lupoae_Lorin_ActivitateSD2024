#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

struct Masina {
	int id;
	char* producator;
	int nrUsi;
	float pret;

};

struct Masina* adaugareInVector(struct Masina* masini, struct Masina m, int* nrMasini) {
	struct Masina* aux = (struct Masina*)malloc(sizeof(struct Masina) * (*nrMasini + 1));
	for (int i = 0; i < (*nrMasini); i++) {
		aux[i] = masini[i]; //am facut shallow copy
	}
	aux[*nrMasini] = m;
	(*nrMasini)++;
	if (masini != NULL) //verificam pt ca initial , la prima inserare vectorul e null si n am avea ce sterge
		free(masini); //nu l am parcurs pt ca am facut shallow copy

	return aux;
}


struct Masina* citireFisier(const char* numeFisier, int* nrMasini)//transmis prin pointer pt a putea fi modificat
{
	FILE* f = fopen(numeFisier, "r");
	//bufferul e unde sa citeasca(primul param al functiei)
	char buffer[100];//alocat static, practic cu cat ar putea contine o linie maxim
	char sep[] = ",\n"; //alocam pe stiva pt ca n avem nevoie de el in main(heap)
	struct Masina* masini = NULL;
	(*nrMasini) = 0;
	while (fgets(buffer, 100, f) != NULL)//cand ajunge la finalul fisierului si nu mai are ce citi, returneaza null
	{
		char* token = strtok(buffer, sep);
		struct Masina m;
		m.id = atoi(token);
		token = strtok(NULL, sep);
		m.producator = malloc(strlen(token) + 1);
		strcpy(m.producator, token);
		token = strtok(NULL, sep);
		m.nrUsi = atoi(token);
		token = strtok(NULL, sep);
		m.pret = atof(token);
		masini = adaugareInVector(masini, m, nrMasini); //e deja pointer deci nu mai punem & (dresa)



	}
	return masini;
}

void afisareMatrice(struct Masina** matrice, int nrLinii, int* nrColoane)
{
	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrCol; j++)
		{
			printf("%d, %s, %d, %.2f \t", matrice[i][j].id, matrice[i][j].producator, matrice[i][j].nrUsi, matrice[i][j].pret);
		}
		printf("\n");
	}

}

struct Masina* citireMatrice(const char* numeFisier, struct Masina** matrice, int nrLinii, int* nrCol)//transmis prin pointer pt a putea fi modificat
{
	FILE* f = fopen(numeFisier, "r");
	//bufferul e unde sa citeasca(primul param al functiei)
	char buffer[100];//alocat static, practic cu cat ar putea contine o linie maxim
	char delimitare[] = ",\n"; //alocam pe stiva pt ca n avem nevoie de el in main(heap)
	while (fgets(buffer, 100, f) != NULL)//cand ajunge la finalul fisierului si nu mai are ce citi, returneaza null
	{
		char* element = strtok(buffer, delimitare);
		struct Masina m;
		m.id = atoi(element);
		element = strtok(NULL, delimitare);
		m.producator = malloc(strlen(element) + 1);
		strcpy(m.producator, element);
		element = strtok(NULL, delimitare);
		m.nrUsi = atoi(element);
		element = strtok(NULL, delimitare);
		m.pret = atof(element);
		matrice[m.nrUsi - 2] = adaugareInVector(matrice[m.nrUsi - 2], m, & (nrColoane[m.nrUsi - 2])); //e deja pointer deci nu mai punem & (dresa)



	}
	fclose(f);
	return matrice;
}

float pretMediu(struct Masina** matrice, int nrLinii, int* nrColoane, int nrUsi) {
	if (nrUsi < 2 || nrUsi>4) 
		return 0;
	float pretTotal = 0;
	int index = nrUsi - 2;
	if (nrColoane[index] == 0)
		return 0;
	for (int i = 0;i < nrColoane[index];i++) {
		preTotal += matrice[index][i].pret;
	}
	return pretTotal / nrColoane[index];
}

struct Masina cautareID(struct Masina** matrice, int nrLinii, int* nrCol, int id) {
	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < nrCol[i];j++) {
			if (nrMatrice[i][j].id == id)
				return matrice[i][j];
		}
	}
	struct Masina m;
	m.id = -1;
	m.producator = NULL;
	m.nrUsi = -1;
	m.pret = -1;
}

void dezalocareMatrice(struct Masina*** matrice, int nrLinii, int** nrCol) {
	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < (*nrCol)[i];j++){
			free((*matrice)[i][j].producator)
		}
		free((*matrice)[i]);

	}
	free((*nrCol));
	(*nrCol) = NULL;
	free((*matrice));
	(*matrice) = NULL;

}

int main()
{
	struct Masina** matrice;
	int nrLinii = 3;
	int* nrCol;

	nrCol = (int*)malloc(sizeof(int) * nrLinii);
	matrice = (struct Masina*)malloc(sizeof(struct Masina) * nrLinii);
	for (int i = 0; i < nrLinii; i++)
	{
		nrCol[i] = 0;
		matrice[i] = NULL;
	}
	citireMatrice("masini.txt", matrice, nrLinii, nrColoane);
	afisareMatrice(matrice, nrLinii, nrColoane);
	printf ("Pretul mediu este:%5.2f " , pretMediu(matrice, nrLinii, nrColoane, 2));

	struct Masina masina_cautata
	masina_cautata = cautareMasinaID(matrice, nrLinii, nrCol, 2);
	printf("%i %s %i %.2f", masina_cautata.id, masina_cautata.producator, masina_cautata.nrUsi, masina_cautata.pret);

	dezalocareMatrice(&matrice, nrLinii, &nrCol);
}
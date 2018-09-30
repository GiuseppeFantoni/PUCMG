#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#define INFINITO 9999999999
using namespace std;

double distEuclides(long xA, long yA, long xB, long yB);
class Celula {

public:
	string name;
	Celula* prox;
	long** raiz;
	unsigned int tam;
	vector<Celula*> vizinhos;

	Celula() {

		tam = 0;
		name = "";
		prox = NULL;

	}//fim Construtor

	Celula(string s) {

		tam = 0;
		name = s;
		prox = NULL;

	}

	void setRaizTam(unsigned int tam);
};

void Celula::setRaizTam(unsigned int tam) {

	this->tam = tam;

	raiz = new long*[tam];

	for (unsigned int i = 0; i < tam; i++) {

		raiz[i] = new long[2];	// Allocate memory for adjacency matrix

	}//fim for

	for (unsigned int i = 0; i < tam; i++) {

		for (int j = 0; j < 2; j++) {

			raiz[i][j] = 0;

		}



	}

}



double distancia(string pai, Celula* cidade, int x, int y) {

	double retorno = 0;

	for (unsigned int i = 0; i < cidade->vizinhos.tam(); i++) {
		if (cidade->vizinhos.at(i)->name != pai) {

			double menor = (INFINITO);

			for (unsigned int j = 0; j < cidade->vizinhos.at(i)->tam; j++) {
				double d = distEuclides(x ,y, cidade->vizinhos.at(i)->raiz[j][0], cidade->vizinhos.at(i)->raiz[j][1]) + distancia(cidade->name, cidade->vizinhos.at(i), cidade->vizinhos.at(i)->raiz[j][0], cidade->vizinhos.at(i)->raiz[j][1]);
				if (d < menor) menor = d;
			}

			if (menor != (INFINITO)) {
				retorno += menor;
			}
		}
	}
	return retorno;
}

double distancia(Celula* cidade) {
	double menor = INFINITO;
	int x, y;
	for (unsigned int i = 0; i < cidade->tam; i++) {
		x = cidade->raiz[i][0];
		y = cidade->raiz[i][1];
		double d = distancia("", cidade, cidade->raiz[i][0], cidade->raiz[i][1]);
		if (d < menor) menor = d;
	}
	return menor;
}

Celula* getNomeCidade(string nome, vector<Celula*> cidades) {
	Celula* cidade = NULL;
	for (unsigned int i = 0; i < cidades.tam(); i++) {
		if (cidades.at(i)->name == nome) {
			cidade = cidades.at(i);
			break;
		}

	}

	return cidade;

}

double distEuclides(long xA, long yA, long xB, long yB) {

	return sqrt(pow((xA-xB), 2) + pow((yA-yB), 2));

}
int main(){

	vector<Celula*> cidades;
	int cidade, quantidadeRaiz, i;
	long x, y;
	string nome, s1, s2;



	do {

		cin >> cidade;

		if (cidade > 0) {

			for (i = 0; i < cidade; i++) {


				cin >> nome;


				cin >> quantidadeRaiz;

				cidades.push_back(new Celula(nome));
				cidades.at(i)->setRaizTam(quantidadeRaiz);

				for (int j = 0; j < quantidadeRaiz; j++) {


					cin >> x;


					cin >> y;

					cidades.at(i)->raiz[j][0] = x;
					cidades.at(i)->raiz[j][1] = y;

				}

			}

			for (int j = 0; j < cidade - 1; j++) {


				cin >> s1;


				cin >> s2;

				Celula* c1 = getNomeCidade(s1, cidades);
				Celula* c2 = getNomeCidade(s2, cidades);
				c1->vizinhos.push_back(c2);
				c2->vizinhos.push_back(c1);

			}

			cout << round(distancia(cidades.back()) * 10) / 10 << endl;

			cidades.clear();

		}

	}while (city > 0);

	return 0;

}

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#define INFINITO 9999999999
using namespace std;

double distanciaEuclidiana(long xA, long yA, long xB, long yB);
class Celula {

public:
	string name;
	Celula* prox;
	long** rot;
	unsigned int size; 
	vector<Celula*> vizinhos;

	Celula() {

		size = 0;
		name = "";
		prox = NULL;

	}//fim Construtor

	Celula(string s) {

		size = 0;
		name = s;
		prox = NULL;

	}//fim construotor

	void setRotSize(unsigned int size);
};

void Celula::setRotSize(unsigned int size) {

	this->size = size;

	rot = new long*[size];

	for (unsigned int i = 0; i < size; i++) {

		rot[i] = new long[2];	// Allocate memory for adjacency matrix

	}//fim for

	for (unsigned int i = 0; i < size; i++) {

		for (int j = 0; j < 2; j++) {

			rot[i][j] = 0;	// Initialize the vertices to 0
			//cout << rot[i][j] << " ";

		}//fim for

		//cout << endl;

	}//fim for

}//fim setRot



double dist(string pai, Celula* cidade, int x, int y) {

	double retorno = 0;

	for (unsigned int i = 0; i < cidade->vizinhos.size(); i++) {
		if (cidade->vizinhos.at(i)->name != pai) {

			double menor = (INFINITO);

			for (unsigned int j = 0; j < cidade->vizinhos.at(i)->size; j++) {
				double d = distanciaEuclidiana(x ,y, cidade->vizinhos.at(i)->rot[j][0], cidade->vizinhos.at(i)->rot[j][1]) + dist(cidade->name, cidade->vizinhos.at(i), cidade->vizinhos.at(i)->rot[j][0], cidade->vizinhos.at(i)->rot[j][1]);
				if (d < menor) menor = d;
			}

			if (menor != (INFINITO)) {
				retorno += menor;
			}
		}
	}
	return retorno;
}

double dist(Celula* cidade) {
	double menor = INFINITO;
	int x, y;
	for (unsigned int i = 0; i < cidade->size; i++) {
		x = cidade->rot[i][0];
		y = cidade->rot[i][1];
		double d = dist("", cidade, cidade->rot[i][0], cidade->rot[i][1]);
		if (d < menor) menor = d;
	}
	return menor;
}

Celula* getCidadePorNome(string nome, vector<Celula*> cidades) {
	Celula* cidade = NULL;
	for (unsigned int i = 0; i < cidades.size(); i++) {
		if (cidades.at(i)->name == nome) {
			cidade = cidades.at(i);
			break;
		}//fim if

	}//fim for

	return cidade;

}//fim getCidadePorNome

double distanciaEuclidiana(long xA, long yA, long xB, long yB) {

	return sqrt(pow((xA-xB), 2) + pow((yA-yB), 2));

}//fim distanciaEuclidiana
int main(){

	vector<Celula*> cidades;
	int city, qtdRot, i;
	long x, y;
	string nome, s1, s2;

	//cout << "Numero de cidades: ";

	do {

		cin >> city;

		if (city > 0) {

			for (i = 0; i < city; i++) {

				//cout << "Nome da cidade: ";
				cin >> nome;

				//cout << "Quantidade de roteadores: ";
				cin >> qtdRot;

				cidades.push_back(new Celula(nome));
				cidades.at(i)->setRotSize(qtdRot);

				for (int j = 0; j < qtdRot; j++) {

					//cout << "Coordenada X: ";
					cin >> x;

					//cout << "Coordenada Y: ";
					cin >> y;

					cidades.at(i)->rot[j][0] = x;
					cidades.at(i)->rot[j][1] = y;

				}//fim for	

			}//fim for

			for (int j = 0; j < city - 1; j++) {

				//cout << "Cidade: ";
				cin >> s1;

				//cout << "Ligada a: ";
				cin >> s2;

				Celula* c1 = getCidadePorNome(s1, cidades);
				Celula* c2 = getCidadePorNome(s2, cidades);
				c1->vizinhos.push_back(c2);
				c2->vizinhos.push_back(c1);

			}//fim for

			cout << round(dist(cidades.back()) * 10) / 10 << endl;

			cidades.clear();

		}//fim if

	}while (city > 0);

	return 0;

}

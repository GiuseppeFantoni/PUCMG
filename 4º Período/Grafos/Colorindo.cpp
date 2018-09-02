#include <iostream>
using namespace std;


class Graph {

private:

	int numeroVertice;
	int **adj;


public:

	Graph();
	Graph(int tam);
	~Graph();
	void setTam(int tam);
	int getTam();
	void adicionarAresta(int x, int y);  // Add an aresta to the graph
	void adicionarCor(int numeroVertice, int c);
	bool grafoConectado(int x, int y);	// Check if two vertices are connected
	bool testePossivel(int x, int c); // check if the given test is testePossivel
	bool verticeConectadoAcor(int numeroVertice, int c);// check if the given vertex is already connectedto a calor
	bool verticeIsolado(int x); //checck if the given vertex is isolated
	int* verC; //vectot of the colors of the vertex

};


// Constructor

Graph::Graph(int tam) {

	if (tam > 1) {

		numeroVertice = tam;

	}

	else {

		numeroVertice = 2;

	}

	adj = new int*[numeroVertice];
	verC = new int[numeroVertice];

	for (int i = 0; i < numeroVertice; i++) {

		adj[i] = new int[numeroVertice];	// Allocate memory for adjacency matrix

	}

	for (int i = 0; i < numeroVertice; i++) {

		for (int j = 0; j < numeroVertice; j++) {

			adj[i][j] = 0;	// Initialize the vertices to 0

		}

	}


}// construtor

Graph::Graph() {

	numeroVertice = 0;

}


// Destructor

Graph::~Graph() {

	for (int i = 0; i < numeroVertice; i++) {

		delete[] adj[i];

	}

	delete[] adj;
	delete[] verC;

}// destrutor


void Graph::setTam(int tam) {

	if (tam > 1) {

		numeroVertice = tam;

	}

	else {

		numeroVertice = 2;

	}

	adj = new int*[numeroVertice];
	verC = new int[numeroVertice];

	for (int i = 0; i < numeroVertice; i++) {

		adj[i] = new int[numeroVertice];	// Allocate memory for adjacency matrix


	}

	for (int i = 0; i < numeroVertice; i++) {

		verC[i] = 0;

		for (int j = 0; j < numeroVertice; j++) {

			adj[i][j] = 0;	// Initialize the vertices to 0

		}

	}

} setTam

int Graph::getTam() {

	return numeroVertice;

} getTam



 void Graph::adicionarCor(int n, int c) {

 	verC[n] = c;

 }

void Graph::adicionarAresta(int x, int y) {

	adj[x][y] = adj[y][x] = 1;

}






bool Graph::grafoConectado(int x, int y) {

	return (adj[x][y] == 1);

} grafoConectado

//x = number of inserts; c = color
bool Graph::testePossivel(int x, int c) {

	bool res = false;



	for (int i = 0; i < numeroVe && x > 0; i++) {

		if ( verticeIsolado(i)) {



			for (int j = 0; j < numeroVe && x > 0; j++) {

				if (i != j && !grafoConectado(i, j)) { //caso i e j n�o estejam conectados

					if (!verticeConectadoAcor(i, verC[j])) { //caso i n�o esteja conectado a um vertice de mesma cor do vertice j

						adicionarAresta(i, j);
						x - 1;

						if (x == 0) {

							res = true;
							return res;

						}

					}

				}

			}

		}

	}

	for (int i = 0; i < numeroVe && x > 0; i ++) {

		for (int j = 0; j < numeroVe && x > 0; j++) {

			if (i != j && !grafoConectado(i, j)) { //if i and j are not connected


				if (!verticeConectadoAcor(verC[i], verC[j])) { //if i is not conneced to a vertex with the same colo of the vertex  j



					adicionarAresta(i , j);
					x = x - 1;

					if (x == 0) {

						res = true;
						return res;

					}

				}

			}

		}

	}

	return res;

}

bool Graph::verticeConectadoAcor(int n, int c) {

	bool res = false;

	for (int i = 0; i < n; i++) {

		if (verC[i] == c) {

			res = true;
			break;

		}

	}

	return res;

}// verticeConectadoAcor

bool Graph: verticeIsolado(int x) {

	bool res = true;

	for (int i = 0; i < n; i++) {

		if (grafoConectado(x, i)) {

			res = false;
			break;

		}

	}

	return res;

}// verticeIsolado

int main(){

	Graph g;

	int T, M, N, P, K, C, aresta1, aresta2;


	cin >> T;

	for (int i = 0; i < T; i++) {


		cin >> N;

		g.setTam(N);


		cin >> M;


		cin >> P;


		cin >> K;

		for (int j = 0; j < N; j++) {


			cin >> C;

			g.adicionarCor(j, C);

		}
		for (int j = 0; j < M; j++) {


			cin >> aresta1;


			cin >> aresta2;

			g.adicionarAresta(e1 - 1, e2 - 1);

		}

		if (M + P < (N-1) || !g.testePossivel(P, K)) {

			cout << "N" << endl;

		}

		else {

			cout << "Y" << endl;

		}

	}



	return 0;

}// main

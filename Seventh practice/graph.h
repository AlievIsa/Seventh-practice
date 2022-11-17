#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//struct Edge {
//	int v;
//	int w;
//	Edge(int v, int w) {
//		this->v = v;
//		this->w = w;
//	}
//};

class Graph {
	int V;
	int E;
	int** Matr;
public:
	Graph(int V) {
		this->V = V;
		E = 0;
		Matr = new int* [V];
		for (int i = 0; i < V; i++) {
			Matr[i] = new int[V];
		}
		
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				Matr[i][j] = 0;
			}
		}
	}

	void insert(int v, int w, int val) {
		v--;
		w--;
		if ( v < V && w < V) {
			if (Matr[v][w] == 0) {
				E++;
				Matr[v][w] = val;
				Matr[w][v] = val;
			}
		}
	}

	/*void remove(int v, int w) {
		if (v < V && w < V) {
			Matr[v][w] = 0;
			Matr[v][w] = 0;
		}
	}*/

	vector <int> findCenter() {
		vector <int> c;
		int minAmount = 1000, amount = 0, i, j;
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (Matr[i][j] == 0)
					amount++;
			}
			if (amount < minAmount)
				minAmount = amount;
			amount = 0;
		}

		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (Matr[i][j] == 0)
					amount++;
			}
			if (amount == minAmount) {
				c.push_back(++i);
				i--;
			}
			amount = 0;
		}

		return c;
	}



	void print() {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cout << setw(5) << Matr[i][j];
			}
			cout << "\n";
		}
	}

	~Graph() {
		for (int i = 0; i < V; i++)
			delete[] Matr[i];
		delete[] Matr;
	}
};


//int** d = new int* [V]; //Lвумерный массив дистанций
//int* e = new int[V]; // Эксцентриситет вершин
//vector <int> c; // Центр графа
//int rad = 10000; // Радиус графа
//
//for (int i = 0; i < V; i++)
//	d[i] = new int[V];
//
//for (int i = 0; i < V; i++) {
//	for (int j = 0; j < V; j++) {
//		if (Matr[i][j] != 0)
//			d[i][j] = 1;
//		else
//			d[i][j] = 0;
//	}
//}
//
//// Алгоритм Флойда-Уоршелла
//for (int k = 0; k < V; k++) {
//	for (int j = 0; j < V; j++) {
//		for (int i = 0; i < V; i++) {
//			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//		}
//	}
//}
//
//// Нахождение эксцентриситета
//for (int i = 0; i < V; i++) {
//	for (int j = 0; j < V; j++) {
//		e[i] = max(e[i], d[i][j]);
//	}
//}
//
//// Нахождение диаметра и радиуса
//for (int i = 0; i < V; i++) {
//	rad = min(rad, e[i]);
//}
//
//for (int i = 0; i < V; i++) {
//	if (e[i] == rad) {
//		c.push_back(i);
//	}
//}
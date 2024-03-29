// passeioCavalo.cpp : define o ponto de entrada para o aplicativo do console.

#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<chrono>

using namespace std;
using namespace chrono;

#define LINE  5	
#define COLUMN 5	
int mat[LINE][COLUMN];

bool horseRide(int steps, int x, int y) {
	if (steps == (LINE*COLUMN) + 1) {			//se o cavalo chegar a dar o passo 26, ele conseguiu completar o passeio com sucesso.
		return true;
	}
	else if (x < 0 || x >= LINE || y < 0 || y >= COLUMN) {		//verifica se a posicao atual do cavalo está fora da matriz.
		return false;
	}
	else if (mat[x][y] != 0) {			//verifica se a casa ja foi vizitada antes.
		return false;
	}
	else {
		mat[x][y] = steps;				//se todas as verificacoes acima falharem signf. q a posicao é valida e atribuo ela como um passo.
		if (horseRide(steps + 1, x - 1, y - 2)) {
			return true;
		}
		else if (horseRide(steps + 1, x - 2, y - 1)) {
			return true;
		}
		else if (horseRide(steps + 1, x - 2, y + 1)) {
			return true;
		}
		else if (horseRide(steps + 1, x - 1, y + 2)) {
			return true;
		}
		else if (horseRide(steps + 1, x + 1, y + 2)) {
			return true;
		}
		else if (horseRide(steps + 1, x + 2, y + 1)) {
			return true;
		}
		else if (horseRide(steps + 1, x + 2, y - 1)) {
			return true;
		}
		else if (horseRide(steps + 1, x + 1, y - 2)) {
			return true;
		}
		else {
			mat[x][y] = 0;
			return false;
		}
	}
}
int main() {
	steady_clock::time_point startTime = steady_clock::now();
	int line, column;
	long long duration;
	srand(time(NULL));

	line = rand() % 5 + 1;
	column = rand() % 5 + 1;

	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			mat[i][j] = 0;
		}
	}
	if (horseRide(1, line, column)) {
		for (int x = 0; x < LINE; x++) {
			for (int y = 0; y < COLUMN; y++) {
				cout << mat[x][y] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		cout << "Posicao incial do cavalo:" << "[" << line << "]" << "[" << column << "]" << endl;
		cout << endl;
		steady_clock::time_point tempoFinal = steady_clock::now();
		duration = duration_cast<milliseconds>(tempoFinal - startTime).count();
		cout << "Duracao para o cavalo passar por toda a matriz:  " << duration << "ms " << endl; 
	}
	else {
		cout << "Nao existe solucao" << endl;
		cout << "Posicao incial do cavalo:" << "[" << line << "]" << "[" << column << "]" << endl;
		cout << endl;
		steady_clock::time_point tempoFinal = steady_clock::now();
		duration = duration_cast<milliseconds>(tempoFinal - startTime).count();
		cout << "Duracao para o cavalo passar por toda a matriz:  " << duration<< "ms " << endl;
	}
	system("pause");
	return 0;
}
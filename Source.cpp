#include <iostream>
#include<ctime>
#include<cmath>

using namespace std;

int main() {
	srand(time(NULL));

	//massA:
	double massA[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			massA[i][j] = rand() % 5;
		}
	}
	cout << "coefficient matrix A:\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << massA[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	//vecX:
	double vecX[10];
	for (int i = 0; i < 10; i++) {
		vecX[i] = rand() % 5;
	}

	//вывод vecX:
	cout << "vector X:\n";
	for (int i = 0; i < 10; i++) {
		cout << vecX[i] << "\n";
	}
	cout << "\n";

	//massB:
	double massB[10];
	for (int i = 0; i < 10; i++) {
		massB[i] = 0;
	}

	//подсчет b:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			massB[i] += massA[i][j] * vecX[j];
		}
	}

	//вывод massB:
	cout << "matrix b:\n";
	for (int i = 0; i < 10; i++) {
		cout << massB[i] << "\n";
	}
	cout << "\n";

	//massAxB:
	double massAxB[10][10 + 1];

	//объединение massA с massB:
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			massAxB[i][j] = massA[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 10; j < 10 + 1; j++) {
			massAxB[i][j] = massB[i];
		}
	}

	//вывод massAxB:
	cout << "matrix A + matrix b:\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10 + 1; j++) {
			cout << massAxB[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	//massX:
	double massX[10];
	for (int i = 0; i < 10; i++) {
		massX[i] = rand() % 5;
	}

	//метод Гаусса:
	int i, j, k;

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (abs(massAxB[i][i]) < abs(massAxB[j][i]))
			{
				for (k = 0; k < 10 + 1; k++)
				{
					massAxB[i][k] = massAxB[i][k] + massAxB[j][k];
					massAxB[j][k] = massAxB[i][k] - massAxB[j][k];
					massAxB[i][k] = massAxB[i][k] - massAxB[j][k];
				}
			}
		}
	}

	//приведение к ступенчатому виду:
	for (i = 0; i < 10 - 1; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			float f = massAxB[j][i] / massAxB[i][i];
			for (k = 0; k < 10 + 1; k++)
			{
				massAxB[j][k] = massAxB[j][k] - f * massAxB[i][k];
			}
		}
	}

	//обратный ход:
	for (i = 10 - 1; i >= 0; i--)
	{
		massX[i] = massAxB[i][10];

		for (j = i + 1; j < 10; j++)
		{
			if (i != j)
			{
				massX[i] = massX[i] - massAxB[i][j] * massX[j];
			}
		}
		massX[i] = massX[i] / massAxB[i][i];
	}
	cout << "values x1-x10:\n";
	for (i = 0; i < 10; i++)
	{
		cout << massX[i] << "\n";
	}
	cout << "\n";
	cout << "error value:\n";
	for (i = 0; i < 10; i++) {
		cout << vecX[i] - massX[i] << "\n";
	}
}
	
	
#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
	char path[256];
	strcpy(path, "D:\\EDA\\dados.txt");

	Matriz matriz_a, matriz_b;

	if (matriz_a.Ler(path))
	{
		printf("\nSuccess\n");
	}else
	{
		printf("\nFail\n");
	};
	matriz_a.Escrever();
	system("pause");
}

#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char path[256];
	strcpy(path, "D:\\EDA\\dados.txt");

	Matriz matriz_a, matriz_b, matriz_c;

	if (matriz_a.Ler(path))
	{
		printf("\nSuccess\n");
	}else
	{
		printf("\nFail\n");
	};
	matriz_a.Escrever();

	matriz_b = matriz_a;
	matriz_c = matriz_a + matriz_b;

	matriz_b.Escrever();

	matriz_c.Escrever();

	matriz_a.PodeMultiplicar(&matriz_b);

	matriz_c = matriz_a * matriz_b;

	matriz_c.Escrever();

	system("pause");
	return 0;
}

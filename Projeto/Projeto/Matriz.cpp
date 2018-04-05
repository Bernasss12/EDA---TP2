#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

Matriz::Matriz()
{
	elems = NULL;
	linhas = 0;
	colunas = 0;
}

void Matriz::Iniciar(int nLinhas, int nColunas) 
{
	linhas = nLinhas;
	colunas = nColunas;
	elems = new float*[linhas];
	for (int i = 0; i < linhas; i++)
	{
		elems[i] = new float[colunas];
		for (int j = 0; j < colunas; j++)
		{
			elems[i][j] = 0;
		}
	}
} // Função responsável pela criação de uma matriz com nLinhas e nColunas variaveis com todos os valores a zero.

Matriz::Matriz(const Matriz& m1)
{
	Iniciar(m1.linhas, m1.colunas);
	for (int i = 0; i < m1.linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			elems[i][j] = m1.elems[i][j];
		}
	}
} // Método que cria uma matriz apartir de outra.

Matriz::Matriz(int nLinhas, int nColunas)
{
	Iniciar(nLinhas, nColunas);
} // Função equivalente à função Iniciar mas funciona através da omissao do método e questão

void Matriz::Apagar()
{
	for (int i = 0; i<linhas; i++)
		delete[]elems[i];
	delete[]elems;
} // Método que apaga a matriz.

bool Matriz::Ler(char*nome_ficheiro)
{
	FILE*ficheiro;
	ficheiro = fopen(nome_ficheiro, "r");
	if (!ficheiro) return false;
	fscanf_s(ficheiro, "%d,%d", &linhas, &colunas);
	Iniciar(linhas, colunas);
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
			fscanf_s(ficheiro, "%f", &elems[i][j]);
	}
	fclose(ficheiro);
	return true;
}

void Matriz::Escrever()
{
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			printf("%.1f  ", elems[i][j]);
		}
		printf("\n");
	}
}

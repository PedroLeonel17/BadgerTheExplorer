//Pedro Leonel, Marco Leite, Jhavan Maciel.
//Badger The explorer

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define ALTURA 63
#define LARGURA 140
#define _AltTex_ 6
#define _LargTex_ 10
#define _AltPanda_ 8
#define _LargPanda_ 11
#define _AltRifeiro_ 10
#define _LargRifeiro_ 10
#define _AltDog_ 7
#define _LargDog_ 13
#define _AltMuro_ 14
#define _LargMuro_ 5
#define _AltMuro2_ 3
#define _LargMuro2_ 20
#define _AltCho_ 5
#define _LargCho_ 7
#define _AltCarta_ 6
#define _LargCarta_ 12
#define _AltOculos_ 3
#define _LargOculos_ 11
#define PI 3.141592

#define _ProbabilidadeChoco_ 0.60

HANDLE wHnd;
HANDLE rHnd;

//Verifica colis�o
void PlotaPonto(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char caracter, unsigned char cor)
{
	TELA[(PosY) + LARGURA * (PosX)].Char.AsciiChar = caracter;
	TELA[(PosY) + LARGURA * (PosX)].Attributes = cor;
}
//Colis�o
bool VerificaColisao(int PosXObjeto, int PosYObjeto, int PosXAlvo, int PosYAlvo, int _AltAlvo_, int _LargAlvo_, int _AltObjeto_, int _LargObjeto_)
{

	int a, l, a1, l1, c, w, c1, w1;
	bool Colidiu = false;
	for (a = 0; a < _AltAlvo_; a++)
	{
		for (l = 0; l < _LargAlvo_; l++)
		{
			a1 = a + PosXAlvo;
			l1 = l + PosYAlvo;
			for (w = 0; w < _AltObjeto_; w++)
			{
				for (c = 0; c < _LargObjeto_; c++)
				{
					w1 = w + PosXObjeto;
					c1 = c + PosYObjeto;
					if ((a1 == w1) && (l1 == c1))
					{
						Colidiu = true;
					}
				}
			}
		}
	}
	return Colidiu;
}

void InscreveTexugo(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Texugo[_AltTex_][_LargTex_], unsigned char Texugocor[_AltTex_][_LargTex_])
{
	int x, y;
	for (x = 0; x < _AltTex_; x++)
	{
		for (y = 0; y < _LargTex_; y++)
		{
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Texugo[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = Texugocor[x][y];
		}
	}
}

void InscreveRifeiro(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Rifeiro[_AltRifeiro_][_LargRifeiro_], unsigned char Rifeirocor[_AltRifeiro_][_LargRifeiro_])
{
	int x, y;
	for (x = 0; x < _AltRifeiro_; x++)
	{
		for (y = 0; y < _LargRifeiro_; y++)
		{
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Rifeiro[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = Rifeirocor[x][y];
		}
	}
}

void InscrevePanda(CHAR_INFO TELA[LARGURA * ALTURA], int PosXpanda, int PosYpanda, char Panda[_AltPanda_][_LargPanda_], unsigned char Pandacor[_AltPanda_][_LargPanda_])
{
	int z, a;
	for (z = 0; z < _AltPanda_; z++)
	{
		for (a = 0; a < _LargPanda_; a++)
		{
			TELA[(PosYpanda + a) + LARGURA * (PosXpanda + z)].Char.AsciiChar = Panda[z][a];
			TELA[(PosYpanda + a) + LARGURA * (PosXpanda + z)].Attributes = Pandacor[z][a];
		}
	}
}

void InscreveDog(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Dog[_AltDog_][_LargDog_], unsigned char Dogcor[_AltDog_][_LargDog_])
{
	int x, y;
	for (x = 0; x < _AltDog_; x++)
	{
		for (y = 0; y < _LargDog_; y++)
		{
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Dog[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = Dogcor[x][y];
		}
	}
}

void InscreveChoco(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Choco[_AltCho_][_LargCho_], unsigned char Chococor[_AltCho_][_LargCho_])
{
	int x, y;
	for (x = 0; x < _AltCho_; x++)
	{
		for (y = 0; y < _LargCho_; y++)
		{
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Choco[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = Chococor[x][y];
		}
	}
}

void InscreveCarta(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Carta[_AltCarta_][_LargCarta_], unsigned char CartaCor[_AltCarta_][_LargCarta_])
{
	int x, y;
	for (x = 0; x < _AltCarta_; x++)
	{
		for (y = 0; y < _LargCarta_; y++)
		{
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Carta[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = CartaCor[x][y];
		}
	}
}

void InscreveOculos(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Oculos[_AltOculos_][_LargOculos_], unsigned char Oculoscor[_AltOculos_][_LargOculos_])
{
	int x, y;
	for (x = 0; x < _AltOculos_; x++)
	{
		for (y = 0; y < _LargOculos_; y++)
		{
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Oculos[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = Oculoscor[x][y];
		}
	}
}

void InscreveMuro(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Muro[_AltMuro_][_LargMuro_], unsigned char Atributos)
{
	int x, y;
	for (x = 0; x < _AltMuro_; x++)
	{
		for (y = 0; y < _LargMuro_; y++)
		{
			Muro[x][y] = 219;
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Muro[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = Atributos;
		}
	}
}

void InscreveMuro2(CHAR_INFO TELA[LARGURA * ALTURA], int PosX, int PosY, char Muro2[_AltMuro2_][_LargMuro2_], unsigned char Atributos)
{
	int x, y;
	for (x = 0; x < _AltMuro2_; x++)
	{
		for (y = 0; y < _LargMuro2_; y++)
		{
			Muro2[x][y] = 219;
			TELA[(PosY + y) + LARGURA * (PosX + x)].Char.AsciiChar = Muro2[x][y];
			TELA[(PosY + y) + LARGURA * (PosX + x)].Attributes = Atributos;
		}
	}
}

void PintaTela(CHAR_INFO TELA[LARGURA * ALTURA], unsigned char CodigoCaracter, unsigned char CodigoCor, int Pontos, int Vidas, int Tempo)

{
	int x, y, i;
	for (x = 0; x < ALTURA; x++)
	{
		for (y = 0; y < LARGURA; y++)
		{
			TELA[y + LARGURA * x].Char.AsciiChar = CodigoCaracter;
			TELA[y + LARGURA * x].Attributes = CodigoCor;
		}
	}
	// Moldura
	for (y = 0; y < LARGURA; y++)
	{
		// linha inferior
		TELA[y + LARGURA * (ALTURA - 1)].Char.AsciiChar = 219;
		TELA[y + LARGURA * (ALTURA - 1)].Attributes = 1110;
		// linha superior
		TELA[y + LARGURA * (0)].Char.AsciiChar = 219;
		TELA[y + LARGURA * (0)].Attributes = 1110;
	}

	for (x = 0; x < ALTURA; x++)
	{
		// linha esquerda
		TELA[0 + LARGURA * (x)].Char.AsciiChar = 219;
		TELA[0 + LARGURA * (x)].Attributes = 1110;
		// linha direita
		TELA[(LARGURA - 1) + LARGURA * (x)].Char.AsciiChar = 219;
		TELA[(LARGURA - 1) + LARGURA * (x)].Attributes = 1110;
	}

	clock_t start;
	double cpu_time_used;
	start = clock();
	cpu_time_used = (double)start / CLOCKS_PER_SEC;
	Tempo = cpu_time_used;

	char ListaVidas[5];
	for (i = 0; i < 5; i++)
	{
		ListaVidas[i] = 197; //Desenha as cruzinhas
	}

	for (i = 0; i < Vidas; i++)
	{
		ListaVidas[i] = 003; //Desenha os cora��eszinhos
	}

	char Pontuacao[39];
	for (x = 0; x < 39; x++)
		Pontuacao[x] = 255; // limpa buffer
	sprintf(Pontuacao, "Pontos:%3d Tempo:%3ds Vidas: %c %c %c %c %c ", Pontos, Tempo, ListaVidas[0], ListaVidas[1], ListaVidas[2], ListaVidas[3], ListaVidas[4]);
	strcpy(&TELA[1 * 1], Pontuacao);

	for (x = 1; x < 40; x++)
	{
		TELA[x + LARGURA * 0].Char.AsciiChar = Pontuacao[x - 1];
		TELA[x + LARGURA * 0].Attributes = 353;
	}
}

int main(int argc, char *argv[])
{

	int Controle[15][30];
	//Tipo,PosX,PosY,Sentido,Dire��o,Velocidade,Sprite,Status;

	int x, y;
	for (x = 0; x < 15; x++)
	{
		for (y = 0; y < 30; y++)
		{
			Controle[x][y] = 0;
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//SPRITES
	char Muro[_AltMuro_][_LargMuro_];

	char Muro2[_AltMuro2_][_LargMuro2_];

	char Texugo[_AltTex_][_LargTex_] =
		{
			//sprite
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
		};

	unsigned char Texugocor[3][_AltTex_][_LargTex_] = {
		{
			{000, 307, 307, 307, 307, 000, 000, 307, 000, 000},
			{307, 000, 303, 307, 307, 307, 303, 000, 303, 307},
			{307, 303, 000, 303, 000, 000, 305, 000, 305, 307},
			{307, 307, 307, 000, 303, 000, 303, 000, 303, 000},
			{307, 307, 307, 000, 303, 000, 307, 000, 307, 307},
			{307, 307, 000, 000, 307, 307, 307, 000, 303, 307},
		},

		{
			{307, 000, 307, 307, 307, 000, 000, 307, 000, 000},
			{307, 307, 000, 303, 307, 307, 303, 000, 303, 307},
			{307, 307, 303, 303, 000, 000, 305, 000, 305, 307},
			{307, 307, 307, 000, 303, 000, 303, 000, 303, 000},
			{307, 307, 000, 000, 307, 000, 307, 000, 307, 307},
			{307, 307, 307, 307, 303, 000, 307, 000, 303, 307},
		},

		{
			{307, 307, 307, 307, 307, 000, 000, 307, 000, 000},
			{000, 000, 303, 307, 307, 307, 303, 000, 303, 307},
			{307, 303, 000, 303, 000, 000, 305, 000, 305, 307},
			{307, 307, 307, 000, 303, 000, 303, 000, 303, 000},
			{307, 307, 307, 000, 307, 000, 307, 000, 303, 307},
			{307, 307, 000, 000, 303, 000, 307, 307, 307, 307},
		},
	};
	char Panda[_AltPanda_][_LargPanda_] =
		{
			//Sprite 1
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
		};

	unsigned char Pandacor[3][_AltPanda_][_LargPanda_] = {
		{
			{307, 307, 307, 307, 307, 307, 000, 307, 307, 307, 000},
			{000, 307, 000, 000, 000, 000, 307, 000, 000, 000, 307},
			{307, 000, 000, 303, 303, 303, 000, 1016, 303, 1016, 000},
			{307, 000, 303, 303, 303, 303, 000, 303, 000, 303, 000},
			{307, 000, 303, 303, 303, 303, 000, 303, 303, 303, 000},
			{307, 000, 000, 303, 303, 303, 303, 000, 000, 000, 307},
			{307, 307, 000, 000, 000, 000, 000, 307, 000, 000, 000},
			{307, 000, 000, 307, 307, 000, 000, 307, 307, 307, 307},
		},
		{
			{307, 307, 307, 307, 307, 307, 000, 307, 307, 307, 000},
			{000, 307, 000, 000, 000, 000, 307, 000, 000, 000, 307},
			{307, 000, 000, 303, 303, 303, 000, 1016, 303, 1016, 000},
			{307, 000, 303, 303, 303, 303, 000, 303, 000, 303, 000},
			{307, 000, 303, 303, 303, 303, 000, 303, 303, 303, 000},
			{307, 000, 000, 303, 303, 303, 303, 000, 000, 000, 307},
			{307, 000, 000, 000, 000, 000, 000, 307, 000, 000, 307},
			{307, 307, 307, 307, 307, 000, 000, 307, 307, 000, 000},
		},
		{
			{307, 307, 307, 307, 307, 307, 000, 307, 307, 307, 000},
			{000, 307, 000, 000, 000, 000, 307, 000, 000, 000, 307},
			{307, 000, 000, 303, 303, 303, 000, 1016, 303, 1016, 000},
			{307, 000, 303, 303, 303, 303, 000, 303, 000, 303, 000},
			{307, 000, 303, 303, 303, 303, 000, 303, 303, 303, 000},
			{307, 000, 000, 303, 303, 303, 303, 000, 000, 000, 307},
			{307, 307, 000, 000, 000, 000, 000, 307, 000, 000, 307},
			{307, 000, 000, 307, 307, 307, 307, 307, 307, 000, 000},
		},
	};

	char Dog[_AltDog_][_LargDog_] =
		{
			//Sprite 1
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
		};

	unsigned char Dogcor[3][_AltDog_][_LargDog_] = {
		{
			{307, 307, 307, 307, 307, 307, 310, 310, 307, 307, 307, 310, 310},
			{307, 310, 310, 307, 307, 307, 307, 307, 310, 307, 310, 307, 307},
			{310, 307, 310, 307, 310, 310, 310, 310, 316, 310, 316, 307, 307},
			{307, 307, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 000},
			{307, 307, 307, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310},
			{307, 307, 307, 310, 310, 307, 310, 307, 310, 307, 307, 307, 307},
			{307, 307, 307, 307, 307, 310, 310, 307, 310, 310, 307, 307, 307},
		},
		{
			{307, 310, 307, 307, 307, 307, 310, 310, 307, 307, 307, 310, 310},
			{307, 310, 310, 307, 307, 307, 307, 307, 310, 307, 310, 307, 307},
			{307, 307, 310, 307, 310, 310, 310, 310, 316, 310, 316, 307, 307},
			{307, 307, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 000},
			{307, 307, 307, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310},
			{307, 307, 307, 307, 310, 310, 310, 307, 310, 307, 307, 307, 307},
			{307, 307, 307, 310, 310, 307, 307, 307, 310, 310, 307, 307, 307},
		},
		{
			{307, 307, 307, 307, 307, 307, 310, 310, 307, 307, 307, 310, 310},
			{307, 307, 310, 307, 307, 307, 307, 307, 310, 307, 310, 307, 307},
			{310, 310, 307, 307, 310, 310, 310, 310, 316, 310, 316, 307, 307},
			{307, 307, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310, 000},
			{307, 307, 307, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310},
			{307, 307, 307, 307, 310, 307, 310, 307, 310, 310, 307, 307, 307},
			{307, 307, 307, 310, 310, 310, 310, 307, 307, 307, 307, 307, 307},
		},
	};
	char Choco[_AltCho_][_LargCho_] =
		{
			{179, 95, 93, 95, 93, 000, 000},
			{179, 95, 93, 95, 93, 95, 93},
			{179, 67, 72, 79, 67, 79, 179},
			{179, 76, 65, 67, 84, 65, 179},
			{179, 178, 178, 178, 178, 178, 179},
		};

	unsigned char Chococor[_AltCho_][_LargCho_] =
		{
			{104, 104, 104, 104, 104, 104, 304},
			{104, 104, 104, 104, 104, 104, 104},
			{243, 243, 243, 243, 243, 243, 243},
			{243, 243, 243, 243, 243, 243, 243},
			{243, 95, 95, 95, 95, 95, 243},
		};

	char Carta[_AltCarta_][_LargCarta_] =
		{
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},

		};
	unsigned char CartaCor[_AltCarta_][_LargCarta_] =
		{
			{000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000},
			{000, 1010, 1010, 1010, 1010, 001, 001, 1010, 1010, 1010, 1010, 000},
			{000, 1010, 1010, 1010, 1010, 001, 001, 1010, 1010, 1010, 1010, 000},
			{000, 001, 1010, 1010, 1010, 1010, 001, 001, 1010, 1010, 1010, 000},
			{000, 001, 001, 001, 001, 001, 001, 001, 001, 1010, 1010, 000},
			{000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000},
		};

	char Oculos[_AltOculos_][_LargOculos_] =
		{
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 220, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
		};

	unsigned char Oculoscor[_AltOculos_][_LargOculos_] =
		{
			{110, 110, 110, 307, 307, 307, 307, 307, 307, 318, 307},
			{110, 307, 110, 110, 110, 110, 110, 110, 110, 110, 110},
			{110, 110, 110, 307, 307, 307, 307, 307, 110, 307, 110},
		};
	char Rifeiro[_AltRifeiro_][_LargRifeiro_] =
		{
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},
			{219, 219, 219, 219, 219, 219, 219, 219, 219, 219},

		};

	unsigned char RifeiroCor[3][_AltRifeiro_][_LargRifeiro_] =
		{

			{
				{307, 307, 303, 303, 303, 307, 307, 307, 307, 307},
				{307, 307, 303, 303, 000, 307, 307, 307, 307, 307},
				{307, 307, 307, 303, 303, 307, 307, 307, 307, 307},
				{307, 307, 307, 303, 307, 307, 307, 312, 312, 307},
				{307, 307, 000, 303, 303, 307, 307, 000, 307, 312},
				{307, 000, 307, 303, 307, 303, 000, 307, 307, 312},
				{303, 307, 307, 303, 307, 000, 307, 307, 307, 307},
				{307, 307, 303, 307, 000, 307, 307, 307, 307, 307},
				{307, 303, 307, 000, 307, 303, 307, 307, 307, 307},
				{303, 303, 307, 307, 307, 303, 303, 307, 307, 307},
			},
			{
				{307, 307, 303, 303, 303, 307, 307, 307, 307, 307},
				{307, 307, 303, 303, 000, 307, 307, 307, 307, 307},
				{307, 307, 307, 303, 303, 307, 307, 312, 307, 307},
				{307, 307, 307, 303, 307, 307, 307, 307, 312, 307},
				{307, 307, 000, 303, 303, 307, 307, 307, 000, 312},
				{307, 000, 307, 303, 307, 303, 307, 000, 307, 312},
				{303, 307, 307, 303, 307, 307, 000, 307, 307, 312},
				{307, 307, 303, 307, 303, 000, 307, 307, 307, 307},
				{307, 303, 307, 307, 000, 303, 307, 307, 307, 307},
				{303, 303, 307, 307, 307, 303, 303, 307, 307, 307},
			},
			{
				{307, 307, 303, 303, 303, 307, 307, 307, 307, 307},
				{307, 307, 303, 303, 000, 307, 307, 307, 307, 307},
				{307, 307, 307, 303, 303, 307, 307, 307, 307, 307},
				{307, 307, 307, 303, 307, 307, 307, 312, 312, 307},
				{307, 307, 000, 303, 303, 307, 307, 000, 307, 312},
				{307, 000, 307, 303, 307, 303, 000, 307, 307, 312},
				{303, 307, 307, 303, 307, 000, 307, 307, 307, 307},
				{307, 307, 303, 307, 000, 307, 307, 307, 307, 307},
				{307, 303, 307, 000, 307, 303, 307, 307, 307, 307},
				{303, 303, 307, 307, 307, 303, 303, 307, 307, 307},
			},

		};

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	srand(time(0));

	/* Window size coordinates, be sure to start index at zero! */
	SMALL_RECT tamanhojanela = {0, 0, LARGURA - 1, ALTURA - 1};

	/* A COORD struct for specificying the console's screen buffer dimensions */
	COORD tamanhobuffer = {LARGURA, ALTURA};

	/* Setting up different variables for passing to WriteConsoleOutput */
	COORD characterBufferSize = {LARGURA, ALTURA};
	COORD characterPosition = {0, 0};
	SMALL_RECT consoleWriteArea = {0, 0, LARGURA - 1, ALTURA - 1};

	CHAR_INFO TELA[LARGURA * ALTURA];

	/* initialize handles */
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);

	/* Set the console's title */
	SetConsoleTitle("BADGER the Explorer");

	/* Set the window size */
	SetConsoleWindowInfo(wHnd, TRUE, &tamanhojanela);

	/* Set the screen's buffer size */
	SetConsoleScreenBufferSize(wHnd, tamanhobuffer);

	int Vidas = 5;
	int Tempo = 0;
	int Pontos = 0;
	int velporta = 0;
	int velporta1 = 0;
	int cont = 0;
	int Tecla = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//CONTROLES DOS OBJETOS

	//Personagem
	Controle[0][0] = 0;	  //Perso
	Controle[0][1] = 2;	  //posX
	Controle[0][2] = 115; //posY
	Controle[0][3] = -1;  //Sentido 0 pra cima, 1 pra baixo
	Controle[0][4] = -1;  //Dire��o 0 para esquerda, 1 para direita
	Controle[0][5] = 5;	  //velocidade
	Controle[0][6] = 0;	  //sprite
	Controle[0][7] = -1;  //STATUS

	//Muros Verticais
	Controle[1][0] = 1;	   //MURO 1
	Controle[1][1] = 53;   //MURO 1
	Controle[1][2] = 13;   //MURO 2
	Controle[1][3] = 53;   //MURO 2
	Controle[1][4] = 1;	   //MURO 3
	Controle[1][5] = 102;  //MURO 3
	Controle[1][6] = 13;   //MURO 4
	Controle[1][7] = 102;  //MURO 4
	Controle[1][8] = 36;   //MURO 5
	Controle[1][9] = 28;   //MURO 5
	Controle[1][10] = 35;  //MURO 6
	Controle[1][11] = 28;  //MURO 6
	Controle[1][12] = 36;  //MURO 7
	Controle[1][13] = 103; //MURO 7
	Controle[1][14] = 35;  //MURO 8
	Controle[1][15] = 103; //MURO 8
	Controle[1][16] = 12;  //MURO 9
	Controle[1][17] = 1;   //MURO 9
	Controle[1][18] = 24;  //MURO 10

	//MUROS HORIZONTAIS
	Controle[1][19] = 87; //MURO 10
	Controle[1][20] = 24; //MURO 11
	Controle[1][21] = 78; //MURO 11

	//PORTAS
	Controle[1][22] = 1;  //PORTA 1
	Controle[1][23] = 21; //PORTA 1
	Controle[1][24] = 24; //PORTA 2
	Controle[1][25] = 58; //PORTA 2
	Controle[1][26] = 1;  //sentido
	Controle[1][27] = 1;  //PORTA 1
	Controle[1][28] = 1;  //PORTA 1
	//PANDA
	Controle[2][0] = 0;
	Controle[2][1] = 41; //POSX
	Controle[2][2] = 4;	 //POSY
	Controle[2][3] = -1; //Sentido 0 pra cima, 1 pra baixo
	Controle[2][4] = 1;	 //Dire��o 0 para esquerda, 1 para direita
	Controle[2][5] = 1;	 //velocidade
	Controle[2][6] = 0;	 //sprite
	Controle[2][7] = -1; //STATUS
	int PosX, PosY;		 //MOVIMENTO CIRCULAR

	//DOG
	Controle[3][0] = -1;
	Controle[3][1] = 10; //POSX
	Controle[3][2] = 59; //POSY
	Controle[3][3] = -1; //Sentido 0 pra cima, 1 pra baixo
	Controle[3][4] = 1;	 //Dire��o 0 para esquerda, 1 para direita
	Controle[3][5] = 1;	 //velocidade
	Controle[3][6] = 0;	 //sprite
	Controle[3][7] = -1; //STATUS

	//CHOCOLATE
	Controle[4][0] = -1;
	Controle[4][1] = 10;  //POSX
	Controle[4][2] = 115; //POSY
	Controle[4][3] = -1;  //Sentido 0 pra cima, 1 pra baixo
	Controle[4][4] = -1;  //Dire��o 0 para esquerda, 1 para direita
	Controle[4][5] = 5;	  //velocidade
	Controle[4][6] = 0;	  //sprite
	Controle[4][7] = -1;  //STATUS

	//CARTA
	Controle[5][0] = -1;
	Controle[5][1] = 1;	 //POSX
	Controle[5][2] = 85; //POSY
	Controle[5][3] = -1; //Sentido 0 pra cima, 1 pra baixo
	Controle[5][4] = -1; //Dire��o 0 para esquerda, 1 para direita
	Controle[5][5] = 5;	 //velocidade
	Controle[5][6] = 0;	 //sprite
	Controle[5][7] = -1; //STATUS

	//OCULOS
	Controle[6][0] = -1;
	Controle[6][1] = 57;  //POSX
	Controle[6][2] = 110; //POSY
	Controle[6][3] = -1;  //Sentido 0 pra cima, 1 pra baixo
	Controle[6][4] = -1;  //Dire��o 0 para esquerda, 1 para direita
	Controle[6][5] = 5;	  //velocidade
	Controle[6][6] = 0;	  //sprite
	Controle[6][7] = -1;  //STATUS

	//CEIFEITO
	Controle[7][0] = -1;
	Controle[7][1] = 30; //POSX
	Controle[7][2] = 10; //POSY
	Controle[7][3] = -1; //Sentido 0 pra cima, 1 pra baixo
	Controle[7][4] = -1; //Dire��o 0 para esquerda, 1 para direita
	Controle[7][5] = 5;	 //velocidade
	Controle[7][6] = 0;	 //sprite
	Controle[7][7] = -1; //STATUS

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//TEMPORIZADOR DOS OBJETOS

	clock_t TempoInicialChoco, TempoDecorridoChoco,
		TempoInicialVisualChoco, TempoDecorridoVisualChoco,
		TempoInicialOculos, TempoDecorridoOculos,
		TempoInicialVisualOculos, TempoDecorridoVisualOculos;

	bool ChocoVisivel = false;
	bool OculosVisivel = false;
	int _ProbabilidadeOculos_ = 0.20;
	bool fase = true;
	bool fase2 = false;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//REPETI��O

	while (fase == true)
	{
		int AlocaposicaoX = Controle[0][1];
		int AlocaposicaoY = Controle[0][2];

		if (kbhit()) // alguma tecla foi pressionada?
		{
			Tecla = getch();
			switch (Tecla)
			{
			case 'w': // acima
			case 'W':
				(Controle[0][1])--;
				if (Controle[0][1] < 1)
					Controle[0][1] = 1;
				break;
			case 's': // abaixo
			case 'S':
				(Controle[0][1])++;
				if (Controle[0][1] >= (ALTURA - _AltTex_ - 1))
					Controle[0][1] = ALTURA - _AltTex_ - 1;
				break;
			case 'd': // direita
			case 'D':
				(Controle[0][2])++;
				if (Controle[0][2] >= (LARGURA - _LargTex_ - 1))
					Controle[0][2] = (LARGURA - _LargTex_ - 1);
				break;
			case 'a': // esquerda
			case 'A':
				(Controle[0][2])--;
				if (Controle[0][2] < 1)
					Controle[0][2] = 1;
				break;
			}
			Controle[0][6]++;
			if (Controle[0][6] >= 3)
				Controle[0][6] = 0;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O DAS PAREDES

		bool Colidiu = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][0], Controle[1][1], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu2 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][2], Controle[1][3], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu2)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu3 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][4], Controle[1][5], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu3)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu4 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][6], Controle[1][7], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu4)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu5 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][8], Controle[1][9], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu5)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu6 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][10], Controle[1][11], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu6)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu7 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][12], Controle[1][13], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu7)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu8 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][14], Controle[1][15], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu8)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu9 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][16], Controle[1][17], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (Colidiu9)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu10 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][18], Controle[1][19], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (Colidiu10)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu11 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][20], Controle[1][21], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (Colidiu11)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O COM PORTAS
		bool ColidiuPortaFase2 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][27], Controle[1][28], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (ColidiuPortaFase2)
		{
			fase = false;
			//Personagem
			Controle[0][0] = 0;	 //Perso
			Controle[0][1] = 54; //posX
			Controle[0][2] = 2;	 //posY
			Controle[0][3] = -1; //Sentido 0 pra cima, 1 pra baixo
			Controle[0][4] = -1; //Dire��o 0 para esquerda, 1 para direita
			Controle[0][5] = 5;	 //velocidade
			Controle[0][6] = 0;	 //sprite
			Controle[0][7] = -1; //STATUS

			//Muros Verticais

			Controle[1][0] = 1;	   //MURO 1
			Controle[1][1] = 20;   //MURO 1
			Controle[1][2] = 15;   //MURO 2
			Controle[1][3] = 20;   //MURO 2
			Controle[1][4] = 35;   //MURO 3
			Controle[1][5] = 20;   //MURO 3
			Controle[1][6] = 48;   //MURO 4
			Controle[1][7] = 20;   //MURO 4
			Controle[1][8] = 1;	   //MURO 5
			Controle[1][9] = 45;   //MURO 5
			Controle[1][10] = 15;  //MURO 6
			Controle[1][11] = 45;  //MURO 6
			Controle[1][12] = 29;  //MURO 7
			Controle[1][13] = 45;  //MURO 7
			Controle[1][14] = 48;  //MURO 8
			Controle[1][15] = 119; //MURO 8

			//MUROS HORIZONTAIS

			Controle[1][18] = 15;  //MURO 10
			Controle[1][19] = 119; //MURO 10

			//PORTAS
			Controle[1][16] = 7;   //MURO 9
			Controle[1][17] = 1;   //MURO 9
			Controle[1][20] = 26;  //MURO 11
			Controle[1][21] = 1;   //MURO 11
			Controle[1][22] = 1;   //PORTA 1
			Controle[1][23] = 119; //PORTA 1
			Controle[1][24] = 48;  //PORTA 2
			Controle[1][25] = 119; //PORTA 2
			Controle[1][26] = 1;   //sentido
			Controle[1][27] = 1;   //PORTA 3
			Controle[1][28] = 134; //PORTA 3
			velporta = 0;
			//PANDA
			Controle[2][0] = 0;
			Controle[2][1] = 41; //POSX
			Controle[2][2] = 4;	 //POSY
			Controle[2][3] = -1; //Sentido 0 pra cima, 1 pra baixo
			Controle[2][4] = 1;	 //Dire��o 0 para esquerda, 1 para direita
			Controle[2][5] = 1;	 //velocidade
			Controle[2][6] = 0;	 //sprite
			Controle[2][7] = -1; //STATUS
			int PosX, PosY;		 //MOVIMENTO CIRCULAR

			//DOG
			Controle[3][0] = 0;
			Controle[3][1] = 25;  //POSX
			Controle[3][2] = 125; //POSY
			Controle[3][3] = -1;  //Sentido 0 pra cima, 1 pra baixo
			Controle[3][4] = 1;	  //Dire��o 0 para esquerda, 1 para direita
			Controle[3][5] = 1;	  //velocidade
			Controle[3][6] = 0;	  //sprite
			Controle[3][7] = -1;  //STATUS
			Controle[3][8] = 1;	  //POSX 2
			Controle[3][9] = 28;  //POSY 2
			Controle[3][10] = 1;  //sentido
			Controle[3][11] = 1;
			//CHOCOLATE
			Controle[4][0] = -1;
			Controle[4][1] = 10;  //POSX
			Controle[4][2] = 115; //POSY
			Controle[4][3] = -1;  //Sentido 0 pra cima, 1 pra baixo
			Controle[4][4] = -1;  //Dire��o 0 para esquerda, 1 para direita
			Controle[4][5] = 5;	  //velocidade
			Controle[4][6] = 0;	  //sprite
			Controle[4][7] = -1;  //STATUS

			//CARTA
			Controle[5][0] = -1;
			Controle[5][1] = 54;  //POSX
			Controle[5][2] = 126; //POSY
			Controle[5][3] = -1;  //Sentido 0 pra cima, 1 pra baixo
			Controle[5][4] = -1;  //Dire��o 0 para esquerda, 1 para direita
			Controle[5][5] = 5;	  //velocidade
			Controle[5][6] = 0;	  //sprite
			Controle[5][7] = -1;  //STATUS

			//OCULOS
			Controle[6][0] = -1;
			Controle[6][1] = 2;	 //POSX
			Controle[6][2] = 5;	 //POSY
			Controle[6][3] = -1; //Sentido 0 pra cima, 1 pra baixo
			Controle[6][4] = -1; //Dire��o 0 para esquerda, 1 para direita
			Controle[6][5] = 5;	 //velocidade
			Controle[6][6] = 0;	 //sprite
			Controle[6][7] = -1; //STATUS

			//CEIFEITO
			Controle[7][0] = -1;
			Controle[7][1] = 20; //POSX
			Controle[7][2] = 90; //POSY
			Controle[7][3] = -1; //Sentido 0 pra cima, 1 pra baixo
			Controle[7][4] = -1; //Dire��o 0 para esquerda, 1 para direita
			Controle[7][5] = 5;	 //velocidade
			Controle[7][6] = 0;	 //sprite
			Controle[7][7] = -1; //STATUS
			Pontos = 0;
			Vidas = 5;
			fase2 = true;
		}

		bool ColidiuPortaprincipal = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][22], Controle[1][23], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (ColidiuPortaprincipal)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool ColidiuPortaVerde = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][24], Controle[1][25], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (ColidiuPortaVerde)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O DO PANDA
		bool ColidiuPanda = VerificaColisao(Controle[0][1], Controle[0][2], Controle[2][1], Controle[2][2], _AltPanda_, _LargPanda_, _AltTex_, _LargTex_);

		if (ColidiuPanda)
		{
			printf("\n::::::: PERECESTES NO  CONTO DO PANDA! ::::::::\n");
			system("pause");
			return 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O DO DOG
		bool ColidiuDog = VerificaColisao(Controle[0][1], Controle[0][2], Controle[3][1], Controle[3][2], _AltDog_, _LargDog_, _AltTex_, _LargTex_);

		if (ColidiuDog)
		{
			Vidas -= 2;
			if (Vidas <= 0)
			{
				printf("\n::::: Perecestes na mordida do cachorro! :::::\n");
				system("pause");
				return 0;
			}
			else
			{
				Controle[0][1] = 1;
				Controle[0][2] = 115;
				Pontos = 0;
				Controle[6][1] = 1;
				Controle[6][2] = 115;
				_ProbabilidadeOculos_ = 0.80;
				Controle[5][1] = 1;
				Controle[5][2] = 85;
				Controle[1][22] = 1;  //PORTA 1
				Controle[1][23] = 21; //PORTA 1
				Controle[1][24] = 24; //PORTA 2
				Controle[1][25] = 58; //PORTA 2
				Controle[1][26] = 1;  //sentido
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool ColidiuRifeiro = VerificaColisao(Controle[0][1], Controle[0][2], Controle[7][1], Controle[7][2], _AltRifeiro_, _LargRifeiro_, _AltTex_, _LargTex_);

		if (ColidiuRifeiro)
		{
			Vidas--;
			Pontos -= 5;
			Controle[7][1] = rand() % (ALTURA - _AltRifeiro_ - 2);
			Controle[7][2] = rand() % (LARGURA - _LargRifeiro_ - 2);
			if (Vidas <= 0)
			{
				printf("Perecestes na foice do ceifeiro");
				system("pause");
				return 0;
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O DO CHOCOLATE
		if (ChocoVisivel)
		{

			bool ColidiuChoco = VerificaColisao(Controle[0][1], Controle[0][2], Controle[4][1], Controle[4][2], _AltCho_, _LargCho_, _AltTex_, _LargTex_);

			if (ColidiuChoco)
			{
				Pontos += 10;
				Controle[4][1] = rand() % (ALTURA - _AltCho_ - 2);
				Controle[4][2] = rand() % (LARGURA - _LargCho_ - 2);
				TempoInicialChoco = clock();
			}

			TempoDecorridoVisualChoco = clock();
			double TempoDecorrido = ((double)(TempoDecorridoVisualChoco -
											  TempoInicialVisualChoco)) /
									CLOCKS_PER_SEC;

			if (TempoDecorrido >= 8.0)
			{
				ChocoVisivel = false;
				TempoInicialVisualChoco = TempoDecorridoVisualChoco = clock();
			}
		}

		else
		{
			double Palpite = (double)rand() / (double)RAND_MAX;
			if (Palpite >= _ProbabilidadeChoco_)
			{
				ChocoVisivel = true;
				Controle[4][1] = rand() % (ALTURA - _AltCho_ - 2);
				Controle[4][2] = rand() % (LARGURA - _LargCho_ - 2);
				TempoInicialVisualChoco = clock();
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLISAO DA CARTA DE CONHECIMENTO
		bool ColidiuCarta = VerificaColisao(Controle[0][1], Controle[0][2], Controle[5][1], Controle[5][2], _AltCarta_, _LargCarta_, _AltTex_, _LargTex_);

		if (ColidiuCarta)
		{
			Pontos += 770;
			Controle[5][1] = -10;
			Controle[5][2] = -10;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLISAO COM OCULOS
		if (OculosVisivel)
		{
			bool ColidiuOculos = VerificaColisao(Controle[0][1], Controle[0][2], Controle[6][1], Controle[6][2], _AltOculos_, _LargOculos_, _AltTex_, _LargTex_);

			if (ColidiuOculos)
			{
				Pontos += 200;
				_ProbabilidadeOculos_ = 10.00;
				Controle[6][1] = -10;
				Controle[6][2] = -10;
			}
			//temporiza��o do oculos
			TempoDecorridoVisualOculos = clock();
			double TempoDecorrido = ((double)(TempoDecorridoVisualOculos - TempoInicialVisualOculos)) / CLOCKS_PER_SEC;
			if (TempoDecorrido >= 8.0)
			{
				OculosVisivel = false;
				TempoInicialVisualOculos = TempoDecorridoVisualOculos = clock();
			}
		}

		else
		{
			double Palpite = (double)rand() / (double)RAND_MAX;
			if (Palpite >= _ProbabilidadeOculos_)
			{
				OculosVisivel = true;
				Controle[6][1] = rand() % (ALTURA - _AltOculos_ - 2);
				Controle[6][2] = rand() % (LARGURA - _LargOculos_ - 2);
				TempoInicialVisualOculos = clock();
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//ABRE A PORTA DO PERGAMINHO
		if (Pontos >= 200)
		{
			velporta++;
			if (Controle[1][25] >= 85)
				Controle[1][25] = 85;
			if (velporta >= 100)
				Controle[1][25]++, velporta = 0;
		}
		//ABRE A PORTA PRINCIPAL
		if (Pontos >= 1000)
		{

			if (Controle[1][26] == 1)
			{
				velporta1++;
				if (velporta1 >= 200)
				{
					velporta1 = 0;
					Controle[1][22]++;
					if (Controle[1][22] == 15)
					{
						Controle[1][26] = 0;
					}
				}
			}
			else
			{
				if (Controle[1][26] == 0)
				{
					velporta1++;
					if (velporta1 >= 150)
					{
						velporta1 = 0;
						Controle[1][22]--;
						{
							if (Controle[1][22] == 1)
							{
								Vidas = 0;
								if (Vidas == 0)
								{
									printf("\n:::::: PERDEU O JOGO! ::::::\n");
									system("pause");
									return 0;
								}
							}
						}
					}
				}
			}
		}

		//SPRITES
		int Vel, Vel1;
		Vel++;
		if (Vel >= 100)
		{
			Controle[3][6] += 1;
			Controle[2][6] += 1;
			Controle[7][6]++;
			Vel = 0;
			if (Controle[2][6] >= 3 && Controle[3][6] >= 3 && Controle >= 3)
				Controle[2][6] = 0, Controle[3][6] = 0, Controle[7][6] = 0;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//MOVIMENTA��O PANDA
		float i, j, k, v;
		int cont;
		cont++;

		if (cont >= 100)
		{
			if (Controle[2][4] == 1)
			{
				k -= 0.1;
				v -= 0.1;
				for (i = (v * PI); i <= (k * PI); i += 0.01)
				{
					j = sin(i);
					PosX = (41) - rintf(j * 12);
					PosY = (4) - rintf(i * 12);
				}
				Controle[2][1] = PosX;
				Controle[2][2] = PosY;
				cont = 0;
				if (Controle[2][2] >= LARGURA - _LargPanda_ - 1)
				{
					Controle[2][2] = LARGURA - _LargPanda_ - 1;
					Controle[2][4] = 0;
				}
				v -= 0.1;
			}

			else
			{
				if (cont >= 100)
				{
					k += 0.1;
					v -= 0.1;
					for (i = (v * PI); i <= (k * PI); i += 0.1)
					{
						j = sin(i);
						PosX = (41) - rintf(j * 12);
						PosY = (4) - rintf(i * 12);
						Controle[2][1] = PosX;
						Controle[2][2] = PosY;
						cont = 0;
						if (Controle[2][2] == _LargPanda_ / 2)
						{
							Controle[2][2] = _LargPanda_ / 2;
							Controle[2][4] = 1;
						}
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//MOVIMENTA��O DO DOG
		Vel1++;
		bool CachorroPorta = VerificaColisao(Controle[3][1], Controle[3][2], Controle[1][24], Controle[1][25], _AltMuro2_, _LargMuro2_, _AltDog_ + 1, _LargDog_);
		if (Controle[3][4] == 1 && Vel1 >= 50)
		{
			Controle[3][1] = Controle[3][1] + Controle[3][5];
			Vel1 = 0;
			if (CachorroPorta)
			{
				if (Controle[3][1] >= Controle[1][24] - _AltDog_)
				{
					Controle[3][4] = 0;
					Controle[3][1] = Controle[1][24] - _AltDog_;
				}
			}
			else
			{
				if (Controle[3][1] >= ALTURA - _AltDog_ - 1)
				{
					Controle[3][4] = 0;
					Controle[3][1] = ALTURA - _AltDog_ - 1;
				}
			}
		}

		else
		{
			if (Vel1 >= 80)
			{
				Controle[3][1] = Controle[3][1] - Controle[3][5];
				Vel1 = 0;
				{
					if (Controle[3][1] <= 1)
					{
						Controle[3][1] = 1;
						Controle[3][4] = 1;
					}
				}
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		int Contvelocidade;
		Contvelocidade++;
		if (Contvelocidade >= 500)
		{
			Contvelocidade = 0;
			if (Controle[7][1] > Controle[0][1])
				Controle[7][1] -= 1;
			if (Controle[7][1] < Controle[0][1])
				Controle[7][1] += 3;
			if (Controle[7][2] > Controle[0][2])
				Controle[7][2] -= 1;
			if (Controle[7][2] < Controle[0][2])
				Controle[7][2] += 3;
			if (Controle[7][1] <= 0)
				Controle[7][1] = 1;
			if (Controle[7][1] >= ALTURA - _AltRifeiro_ - 1)
				Controle[7][1] = ALTURA - _AltRifeiro_ - 2;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//INSCRI��ES
		PintaTela(TELA, 219, 19, Pontos, Vidas, Tempo);
		InscreveTexugo(TELA, Controle[0][1], Controle[0][2], Texugo, Texugocor[Controle[0][6]]);
		InscrevePanda(TELA, Controle[2][1], Controle[2][2], Panda, Pandacor[Controle[2][6]]);
		InscreveDog(TELA, Controle[3][1], Controle[3][2], Dog, Dogcor[Controle[3][6]]);
		InscreveChoco(TELA, Controle[4][1], Controle[4][2], Choco, Chococor);
		InscreveCarta(TELA, Controle[5][1], Controle[5][2], Carta, CartaCor);
		InscreveOculos(TELA, Controle[6][1], Controle[6][2], Oculos, Oculoscor);
		InscreveRifeiro(TELA, Controle[7][1], Controle[7][2], Rifeiro, RifeiroCor[Controle[7][6]]);
		//PORTAS
		InscreveMuro(TELA, Controle[1][22], Controle[1][23], Muro, 1);	 //1 PORTA VERTICAL
		InscreveMuro2(TELA, Controle[1][24], Controle[1][25], Muro2, 2); //1 PORTA HORIZONTAL
		InscreveMuro(TELA, Controle[1][27], Controle[1][28], Muro, 7);	 //SEGUNDA FASEsssss
		//MUROS
		InscreveMuro(TELA, Controle[1][0], Controle[1][1], Muro, 1110);		/* 1 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][2], Controle[1][3], Muro, 1110);		//2 MURO VERTICAL////
		InscreveMuro(TELA, Controle[1][4], Controle[1][5], Muro, 1110);		/* 3 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][6], Controle[1][7], Muro, 1110);		//4 MURO VERTICAL////
		InscreveMuro(TELA, Controle[1][8], Controle[1][9], Muro, 1110);		/* 5 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][10], Controle[1][11], Muro, 1110);	//6 MURO VERTICAL////
		InscreveMuro(TELA, Controle[1][12], Controle[1][13], Muro, 1110);	/* 7 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][14], Controle[1][15], Muro, 1110);	//8 MURO VERTICAL////
		InscreveMuro2(TELA, Controle[1][16], Controle[1][17], Muro2, 1110); ////* 9 MURO HORIZONTAL////////////////////////////////////////////////////////////////////////////////////////////////
		InscreveMuro2(TELA, Controle[1][18], Controle[1][19], Muro2, 1110); /* 10 MURO HORIZONTAL*/
		InscreveMuro2(TELA, Controle[1][20], Controle[1][21], Muro2, 1110); // 11 MURO HORIZONTAL//

		WriteConsoleOutput(wHnd, TELA, characterBufferSize, characterPosition, &consoleWriteArea);
	}

	while (fase2 == true)
	{

		int AlocaposicaoX = Controle[0][1];
		int AlocaposicaoY = Controle[0][2];

		if (kbhit()) // alguma tecla foi pressionada?
		{
			Tecla = getch();
			switch (Tecla)
			{
			case 'w': // acima
			case 'W':
				(Controle[0][1])--;
				if (Controle[0][1] < 1)
					Controle[0][1] = 1;
				break;
			case 's': // abaixo
			case 'S':
				(Controle[0][1])++;
				if (Controle[0][1] >= (ALTURA - _AltTex_ - 1))
					Controle[0][1] = ALTURA - _AltTex_ - 1;
				break;
			case 'd': // direita
			case 'D':
				(Controle[0][2])++;
				if (Controle[0][2] >= (LARGURA - _LargTex_ - 1))
					Controle[0][2] = (LARGURA - _LargTex_ - 1);
				break;
			case 'a': // esquerda
			case 'A':
				(Controle[0][2])--;
				if (Controle[0][2] < 1)
					Controle[0][2] = 1;
				break;
			}
			Controle[0][6]++;
			if (Controle[0][6] >= 3)
				Controle[0][6] = 0;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O DAS PAREDES

		bool Colidiu = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][0], Controle[1][1], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu2 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][2], Controle[1][3], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu2)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu3 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][4], Controle[1][5], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu3)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu4 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][6], Controle[1][7], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu4)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu5 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][8], Controle[1][9], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu5)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu6 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][10], Controle[1][11], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu6)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu7 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][12], Controle[1][13], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu7)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu8 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][14], Controle[1][15], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (Colidiu8)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu9 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][16], Controle[1][17], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (Colidiu9)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu10 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][18], Controle[1][19], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (Colidiu10)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool Colidiu11 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][20], Controle[1][21], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (Colidiu11)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
			Controle[1][21] += 1;
			if (Controle[1][21] >= 115)
				Controle[1][21] = 115;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O COM PORTAS
		bool ColidiuPortaFase2 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][27], Controle[1][28], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (ColidiuPortaFase2)
		{
			system("pause");
			return 0;
		}

		bool ColidiuPortaprincipal = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][22], Controle[1][23], _AltMuro_, _LargMuro_, _AltTex_, _LargTex_);

		if (ColidiuPortaprincipal)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		bool ColidiuPortaVerde = VerificaColisao(Controle[0][1], Controle[0][2], Controle[1][24], Controle[1][25], _AltMuro2_, _LargMuro2_, _AltTex_, _LargTex_);

		if (ColidiuPortaVerde)
		{
			Controle[0][1] = AlocaposicaoX;
			Controle[0][2] = AlocaposicaoY;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O DO DOG
		bool ColidiuDog = VerificaColisao(Controle[0][1], Controle[0][2], Controle[3][1], Controle[3][2], _AltDog_, _LargDog_, _AltTex_, _LargTex_);

		if (ColidiuDog)
		{
			Controle[0][1] = 54; //posX
			Controle[0][2] = 2;	 //posY
			Pontos = 0;
			Controle[6][1] = 2; //POSX
			Controle[6][2] = 5; //POSY
			_ProbabilidadeOculos_ = 0.80;
			Controle[5][1] = 54;   //POSX
			Controle[5][2] = 126;  //POSY
			Controle[1][16] = 7;   //MURO 9
			Controle[1][17] = 1;   //MURO 9
			Controle[1][20] = 26;  //MURO 11
			Controle[1][21] = 1;   //MURO 11
			Controle[1][22] = 1;   //PORTA 1
			Controle[1][23] = 119; //PORTA 1
			Controle[1][24] = 48;  //PORTA 2
			Controle[1][25] = 119; //PORTA 2
			Controle[1][26] = 1;   //sentido
			Controle[1][27] = 1;   //PORTA 3
			Controle[1][28] = 134; //PORTA 3
			Vidas -= 2;

			if (Vidas <= 0)
			{
				printf("\n::::: Perecestes na mordida do cachorro! :::::\n");
				system("pause");
				return 0;
			}
		}

		bool ColidiuDog2 = VerificaColisao(Controle[0][1], Controle[0][2], Controle[3][8], Controle[3][9], _AltDog_, _LargDog_, _AltTex_, _LargTex_);

		if (ColidiuDog2)
		{
			Controle[0][1] = 54; //posX
			Controle[0][2] = 2;	 //posY
			Pontos = 0;
			Controle[6][1] = 2; //POSX
			Controle[6][2] = 5; //POSY
			_ProbabilidadeOculos_ = 0.80;
			Controle[5][1] = 54;   //POSX
			Controle[5][2] = 126;  //POSY
			Controle[1][16] = 7;   //MURO 9
			Controle[1][17] = 1;   //MURO 9
			Controle[1][20] = 26;  //MURO 11
			Controle[1][21] = 1;   //MURO 11
			Controle[1][22] = 1;   //PORTA 1
			Controle[1][23] = 119; //PORTA 1
			Controle[1][24] = 48;  //PORTA 2
			Controle[1][25] = 119; //PORTA 2
			Controle[1][26] = 1;   //sentido
			Controle[1][27] = 1;   //PORTA 3
			Controle[1][28] = 134; //PORTA 3
			Vidas -= 2;

			if (Vidas <= 0)
			{
				printf("\n::::: Perecestes na mordida do cachorro! :::::\n");
				system("pause");
				return 0;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool ColidiuRifeiro = VerificaColisao(Controle[0][1], Controle[0][2], Controle[7][1], Controle[7][2], _AltRifeiro_, _LargRifeiro_, _AltTex_, _LargTex_);

		if (ColidiuRifeiro)
		{
			Vidas -= 2;
			Controle[7][1] = rand() % (ALTURA - _AltRifeiro_ - 20) + 1;
			Controle[7][2] = 50;
			if (Vidas <= 0)
			{
				printf("Perecestes na foice do ceifeiro");
				system("pause");
				return 0;
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLIS�O DO CHOCOLATE
		if (ChocoVisivel)
		{

			bool ColidiuChoco = VerificaColisao(Controle[0][1], Controle[0][2], Controle[4][1], Controle[4][2], _AltCho_, _LargCho_, _AltTex_, _LargTex_);

			if (ColidiuChoco)
			{
				Pontos += 10;
				Controle[4][1] = rand() % (ALTURA - _AltCho_ - 2);
				Controle[4][2] = rand() % (LARGURA - _LargCho_ - 2);
				TempoInicialChoco = clock();
			}

			TempoDecorridoVisualChoco = clock();
			double TempoDecorrido = ((double)(TempoDecorridoVisualChoco -
											  TempoInicialVisualChoco)) /
									CLOCKS_PER_SEC;

			if (TempoDecorrido >= 8.0)
			{
				ChocoVisivel = false;
				TempoInicialVisualChoco = TempoDecorridoVisualChoco = clock();
			}
		}

		else
		{
			double Palpite = (double)rand() / (double)RAND_MAX;
			if (Palpite >= _ProbabilidadeChoco_)
			{
				ChocoVisivel = true;
				Controle[4][1] = rand() % (ALTURA - _AltCho_ - 2);
				Controle[4][2] = rand() % (LARGURA - _LargCho_ - 2);
				TempoInicialVisualChoco = clock();
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLISAO DA CARTA DE CONHECIMENTO
		bool ColidiuCarta = VerificaColisao(Controle[0][1], Controle[0][2], Controle[5][1], Controle[5][2], _AltCarta_, _LargCarta_, _AltTex_, _LargTex_);

		if (ColidiuCarta)
		{
			Pontos += 750;
			Controle[5][1] = -10;
			Controle[5][2] = -10;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//COLISAO COM OCULOS
		if (OculosVisivel == false)
		{
			bool ColidiuOculos = VerificaColisao(Controle[0][1], Controle[0][2], Controle[6][1], Controle[6][2], _AltOculos_, _LargOculos_, _AltTex_, _LargTex_);

			if (ColidiuOculos)
			{
				Pontos += 200;
				_ProbabilidadeOculos_ = 10.00;
				Controle[6][1] = -10;
				Controle[6][2] = -10;
				OculosVisivel = true;
			}
			//temporiza��o do oculos
			TempoDecorridoVisualOculos = clock();
			double TempoDecorrido = ((double)(TempoDecorridoVisualOculos - TempoInicialVisualOculos)) / CLOCKS_PER_SEC;
			if (TempoDecorrido >= 8.0)
			{
				OculosVisivel = false;
				TempoInicialVisualOculos = TempoDecorridoVisualOculos = clock();
			}
		}

		else
		{
			double Palpite = (double)rand() / (double)RAND_MAX;
			if (Palpite >= _ProbabilidadeOculos_ && OculosVisivel == false)
			{
				OculosVisivel = true;
				Controle[6][1] = rand() % (ALTURA - _AltOculos_ - 2);
				Controle[6][2] = rand() % (LARGURA - _LargOculos_ - 2);
				TempoInicialVisualOculos = clock();
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//ABRE A PORTA DO PERGAMINHO
		if (Pontos >= 200)
		{
			velporta++;

			if (velporta >= 100)
				Controle[1][25]--, velporta = 0;
			if (Controle[1][25] <= 102)
				Controle[1][25]++;
		}

		//ABRE A PORTA PRINCIPAL
		if (Pontos >= 1000)
		{

			if (Controle[1][26] == 1)
			{
				velporta1++;
				if (velporta1 >= 200)
				{
					velporta1 = 0;
					Controle[1][22]++;
					if (Controle[1][22] == 15)
					{
						Controle[1][26] = 0;
					}
				}
			}
			else
			{
				if (Controle[1][26] == 0)
				{
					velporta1++;
					if (velporta1 >= 150)
					{
						velporta1 = 0;
						Controle[1][22]--;
						{
							if (Controle[1][22] == 1)
							{
								Vidas = 0;
								if (Vidas == 0)
								{
									printf("\n:::::: PERDEU O JOGO! ::::::\n");
									system("pause");
									return 0;
								}
							}
						}
					}
				}
			}
		}

		//ABRE PORTA SECRETA
		int Velportasec;
		Velportasec++;
		if (Velportasec >= 100)
		{
			Velportasec = 0;
			if (Pontos >= 50)
			{
				Controle[1][16]++;
				if (Controle[1][16] >= 45)
					Controle[1][16] = 45;
			}
		}

		//SPRITES
		int VelSprites;
		VelSprites++;
		if (VelSprites >= 100)
		{
			Controle[3][6]++;
			Controle[2][6]++;
			Controle[7][6]++;
			VelSprites = 0;
			if (Controle[2][6] >= 3 && Controle[3][6] >= 3 && Controle >= 3)
				Controle[2][6] = 0, Controle[3][6] = 0, Controle[7][6] = 0;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//MOVIMENTA��O DO DOG
		int VelDog;
		VelDog++;
		bool CachorroPorta = VerificaColisao(Controle[3][1], Controle[3][2], Controle[1][24], Controle[1][25], _AltMuro2_, _LargMuro2_, _AltDog_ + 1, _LargDog_);
		bool CachorroPortavermelha = VerificaColisao(Controle[3][1], Controle[3][2], Controle[1][20], Controle[1][21], _AltMuro2_, _LargMuro2_, _AltDog_ + 1, _LargDog_);
		if (Controle[3][4] == 1 && VelDog >= 10)
		{
			Controle[3][1] = Controle[3][1] + Controle[3][5];
			VelDog = 0;
			if (CachorroPorta)
			{
				if (Controle[3][1] >= Controle[1][24] - _AltDog_)
				{
					Controle[3][4] = 0;
					Controle[3][1] = Controle[1][24] - _AltDog_;
				}
			}
			else if (CachorroPortavermelha)
			{
				if (Controle[3][1] >= Controle[1][20] - _AltDog_)
				{
					Controle[3][4] = 0;
					Controle[3][1] = Controle[1][20] - _AltDog_;
				}
			}
			else
			{
				if (Controle[3][1] >= ALTURA - _AltDog_)
				{
					Controle[3][1] = ALTURA - _AltDog_;
					Controle[3][4] = 0;
				}
			}
		}

		else
		{
			if (VelDog >= 10)
			{
				Controle[3][1] = Controle[3][1] - Controle[3][5];
				VelDog = 0;
				{
					if (Controle[3][1] <= 18)
					{
						Controle[3][1] = 18;
						Controle[3][4] = 1;
					}
				}
			}
		}

		//DOG 2
		int Veldog2;
		Veldog2++;
		bool CachorroPorta2 = VerificaColisao(Controle[3][8], Controle[3][9], Controle[1][20], Controle[1][21], _AltMuro2_, _LargMuro2_, _AltDog_ + 1, _LargDog_);
		if (Controle[3][10] == 1 && Veldog2 >= 10)
		{
			Controle[3][8] = Controle[3][8] + Controle[3][11];
			Veldog2 = 0;
			if (CachorroPorta2)
			{
				if (Controle[3][8] >= Controle[1][20] - _AltDog_)
				{
					Controle[3][10] = 0;
					Controle[3][1] = Controle[1][20] - _AltDog_;
				}
			}
			else
			{
				if (Controle[3][8] >= ALTURA - _AltDog_ - 1)
				{
					Controle[3][10] = 0;
					Controle[3][8] = ALTURA - _AltDog_ - 1;
				}
			}
		}

		else
		{
			if (Veldog2 >= 10)
			{
				Controle[3][8] = Controle[3][8] - Controle[3][11];
				Veldog2 = 0;
				{
					if (Controle[3][8] <= 1)
					{
						Controle[3][8] = 1;
						Controle[3][10] = 1;
					}
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//MOV CEIFEIRO
		int Vel4;
		Vel4++;
		if (Controle[7][4] == 1 && Vel4 >= 200)
		{
			Controle[7][2] = Controle[7][2] + Controle[7][5];
			Vel4 = 0;
			if (Controle[7][2] >= LARGURA - _LargRifeiro_ - 20)
			{
				Controle[7][4] = 0;
				Controle[7][1] = rand() % (ALTURA - _AltRifeiro_ - 20) + 1;
			}
		}

		else
		{
			if (Vel4 >= 200)
			{
				Controle[7][2] = Controle[7][2] - Controle[7][5];
				Vel4 = 0;
				{
					if (Controle[7][2] <= 45)
					{
						Controle[7][2] = rand() % (ALTURA - _AltRifeiro_ - 20) + 45;
						Controle[7][4] = 1;
					}
				}
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//INSCRI��ES
		PintaTela(TELA, 219, 19, Pontos, Vidas, Tempo);
		InscreveTexugo(TELA, Controle[0][1], Controle[0][2], Texugo, Texugocor[Controle[0][6]]);
		//InscrevePanda  (TELA,Controle[2][1],Controle[2][2],Panda,Pandacor[Controle [2][6]]);
		InscreveDog(TELA, Controle[3][1], Controle[3][2], Dog, Dogcor[Controle[3][6]]);
		InscreveDog(TELA, Controle[3][8], Controle[3][9], Dog, Dogcor[Controle[3][6]]);
		InscreveChoco(TELA, Controle[4][1], Controle[4][2], Choco, Chococor);
		InscreveCarta(TELA, Controle[5][1], Controle[5][2], Carta, CartaCor);
		InscreveOculos(TELA, Controle[6][1], Controle[6][2], Oculos, Oculoscor);
		InscreveRifeiro(TELA, Controle[7][1], Controle[7][2], Rifeiro, RifeiroCor[Controle[7][6]]);
		//PORTAS
		InscreveMuro(TELA, Controle[1][22], Controle[1][23], Muro, 1);	   //1 PORTA VERTICAL
		InscreveMuro2(TELA, Controle[1][24], Controle[1][25], Muro2, 2);   //1 PORTA HORIZONTAL
		InscreveMuro(TELA, Controle[1][27], Controle[1][28], Muro, 111);   //SEGUNDA FASE
		InscreveMuro2(TELA, Controle[1][16], Controle[1][17], Muro2, 302); ////* 9 MURO HORIZONTAL
		InscreveMuro2(TELA, Controle[1][20], Controle[1][21], Muro2, 100); // 11 MURO HORIZONTAL//
		//MUROS
		InscreveMuro(TELA, Controle[1][0], Controle[1][1], Muro, 1110);		/* 1 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][2], Controle[1][3], Muro, 1110);		//2 MURO VERTICAL////
		InscreveMuro(TELA, Controle[1][4], Controle[1][5], Muro, 1110);		/* 3 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][6], Controle[1][7], Muro, 1110);		//4 MURO VERTICAL////
		InscreveMuro(TELA, Controle[1][8], Controle[1][9], Muro, 1110);		/* 5 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][10], Controle[1][11], Muro, 1110);	//6 MURO VERTICAL////
		InscreveMuro(TELA, Controle[1][12], Controle[1][13], Muro, 1110);	/* 7 MURO VERTICAL*/
		InscreveMuro(TELA, Controle[1][14], Controle[1][15], Muro, 1110);	//8 MURO VERTICAL////
		
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		InscreveMuro2(TELA, Controle[1][18], Controle[1][19], Muro2, 1110); /* 10 MURO HORIZONTAL*/

		WriteConsoleOutput(wHnd, TELA, characterBufferSize, characterPosition, &consoleWriteArea);
	}

	return 0;
}

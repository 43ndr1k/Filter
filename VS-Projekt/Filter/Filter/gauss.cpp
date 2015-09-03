#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <cstdlib>

#define GAUSSSIZE 3	
#define MATRIXSIZE 10
#define GRID_SIZE 1

// Hier werden die Werte für die Gauss-Matrix erstellt (je nach Sigma)
void generate_gauss_vals(float);
// Ausgabe der Gauss-Werte
void print_gauss_vals();

void print_matrix_vals();
// Gaussschen Weichzeichner auf Matrix anwenden
void gaussian(float *matrix, float *output);

float gausss[GAUSSSIZE][GAUSSSIZE];
float gauss[GAUSSSIZE][GAUSSSIZE];
float matrix[MATRIXSIZE][MATRIXSIZE]; // Die zu berechnen Werte
float *matrixx;
float *matrix_output;

int start(void)
{
	



	printf("\r\nUrsprungsmatrix:\r\n");
	print_matrix_vals();

	// Gauss-Werte generieren
	generate_gauss_vals(0.798f);
	printf("Gauss-Matrix: \r\n");
	print_gauss_vals();


	// Gauss-Filter auf die Matrix anwenden
	printf("Berechnen ...\r\n");
	//Noch nicht funktionsbereit
	gaussian (matrixx, matrix_output);

	// Matrix ausgeben
	printf("Matrix:\r\n");
	print_matrix_vals();

	// Speicher freigeben
	free(matrix);
	free(matrix_output);

	_getch();
	exit(EXIT_SUCCESS);
}

// Gauss-Filter auf Matrix berechnen.
void gaussian(float *matrix, float *output)
{
	
	// Hier muss noch die Auswahl der Zeile und Spalte aus der Bild Matrix statt finden. NxN
	int zeile = 0;
	int spalte = 0;

	if (zeile >= MATRIXSIZE || spalte >= MATRIXSIZE)
	{
		return;
	}

	// Ich nehme die Werte um den Punkt herum
	// und berechne den neuen Wert nach Gauss.
	// Problem: Werte am Rand.
	float new_val = 0.0f;

	// Keine Rand-Werte
	int matrix_loc = (int)(floor((float)GAUSSSIZE / 2.0f));
	for (int i = 0; i < GAUSSSIZE; i++)
	{
		for (int j = 0; j < GAUSSSIZE; j++)
		{
			bool weiter = false;

			// Ecke links oben
			if (spalte == 0 && zeile == 0 && i < GAUSSSIZE - matrix_loc && j < GAUSSSIZE - matrix_loc)
			{
				new_val += (matrix[MATRIXSIZE * spalte + zeile] * gausss[i][j]);
				weiter = true;
			}

			if (spalte == 0 && zeile == 0 && (i >= GAUSSSIZE - matrix_loc || j >= GAUSSSIZE - matrix_loc))
			{
				if (i < GAUSSSIZE - matrix_loc)
				{
					new_val += (matrix[MATRIXSIZE * (spalte + 1) + zeile] * gausss[i][j]);
					weiter = true;
				}

				if (j < GAUSSSIZE - matrix_loc)
				{
					new_val += (matrix[MATRIXSIZE * spalte + (zeile + 1)] * gausss[i][j]);
					weiter = true;
				}
			}

			// In der oberen Spalte aber ohne den rechten Rand
			if (spalte == 0 && zeile < MATRIXSIZE - 1 && zeile != 0 && i < GAUSSSIZE - matrix_loc)
			{
				new_val += (matrix[MATRIXSIZE * spalte + (zeile + j - matrix_loc)] * gausss[i][j]);
				weiter = true;
			}

			// in der oberen rechten Ecke
			if (spalte == 0 && zeile == MATRIXSIZE - 1 && i < GAUSSSIZE - matrix_loc && j >= GAUSSSIZE - matrix_loc - 1)
			{
				new_val += (matrix[MATRIXSIZE * spalte + zeile] * gausss[i][j]);
				weiter = true;
			}

			if (spalte == 0 && zeile == MATRIXSIZE - 1 && (i < GAUSSSIZE - matrix_loc || j >= GAUSSSIZE - matrix_loc - 1))
			{
				if (i >= GAUSSSIZE - matrix_loc)
				{
					new_val += (matrix[MATRIXSIZE * (spalte + 1) + zeile] * gausss[i][j]);
					weiter = true;
				}

				if (j < GAUSSSIZE - matrix_loc - 1)
				{
					new_val += (matrix[MATRIXSIZE * spalte + (zeile - 1)] * gausss[i][j]);
					weiter = true;
				}
			}

			// Ecke links unten
			if (spalte == MATRIXSIZE - 1 && zeile == 0 && i >= GAUSSSIZE - matrix_loc - 1 && j < GAUSSSIZE - matrix_loc)
			{
				new_val += (matrix[MATRIXSIZE * spalte + zeile] * gausss[i][j]);
				weiter = true;
			}

			if (spalte == MATRIXSIZE - 1 && zeile == 0 && (i >= GAUSSSIZE - matrix_loc - 1 || j < GAUSSSIZE - matrix_loc))
			{
				if (i < GAUSSSIZE - matrix_loc - 1)
				{
					new_val += (matrix[MATRIXSIZE * (spalte - 1) + zeile] * gausss[i][j]);
					weiter = true;
				}

				if (j >= GAUSSSIZE - matrix_loc)
				{
					new_val += (matrix[MATRIXSIZE * spalte + (zeile + 1)] * gausss[i][j]);
					weiter = true;
				}
			}

			// unterer Rand
			if (spalte == MATRIXSIZE - 1 && zeile != 0 && zeile < MATRIXSIZE - 1 && i >= GAUSSSIZE - matrix_loc)
			{
				new_val += (matrix[MATRIXSIZE * spalte + (zeile + j - matrix_loc)] * gausss[i][j]);
				weiter = true;
			}

			// Ecke rechts unten
			if (spalte == MATRIXSIZE - 1 && zeile == MATRIXSIZE - 1 && i >= GAUSSSIZE - matrix_loc - 1 && j >= GAUSSSIZE - matrix_loc - 1)
			{
				new_val += (matrix[MATRIXSIZE * spalte + zeile] * gausss[i][j]);
				weiter = true;
			}

			if (spalte == MATRIXSIZE - 1 && zeile == MATRIXSIZE - 1 && (i >= GAUSSSIZE - matrix_loc - 1 || j >= GAUSSSIZE - matrix_loc - 1))
			{
				if (i < GAUSSSIZE - matrix_loc - 1)
				{
					new_val += (matrix[MATRIXSIZE * (spalte - 1) + zeile] * gausss[i][j]);
					weiter = true;
				}

				if (j < GAUSSSIZE - matrix_loc - 1)
				{
					new_val += (matrix[MATRIXSIZE * spalte + (zeile - 1)] * gausss[i][j]);
					weiter = true;
				}
			}

			// der linke Rand
			if (zeile == 0 && spalte != 0 && spalte < MATRIXSIZE - 1 && j < GAUSSSIZE - matrix_loc)
			{
				new_val += (matrix[MATRIXSIZE * (spalte + i - matrix_loc) + zeile] * gausss[i][j]);
				weiter = true;
			}

			// der rechte Rand
			if (zeile == MATRIXSIZE - 1 && spalte != 0 && spalte < MATRIXSIZE - 1 && j >= GAUSSSIZE - matrix_loc)
			{
				new_val += (matrix[MATRIXSIZE * (spalte + i - matrix_loc) + zeile] * gausss[i][j]);
				weiter = true;
			}

			// Sonst
			if (!weiter)
			{
				new_val += (matrix[MATRIXSIZE * (spalte + i - matrix_loc) + (zeile + j - matrix_loc)] * gausss[i][j]);
			}
		}
	}

	output[MATRIXSIZE * spalte + zeile] = new_val;
}

// Generiert die Werte für eine NxN-Gauss-Matrix
void generate_gauss_vals(float sigma)
{
	float x, y;

	for (int i = 0; i < GAUSSSIZE; i++)
	{
		for (int j = 0; j < GAUSSSIZE; j++)
		{
			x = (float)(i - (int)(GAUSSSIZE / 2));
			y = (float)(j - (int)(GAUSSSIZE / 2));

			gauss[i][j] = exp((-1.0f) * (x * x + y * y) / (2 * sigma * sigma));
			gauss[i][j] = gauss[i][j] / (2 * ((float)M_PI) * sigma * sigma);
		}
	}
}

// Gibt die Gauss-Matrix aus
void print_gauss_vals(void)
{
	for (int i = 0; i < GAUSSSIZE; i++)
	{
		for (int j = 0; j < GAUSSSIZE; j++)
		{
			printf("%.4f, ", gauss[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
}

// Gibt die Matrix aus
void print_matrix_vals(void)
{
	for (int i = 0; i < MATRIXSIZE; i++)
	{
		for (int j = 0; j < MATRIXSIZE; j++)
		{
			printf("%.3f, ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
}


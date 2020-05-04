#include "AdjacencyMatrix.h"



int main()
{
	AdjacencyMatrix matrix;
	ifstream file;
	file.open("input.txt");
	matrix.input(file);
	matrix.SetCityCount();
	matrix.CreateAdjacencyMatrix();
	matrix.printMatrix();
	matrix.EnterNameOfCities_i_and_j();
	matrix.Floyd_Warshell_algorithm();
}
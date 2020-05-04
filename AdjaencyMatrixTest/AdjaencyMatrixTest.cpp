#include "pch.h"
#include "CppUnitTest.h"
#include"../AISDLAB3/AdjacencyMatrix.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AdjaencyMatrixTest
{
	TEST_CLASS(AdjaencyMatrixTest)
	{
	public:
		
		TEST_METHOD(TestInput)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test1.txt");
			matrix.input(file);
			Assert::AreEqual(matrix.get_size_of_file(), 5);
		}
		TEST_METHOD(TestSetCityCount1)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test1.txt");
			matrix.input(file);
			matrix.SetCityCount();
			Assert::AreEqual(matrix.get_count_of_cities(), 5);
		}
		TEST_METHOD(TestSetCityCount2)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test2.txt");
			matrix.input(file);
			matrix.SetCityCount();
			Assert::AreEqual(matrix.get_count_of_cities(), 6);
		}
		TEST_METHOD(TestCreateMatrix)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test1.txt");
			matrix.input(file);
			matrix.SetCityCount();
			matrix.CreateAdjacencyMatrix();
		}
		TEST_METHOD(TestFloyd_Warshell_algorithm1)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test1.txt");
			matrix.input(file);
			matrix.SetCityCount();
			matrix.CreateAdjacencyMatrix();
			matrix.set_cities_to_find_a_way(0,3); //Saint-petersburg - Tomsk
			Assert::AreEqual(matrix.Floyd_Warshell_algorithm(), 24);
		}
		TEST_METHOD(TestFloyd_Warshell_algorithm2)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test1.txt");
			matrix.input(file);
			matrix.SetCityCount();
			matrix.CreateAdjacencyMatrix();
			matrix.set_cities_to_find_a_way(1, 2); //Moscow - Novosibirsk
			Assert::AreEqual(matrix.Floyd_Warshell_algorithm(), 19);
		}
		TEST_METHOD(TestFloyd_Warshell_algorithm3)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test2.txt");
			matrix.input(file);
			matrix.SetCityCount();
			matrix.CreateAdjacencyMatrix();
			matrix.set_cities_to_find_a_way(0, 2); //Saint-petersburg - Novosibirsk
			Assert::AreEqual(matrix.Floyd_Warshell_algorithm(), 34);
		}
		TEST_METHOD(TestFloyd_Warshell_algorithm4)
		{
			AdjacencyMatrix matrix;
			ifstream file;
			file.open("../AISDLAB3/test2.txt");
			matrix.input(file);
			matrix.SetCityCount();
			matrix.CreateAdjacencyMatrix();
			matrix.set_cities_to_find_a_way(5, 3); //Habarovsk - Tomsk
			Assert::AreEqual(matrix.Floyd_Warshell_algorithm(), 60);
		}
	};
}

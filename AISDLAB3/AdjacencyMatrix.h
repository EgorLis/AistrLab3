#include "List.cpp"
#include <fstream>
#include <iostream>


class AdjacencyMatrix
{
private:
	class string
	{
	public:
		List<char>* city1;
		List<char>* city2;
		int price1to2;
		int price2to1;
		string():city1(new List<char>),city2(new List<char>),price1to2(0),price2to1(0) {};
		~string()
		{
			city1->~List();
			city2->~List();
		}
	};
	List<string*> File;
	int** matrix;
	List<List<char>*> All_cities;
	int City_i;
	int City_j;
	int max;
public:
	AdjacencyMatrix() : matrix(NULL),City_i(0),City_j(0),max(0){};
	~AdjacencyMatrix()
	{
		File.~List();
		All_cities.~List();
		for (int i = 0; i < this->All_cities.get_size(); i++)
		{
			delete[] matrix[i];
		}
	}
	void input(ifstream& file); //input text from text file
	void SetCityCount(); //find all cities
	void CreateAdjacencyMatrix(); //create Adjacency Matrix
	void printMatrix(); //print  Adjacency Matrix
	void EnterNameOfCities_i_and_j(); //Enter two names of cities for find she shortest way between them from console
	int Floyd_Warshell_algorithm(); //it is Floyd-Warshell algorithm, which find the shortest way between all the
	void set_cities_to_find_a_way(int index_i, int index_j)
	{
		if (index_i >= this->All_cities.get_size() || index_j >= this->All_cities.get_size() || index_i == index_j || index_i < 0 || index_j < 0 )
		{
			throw std::out_of_range("wrong number");
		}
		else
		{
			this->City_i = index_i;
			this->City_j = index_j;
		}
	}
	int get_size_of_file() //count of strings
	{
		return this->File.get_size();
	}
	int get_count_of_cities()
	{
		return this->All_cities.get_size();
	}
};


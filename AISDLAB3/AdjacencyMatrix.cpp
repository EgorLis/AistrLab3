#include "AdjacencyMatrix.h"

void AdjacencyMatrix::input(ifstream& file) //input text from text file
{
	if (file.eof() != true)
	{
		file.unsetf(ios::skipws);
		List<char>* temp_number;
		string* str;
		while (!file.eof())
		{
			int step = 1;
			temp_number = new List<char>;
			str = new string;
			char symbol = 0;
			while (symbol != '\n')
			{
				file >> symbol;
				if (file.eof())
					return;
				if (symbol == ';')
				{
					if (step == 2)
					{

						temp_number = new List<char>;
					}
					if (step == 3)
					{
						if (temp_number->get_size() == 0)
							throw std::out_of_range("wrong number");
						if (temp_number->get_size() == 3 && temp_number->at(0) == 'N' && temp_number->at(1) == '/' && temp_number->at(2) == 'A')
						{
							str->price1to2 = 0;
						}
						else
						{
							int temp = 0;
							for (int i = 0; i < temp_number->get_size(); i++)
							{
								if (temp_number->at(i) >= 48 && temp_number->at(i) <= 57)
								{
									temp = temp * 10 + (temp_number->at(i) - 48);
								}
								else
									throw std::out_of_range("wrong number");
							}
							str->price1to2 = temp;
						}
						temp_number = new List<char>;
					}
					if (step == 4)
					{
						if (temp_number->get_size() == 0)
							throw std::out_of_range("wrong number");
						if (temp_number->get_size() == 3 && temp_number->at(0) == 'N' && temp_number->at(1) == '/' && temp_number->at(2) == 'A')
						{
							str->price2to1 = 0;
						}
						else
						{
							int temp = 0;
							for (int i = 0; i < temp_number->get_size(); i++)
							{
								if (temp_number->at(i) >= 48 && temp_number->at(i) <= 57)
								{
									temp = temp * 10 + (temp_number->at(i) - 48);
								}
								else
									throw std::out_of_range("wrong number");
							}
							str->price2to1 = temp;
						}
					}
					step++;
				}
				else {
					switch (step)
					{
					case 1:
						str->city1->push_back(symbol);
						break;
					case 2:
						str->city2->push_back(symbol);
						break;
					case 3:
						temp_number->push_back(symbol);
						break;
					case 4:
						temp_number->push_back(symbol);
						break;
					default:
						break;
					}
				}
			}
			if (step == 1)
				throw std::out_of_range("wrong string");
			this->File.push_back(str);
		}
	}
}

void AdjacencyMatrix::SetCityCount() //find all cities
{
	for (int i = 0; i < this->File.get_size(); i++)
	{
		int step = 1;
		while (step != 3)
		{
			if (this->All_cities.get_size() == 0)
			{

				switch (step)
				{
				case 1:
					this->All_cities.push_back(this->File.at(i)->city1);
					break;
				case 2:
					this->All_cities.push_back(this->File.at(i)->city2);
					break;
				}
			}
			else
			{
				int match = 0;
				switch (step)
				{
				case 1:
					for (int j = 0; j < this->All_cities.get_size(); j++)
					{
						if (this->File.at(i)->city1->get_size() == this->All_cities.at(j)->get_size())
						{
							for (int index = 0; index < this->File.at(i)->city1->get_size(); index++)
							{
								if (this->File.at(i)->city1->at(index) == this->All_cities.at(j)->at(index))
								{
									match = 1;
								}
								else
								{
									match = 0;
									break;
								}
							}
							if (match == 1)
								break;
						}
					}
					break;
				case 2:
					for (int j = 0; j < this->All_cities.get_size(); j++)
					{
						if (this->File.at(i)->city2->get_size() == this->All_cities.at(j)->get_size())
						{
							for (int index = 0; index < this->File.at(i)->city2->get_size(); index++)
							{
								if (this->File.at(i)->city2->at(index) == this->All_cities.at(j)->at(index))
								{
									match = 1;
								}
								else
								{
									match = 0;
									break;
								}
							}
							if (match == 1)
								break;
						}
					}
					break;
				}
				if (match == 0)
				{
					switch (step)
					{
					case 1:
						this->All_cities.push_back(this->File.at(i)->city1);
						break;
					case 2:
						this->All_cities.push_back(this->File.at(i)->city2);
						break;
					}
				}
			}
			step++;
		}
	}
}

void AdjacencyMatrix::CreateAdjacencyMatrix() //create Adjacency Matrix
{
	this->All_cities.get_size();
	this->matrix = new int* [this->All_cities.get_size()];

	for (int i = 0; i < this->All_cities.get_size(); i++)
	{
		this->matrix[i] = new int[this->All_cities.get_size()];
	}

	for (int i = 0; i < this->All_cities.get_size(); i++)
	{
		for (int j = 0; j < this->All_cities.get_size(); j++)
		{
			this->matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < this->File.get_size(); i++)
	{
		int step = 1;
		int index_1 = -1;
		int index_2 = -1;
		while (step != 3)
		{
			int match = 0;
			switch (step)
			{
			case 1:
				for (int j = 0; j < this->All_cities.get_size(); j++)
				{
					if (this->File.at(i)->city1->get_size() == this->All_cities.at(j)->get_size())
					{
						for (int index = 0; index < this->File.at(i)->city1->get_size(); index++)
						{
							if (this->File.at(i)->city1->at(index) == this->All_cities.at(j)->at(index))
							{
								match = 1;
								index_1 = j;
							}
							else
							{
								match = 0;
								index_1 = -1;
								break;
							}
						}
						if (match == 1)
							break;
					}
				}
				break;
			case 2:
				for (int j = 0; j < this->All_cities.get_size(); j++)
				{
					if (this->File.at(i)->city2->get_size() == this->All_cities.at(j)->get_size())
					{
						for (int index = 0; index < this->File.at(i)->city2->get_size(); index++)
						{
							if (this->File.at(i)->city2->at(index) == this->All_cities.at(j)->at(index))
							{
								match = 1;
								index_2 = j;
							}
							else
							{
								match = 0;
								index_2 = -1;
								break;
							}
						}
						if (match == 1)
							break;
					}
				}
				break;
			}
			step++;
		}
		this->matrix[index_1][index_2] = this->File.at(i)->price1to2;
		this->matrix[index_2][index_1] = this->File.at(i)->price2to1;
	}
	this->max = 0;
	for (int i = 0; i < this->All_cities.get_size(); i++)
	{
		for (int j = 0; j < this->All_cities.get_size(); j++)
		{
			if (this->matrix[i][j] > max)
				max = this->matrix[i][j];
		}
	}
	this->max = this->max + 1;
	for (int i = 0; i < this->All_cities.get_size(); i++)
	{
		for (int j = 0; j < this->All_cities.get_size(); j++)
		{
			if (this->matrix[i][j] == 0 && i != j)
				this->matrix[i][j] = this->max;
		}
	}
}
void AdjacencyMatrix::printMatrix() //print  Adjacency Matrix (for cities without a direct link,was put the biggest number +1)
{
	for (int i = 0; i < this->All_cities.get_size(); i++)
	{
		cout << endl;
		for (int j = 0; j < this->All_cities.get_size(); j++)
		{
			cout << this->matrix[i][j] << " ";
		}
	}
	cout << endl;
}
void AdjacencyMatrix::EnterNameOfCities_i_and_j() //Enter two names of cities for find she shortest way between them
{
	char s = 1;
	List<char> temp_name_i;
	List<char> temp_name_j;
	cout << "Enter name of fisrt city...";
	for (s = getchar(); s != '\n'; s = getchar())
	{
		temp_name_i.push_back(s);
	}
	cout << "Enter name of second city...";
	for (s = getchar(); s != '\n'; s = getchar())
	{
		temp_name_j.push_back(s);
	}
	this->City_j = -1;
	this->City_i = -1;
	int match = 0;
	for (int j = 0; j < this->All_cities.get_size(); j++)
	{
		if (temp_name_i.get_size() == this->All_cities.at(j)->get_size())
		{
			for (int index = 0; index < temp_name_i.get_size(); index++)
			{
				if (temp_name_i.at(index) == this->All_cities.at(j)->at(index))
				{
					match = 1;
					this->City_i = j;
				}
				else
				{
					match = 0;
					this->City_i = -1;
					break;
				}
			}
			if (match == 1)
				break;
		}
	}
	for (int j = 0; j < this->All_cities.get_size(); j++)
	{
		if (temp_name_j.get_size() == this->All_cities.at(j)->get_size())
		{
			for (int index = 0; index < temp_name_j.get_size(); index++)
			{
				if (temp_name_j.at(index) == this->All_cities.at(j)->at(index))
				{
					match = 1;
					this->City_j = j;
				}
				else
				{
					match = 0;
					this->City_j = -1;
					break;
				}
			}
			if (match == 1)
				break;
		}
	}
	if (this->City_i == -1 || this->City_j == -1)
		throw std::out_of_range("Wrong name");
	if (this->City_i == this->City_j)
		throw std::out_of_range("City i its city j");
}
int AdjacencyMatrix::Floyd_Warshell_algorithm() //it is Floyd-Warshell algorithm, which find the shortest way between all the
{
	for (int k = 0; k < this->All_cities.get_size(); k++)
		for (int i = 0; i < this->All_cities.get_size(); i++)
			for (int j = 0; j < this->All_cities.get_size(); j++)
				if (this->matrix[i][k] && this->matrix[k][j] && i != j)
					if (this->matrix[i][k] + this->matrix[k][j] < this->matrix[i][j] || this->matrix[i][j] == 0)
						this->matrix[i][j] = this->matrix[i][k] + this->matrix[k][j];

	cout << "Shortest way is: " << this->matrix[this->City_i][this->City_j];
	return this->matrix[this->City_i][this->City_j];
}

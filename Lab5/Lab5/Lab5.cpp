#include "pch.h"
#include <fstream>
#include <iostream>
using namespace std;
const int k = 3, l = 5, m = 3, n = 4;

struct Matrix1
{
	int array1[m][n];
};

struct Matrix2
{
	int array2[m][n];
};

void Save_in_File(Matrix1 *matrix1, ofstream &save1, Matrix2 *matrix2, ofstream &save2)
{
	for (size_t i = 0; i < k; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				save1 << "\t" << matrix1[i].array1[j][k];
			}
			save1 << "\n";
		}
		save1 << "===========================\n";
	}

	for (size_t i = 0; i < l; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				save2 << "\t" << matrix2[i].array2[j][k];
			}
			save2 << "\n";
		}
		save2 << "===========================\n";
	}
}

void Swap_1(Matrix1 *matrix, int x)
{
	for (size_t i = 0; i < x - 1; i += 2)
	{
		Matrix1 temp;
		temp = matrix[i];
		matrix[i] = matrix[i + 2];
		matrix[i + 2] = temp;
	}
}

void Swap_2(Matrix2 *matrix, int x)
{
	for (size_t i = 0; i < x - 1; i += 2)
	{
		Matrix2 temp;
		temp = matrix[i];
		matrix[i] = matrix[i + 2];
		matrix[i + 2] = temp;
	}
}

void Read_Array(ifstream &mat1, ifstream &mat2, Matrix1 *matrix1, Matrix2 *matrix2)
{
	for (size_t i = 0; i < k; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t f = 0; f < n; f++)
			{
				mat1 >> matrix1[i].array1[j][f];
			}
		}
	}

	for (size_t i = 0; i < l; i++)
	{
		for (int g = 0; g < m; g++)
		{
			for (int j = 0; j < n; j++)
			{
				mat2 >> matrix2[i].array2[g][j];
			}
		}
	}
}

void Print(Matrix1 *matrix1, Matrix2 *matrix2)
{
	std::cout << "Матрицы первого файла:" << "\n" << "\n";
	for (size_t i = 0; i < k; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				std::cout << "\t" << matrix1[i].array1[j][k];
			}
			std::cout << "\n";
		}
		std::cout << "================================" << "\n";
		std::cout << "\n";
	}

	std::cout << "Матрицы второго файла:" << "\n" << "\n";
	for (size_t i = 0; i < l; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				std::cout << "\t" << matrix2[i].array2[j][k];
			}
			std::cout << "\n";
		}
		std::cout << "================================" << "\n";
		std::cout << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	ifstream mat1;
	ifstream mat2;

	mat1.open("matrix1.txt");
	mat2.open("matrix2.txt");

	if (!mat1.is_open())
	{
		std::cout << "Ошибка открытия файла matrix1!" << "\n";
	}
	else
	{
		std::cout << "Успешное открытие файла matrix1" << "\n";
	}

	if (!mat2.is_open())
	{
		std::cout << "Ошибка открытия файла matrix2" << "\n";
	}
	else
	{
		std::cout << "Успешное открытие файла matrix2" << "\n";
	}

	Matrix1 *matrix1 = new Matrix1[k];
	Matrix2 *matrix2 = new Matrix2[l];

	std::cout << "Считывание файла..." << "\n";

	Read_Array(mat1, mat2, matrix1, matrix2);

	std::cout << "Полученные матрицы: " << "\n";

	Print(matrix1, matrix2);

	std::cout << "Сортируем матрицы..." << "\n";

	Swap_1(matrix1, k);
	Swap_2(matrix2, l);

	std::cout << "Вывод матриц: " << "\n" << "\n";
	Print(matrix1, matrix2);

pointer:
	std::cout << "Сохранить матрицы в файлы?" << "\n";
	int choice = 0;
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет. Закрыть программу." << "\n";

	std::cin >> choice;
	if (choice = 1)
	{
		mat1.close();
		mat2.close();

		ofstream save1;
		ofstream save2;

		save1.open("matrix1.txt");
		save2.open("matrix2.txt");

		if (!save1.is_open())
		{
			std::cout << "Ошибка открытия файла matrix1 для записи!" << "\n";
		}
		else
		{
			std::cout << "Успешное открытие для перезаписи файла matrix1" << "\n";
		}

		if (!save2.is_open())
		{
			std::cout << "Ошибка открытия файла matrix2 для записи!" << "\n";
		}
		else
		{
			std::cout << "Успешное открытие для перезаписи файла matrix1" << "\n";
		}

		Save_in_File(matrix1, save1, matrix2, save2);
		std::cout << "Успешное сохранение." << "\n";
		save1.close();
		save2.close();
	}
	else if (choice = 2)
	{
		mat1.close();
		mat2.close();
		return 0;
	}
	else
	{
		std::cout << "Некорректный ввод. Попробуйте еще раз." << "\n";
		goto pointer;
	}

	mat1.close();
	mat2.close();

	system("pause");
	return 0;
}
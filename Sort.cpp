#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>
const int SIZE = 1000000;

// Метод сортировки Шелла
template<typename T>
void ShellSort(T* arr, int n)
{
    int step, i, j;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
                std::swap(arr[j], arr[j + step]);
            }
        }
    }
}

// Функция генерирующая случайные числа
double SetRand(int min, int maarr)
{
	return (double)(rand()) / RAND_MAX * ((long long)maarr - min) + min;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	double* arr = new double[SIZE];
	srand((unsigned int)time(NULL));
	
	std::cout << "Заполнение массива...\n";
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = SetRand(-100,100);
	}

	std::cout << "Выполнение сортировки...\n";
	auto begin = std::chrono::high_resolution_clock::now();
	ShellSort(arr, SIZE);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - begin;
	std::cout << "Сортировка заняла " << duration.count() << " с\n\n";

	std::cout << "Проверка правильности сортировки...\n";
	int check = 1;
	for (int i = 0; i < SIZE-1; ++i) {
		if (arr[i] <= arr[i + 1]) check++;
	}
	if (check == SIZE) std::cout << "Сортировка выполнена успешно!\n";
	else std::cout << "Сортировка выполнена неправильно!\n";;

	return 0;
}

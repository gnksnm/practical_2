#include <iostream>
#include <ctime>
#include <chrono>

const int N = 100, mxel = 199, mnel = -99;
using namespace std;
using namespace chrono;
int arr[N], sort_arr[N], sort_arr1[N];
time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start_time, end_time;
nanoseconds result_time;

void insertsort(int* arr, int N) {
	for (int i = 1; i < N; i++) {
		if (arr[0] > arr[1]) swap(arr[0], arr[1]);
		int mid = 0;
		int lo = 0;
		int hi = i;
		while (lo < hi) {
			mid = (lo + hi) / 2;
			if (arr[i] > arr[mid]) lo = mid + 1;
			if (arr[i] <= arr[mid]) hi = mid;
		}
		int j = i;
		while (j > lo) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}
void quicksort(int* arr, int  end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) quicksort(arr, l, begin);
	if (f < end) quicksort(arr, end, f);
}
int binarysearch(int* arr, int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarysearch(arr, value, start, mid - 1);
		}

		return binarysearch(arr, value, mid + 1, end);
	}

	return -1;
}
int binarysearch1(int* arr, int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarysearch(arr, value, start, mid - 1);
		}

		return binarysearch(arr, value, mid + 1, end);
	}

	return -10000;
}


void task1() {
	cout << endl << "1 Задание: " << endl << endl;
	srand(time(0));
	cout << "Несортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 19 -9;
		cout << arr[i] << " ";
	}
	for (int i = 0; i < N; i++) {
		sort_arr[i] = arr[i];
		sort_arr1[i] = arr[i];
	}
	cout << endl << endl;

}
void task11() {
	cout << "Несортированный массив: ";
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 199 - 99;
		cout << arr[i] << " ";
	}
	for (int i = 0; i < N; i++) {
		sort_arr[i] = arr[i];
		sort_arr1[i] = arr[i];
	}
	cout << endl << endl;

}
void task2() {
	cout << endl << "2 Задание: " << endl << endl;
	int end = N - 1, begin = 0;
	start_time = steady_clock::now();
	quicksort(sort_arr, end, begin);
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);

	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
		cout << sort_arr[i] << " ";
	cout << endl;
	cout << "Время, затраченное на сортировку: " << result_time.count() << " наносекунд" << endl;
	cout << endl << endl;
}
void task21() {
	int end = N - 1, begin = 0;
	start_time = steady_clock::now();
	quicksort(sort_arr, end, begin);
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);

	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
		cout << sort_arr[i] << " ";
	cout << endl;
	cout << "Время, затраченное на сортировку: " << result_time.count() << " наносекунд" << endl;
	cout << endl << endl;
}
void task3() {
	cout << endl << "3 Задание: " << endl << endl;
	start_time = steady_clock::now();
	int min = sort_arr[0];
	int max = sort_arr[N - 1];
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	cout << "Min: " << min << "\n";
	cout << "Max: " << max << "\n";
	cout << "Время, затраченное на поиск в отсортированном массиве: " << result_time.count() << " наносекунд" << endl;
	cout << endl;
	int mm = arr[0];
	int mn = arr[0];
	start_time = steady_clock::now();
	for (int i = 1; i < N; i++) {
		if (arr[i] > mn)
			mn = arr[i];
		if (arr[i] < mm)
			mm = arr[i];
	}
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	cout << "Min: " << mm << "\n";
	cout << "Max: " << mn << "\n";
	cout << "Время, затраченное на поиск в неотсортированном массиве: " << result_time.count() << " наносекунд" << endl << endl;
}
void task4() {
	cout << endl << "4 Задание: " << endl << endl;
	int min = sort_arr[0];
	int max = sort_arr[N - 1];
	int mid = (min + max) / 2;
	int k = 0;
	int d,d1;
	cout <<"Среднее значение: " << mid<<endl<<endl;
	cout << "Поиск индексов со средним значением в неотсортированном массиве: " ;
	start_time = steady_clock::now();
	for (int i = 0; i < N; i++) {
		if (arr[i] == mid) {
			cout << i << " ";
			k++;
		}
	}
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	cout << endl;
	cout << "Количество элементов со средним значением: " << k<< endl;
	cout << "Время, затраченное на поиск в неотсортированном массиве: " << result_time.count() << " наносекунд" << endl << endl;
	k = 0;
	cout << "Поиск индексов со средним значением в отсортированном массиве: ";
	start_time = steady_clock::now();
	d=binarysearch1(sort_arr, mid, 0, N);
	if (d > -10000) {
		d1 = d - 1;
		while ((sort_arr[d] == mid)and(d<=N-1)) {
			k++;
			d++;
		}
		while ((sort_arr[d1] ==mid)and(d1>=0)) {
			k++;
			d1--;
		}
	}
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	cout << endl;
	cout << "Количество элементов со средним значением: " << k << endl;
	cout << "Время, затраченное на поиск в отсортированном массиве: " << result_time.count() << " наносекунд" << endl << endl;
	cout << endl;

}
void task5() {
	cout << endl << "5 Задание: " << endl << endl <<"Введите число: ";
	int a;
	cin >> a;
	int i = 0;
	while (sort_arr[i] < a) {
		i++;
	}
	cout << endl << "Количество элементов, которые меньше числа " << a << " = " << i<<endl<<endl;
	
}
void task6() {
	cout << endl << "6 Задание: " << endl << endl << "Введите число: ";
	int b;
	cin >> b;
	int i = N-1;
	while (sort_arr[i] > b) {
		i--;
	}
	cout << endl << "Количество элементов, которые больше числа " << b << " = " << N-1-i << endl << endl;

}
void task7() {
	cout << endl << "7 Задание: " << endl << endl << "Введите число: ";
	int c;
	cin >> c;
	cout << endl << "Обычный перебор: " << endl;
	int d = -1;
	start_time = steady_clock::now();
	for (int i = 0; (sort_arr[i] <= c) and (i<N); i++) {
		if (sort_arr[i] == c) {
			d++;
			break;
		}
	}
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	if (d == -1) {
		cout << endl << "Введенного пользователем числа нет в отсортированном массиве" << endl;
	}
	else {
		cout << endl << "Введенное пользователем число есть в отсортированном массиве" << endl;

	}
	cout << "Время, затраченное на поиск обычным перебором: " << result_time.count() << " наносекунд" << endl << endl;

	cout << endl << "Алгоритм бинарного поиска: " << endl;
	d = -1;
	start_time = steady_clock::now();
	d = (binarysearch(sort_arr, c, 0, N-1));
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	if (d == -1) {
		cout << endl << "Введенного пользователем числа нет в отсортированном массиве" << endl;
	}
	else {
		cout << endl << "Введенное пользователем число есть в отсортированном массиве" << endl;
	
	}
	cout << "Время, затраченное на бинарный поиск: " << result_time.count() << " наносекунд" << endl << endl;
	cout << endl;
}
void task8() {
	cout << endl<<"8 Задание: " << endl << endl << "Введите индекс первого элемента: ";
	int m1, m2;
	cin >> m1;
	cout << endl << "Введите индекс второго элемента: ";
	cin >> m2;
	start_time = steady_clock::now();
	swap(arr[m1], arr[m2]);
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	cout << "Измененный массив:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout <<endl<< "Время, затраченное на обмен: " << result_time.count() << " наносекунд" << endl << endl;
}
void task9() {
	cout << endl << "9 Задание: " << endl << endl;
	task11();
	start_time = steady_clock::now();
	insertsort(sort_arr1, N);
	end_time = steady_clock::now();
	result_time = duration_cast<nanoseconds>(end_time - start_time);
	cout << "Сортировка вставками с использованием бинарного поиска: " << endl;

	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
		cout << sort_arr1[i] << " ";
	cout << endl;
	cout << "Время, затраченное на сортировку: " << result_time.count() << " наносекунд" << endl;
	cout << endl << endl;

	cout << "Быстрая сортировка: " << endl;
	task21();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	task1();
	int choice;
	cout<< "1 - Создать массив;" << endl
		<< "2 - Отсортировать массив;" << endl
		<< "3 - Найти максимальный и минимальный элементы;" << endl
		<< "4 - Выводит среднее значение, индексы равных ему элементов и количество;" << endl
		<< "5 - Выводит количество элементов, которые меньше введенного числа;" << endl
		<< "6 - Выводит количество элементов, которые больше введенного числа;" << endl
		<< "7 - Поиск введенного числа;" << endl
		<< "8 - Меняет местами элементы" << endl
		<< "9 - Сортирует простыми вставками, используя алгоритм бинарного поиска" << endl;
	do {
		cout << "Выберите задание для выполнения (1-9) или 0 для завершения: " << endl<<endl;
		cin >> choice;

		switch (choice) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		case 6:
			task6();
			break;
		case 7:
			task7();
			break;
		case 8:
			task8();
			break;
		case 9:
			task9();
			break;
		case 0:
			cout << "Завершение работы программы." << endl;
			break;
		default:
			cout << "Некорректный ввод. Введите число от 0 до 9" << endl;
			break;
		}

	} while (choice != 0);

}

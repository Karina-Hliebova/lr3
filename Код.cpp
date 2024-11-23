#include <iostream>
#include "windows.h"
#include <cmath>
using namespace std;

//If5.Дано три цілих числа. Знайти кількість додатних та від'ємних чисел в початковому наборі
void task_if5(); //завдання 1, декларація функції

// Дано координати точки на площині (х, у).
// Визначити, чи потрапляє точка в фігуру заданого кольору (або групу фігур)
// і вивести відповідне повідомлення.
void task_geom4(); //завдання 2, декларація функції

int main()
{
	SetConsoleOutputCP(1251);
	int menu;
	cout << "Номер завдання:";
	cin >> menu;
	// перемикання між завданнями
	switch (menu)
	{
	case 1: task_if5(); break; // Завдання 1
	case 2: task_geom4(); break; // Завдання 2
	default: cout << "Помилка! (Тільки 1,2)" << endl; // Повідомлення про помилку
	}
	system("pause");
	return 0;
}

// Завдання 1 реалізація
void task_if5()
{
	int a, b, c;
	cout << "**************** If 5 ****************" << endl;
	cout << "Введіть три цілих числа:"; // введення чисел
	cin >> a >> b >> c;
	int positiveCount = 0, negativeCount = 0; // ініціалізація змінних

	if (a > 0) positiveCount++; // перевірка кожного числа окремо
	if (a < 0) negativeCount++;
	if (b > 0) positiveCount++;
	if (b < 0) negativeCount++;
	if (c > 0) positiveCount++;
	if (c < 0) negativeCount++; 

	cout << "Кількість додатніх чисел:" << positiveCount << endl; // виведення результату
	cout << "Кількість від'ємних чисел:" << negativeCount << endl;
}

// Завдання 2, реалізація
void task_geom4()
{
	float x, y, r, a;
	double phi;
	const double pi = 3.141592;
	cout << "**************** Point in geometry region 4 ****************" << endl;
	cout << "Введіть координати точки:"; //введення координат точки 
	cin >> x >> y;
	cout << "Введіть радіус кола:"; //введення радіуса кола
	cin >> r;
	cout << "Введіть сторону трикутника:"; //введення сторони трикутника
	cin >> a;
	cout << "Введіть кут:"; //введення кута
	cin >> phi;

	float area_circle = pi * r * r; //обчислення площі кола 
	float area_yellow = ((r * r) / 2 * (phi - sin(phi))) / 2; //знаходимо площу жовтої частини
	float real_circle = area_circle - area_yellow; //обчислюємо площу червоної частини 

	if (r <= 0 || a <= 0) //перевірка коректності даних
		cout << "Повинно бути додатнім!";
	else {
		if (x * x + y * y <= r * r && (y < 0 || x > 0 && y > 0 || x < 0 && x < a && y > 0) && x < a && y >= -x + a) {
			//перевірка на належність точки до кола
			cout << "Точка належить колу." << endl; //виведення результатів
		}
		else {
			cout << "Точка не належить колу." << endl;
		}
	} 
	double perimeter = 2 * pi * r - ((pi * r) / 2 + 2 * r); //від периметра повного кола потрібно
	//відняти периметер жовтої частини
	cout << "Площа фігури:" << real_circle << endl; //виведення результату 
	cout << "Периметер фігури:" << perimeter << endl;
}

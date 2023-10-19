#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Запусик дочернего процесса" << endl;
	cout << "Дочерний процес запущен...." << endl;
	cout << "Дочерний процесс завершён" << endl;
	exit(0);
}
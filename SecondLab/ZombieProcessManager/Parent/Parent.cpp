#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	STARTUPINFO sti = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	DWORD excode;

	wstring ApplicationName(L"D:\Programming\BSUIR3\FirstHalf\OSiSP\SecondLab\ZombieProcessManager\x64\Debug\Child.exe");
	LPWSTR lpwAppName = &ApplicationName[0];

	wstring CommandLine(L"Child.exe");
	LPWSTR lpwCmdLine = &CommandLine[0];

	cout << "PARENT PROCESS START\n";
	if (!CreateProcess(NULL, // ��� ������ ������
		lpwCmdLine, //��������� ������
		NULL,
		NULL,
		TRUE, //���� ������������ ����������� �������� ��������
		NULL, //����� �������� �������� ��������
		NULL, //��������� �� ���� �����
		NULL, //������� �������
		&sti,
		&pi
	)) {
		cout << "������ �������� ��������\n";
		return -1;
	}

	_getch();

	GetExitCodeProcess(pi.hProcess, &excode);
	cout << excode << endl;

	if (excode != STILL_ACTIVE) {
		cout << "������� ��������\n";
	}
	else {
		cout << "������� ��� �����������\n";
	}

	cout << "������� ��������";
	_getch();
	return 0;
}
#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

STARTUPINFO si;
PROCESS_INFORMATION pi;

void CheckZombie() {
    // check zombie
    auto result = WaitForSingleObject(pi.hProcess, 0);

    if (result != WAIT_OBJECT_0) {
        cout << "������� ����������\n";
    }
    else {
        cout << "����� �������\n";
    }
    // check zombie
}

void RunChildProcess(bool saveHandle) {
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    wstring ApplicationName(L"D:\Programming\BSUIR3\FirstHalf\OSiSP\SecondLab\ZombieProcessManager\x64\Debug\Parent.exe");
    LPWSTR lpwAppName = &ApplicationName[0];

    wstring CommandLine(L"Child.exe");
    LPWSTR lpwCmdLine = &CommandLine[0];

    // Start the child process.
    if (!CreateProcess(NULL,    // No module name (use command line)
        lpwCmdLine,      // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
        ) {
        std::cout << "������ �������� ��������\n";
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    if (saveHandle) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "�������� �������\n";
    int savehandle;
    while (true) {
        cout << "��������� �������? 1 - ��, 0 - ���, 2 - ����������\n";

        cin >> savehandle;
        if (savehandle == 2) {
            return 0;
        }

        RunChildProcess(savehandle);
        WaitForSingleObject(pi.hProcess, INFINITE);
        CheckZombie();
    }

}

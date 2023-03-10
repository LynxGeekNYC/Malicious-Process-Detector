#include <Windows.h>
#include <iostream>

int main()
{
    // Get a handle to the current process
    HANDLE hProcess = GetCurrentProcess();

    // Get a handle to the snapshot of the current system
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    // Initialize the process entry structure
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    // Loop through all processes in the system
    if (Process32First(hSnapshot, &processEntry))
    {
        do
        {
            // Check if the process name matches a known keylogger name
            if (strcmp(processEntry.szExeFile, "keylogger.exe") == 0 ||
                strcmp(processEntry.szExeFile, "keysteal.exe") == 0 ||
                strcmp(processEntry.szExeFile, "keyspy.exe") == 0)
            {
                std::cout << "Keylogger detected!" << std::endl;
                return 0;
            }
        } while (Process32Next(hSnapshot, &processEntry));
    }

    // No keylogger detected
    std::cout << "No keylogger detected." << std::endl;
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>

#define UART_COM_PORT "COM10"

/*
key z = note c4;
key s = note c4#;
key x = note D4;
key d = note D4#;
key c = note E4;
key v = note F4;
key g = note F4#;
key b = note G4;
key h = note G4#;
key n = note A4;
key j = note A4#;
key m = note B4;
key , = note C5;
key q = note C5;
key 2 = note C5#;
key w = note D5;
key 3 = note D5#;
key e = note E5;
key r = note F5;
key 5 = note F5#;
key t = note G5;
key 6 = note G5#;
key y = note A5;
key 7 = note A5#;
key u = note B5;
key i = note C6;
*/

int main()
{

    HANDLE hSerial;
    DCB dcbSerialParams = { 0 };
    DWORD dwBytesRead = 0;
    COMMTIMEOUTS timeout;

    // Open UART port
    hSerial = CreateFile("\\\\.\\COM10", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if(hSerial == INVALID_HANDLE_VALUE)
        {
            printf("Error opening %s\n", UART_COM_PORT);
            return 1;
        }

    GetCommTimeouts(hSerial, &timeout);
    timeout.ReadIntervalTimeout = 50;
    timeout.ReadTotalTimeoutConstant = 50;
    timeout.ReadTotalTimeoutMultiplier = 1;

    timeout.WriteTotalTimeoutConstant = 50;
    timeout.WriteTotalTimeoutMultiplier = 1;

    SetCommTimeouts(hSerial, &timeout);

    GetCommState(hSerial, &dcbSerialParams);

    // Set UART parameters
    dcbSerialParams.BaudRate = CBR_14400;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
        if(!SetCommState(hSerial, &dcbSerialParams))
        {
            printf("Error setting UART parameters\n");

            CloseHandle(hSerial);
            return 1;
        }
        else
            printf("****************************\n* Opening keyboard program *\n*--------------------------*\n*   For exit key press a   *\n****************************\n");

    // Loop to read input from user and write it to the UART port
    char input[8];

    while(true)
    {
       // printf(".");

        input[0] = getch();
        fflush(stdin);

        // Check if user wants to exit
    if(input[0]=='a')
    {
        MessageBeep(MB_OK);
        break;
    }

    DWORD bytesWritten;

    //char input = getchar();

    WriteFile(hSerial, input, strlen(input), &bytesWritten, NULL);

    // Read response from UART and print it to the console
    DWORD dwBytesRead = 0;

    ReadFile(hSerial, &input, strlen(input), &dwBytesRead, NULL);
    }
    CloseHandle(hSerial);
    return 0;
}

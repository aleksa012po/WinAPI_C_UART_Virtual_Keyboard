# WinAPI_C_UART_Virtual_Keyboard
This is a simple WinAPI-based C program that emulates a virtual keyboard through a UART (Universal Asynchronous Receiver-Transmitter) COM port on a Windows system. It allows sending keyboard inputs to the specified UART COM port and receiving responses from the connected device.

Prerequisites
- Windows operating system
- UART COM port available on the system 

Setup
1. Connect the UART device to the designated COM port on your Windows system.
2. Open the project and navigate to the main.c file.
3. Modify the UART_COM_PORT definition if the target COM port is different from "COM10".
4. Build and compile the project using a C compiler of your choice.

Usage
1. Run the compiled executable.
2. The program will attempt to establish a connection with the specified UART COM port.
3. If the connection is successful, a message will be displayed indicating the program is ready to receive keyboard inputs.
4. Press the corresponding keys on your physical keyboard to emulate the desired notes according to the defined mappings (shown in the comments section of the code).
To exit the program, press the 'a' key.
5. Upon exiting, the program will close the UART connection.
6. 
Notes
The program uses the WinAPI functions for UART communication, including CreateFile, ReadFile, WriteFile, GetCommTimeouts, SetCommTimeouts, and GetCommState.
UART parameters such as baud rate, byte size, stop bits, and parity are configured in the code. Modify these parameters in the main function if required.
The program incorporates the <windows.h>, <stdio.h>, <string.h>, <stdlib.h>, <stdbool.h>, and <conio.h> libraries.
Feel free to modify and adapt the code to suit your specific UART device and application requirements.

Disclaimer
This program serves as a basic example for UART communication and virtual keyboard emulation. It may require customization and further development to suit specific use cases. Use it at your own risk.

For any questions or issues, please contact the project maintainers.

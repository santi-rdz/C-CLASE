#ifndef GETCH_H
#define GETCH_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

// Función que actúa como getch
char getch() {
    struct termios oldt, newt;
    char ch;

    // Guarda la configuración actual del terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Desactiva el modo canónico y el eco
    newt.c_lflag &= ~(ICANON | ECHO);

    // Aplica la nueva configuración
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Lee un solo carácter
    ch = getchar();

    // Restaura la configuración del terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

#endif // GETCH_H
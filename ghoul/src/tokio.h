#ifndef TOKIO_H
#define TOKIO_H
#include <stdio.h>

#if defined(__WIN32__) || defined (_WIN32) || defined(WIN32)
#include <windows.h>
#define DELAY(MS) Sleep(MS)
#else // Linux delay
#include <unistd.h>
#define DELAY(MS) usleep(MS * 1000)
#endif

char* counter(int i) {
    return (i - 7 > 0) ? "%d - %d = %d\n" : "%d - %d = \n";
}

void print_ghoul(int i) { printf(counter(i), i, 7, i - 7); }

void print_red(const char* text) {

#if WINVER<0x0502 // Special for old windows
    system("color 0C");
    printf("%s\n", text);
#else
    printf("\033[0;31m%s\033[0m\n", text);
#endif
}
#endif

#include <cstdio>
#include <windows.h>

int main() {
    DWORD ms = GetTickCount();

    unsigned int hours   = ms / 3600000;
    unsigned int minutes = (ms / 60000) % 60;
    unsigned int seconds = (ms / 1000) % 60;

    printf("Time since bootup: %u:%u:%u", hours, minutes, seconds);

    return 0;
}
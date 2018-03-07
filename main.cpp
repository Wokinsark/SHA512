#include <iostream>
#include "sha512.h"

typedef unsigned char byte;

void printArray(const byte * array, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%02x ", array[i]);
        if (!((i + 1) % 16)) {
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    byte data[1000000] = { 0x00 };
    for (int i = 0; i < 1000000; i++) {
        data[i] = 0x61;
    }

    // Digest must have
    // e7 18 48 3d 0c e7 69 64 4e 2e 42 c7 bc 15 b4 63
    // 8e 1f 98 b1 3b 20 44 28 56 32 a8 03 af a9 73 eb
    // de 0f f2 44 87 7e a6 0a 4c b0 43 2c e5 77 c3 1b
    // eb 00 9c 5c 2c 49 aa 2e 4e ad b2 17 ad 8c c0 9b

    byte * digest = SHA512(data, 1000000, NULL);
    printArray(digest, SHA512_DIGEST_LENGTH);
    return 0;
}


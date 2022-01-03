#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "defs.h"

void encryptMessage(unsigned char *plaintext, unsigned char *encryptedMessage, int key){
    int length = strlen(plaintext)-1;
    unsigned char temp[MAXLEN];
    unsigned char temp2[MAXLEN];

    caesarShift(plaintext, temp, key*length);
    encryptXOR(temp, temp2, secret_key1, length);
    encryptXOR(temp2, encryptedMessage, secret_key2, length);
    strrev(encryptedMessage);
}

void decryptMessage(unsigned char *encryptedMessage, unsigned char *decryptedMessage, int key, int size){
    unsigned char temp[MAXLEN];
    unsigned char temp2[MAXLEN];

    strrev(encryptedMessage);
    encryptXOR(encryptedMessage, temp, secret_key2, size);
    encryptXOR(temp, temp2, secret_key1, size);
    caesarReverse(temp2, decryptedMessage, size*key, size);
}

void caesarShift(unsigned char *receiving, unsigned char *output, int shift){
    int i = 0;

    while (receiving[i] != '\0' && i < strlen(receiving)-1){
        int ascii = ((int)receiving[i] - 97);
        char ciphered = receiving[i];

        if (0 <= ascii && ascii <= 25){
            ciphered = (ascii + shift) % 26 + 97;
        }

        output[i] = ciphered;
        i += 1;
    }
}

void caesarReverse(unsigned char *receiving, unsigned char *output, int shift, int length){
    for (int  i = 0; i < length; i++){
        int ascii = ((int)receiving[i] - 97);
        char value = receiving[i];

        if (0 <= ascii && ascii <= 25){
            value = (ascii - shift) % 26 + 97;

            if (value < 97){
                value += 26;
            }
        }

        output[i] = value;
    }
}

void encryptXOR(unsigned char *receiving, unsigned char *output, int key, int length){
    for (int i=0; i < length; i++){
        unsigned char value = key ^ receiving[i];
        output[i] = value;
    }
}

void printASCII(unsigned char *receiving, int length){
    for (int i = 0; i < length; i++){
        int value = (int)receiving[i];
        printf("%d ", receiving[i]);
    }
    printf("257");
}

void printMessage(unsigned char *receiving, int length){
  for (int i = 0; i < length; i++){
        char value = (char)receiving[i];
        printf("%c", receiving[i]);
    }
}

char *strrev(char *str){
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLEN  256
#define secret_key1 0b01101101
#define secret_key2 0b11110100

void caesarShift(unsigned char *receiving, unsigned char *output, int shift);
void encryptXOR(unsigned char *receiving, unsigned char *output, int key, int length);
void printASCII(unsigned char *receiving, int length);
void encryptMessage(unsigned char *plaintext, unsigned char *encryptedMessage, int key);
void caesarReverse(unsigned char *receiving, unsigned char *output, int shift, int length);
void printMessage(unsigned char *receiving, int length);
void decryptMessage(unsigned char *encryptedMessage, unsigned char *decryptedMessage, int key, int size);
char *strrev(char *str);

#endif

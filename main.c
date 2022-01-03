#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "defs.h"

int main(){
    char string_input[8];
    unsigned char readable[MAXLEN];
    unsigned char encrypted[MAXLEN];
    unsigned char input = 0;
    int selection;
    int key;

    printf("\nWelcome to the matrix! What would you like to do:\n");
    printf("  1. Encrypt a message \n");
    printf("  2. Decrypt a message \n");
    printf("  3. Leave \n");
    printf("\n  what is your selection: ");
    fgets(string_input, sizeof(string_input), stdin);
    sscanf(string_input, "%d", &selection);

    if (selection == 1){
      printf("\nPlease enter your key (between 1 and 1000): ");
      fgets(string_input, sizeof(string_input), stdin);
      sscanf(string_input, "%d", &key);

      if (1 <= key && key <= 1000){
          printf("\nPlease enter text to encrypt: \n");
          fgets(readable, sizeof(readable), stdin);

          encryptMessage(readable, encrypted, key);
          printf("\nEncrypted Text: \n");
          printASCII(encrypted, strlen(readable)-1);
          printf("\n");
      }
      else {
        printf("\nYou did not enter a valid key\n");
      }
    }

    else if (selection == 2){
      printf("\nPlease enter your key (between 1 and 1000): ");
      fgets(string_input, sizeof(string_input), stdin);
      sscanf(string_input, "%d", &key);

      if (1 <= key && key <= 1000){
          int size = 0;
          int temp = 0;

          printf("\nPlease enter encrypted text: \n");

          while (size < MAXLEN){
              scanf("%d", &temp);

              if (temp != 257){
                  encrypted[size] = temp;
                  size += 1;
              }
              else{
                  break;
              }
          }

          printf("\nDecrypted Text: \n");
          decryptMessage(encrypted, readable, key, size);
          printMessage(readable, size);
          printf("\n");
      }

      else {
        printf("\nYou did not enter a valid key\n");
      }
    }

    else if (selection == 3){
      printf("Goodbye...\n");
    }

    else {
      printf("\nYou did not enter a valid choice\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Encrypt(FILE *FileToEncrypt, FILE *Keys, FILE *EncryptedFile) {
  srand(time(0));
  int c;
  while ((c = fgetc(FileToEncrypt)) != EOF) {
    int key = rand();
    int EncChar = key ^ c;
    fputc(key, Keys);
    fputc(EncChar, EncryptedFile);
  }
}

int main(int arg, char *karg[]) {
  if (arg != 2) {
    printf("Need a file to encrypt");
  } else {

    char *FileName = karg[1];
    FILE *FileToEncrypt = fopen(FileName, "r");
    FILE *Keys = fopen("keys.out", "w");
    FILE *EncryptedFile = fopen("Encrypted.out", "w");
    Encrypt(FileToEncrypt, Keys, EncryptedFile);
    fclose(FileToEncrypt);
    fclose(Keys);
    fclose(EncryptedFile);
  }
}

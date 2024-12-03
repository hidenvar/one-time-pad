#include <stdlib.h>
#include <stdio.h>

void decrypt(FILE* encryptedFile, FILE* keys, FILE* decryptedFILE){
  int c;
  while((c = fgetc(encryptedFile)) != EOF){
    int key = fgetc(keys);
    int decChar = key ^ c;
    fputc(decChar, decryptedFILE);
  }
}
int main(int args, char* kargs[]){
  if(args != 3){
    printf("this is how to use this app:\n\t");
    printf("./decrypt [encrypted file] [keys]");
  } else{
    FILE* encryptedFile = fopen(kargs[1],"r");
    FILE* keys = fopen(kargs[2],"r");
    FILE* decryptedFile = fopen("decrypted.out", "w");
    decrypt(encryptedFile, keys, decryptedFile);

    fclose(encryptedFile);
    fclose(keys);
    fclose(decryptedFile);
  }
}

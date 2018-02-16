#include <stdio.h>
#include <stdlib.h>

struct freqList {
    int freq[256];
};


int main(void){

    int mess = open("MENSAGEM.TXT", O_RDONLY);
    int letter;

    freqList freqs = {0};

    while(read(mess, letter, 1) > 0){
        freqs[letter] = freqs[letter] + 1
    }

    close(mess);

    int i = 0;
    while(i < 257){
        printf("Letter %s freq is %d\n", i, freqs[i]);
        i++;
    }

}


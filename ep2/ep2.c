#include <stdio.h>
#include <stdlib.h>

struct freqList {
    int freq[256];
};


int main(void){

    /* Message read phase */
    FILE *dec_file = fopen("MENSAGEM.TXT", "rb");   // Open the file for reading
    fseek(dec_file, 0, SEEK_END);                   // To discover the file's size
    int mess_size = ftell(dec_file) + 1;            // The message size + end zero
    unsigned char letters[mess_size];               // Create a buffer to the size
    rewind(dec_file);                               // Go back to start of file

    /* Read the message all at once and close */
    fread(letters, mess_size, sizeof(unsigned char), dec_file);
    letters[mess_size - 1] = 0;
    fclose(dec_file);
    printf("File read. Message is:\n%s\n", letters);

    /* Create the frequency table */
    struct freqList freqs = {0};

    /* And populate it */
    int i = 0;
    while(i < mess_size - 1){
        freqs.freq[letters[i]] = freqs.freq[letters[i]] + 1;
        i++;
    }
    puts("Frequencies populated.");

    /* Print our frequency table contents */
    i = 0;
    while(i < 256){
        if(freqs.freq[i] > 0){
            printf("Letter %d frequecy is %d\n", i, freqs.freq[i]);
        }
        i++;
    }

    /* Write this table to disk */
    i = 0;
    FILE *freqs_file = fopen("TABELA.TXT", "w");
    while(i < 256){
        fprintf(freqs_file, "%d %d ", freqs.freq[i], freqs.freq[i + 1]);
        i++;
    }
    fprintf(freqs_file, "\n");
    fclose(freqs_file);

    /* Now we encode the message in the following way: we shift the character
     * the number of occurences in the text, by looking up in our frequency
     * table. E.g. "abbccc" becomes "bddfff". */
    puts("Encoding...");

    unsigned char enc_mess[mess_size];
    i = 0;
    while(i < mess_size){
        enc_mess[i] = letters[i] + freqs.freq[letters[i]] % 256;
        i++;
    }

    /* Print the encoded string */
    puts(enc_mess);

    /* Now we write this encoded string to a file */
    FILE *enc_file = fopen("CODIFICADA.TXT", "wb");
    fwrite(enc_mess, mess_size, sizeof(unsigned char), enc_file);
    fclose(enc_file);

    return 0;
}


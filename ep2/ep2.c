#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define struct to hold letters frequencies */
struct freqList {
    /* We only support ascii characters now */
    int freq[256];
};

/* Encode a message into a string */
unsigned char *encode(unsigned char *message){

    /* Create the frequency table */
    struct freqList freqs = {0};

    /* And populate it */
    int i = 0;
    int mess_len = strlen(message);

    while(i < mess_len - 1){        // Don't include terminating zero
        freqs.freq[message[i]] = freqs.freq[message[i]] + 1;
        i++;
    }
    puts("Frequencies populated.");

    /* 
     * Now we encode the message in the following way: we shift the character
     * the number of occurences in the text, by looking up in our frequency
     * table. E.g. "abbccc" becomes "bddfff". 
     */
    puts("Encoding...");

    unsigned char enc_mess[mess_len];
    i = 0;
    while(i < mess_len){
        enc_mess[i] = message[i] + freqs.freq[message[i]] % 256;
        i++;
    }

    /* Print the encoded string */
    puts(enc_mess);

    return strdup(enc_mess);
}

int main(void){

    /*
     * Problem 1
     */

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

    /* Print our frequency table contents */
    int i = 0;
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

    /* Encoded message */
    unsigned char *enc_mess = encode(letters);

    /* Now we write this encoded string to a file */
    FILE *enc_file = fopen("CODIFICADA.TXT", "wb");
    fwrite(enc_mess, mess_size, sizeof(unsigned char), enc_file);
    fclose(enc_file);

    /*
     * Problem 2
     */

    /* Message read phase */
    enc_file = fopen("CODIFICADA.TXT", "rb");       // Open the file for reading
    fseek(enc_file, 0, SEEK_END);                   // To discover the file's size
    int mess_len = ftell(enc_file) + 1;             // The message size + end zero
    rewind(dec_file);                               // Go back to start of file

    /* Clear the variale */
    bzero(enc_mess, mess_len);

    /* Read the message all at once and close */
    fread(enc_mess, mess_len, sizeof(unsigned char), enc_file);
    letters[mess_len - 1] = 0;
    fclose(dec_file);
    printf("File read. Message is:\n%s\n", enc_mess);

    /* Read the frequencies table file */
    freqs_file = fopen("TABELA.TXT", "w");
    fseek(freqs_file, 0, SEEK_END);                 // To discover the file's size
    int table_len = ftell(freqs_file) + 1;          // The message size + end zero
    rewind(freqs_file);                             // Go back to start of file

    /* Read the table and close */
    struct freqList table = {0};

    fread(enc_mess, mess_len, sizeof(unsigned char), enc_file);
    letters[mess_len - 1] = 0;
    fclose(dec_file);
    printf("File read. Message is:\n%s\n", enc_mess);

    return 0;
}


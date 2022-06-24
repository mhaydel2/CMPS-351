#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>
/*  Milan Haydel
    C00419477
    CMPS 351
    Program Description: This project input focuses on
        identification and validation, thread creation, and synchronization.
    Certificate of Authenticity: I certify that the code in the
        method functions including method function main of this
        project are entirely my own work.
 */
void check_input() {
    char input[100];
    puts("Enter something for input: (X for exit) ");
    fflush(stdout);
    fgets(input, 100, stdin);
    //  check input character array
    /*for (int i = 0; i < len; i++){
        printf("Status: %c\n", input[i]);
    }*/
    while (input[0] != 'X') {
        bool integer = true;
        bool intP = false;
        bool intN = false;
        bool str = false;
        bool dec = false;
        bool decCrit = false;

        int len = strlen(input)-1;
        int count = 0;
        int strCount = 0;
        int decCount = 0;
        for (int i = 0; i < len; i++) {
            if (i == 0 && input[i] == '-') {
                intN = true;
            } else if (isdigit(input[i])) {
                if (!intN)
                    intP = true;
                else intP = false;
                count++;
            } else if (input[i] == '.') {
                if (count > 0 && i < len - 1 && decCount == 0) {
                    dec = true;
                    decCount++;
                }
                //(decCount > 0 && count > 0) || (count > 0 && strCount == 0) || (count == 0 && strCount == 0)
                else if ((decCount != 0) || (count == 0) || (count != 0)){
                    decCrit = true;
                }
                else {
                    str = true;
                }
            } else {
                integer = false;
                strCount++;
                str = true;
            }
        }


        if (decCrit && !str) {
            printf("Decimal Criteria was not met.\n");
            dec = false;
            integer = false;
        }

        if (strCount > 0 && count > 0 && !integer && !decCrit) {
            str = true;
            integer = true;
        }
        else if (count == 0 && !integer && !decCrit)
            str = true;

        if (integer && !str) {
            if (dec) {
                if (intP) {
                    printf("This is a positive decimal number! %s", input);
                } else if (intN)
                    printf("This is a negative decimal number! %s", input);
            } else if (intP)
                printf("This is a positive number! %s", input);
            else if (intN)
                printf("This is a negative number! %s", input);
        } else
            printf("This is a character string! %s", input);
        /*else
            printf("This is not a number or character string! %s", input);*/

        puts("Enter something for input: (X for exit) ");
        fflush(stdout);
        fgets(input, 100, stdin);
    }
    printf("\n");
}

int* generator(size_t len, int a, int b, int c) {
    int *x = malloc(len);
    int value;
    for (int i = 1; i <= len; i++){
        value = a*(i*i) + b*i + c;
        x[i-1] = value;
    }
    return x;

}

void first_fit(char* buffer, size_t buffer_size, char* input) {
    int inCount = 0;
    for (int i = 0; i < buffer_size; i++) {
        if (input[i] != '\0') {
            inCount++;
        }
        else {
            break;
        }
    }
    int track[inCount];
    int count = 0;
    for (int i = 0; i < buffer_size; i++){
        if (inCount >= count && buffer[i] == '-'){
            track[count] = i;
            count++;
            //printf("count: %i\n", count);
            if (count == inCount+1){
                break;
            }
        }
        else if (buffer[i] != '-'){
            count = 0;
        }
        else{
            count = 0;
            break;
        }
    }
    //printf("\ncount: %i \nin-count: %i\n", count, inCount);
    if (count == inCount+1){
        //printf("%i %i\n", count, inCount);
        int j = 0;
        int k = track[0];
        for (int i = 0; i < inCount; i++){
            //printf("%i \n", i);
            buffer[k] = input[j];
            j++;
            k++;
        }
        buffer[track[inCount]] = '\0';
    }
    else {
        printf("Not enough space in the buffer!\n");
    }

    for (int i = 0; i < buffer_size; i++){
        printf("%c ", buffer[i]);
    }
}

int main() {
    check_input();

    int a, b, c;
    printf("Enter value for a: ");
    fflush(stdout);
    scanf("%i", &a);
    printf("Enter value for b: ");
    fflush(stdout);
    scanf("%i", &b);
    printf("Enter value for c: ");
    fflush(stdout);
    scanf("%i", &c);
    //printf("%i %i %i\n", a, b, c);
    int *array = generator(10, a, b, c);
    for (int i = 0; i < 10; i++){
        printf("[%d] ", *(array+i));
    }
    printf("\n\n");
    free(array);

    //[‘-’, ‘a’, ‘b’,’c’, ‘\0’, ‘-’, ‘-’, ‘-’,’-’, ‘-’], 10, “cat”
    char arrChar[] = {'-', 'a', 'b', 'c', '\0', '-', '-', '-', '-', '-'};
    first_fit(arrChar, 10, "cat");

    return 0;
}

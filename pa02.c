/*============================================================================
| Assignment: pa02 - Calculate the checksum of an input file given:
| -> the name of the input file,
| -> the checksum size of either 8, 16, or 32 bits
| Author: Payton Garing
| Language: c
| To Compile: 
| gcc -o pa02 pa02.c
| To Execute: java -> java pa02 inputFilename.txt checksumSize
| or c -> ./pa02 inputFilename.txt checksumSize
| where inputFilename.txt is the input file
| and checksumSize is either 8, 16, or 32
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
| Class: CIS3360 - Security in Computing - Spring 2025
| Instructor: McAlpin
| Due Date: 3-23-2025
+===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void formattedPrint(const char* input){
    
    int length = strlen(input);

    // format output to 80 characters per line
    for(int i = 0; i< length; ++i){
        putchar(input[i]);
        if((i+1) % 80 == 0){
            putchar('\n');
        }
    }
}

unsigned long int sum8bit(const char* input){
    unsigned long int sum = 0;
    int length = strlen(input);

    for(int i = 0; i < length; i++){
        sum += (unsigned char)input[i];
    }
    // return only last 2 bits
    return sum & 0xff;
}

unsigned long int sum16bit(char* input){
    unsigned long int sum = 0;
    int length = strlen(input);

    for(int i =0; i< length; i+= 2){
        sum += (unsigned char)input[i] << 8;
        sum += (unsigned char)input[i+1];
    }
    // return only last 4 bits
    return sum & 0xffff;
}

unsigned long int sum32bit(char *input){
    unsigned long int sum = 0;
    int length = strlen(input);

    for(int i = 0; i< length; i+= 4){
        sum += (unsigned char)input[i] << 24;
        sum += (unsigned char)input[i+1] << 16;
        sum += (unsigned char)input[i+2] << 8;
        sum += (unsigned char)input[i+3];
    }
    // return only last 8 bits
    return sum & 0xffffffff;
}

int checkSumCalculation(int checkSumSize, char* input, int length){
    unsigned long sum = 0;
    
    switch(checkSumSize){
        case 8:
            sum = sum8bit(input);
            break;
        case 16:
            sum = sum16bit(input);
            break;
        case 32:
            sum = sum32bit(input);
            break;
    }

    return sum;
}

int main(int argc, char *argv[]){
    unsigned long checksum = 0;
    
    if(argc != 3){
        printf("Not valid # of args");
        return 0;
    }

    // gather size of checksum from command line input
    int checkSumSize = atoi(argv[2]); 

    if(checkSumSize != 8 && checkSumSize != 16 && checkSumSize != 32){
        fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
        return 0;
    }

    int index = 0; 
    char output[20000];
    char asciiChar;
    
    // open file from command line input
    FILE * fptrCheck = fopen(argv[1], "r"); 

    if(fptrCheck == NULL){
        printf("Error in opening Checksum file");
        exit(1);
    }
    
    // gather input from file into an array
    while((asciiChar = fgetc(fptrCheck)) != EOF){
            output[index++] = (asciiChar);
        }
        
    fclose(fptrCheck);

    printf("\n");
    int length = strlen(output);

    // if statemetns to calculate checksum according to checksum size
    if(checkSumSize == 8){
    checksum = checkSumCalculation(checkSumSize, output, index);
    formattedPrint(output);
    printf("\n");

    } else if(checkSumSize == 16){
        // insert padding
        if (length % 2 != 0){
            strcat(output, "X");
            length++;
        }

    checksum = checkSumCalculation(checkSumSize, output, index);
    formattedPrint(output);
    printf("\n");

    } else if(checkSumSize == 32){
        // insert padding
        while(length % 4 != 0){
            strcat(output, "X");
            length++;
        }

    checksum = (unsigned int) checkSumCalculation(checkSumSize, output, index);
    formattedPrint(output);
    printf("\n");
    }
    
    // final formatted checksum output
    printf("%2d bit checksum is %8lx for all %4d chars\n", checkSumSize, checksum, length);
    return 0;
}

/*=============================================================================
| I Payton Garing (pa783023) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
    /*============================================================================
    | Assignment: pa01 - Encrypting a plaintext file using the Hill cipher
    |
    | Author: Payton Garing
    | Language: C
    | To Compile: gcc -o pa01 pa01.c
    | To Execute: c -> ./pa01 kX.txt pX.txt
    | where kX.txt is the keytext file
    | and pX.txt is plaintext file
    | Note:
    | All input files are simple 8 bit ASCII input
    | All execute commands above have been tested on Eustis
    |
    | Class: CIS3360 - Security in Computing - Spring 2025
    | Instructor: McAlpin
    | Due Date: 02-23-2025
    +===========================================================================*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>


    int matrixMultiply(int n, int A[n][n], int B[n][1], int result[n][1]){
        

        for(int i =0; i < n; i++){
            result[i][0] = 0;
        }

        for(int i =0; i < n; i++){
            for (int j =0; j < n; j++){
                    result[i][0] = result[i][0] + (A[i][j] * B[j][0]);
            }
            result[i][0] = result[i][0] % 26;
        }
        return 0;
        }
        
        
    int main(int argc, char *argv[]){
        char inputLine[12000];

        // open key file from command line argument
        FILE * fptrKey = fopen(argv[1], "r");

        int n; //matrix dimensions
        fscanf(fptrKey, "%d", &n);

        // key matrix with n rows and n columns
        int matrixA[n][n]; 

        //scan key file for matrix contents
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++){
                fscanf(fptrKey, "%d", &matrixA[i][j]);
            }
        }

        printf("Key Matrix:\n");
        // print key matrix
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                printf( "%4d", matrixA[i][j]);
            }
            printf("\n");
        }
        printf("\n");


        fclose(fptrKey);

        char c;
        int count = 0;
        int charIndex = 0;

        // echo input file
        FILE * fptrPlain = fopen(argv[2], "r");
        if(fptrPlain == NULL){
            printf("error plain file");
            exit(1);
        }
        // convert text to lowercase
        while((c = fgetc(fptrPlain)) != EOF){
            if (isalpha(c)){
                inputLine[charIndex++] = tolower(c);
            }
        }

        fclose(fptrPlain);
        printf("Plaintext:\n");
        for(int i = 0 ;i < charIndex; i++){
            putchar(inputLine[i]);
            // insert newline every 80 chharacters
            if((i + 1) % 80 == 0){
                printf("\n"); 
            }
        }
        printf("\n");
        printf("\n");

        while(charIndex % n != 0){
            inputLine[charIndex++] = 'x';
        }

        printf("Ciphertext:\n");
    
        for(int i =0; i< charIndex; i += n){
            int cipherBlock[n][1];
            for(int j =0; j < n; j++){
                cipherBlock[j][0] = inputLine[i + j] - 'a';
            }

            int result[n][1];
            matrixMultiply(n, matrixA, cipherBlock, result);

            for(int j =0; j < n; j++)
            {
                char cipherChar = result [j][0] + 'a';
                
                putchar(cipherChar);
            }
            if((i +n) % 80 == 0){
                printf("\n");
            }
        }
        printf("\n");
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
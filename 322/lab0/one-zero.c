#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

// constants
#define BUFFERSIZE 4096
#define BYTELENGTH 8

// ASCII named constants
char *ascii[] = {"NULL","SOH","STX","ETX","EOT","ENQ",
"ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI","DLE",
"DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB",
"ESC","FS","GS","RS","US","SPACE"};

// function prototypes
int byteToDecimal(char[]);
char decimalToAscii(int);
void conversionManager(char[]);
int calculateParity(char[]);
void printHandler(int);
int powers(int, int);

int main(int argc, char *argv[]){
    char buffer[BUFFERSIZE];
    int charCount;
    int n;
    int status = 1;

    // check if the filename is given or only a -
    int i;
    for(i=0;i<argc;i++){
        if(*argv[i] == '-' || *argv[i] == '\0')
            status = 0;
    }
 
    if(status){
        int file_descriptor = open(argv[1], O_RDONLY);
        while((n = read(file_descriptor, buffer, BUFFERSIZE)) > 0){
            charCount = n;
        }
        close(file_descriptor);
    }
    else {
        while((n = read(STDIN_FILENO, buffer, BUFFERSIZE)) > 0){
            charCount = n;
        }    
    }
    // pad the buffer so everything is an even 8 bytes
    while((charCount%BYTELENGTH) != 0){
        int i;
        for(i=0;i<=charCount;i++){
            if(buffer[i]=='\0' || buffer[i] == '\n')
                buffer[i]='0';
        }
        charCount++;
    }
    // print the header
    printHandler(0);
    // drive the program.
    while(charCount >= 1){
        conversionManager(buffer);
        charCount=charCount-BYTELENGTH;
    }
    return 0;
}
// converts the decimal number to ascii value.
char decimalToAscii(int num){  
    char c = (char)num;
    return c;
}

void conversionManager(char buffer[]){
    static int COUNTS=0;
    // make a byte array and account for \0 terminator.
    char eightBytes[BYTELENGTH];
    int i = 0;
    // copy just 8 bytes
    for(i=0; i < BYTELENGTH;i++)
        eightBytes[i] = buffer[i+COUNTS];
    eightBytes[BYTELENGTH] = '\0';

    fprintf(stdout, "%s\t", eightBytes);

    int decimal = byteToDecimal(eightBytes);
    
    if(decimal>=0 && decimal <=32){
        fprintf(stdout, "%s", ascii[decimal]);
    }
    fprintf(stdout, "%c\t", decimalToAscii(decimal));
    fprintf(stdout, "%d\t", decimal);
 
    if(calculateParity(eightBytes) == 0) printHandler(1);
    else printHandler(2);
    COUNTS+=8;
}

// Calculates the parity bit. We check for even parity.
int calculateParity(char buffer[]){
    // We don't count the least significant bit.
    int i = 1;
    int result = 0;
    for(i; i<=BYTELENGTH; i++){
        if(buffer[i] == '1')
         result++;
    }
    // check with mod 2 for even parity.
    if((result%2) == 0){ return 0; }
    else{ return 1; }
}

// Calculates the decimal number.
int byteToDecimal(char buffer[]){
    // let's ignore the least significant
    int i = 7;
    int result=0;
    int power=0;
    for(i; i > 0;i--){
        if(buffer[i]== '1'){
            result=result+powers(2,power);
        }   
        power++;
    }

    return result;
}

// a function that raises a to the power b in int form.
int powers(int a, int b){
    // base case
    if(b==0){
        return 1;
    }
    else{
        return a*powers(a,b-1);
    }
}

// Handles the different print jobs.
void printHandler(int flag){
    if(flag == 0){
        fprintf(stdout, "\n Original\tASCII\tDecimal\tParity\tT.Error");
        fprintf(stdout, "\n --------\t-----\t-------\t------\t-------\n");
    }
    if(flag == 1){ fprintf(stdout, "EVEN\tFALSE\n"); }
    if(flag == 2){ fprintf(stdout, "ODD\tTRUE\n"); }
    if(flag == 9){ fprintf(stderr, "ERROR!\n" ); }
}
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "longCalculation.h"
char *nameInp;
char *nameOut;
int base;
int flag;

void getFlag(char *fl){
    if(strcmp(fl, "-p")==0){
        flag =1;
    }
    if(strcmp(fl,"-m") == 0){
        flag = 2;
    }
    if(strcmp(fl,"-a") == 0){
        flag = 3;
    }
    if(strcmp(fl,"-d") == 0){
        flag = 4;
    }
    if(strcmp(fl,"-s") == 0){
        flag =5;
    }
}

void checkFlag(char arg[], int num){
    if(num ==1){
         int ch1 = strcmp(arg, "-p");
         int ch2 = strcmp(arg, "-m");
         int ch3 = strcmp(arg, "-a");
         int ch4 = strcmp(arg, "-d");
         int ch5 = strcmp(arg, "-s");
         if(ch1 !=0 && ch2!=0 && ch3!=0 && ch4!=0 && ch5!=0){
             printf("Wrong command: %s\n", arg);
             exit(-5);
         } else{
             getFlag(arg);
         }
    }
    if(num == 2) {
        int pr = strcmp(arg, "-i");
        if (pr != 0) {
            printf("Wrong command: %s\n", arg);
            exit(-5);
        }
    }
    if(num == 3) {
        int pr = strcmp(arg, "-o");
        if (pr != 0 ) {
            printf("Wrong command: %s\n", arg);
            exit(-5);
        }
    }
}
void checkArgs(int argc, char **argv) {
    if (argc !=  7) {
        printf("wrong command line");
        exit(-5);
    }
    // argv[1]:
    //  -p plus
    //  -m minus
    //  -a multiplication
    //  -d div
    //  -s mod
    // argv[2] :
    //  -i флаг фходного файла
    // argv[3] :
    //  inpFile.txt имя входного файла
    // argv[4] :
    //  -o флаг выходного файла
    // argv[5] :
    //  outFile.txt имя выходного файла
    // argv[6] :
    // base - int
    checkFlag(argv[1],1);
    checkFlag(argv[2],2);
    checkFlag(argv[4],3);
    char *end;
    base = strtol(argv[6],&end,10);
    if(base == 0){
        printf(" Dont correct base : %s", argv[6]);
        exit(-10);
    }
    if(strlen(argv[3]) ==0){
        printf("Empty inputfile name");
        exit(-11);
    } else {
        nameInp = argv[3];
    }
    if(strlen(argv[5]) ==0){
        printf("Empty outputfile name");
        exit(-11);
    } else {
        nameOut = argv[5];
    }
}
void clenUp(){
    free(nameInp);
    free(nameOut);
    clean();
}
int main(int argc, char **argv){
    checkArgs(argc,argv);
    work(nameInp,nameOut,base,flag);
    printf("Done\n");
    clenUp();
    clean();
}
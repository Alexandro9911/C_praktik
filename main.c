#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include "longCalculation.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>

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
}
void checkArgs(int argc, char **argv) {
    if (argc <= 1 || argc >  6) {
        printf("wrong command line");
        exit(-5);
    }
    // argv[1]:
    //  -p plus
    //  -m minus
    //  -a multiplication
    //  -d division
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

    if(strcmp(argv[1], "-p") !=0 && strcmp(argv[1], "-m") !=0 && strcmp(argv[1], "-a") !=0 &&
    strcmp(argv[1], "-d") !=0 && strcmp(argv[2], "-i")!=0 && strcmp(argv[4],"-o")!= 0){
        printf("wrong option : %s\n", argv[1]);
        exit(-6);
    } else{
        getFlag(argv[1]);
    }
    if(base == 0){
        printf(" Dont correct base : %s", argv[6]);
        exit(-10);
    } else{
        base = (int)argv[6] - '0';
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
    clenUp();
}
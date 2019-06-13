#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <mem.h>
#include "longCalculation.h"
void testPlus(){
    int result=1;
    int base = 10;
    int flag = 1;
    char *chA;
    char nameInp[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\data.txt";
    char nameOut[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\out.txt";
    work(nameInp,nameOut,base,flag);
    FILE *openFile = fopen(nameOut, "r");
    chA = (char*)calloc((size_t) base, sizeof(char));
    while(fscanf(openFile,"%s",chA) != EOF) {
    }
    fclose(openFile);
    if(strcmp(chA,"77777")== 0){
        result = 1;
    }else{
        result =0;
    }
    assert(result);
}

void testMinus(){
    int result=1;
    int base = 10;
    int flag = 2;
    char *chA;
    char nameInp[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\data.txt";
    char nameOut[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\out.txt";
    work(nameInp,nameOut,base,flag);
    FILE *openFile = fopen(nameOut, "r");
    chA = (char*)calloc((size_t) base, sizeof(char));
    while(fscanf(openFile,"%s",chA) != EOF) {
    }
    fclose(openFile);
    if(strcmp(chA,"33333")== 0){
        result = 1;
    }else{
        result =0;
    }
    assert(result);
}
void testMultpl(){
    int result=1;
    int base = 10;
    int flag = 3;
    char *chA;
    char nameInp[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\data.txt";
    char nameOut[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\out.txt";
    work(nameInp,nameOut,base,flag);
    FILE *openFile = fopen(nameOut, "r");
    chA = (char*)calloc((size_t) base, sizeof(char));
    while(fscanf(openFile,"%s",chA) != EOF) {
    }
    fclose(openFile);
    if(strcmp(chA,"1234543210")== 0){
        result = 1;
    }else{
        result =0;
    }
    assert(result);
}
void testDiv(){
    int result=1;
    int base = 10;
    int flag = 4;
    char *chA;
    char nameInp[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\data.txt";
    char nameOut[] = "C:\\Users\\LEGION\\CLionProjects\\untitled5\\out.txt";
    work(nameInp,nameOut,base,flag);
    FILE *openFile = fopen(nameOut, "r");
    chA = (char*)calloc((size_t) base, sizeof(char));
    while(fscanf(openFile,"%s",chA) != EOF) {
    }
    fclose(openFile);
    if(strcmp(chA,"77777")== 0){
        result = 1;
    }else{
        result =0;
    }
    assert(result);
}
int main() {
    testPlus();
    testMinus();
    testMultpl();
    printf("Tests done");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ArrC;
int *ArrA;
int *ArrB;
char *chA;
char *chB;
char *nameInp;
char *nameOut;

int checkBase(int base, int len1){
    if(base < len1){
        return 1;
    } else {
        return 0;
    }
}
void fromStrToInt(char *str, int *arr, int base) {
    int counter = 0;
    int size = (int) strlen(str);
    int check = checkBase(base, (int) strlen(str));
    if( check ==1 ){
        printf("ERROR : too small base");
        exit(-6);
    }
    for (int i = size-1; i >= 0; i--) {
        arr[counter] = str[i] - '0';
        if (arr[counter] < 0 || arr[counter] > 9){
            printf("ERROR : unreachble symbol : %c", '0' + arr[counter]);
            exit(-5);
        }
        counter++;
    }
}

void plus(const int *arrA, const int *arrB,int *ArrC, int n, int m) {
    int len = 0;
    if (n > m) {
        len = n + 1;
    } else {
        len = m + 1;
    }
    for (int i = 0; i < len; i++) {
        int sum = arrA[i] + arrB[i] + ArrC[i];
        if (sum >= 10) {
            ArrC[i] = 0;
            ArrC[i + 1] = 1;
        } else {
            ArrC[i] = sum;
        }
    }
}

void minus(int *x, const int *y, int *ArrC, int length) {
    for (int i = 0; i < (length); i++) {    // проход по всем разрядам числа, начиная с последнего, не доходя до первого
        if (i < (length - 1)) {             // если текущий разряд чисел не первый
            x[i + 1]--;                     // в следующуем разряде большего числа занимаем 1.
            ArrC[i] += 10 + x[i];           // в ответ записываем сумму значения текущего разряда большего числа и 10-ти
        } else {                            // если текущий разряд чисел - первый
            ArrC[i] += x[i];                // в ответ суммируем значение текущего разряда большего числа
        }
        ArrC[i] -= y[i];                    // вычитаем значение текущего разряда меньшего числа
        if (ArrC[i] / 10 > 0) {             // если значение в текущем разряде двухразрядное
            ArrC[i + 1]++;                  // переносим единицу в старший разряд
            ArrC[i] %= 10;                  // в текущем разряде отсекаем ее
        }
    }
}

void division(int ArrA[], int ArrB[], int n, int m) { // при условии,  что второе число меньше разрядности первого числа

}

void multiplication(const int *ArrA, const int *ArrB, int *ArrC, int n, int m) {
    int length = n + m + 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ArrC[i + j] += ArrA[i] * ArrB[j];
    for (int i = 0; i < length; i++) {
        ArrC[i + 1] += ArrC[i] / 10;
        ArrC[i] %= 10;
    }
}

void toString(char *str, int n) { // n - размер действительного числа, без нулей
    int counter = 0;
    int flag = 0;
    int norm = 0;
    for (int i = n-1; i >= 0; i--) {
        char ch = (char) ('0' + ArrC[i]);
        if (flag == 0 && ch == '0') {
            counter++;
        } else {
            flag = 1;
            str[norm] = ch;
            norm++;
            counter++;
        }
    }
}

int countlessZeros(int n) { // разрядность числа
    int zeros = 0;
    int flag = 0;
    for (int i = n-1; i >= 0; i--) {
        if (flag == 0 && ArrC[i] == 0) {
            zeros++;
        } else {
            if (ArrC[i] != 0) {
                flag = 1;
            }
        }
    }
    return zeros;
}

int readFile(char *name, int base) {
    FILE *openFile = fopen(name, "r");
    if (openFile == NULL) {
        printf("ERROR : File not open \n");
        return -2;
    }
    chA = (char*)calloc((size_t) base, sizeof(char));
    if(chA == NULL){
        printf("ERROR : Problem with memory");
        exit(-3);
    }
    chB = (char*)calloc((size_t) base, sizeof(char));
    if(chB == NULL){
        printf("ERROR : Problem with memory");
        exit(-3);
    }
    while(fscanf(openFile,"%s %s",chA,chB) != EOF) {
    }
    fclose(openFile);
    return 0;
}
int writeAnsw(char answ[], char name[]) {
    FILE *outFile;
    outFile = fopen(name, "w");
    if (outFile == NULL) {
        printf("ERROR : file not open\n");
        exit(-4);
    } else {
        fprintf(outFile, "%s", answ);
        fclose(outFile);
    }
    return 0;
}
int work(char *nameInp, char*nameOut, int base,int flag){
    readFile(nameInp, base);
    ArrA = (int*)calloc((size_t) base, sizeof(int));
    if(ArrA == NULL){
        printf("ERROR : Problem with memory");
        return -3;
    }
    ArrB = (int*)calloc((size_t) base, sizeof(int));
    if (ArrB == NULL) {
        printf("ERROR : Problem with memory");
        return -3;
    }
    fromStrToInt(chA, ArrA, base); // переводим в числовой формат массив
    fromStrToInt(chB, ArrB, base);
    int a = (int) strlen(chA), b = (int) strlen(chB);
    int leng = 0;
    if (flag == 1) { // if flag = 1 - plus
        int len = 0;
        if (a > b) {
            len = a + 1;
        } else {
            len = b + 1;
        }
        leng = len;
        ArrC = (int *) calloc((size_t) len, sizeof(int));
        if (ArrC == NULL) {
            printf("ERROR : Problem with memory");
            return -3;
        }
        plus(ArrA, ArrB, ArrC, a, b);
    }
    if (flag == 2) { // if flag = 2 minus
        int len = 0;
        if (a > b) {
            len = a;
        } else {
            len = b;
        }
        ArrC = (int *) calloc((size_t) len, sizeof(int));
        if (ArrC == NULL) {
            printf("ERROR : Problem with memory");
            return -3;
        }
        leng = len;
        minus(ArrA, ArrB, ArrC, len);
    }
    if (flag == 3) { // if flag = 3 - multpl
        int length = a + b + 1;
        ArrC = (int *) calloc((size_t) length, sizeof(int));
        if (ArrC == NULL) {
            printf("ERROR : Problem with memory");
            return -3;
        }
        leng = length;
        multiplication(ArrA, ArrB,ArrC, a, b);
    }
    if (flag == 4) {
        printf("DELYENIE BLYAT");
    }
    int zeros = countlessZeros(base);
    char *ArrD;
    ArrD = (char *)calloc((size_t) (base - zeros), sizeof(char)); // формируем ответ
    if(ArrD == NULL){
        printf("ERROR : Problem with memory");
        return -3;
    }
    toString(ArrD, leng);
    writeAnsw(ArrD,nameOut);
    return 0;
}
void clean(){
    free(ArrC);
    free(ArrB);
    free(ArrA);
    free(chA);
    free(chB);
    free(nameInp);
    free(nameOut);
}

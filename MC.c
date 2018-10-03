#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct P_Q {
    int Price;
    int Quantity;
    int Revenue;
    float  MR;
};

struct Data{
    char* data_file;
    int size;
    int line;} data;

struct Data readfile (FILE* file)
{
    data.data_file = malloc(sizeof(char) * 6);
    data.size = 0;
    while(1){
        int next = fgetc(file);
        if (next == EOF){
            return data;}
        else {
            data.data_file[data.size++] = (char)next;
            if((char)next == '\n'){
                data.line++;
            }
        }
    }
}
void marginalR (struct P_Q first, 
                struct P_Q second){
    first.MR = (first.Revenue - second.Revenue)/(first.Quantity - second.Quantity);
    printf("Marginal Revenue: %g Quantity: %d Price: %d \n", first.MR, first.Quantity, first.Price);
    //return first.MR;
}
int main (int argc, char** argv){
    char *filename = malloc(sizeof(char));
    for (int i = 0; i <strlen(argv[1]); ++i){
        filename[i] = argv[1][i];
    }
    FILE* testfile = fopen(filename, "r");
    if (testfile == NULL){
        printf("wtf \n");
    }
    readfile(testfile);
    struct P_Q pq[data.line];
    for (int i = 0; i < data.line; i++){
        char num[3];
        for (int j = 0; j < 3; j++){
            num[j] = data.data_file[j+i*8];}
        pq[i].Price = atoi(num);
        for (int j = 0; j < 3; j++){
            num[j] = data.data_file[j+4+i*8];}
        pq[i].Quantity = atoi(num);
        pq[i].Revenue = pq[i].Price*pq[i].Quantity;
        printf("%d \n", pq[i].Revenue);
    }
    for (int i = 1; i < data.line; i++){
        marginalR(pq[i], pq[i-1]);
        //printf(" %d %g \n", pq[i].Quantity, pq[i].MR);
    }
    //printf("%g \n", pq[1].MR);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "simplemath.h"

long hash(char* value,int size) {
    long converted = strtol(value,NULL,10);
    int result=0;
    int digits=count_digits(converted);
    if (value[0]=='0'){digits++;}
    int sum = long_sum(converted);
    result = sum *first_digit(converted) * int_pow(converted,converted%2 + converted%3);
    result = (result + converted%7 + first_digit(converted))%size;
    if (result<1){result = result *-1;}
    return result;
}

long hash2(char* value, int size) {
    long converted = strtol(value,NULL,10);
    long result = 1 + (converted % (size - 1));
    if (result < 0) { result = result * -1; }
    if (result == 0) { result = 1; }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc<2) {
        printf("missing file arg.\n");
        return 1;
    }
    printf(".\n");
    FILE *file;
    FILE *out;
    out = fopen("out.txt","w");
    file = fopen(argv[1],"r");
    fprintf(out,"");
    fclose(out);
    out = fopen("out.txt","a");
    char *ptr="\n";
    char buf[12];
    long num;
    int n=0;
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    while(fscanf(file, "%s", buf)==1) {
        n++;
    }
    printf("size is %i\n",n);
    fclose(file);
    
    int size_com_folga = (int)(n * 1.2);
    if (size_com_folga <= 1) { size_com_folga = 2; }
    
    long *hash_table = (long *)malloc(size_com_folga * sizeof(long));
    for (int i = 0; i < size_com_folga; i++) {
        hash_table[i] = -1;
    }
    
    file = fopen(argv[1],"r");
    while(fscanf(file, "%s", buf)==1) {
        long val = strtol(buf, NULL, 10);
        long h1 = hash(buf, size_com_folga);
        long h2 = hash2(buf, size_com_folga);
        long index = h1;
        int i = 0;
        
        while (hash_table[index] != -1 && i < size_com_folga) {
            i++;
            index = (index + h2) % size_com_folga;
        }
        
        if (i < size_com_folga) {
            hash_table[index] = val;
            fprintf(out,"%li\n",index);
        }
    }
    
    free(hash_table);
    fclose(file);
    printf("done\n");
    return 0;
}

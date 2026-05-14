#include <stdio.h>
#include <stdlib.h>
#include "simplemath.h"





long hash(char* value) {

long converted = strtol(value,NULL,10);
int result=0;
int digits=count_digits(converted);
if (value[0]=='0'){digits++;}
int sum = long_sum(converted);
result = sum *first_digit(converted) * int_pow(converted,converted%2 + converted%3);
if (result<1){result = result *-1;}
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
if (file == NULL) {
printf("Unable to open file.\n");
return 1;
}
while(fscanf(file, "%s", buf)==1) {
 //printf("%s : %li\n",buf,hash(buf));
 fprintf(out,"%li\n",hash(buf)); 
}
//long test = 2;
//printf("%i\n",int_pow(test,5));


printf("done\n");






}

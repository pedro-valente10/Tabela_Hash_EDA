#include <stdio.h>
#include <stdlib.h>






long hash(long value) {
long result;
int digits=0;
long n=value;
while (!(n==0)){
n = n/10;
digits++;
}
printf("digits is %i\n",digits);

return result;


}

int main(int argc, char *argv[]) {

if (argc<2) {
printf("missing file arg.\n");
return 1;
}
printf(".\n");
FILE *file;
file = fopen(argv[1],"r");
char *ptr="\n";
char buf[12];
long num;
if (file == NULL) {
printf("Unable to open file.\n");
return 1;
}
while(fscanf(file, "%s", buf)==1) {
 num = strtol(buf,NULL,10);
 printf("%s : %li\n",buf,hash(num));
}
printf("done\n");






}

#include "simplemath.h"
#include <stdlib.h>

int long2int(long number) {

 long temp = number;
 int result=0;
 while (temp>0) {
 temp = temp/10;
 result++;
}
temp = number;
char* numberstring = malloc(sizeof(char)*result);
 for(int i=0;i<result;i++) {
  numberstring[i] = temp%10;
  temp = temp/10;
 }


return 1;

}


long int_pow(long base,int exponent){
 long result =base; 
 int i =1;
 while(i<exponent) {
   result = result * base;
   i++;

 }
return result;
}
int count_digits(long number) {
int result=0;
long temp = number;
while (temp>0) {
temp = temp/10;
result++;
}
return result;
}


int int_sum(int number) {
 int temp = number;
 int sum = 0;
 for(int i=count_digits(number);i>0;i--) {
  sum = sum + temp%10;
  temp = temp/10;
 }
return sum;
}


int long_sum(long number) {
 long temp = number;
 int sum = 0;
 for(int i=count_digits(number);i>0;i--) {
  sum = sum + temp%10;
  temp = temp/10;
 }
return sum;
}

int first_digit(long number)
{
long temp = number;
int count =count_digits(number);
while(count>1)
{
temp = temp/10;
count--;
}
return (int)temp;


}

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

int threads= 2;

void *prime(void *n){
int *p=(int *)n;
int no=*p;
clock_t start =clock();
int count =0;

for(int i =2; i< no;i++){
    int p =1;
    for(int j=2;j*j<=i;j++){
      if(i%j==0){
        p=0;
        break;
}
             }
if(p){
count++;
if(count<=100)
  printf("%d ",i);
else if(count > 348413)
  printf("%d ",i);
}
        }

clock_t end =clock();
printf("\n\nThere are %d primes under %d.\n",count,no);
printf("Program took %d times.\n",(end-start));

pthread_exit(NULL);
}

int main(){
pthread_t thread;

int number;
printf("Enter Number : ");
scanf("%d",&number);
pthread_create(&thread,NULL,prime,&number);
pthread_join(thread,NULL);

pthread_exit(NULL);
}





















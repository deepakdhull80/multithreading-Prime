#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

int threads= 2;

void *prime(){
clock_t start =clock();
int count =0;

for(int i =2; i< 5000000;i++){
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
printf("\n\nThere are %d primes under 5000000.",count);
printf("Program took %d times.",(end-start));

pthread_exit(NULL);
}

int main(){
pthread_t thread[threads];
int rc;
int i;
for(i=0;i<threads;i++){
rc=pthread_create(&thread[i],NULL,prime,NULL);
pthread_join(thread[i],NULL);
if(rc){
printf("ERROR - In creation of thread");
exit(0);
}
}

pthread_exit(NULL);
}






















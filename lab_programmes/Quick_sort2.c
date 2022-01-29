#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
void quicksort(int a[],int s,int e,int c1,char ch);

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int s,int e){
    int pivot=a[e];
    int i=s-1;
    int j=s;
    for(j=s;j<e;j++){
       
       if(a[j]<=pivot){
           i++;
           swap(&a[i],&a[j]);
       }

    }
    swap(&a[i+1],&a[e]);
    return i+1;
}
int middleOfThree(int a, int b, int c){
    // Checking for b
    if ((a < b && b < c) || (c < b && b < a))
       return b;
 
    // Checking for a
    else if ((b < a && a < c) || (c < a && a < b))
       return a;
 
    else
       return c;
}
int random_partition(int a[],int s,int e,int choice,char ch){

    if(choice==1)
    swap(&a[0],&a[e]);

    else if(choice==2){
        srand(time(0));
        int r=rand()%(e-s)+s+1;
         swap(&a[r],&a[s]);        
    }
    else{ 
        int n=e-s+1;// subArray Length
        if(ch=='a'){
         int p= middleOfThree(0,n/2,n-1)+s;
         swap(&a[p],&a[s]);        
        }
        else{
         int p=middleOfThree(n/4,n/2,(3*n)/4);
         swap(&a[p],&a[s]);
        } 
    }

    return partition(a,s,e);
}
void quicksort(int a[],int s,int e,int c1,char ch){
    if(s<e){
        int p=random_partition(a,s,e,c1,ch);
        quicksort(a,s,p-1,c1,ch);
        quicksort(a,p+1,e,c1,ch);
    }
}
void populate2(int arr[],int n){
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000+1;
    }
}
void print(int a[],int n){

    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
    printf("\n\n");
}
int main(){

// populate Arrays with random Integers
   int A1[10],A2[100],A3[1000];
    populate2(A1,10);
    populate2(A2,100);
    populate2(A3,1000);

     clock_t c1;
     float time[12];
      int x=1;
    
         c1=clock();
         printf("Length 10\nArray 1.\n");
         print(A1,10);
         quicksort(A1,0,9,1,'c');
         c1=clock()-c1;
         time[0]=(double)c1/CLOCKS_PER_SEC;
         print(A1,10);

         printf("Length 10\nArray 2.\n");
         print(A1,10);
         c1=clock();
         quicksort(A1,0,9,2,'c');
         c1=clock()-c1;
         print(A1,10);
         time[1]=(double)c1/CLOCKS_PER_SEC;

         printf("Length 10\nArray 3.(a)\n");
         print(A1,10);
         c1=clock();
         quicksort(A1,0,9,3,'a');
         c1=clock()-c1;
         time[2]=(double)c1/CLOCKS_PER_SEC;          

         printf("Length 10\nArray 3.(b)\n");
         print(A1,10);
         c1=clock();
         quicksort(A1,0,9,3,'b');
         c1=clock()-c1;
         print(A1,10);
         time[3]=(double)c1/CLOCKS_PER_SEC;
     
         printf("Length 100\nArray 1.\n");
         print(A2,100);
         c1=clock();
         quicksort(A2,0,99,1,'c');
         c1=clock()-c1;
         time[4]=(double)c1/CLOCKS_PER_SEC;

         printf("Length 100\nArray 2.\n");
         print(A2,100);
         c1=clock();
         quicksort(A2,0,99,2,'c');
         c1=clock()-c1;
         print(A2,100);
         time[5]=(double)c1/CLOCKS_PER_SEC;

         printf("Length 100\nArray 3.(a)\n");
         print(A2,100);
         c1=clock();
         quicksort(A2,0,99,3,'a');
         c1=clock()-c1;
         print(A2,100);
         time[6]=(double)c1/CLOCKS_PER_SEC;          

         printf("Length 100\nArray 3.(b)\n");
         print(A2,100);
         c1=clock();
         quicksort(A2,0,99,3,'b');
         c1=clock()-c1;
         print(A2,100);
         time[7]=(double)c1/CLOCKS_PER_SEC;

         printf("Length 1000\nArray 1.\n");
         print(A3,1000);
         c1=clock();
         quicksort(A3,0,999,1,'c');
         c1=clock()-c1;
         print(A3,1000);
         time[8]=(double)c1/CLOCKS_PER_SEC;

         printf("Length 1000\nArray 2.\n");
         print(A3,1000);
         c1=clock();
         quicksort(A3,0,999,2,'c');
         c1=clock()-c1;
         print(A3,1000);
         time[9]=(double)c1/CLOCKS_PER_SEC;

         printf("Length 1000\nArray 3.(a)\n");
         print(A3,1000);
         c1=clock();
         quicksort(A3,0,999,3,'a');
         c1=clock()-c1;
         print(A3,1000);
         time[10]=(double)c1/CLOCKS_PER_SEC;          

         printf("Length 1000\nArray 3.(b)\n");
         print(A3,1000);
         c1=clock();
         quicksort(A3,0,999,3,'b');
         c1=clock()-c1;
         print(A3,1000);
         time[11]=(double)c1/CLOCKS_PER_SEC;
     
     printf("n         Pivot Type           Time\n");
     printf("10        First                %f\n",time[0]);
     printf("10        Random               %f\n",time[1]);
     printf("10   Median Of three(a)        %f\n",time[2]);
     printf("10   Median Of three(b)        %f\n",time[3]);
     
     printf("100        First                %f\n",time[4]);
     printf("100        Random               %f\n",time[5]);
     printf("100   Median Of three(a)        %f\n",time[6]);
     printf("100   Median Of three(b)        %f\n",time[7]);
     
     printf("1000        First                %f\n",time[8]);
     printf("1000        Random               %f\n",time[9]);
     printf("1000   Median Of three(a)        %f\n",time[10]);
     printf("1000  Median Of three(b)         %f\n",time[11]);
     
}
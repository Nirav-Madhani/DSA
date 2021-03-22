/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
struct Queue
{
int F;
int R;
int *p;
int length;
int size;
};

void Create(struct Queue *q,int L)
{
    q->p = (int *)malloc((L+1)*sizeof(int));
    q->F=0;
    q->R=0;
    q->length = L;
    q->size =L+1;
    *(q->p)= 588714;
}
int isEmpty(struct Queue *q){
    if(q->F==q->R)
        return 1;
    return 0;
}
int isFull(struct Queue *q){
    if((q->R+1)%q->size == q->F){
        return 1;
    }
    return 0;
}

void EnQF(struct Queue *q, int I)
{
if(isFull(q)){
    printf("Queue Full!");
    return;
}
q->R=(q->R+1) % (q->size);
*(q->p+q->R)=I;

}


void EnQR(struct Queue *q, int I)
{
if(isFull(q)){
    printf("Queue Full!");
    return;
}
q->F=(q->F-1) % (q->size);
if(q->F <0)
    q->F+=q->size;
  //  printf("%d",q->F);
*(q->p+q->F)=I;

}
int DeQF(struct Queue *q){
    if(isEmpty(q))
           {
           printf("Empty Q!");
           return -1001;
               
           }
           
    int i = *(q->p+q->F);
    *(q->p+q->F) = 588714;
     printf("F = %d *F = %d\n\n",q->F, *(q->p+q->F));
    q->F=(q->F+1)%(q->size);
   
    return i;
    
}
int DeQR(struct Queue *q){
    if(isEmpty(q))
        return -1001;
  int i=  *(q->p+q->R);
  *(q->p+q->R) = 588714;
    q->R=(q->R-1)%q->size;
    if(q->R<0)
        q->R+=q->size;
    return i;
}
void Print(struct Queue q){
  //  printf("%d", (q.R+1) % q.length);
  int i;
    for( i= (q.F+1)%q.size;i!=(q.R)%q.size ;i=(i+1) % q.size){
      if(*(q.p+i)==588714)
      continue;
        printf("%d i = %d \n",*(q.p+i),i);
    }
     printf("%d i = %d \n",*(q.p+i),i);
}
int main ()
{
 struct Queue DEQ;
 Create(&DEQ,5);
 EnQF(&DEQ,1);
 EnQF(&DEQ,2);
 EnQF(&DEQ,3);
 DeQF(&DEQ);
 EnQR(&DEQ,-1);
 EnQR(&DEQ,-2);

 
 Print(DEQ);
  return 0;
}





#include <stdio.h>
#include <stdlib.h>
struct Queue
{
int F;
int R;
int *p;
int length;
};
void Create(struct Queue *q,int L){
    q->p = (int *)malloc((L+1)*sizeof(int));
    q->F=0;
    q->R=0;
    q->length = L+1;
}

void EnQ(struct Queue *q,int L){
    if((q->R+1)%q->length == q->F){
        //Queue is full
        printf("\nQueue is full!");
        return;
    }
    q->R=(q->R+1)%q->length;
    *(q->p+q->R)=L;
    
}

int  DeQ(struct Queue *q){
    int L;
    if((q->F) == q->R){
        //Queue is full
        printf("\nQueue is  Empty! \n");
        return -5010;
    }
    q->F=(q->F+1)%q->length;
    L  = *(q->p+q->R);
    return L;
}
void Display(struct Queue q){                                                       
    int i=0;
    for(i = (q.F+1)%q.length;i!=q.R;i = (i+1)%q.length)
    {
        printf("%d\n",*(q.p+i));
    }
    printf("%d\n",*(q.p+i));
}

/*******************
 * 
 * Priority Start
 * 
 * ****************/
 struct PQ{
     struct Queue *q;
     int Prio;
 };
 
void CreatePQ(struct PQ *Q,int Len,int priority){
    Q->q = (struct Queue*) malloc(priority*(2*sizeof(int)+sizeof(int)*(Len+1) ));
    Q->Prio=priority;
}
void PEnQ(struct PQ *Q,int e,int p){
        EnQ(&(Q->q[p-1]),e);//EnQ x  (PQ->(q+p-1),e); x ||(p-1)*sizeof(Queue)||
}
void DisplayPQ(struct PQ *Q){
    int i=0;
    for(i=0;i<Q->Prio;i++)
        Display(Q->q[i]);
}
int
main ()
{
  printf ("Hello World\n");
struct Queue q;
Create(&q,5);
EnQ(&q,1);
EnQ(&q,2);
DeQ(&q);
EnQ(&q,3);
EnQ(&q,4);
EnQ(&q,5);
DeQ(&q);
EnQ(&q,1);
Display(q);
  return 0;
}
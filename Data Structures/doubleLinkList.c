
#include <stdio.h>
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct {
Node *first, *Last;
int Length;
}LinkList;

void Create(LinkList *L,int k){
    L->first = NULL; //(Node *)malloc(sizeof(Node *));
    Node *N= (Node *)malloc(sizeof(Node));
    N->value=k;
    N->prev=NULL;
    N->next=NULL;
    L->first = N;
    L->Last=N;
    L->Length=1;
    
}
   
void Add(LinkList *L,int k)
{
    Node *N = (Node *)malloc(sizeof(Node));
    N->value=k;
    N->next=NULL;
    (L->Last->next) = N;
    N->prev=L->Last;
    L->Last=N;
    L->Length++;
}
void Display(LinkList L){
    Node *q=L.first;                         ///PENDING Done
    while(q!=NULL){
        printf("%d\n",q->value);
        q=q->next;
    }
}
void Modify(LinkList *L,int index,int value){
     Node *q=L->first;
     int i=0;
    while(q!=NULL){
        if(i==index){                           ///PENDING  Done
            q->value = value;
            break;
        }
         i++;
        q=q->next;
    }
}

void InsertAtFront(LinkList *L,int index,int value){
    Node *q=L->first;
    Node *p ;
    p = (Node *)malloc(sizeof(Node));                    /////PENDING Done
    p->value=value;
    p->next=L->first;
    L->first=p;
    p->next->prev=p;
}                
void Reverse(LinkList *L){
     Node *p,*q,*r;
     p=L->first;
     q=p->next;
     p->next=NULL;             /////PENDING
     r=q->next;
     L->Last = p;
     q->next=p;
     q->prev=r;
     while(r!=NULL){
        p=q;
        q=r; // r is next p <--q
        r=q->next;
        q->next=p;
        q->prev=r;
         
     }
    L->first=q;
}
void Insert(LinkList *L,int index,int value)///Insert After
{
    Node *q=L->first;
    Node *p ;
    p = (Node *)malloc(sizeof(Node));
    p->value=value;
    int i;
    for(i=1;i<index;i++){
        q=q->next;
    }
    p->next=q->next;
    p->prev=q;
    q->next=p;
    
}
int DeleteAt(LinkList *L,int index){
  if(index==0){
      int a = L->first->value;
     L->first=L->first->next;
     L->first->prev=NULL;
        return a;
      
  }
    Node *q=L->first;
    int i;
    for(i=1;i<index;i++)
        q=q->next;
        
    int a = q->next->value;
    q->next=q->next->next;
    q->next->prev=q;
    return a;
}

int main()
{
    int k;
    LinkList L;
    do{
        scanf("%d",&k);
        if(k==0)
            {
                int v ;
                scanf("%d",&v);
               Create(&L,v);
            }
        else if(k==1){
                int v ;
                scanf("%d",&v);
               Add(&L,v);
        }    
        else if(k==2){
                int s;//position
                int v ;//value
                scanf("%d %d",&v,&s);
               Insert(&L,s,v);
        }    
        
        else if(k==3)//Modify
        {
                int s;//position
                int v ;//value
                scanf("%d %d",&v,&s);
               Modify(&L,s,v);
        }
        else if(k==4){
               
                int v ;//pos
                scanf("%d",&v);
               DeleteAt(&L,v);
        }    
        else
            {
                k=5;
                        }
    }while( k !=5);
    
 /*   Create(&L,0);
    Add(&L,1);
    Add(&L,2);
    Add(&L,3);
    Modify(&L,0,1);
    Modify(&L,1,2);
        Modify(&L,2,3);
    Modify(&L,3,4);
    DeleteAt(&L,0);
    Display(L);
    Reverse(&L);
    */
    printf("\n\n\n");
    Display(L);
    Reverse(&L);
    Display(L);
    printf("\n%d",L.Length);
    printf("Hello World");

    return 0;
}





#include <stdio.h>
#include <malloc.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode;

ListNode* create_list(int ar[],int n)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->data = ar[0];
    head->next = NULL;


ListNode *p = head;
for(int i = 1; i < n; ++i){
    ListNode *s =(ListNode*)malloc(sizeof(ListNode));
    s->data = ar[i];
    s->next = NULL;

    p->next = s;
    p = s;
}
return head;
}

void show_list(ListNode *head){
    ListNode *p = head;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

void Swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int n;
    scanf("%d",&n);
    int ar[n];
    for(int i = 0; i < n;i++){
        scanf("%d",&ar[i]);
    }

    ListNode *head = create_list(ar,n);

    ListNode *pre = head,*p = head->next;
    Swap(&pre->data,&p->data);

    while(p->next != NULL){
        pre = p;
        p = p->next;
    }

    Swap(&pre->data,&p->data);

    show_list(head);



    return 0;
}

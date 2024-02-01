#include <malloc.h>
#include <stdio.h>

typedef struct ListNode{
    int data ;
    struct ListNode *next;
}ListNode;

ListNode *create_list(int ar[],int n){
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = ar[0];
    head ->next = NULL;

    ListNode *p = head;
    for (int i = 1; i < n; ++i){
        ListNode *s =(ListNode *)malloc(sizeof(ListNode));
        s->data = ar[i];
        s->next = NULL;

        p->next = s;
        p = s;
    }
    return head;
}

void show_list(ListNode *head){
    ListNode *p = head;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void merge_list(ListNode *ha,ListNode *hb){
    ListNode *pa=ha, *pb=hb;
    while(pa){
        pb->data += pa->data;
    pa = pa->next;
    pb = pb->next;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    for(int i = 0;i < n;i++)
        scanf("%d",&b[i]);

    ListNode *ha = create_list(a,n);
    ListNode *hb = create_list(b,n);

merge_list(ha,hb);
show_list(hb);
    return 0;
}
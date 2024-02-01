#include <malloc.h>
#include <stdio.h>


typedef struct ListNode {
  int data;
  struct ListNode *next;
} ListNode;

ListNode *create_list(int ar[], int n) {
  ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  head->data = ar[0];
  head->next = NULL;

  ListNode *p = head;
  for (int i = 1; i < n; i++) {
    ListNode *s = (ListNode *)malloc(sizeof(ListNode));
    s->data = ar[i];
    s->next = NULL;

    p->next = s;
    p = s;
  }
  return head;
}

void insert_list(ListNode *head, int x, int a) {
  ListNode *s = (ListNode *)malloc(sizeof(ListNode));
  s->data = a;

  ListNode *pre = head;
  while (--x) {
    pre = pre->next;

    s->next = pre->next;
    pre->next = s;
  }
}
void show_list(ListNode *head) {
  ListNode *p = head;
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
}

int main() {
  int n, x, a;
  scanf("%d%d%d", &n, &x, &a);
  int ar[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }
  ListNode *head = create_list(ar, n);
  insert_list(head, x, a);
  show_list(head);
  return 0;
}
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
  for (int i = 1; i < n; ++i) {
    ListNode *s = (ListNode *)malloc(sizeof(ListNode));
    s->data = ar[i];
    s->next = NULL;

    p->next = s;
    p = s;
  }
  return head;
}

int sum_list(ListNode *head) {
  int sum = 0;
  while (head != NULL) {
    sum += head->data;
    head = head->next;
  }
  return sum;
}
int main() {
  int n;
  scanf("%d", &n);
  int ar[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }

  ListNode *head = create_list(ar, n);

  printf("%d", sum_list(head));
  return 0;
}
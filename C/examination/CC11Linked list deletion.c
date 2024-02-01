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
void show_list(ListNode *head) {
  ListNode *p = head;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}
void delete_list(ListNode *head, int x) {
  ListNode *t = (ListNode *)malloc(sizeof(ListNode));
  t->next = head;

  ListNode *pre = t, *p = head;
  while (p != NULL) {
    if (p->data == x) {
      pre->next = p->next;
      free(p);
      p = pre->next;
    } else {
      pre = p;
      p = p->next;
    }
  }
  head = t->next;
  free(t);
}
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int ar[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i]);
  }
  ListNode *head = create_list(ar, n);
  delete_list(head, x);
  show_list(head);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node* next;  
}node;

typedef struct{
  node* head;
  size_t len;
}linkedlist;

void printlist(linkedlist ll);
void freelist(linkedlist* ll);

int insert(linkedlist* ll, unsigned int idx, int val);
int pushfront(linkedlist* ll, int val);
int pushback(linkedlist* ll, int val);

int delete(linkedlist*ll, unsigned int idx, int* deletedElem);
int popfront(linkedlist* ll, int* poppedElem);
int popback(linkedlist* ll, int* poppedElem);

int reverse(linkedlist* ll);

int main(void){

  linkedlist ll = {NULL, 0};
  pushback(&ll, 1);
  pushback(&ll, 2);
  pushfront(&ll, 3);
  insert(&ll, 0, 4);
  insert(&ll, 4, 5);
  insert(&ll, 3, 6);
  printlist(ll);
  printf("----BREAK----\n");
  reverse(&ll);
  printlist(ll);
  freelist(&ll);
  return 0;
}

void freelist(linkedlist* ll){
  node* curr = ll->head;
  while (curr != NULL){
    node* temp = curr->next;
    free(curr);
    curr = temp;
  }  
  ll->head = NULL;
  ll->len = 0;
}

void printlist(linkedlist ll){
  node* curr = ll.head;
  while (curr != NULL){
    printf("%d\n", curr->val);
    curr = curr->next;
  }
}

int insert(linkedlist* ll, unsigned int idx, int val){
  if (idx > ll->len || idx < 0)
    return -1;

  node* newNode = malloc(sizeof(node));
  if (newNode == NULL)
    return -1;
  newNode->val = val;
  newNode->next = NULL;

  if (idx == 0){
    if (ll->head == NULL){
      ll->head = newNode;
    }else{
      newNode->next = ll->head;
      ll->head = newNode;
    }
    ll->len++;
    return 0;
  }

  node* prev = ll->head;
  node* temp = (ll->head)->next;
  for (int i = 1; i<idx; i++){
    prev = temp;
    temp = temp->next;
  }
  newNode->next = temp;
  prev->next = newNode;
  ll->len++;
  return 0;
}

int pushfront(linkedlist* ll, int val){
  int res = insert(ll, ll->len, val);
  if (res != 0)
    return -1;
  return 0;
}

int pushback(linkedlist* ll, int val){
  int res = insert(ll, 0, val);
  if (res != 0)
    return -1;
  return 0;
}

int delete(linkedlist*ll, unsigned int idx, int* deletedElem){
  if (idx < 0 || idx >= ll->len)
    return -1;  

  if (idx == 0){
    node* temp = (ll->head)->next;
    *deletedElem = (ll->head)->val;
    free(ll->head);
    ll->head = temp;
    ll->len--;
    return 0;
  }

  node* prev = ll->head;
  node* temp = (ll->head)->next;
  for (int i = 1; i<idx; i++){
    prev = temp;
    temp = temp->next;
  }

  prev->next = temp->next;
  *deletedElem = temp->val;
  free(temp);
  ll->len--;
  return 0;
}

int popfront(linkedlist* ll, int* poppedElem){
  int res = delete(ll, ll->len-1, poppedElem);
  if (res != 0)
    return -1;
  return 0;
}

int popback(linkedlist* ll, int* poppedElem){
  int res = delete(ll, 0, poppedElem);
  if (res != 0)
    return -1;
  return 0;
}

int reverse(linkedlist* ll){
  node* prev = NULL;
  node* curr = ll->head;

  while (curr != NULL){
    node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  ll->head = prev;

  return 0;
}

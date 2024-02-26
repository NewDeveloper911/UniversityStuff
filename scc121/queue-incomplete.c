#include<stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *next;
};

#define MAX_SIZE 50;
struct element *head = NULL;

void enqueue(int data);
int dequeue();
void printQueue();

//free(el);
int dequeue() {
    if(head == NULL) {printf("Nobody is in the queue.\n");}
    else{
        int data = head->data;
        struct element *newhead = head->next;
        free(head);
        head = newhead;
        return data;
    }
}

//struct element *el = (struct element*)malloc(sizeof(struct element));
void enqueue(int data) {
    struct element *el = (struct element*)malloc(sizeof(struct element));
    struct element *tmp = head;
    el->data = data;
    el->next = NULL;
    if(head == NULL) {head = el;}
    else{
        tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = el;
    }
}

void printQueue(){
  struct element *tmp = head;
  printf("The resulting queue is...");
  while(NULL!=tmp) {
    printf("%d...",tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  while(1){
    printf("\n Enter operation: 1 for enqueue, 2 for dequeue...");
    int op;
    scanf("%d", &op);
    switch(op){
    case 1:
      printf("\n Enter data...");
      int data;
      scanf("%d", &data);
      enqueue(data);
      printQueue();
      break;
    case 2:
      data = dequeue();
      if(-1 != data) printf("Dequeued %d\n", data);
      else{
        printf("Queue empty\n");
      }
      printQueue();
      break;
    default:
      return 0;
    }
  }
}
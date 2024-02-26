#include <stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *prev;
};

struct element *top = NULL;

int pop() {
    if(top == NULL){
      printf("Underflow");
      return -1;
    }
    else{
        struct element *temp = (struct element*)malloc(sizeof(struct element));
        temp = top;
        top = top->prev;
        return temp->data;
    }
}

void push(int data) {
  struct element *el = (struct element*)malloc(sizeof(struct element));
  el->data = data;
  /*Continue your code here*/
  el->prev = NULL;
  if(top == NULL) top = el;
  else{
    el->prev = top;
    top = el;
  }
}


int main() {
  while(1){
    printf("\n Enter operation: 1 for push, 2 for pop...");
    int op;
    scanf("%d", &op);
    switch(op){
    case 1:
      printf("\n Enter data...");
      int data;
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      printf("\n Popped %d", pop());
      break;
    default:
      return 0;
    }
  }
}

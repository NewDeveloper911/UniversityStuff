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

//Dumbest way of achieving this as possible
int matched(char *str) {
    int c;
    
    FILE *fp = fopen("stupid_text.txt","w");
    fputs(str,fp);
    fclose(fp);
    
    fp = fopen("stupid_text.txt","r");
    
    while((c=getc(fp)) != EOF){
        if(c == '{') push(1);
        else{
            if(pop() == -1) return 0;
        }
    }
    fclose(fp);
    
    if(pop() == -1) return 1;
    else{return 0;}
    
}
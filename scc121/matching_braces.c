#include <stdio.h>
#include <stdlib.h>

struct element {
  char data;
  struct element *prev;
};

struct element *top = NULL;

int pop() {
    if(top == NULL){
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

#include <string.h>

int match(char braces[]){
  for(int i=0;i<strlen(braces);i++){
    if(braces[i] == '{') push(1);
    else if(braces[i] == '}'){
      //return 0 means the braces don't match
      //Underflow means that there are more } than {
      if(pop() == -1) return 0;
    } 
  }

  //The braces were matching - nothing else can be popped
  if(pop() == -1) return 1;
  else return 0;
}

int main() {
  char braces[10] = "{{}{}}";
  printf("%d\n", match(braces)); 
  
}

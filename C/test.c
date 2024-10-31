#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *prev, *next;
} node;

void foobar(node *start) {
    node *current = start, *tmp;
    int iseven = 0;
    while (current != NULL) {
      if (iseven == 1) {
        current->prev->next = current->next;
        if (current->next != NULL)
          current->next->prev = current->prev;
      }
      current = current->next;
      iseven = 1 - iseven;
    
      tmp = start;
      while (tmp && iseven == 1) {
        printf("%d ", tmp->key);
        tmp = tmp->next;
      }
    printf("\n");
  }
}

int main() {
    node *tmp, *prevp = NULL, *head;
    for (int i = 0; i < 10; i++) {
        tmp = (node*) malloc(sizeof(node*));
        tmp->key = i;
        tmp->prev = prevp;
        
        if (prevp == NULL) head = tmp;
        else prevp->next = tmp;
        prevp = tmp;
    }
    foobar(head);
    return 0;
}


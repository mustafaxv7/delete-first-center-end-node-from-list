#include <stdio.h>
#include <stdlib.h>
struct cellule{
  int data;
  struct cellule *link;
};


struct cellule* delete_first_node(struct cellule *head);

int main()
{
   struct cellule *head, *ptr;
   head = malloc(sizeof(struct cellule));
   head->data = 8;
   head->link = NULL;
  
   struct cellule *cel = malloc(sizeof(struct cellule));
   cel->data = 16;
   cel->link = NULL;
   head->link = cel;
   
   cel = malloc(sizeof(struct cellule));
   cel->data = 59;
   cel->link = NULL;
   head->link->link = cel;
   head = delete_first_node(head);
   ptr = head;
   printf("{ ");
   while(ptr != NULL){
     printf(" %d, ",ptr->data);
     ptr = ptr->link;
   }
   printf("}");
}
struct cellule* delete_first_node(struct cellule *head){
  struct cellule *temp;
  temp = head;
  head = head->link;
  free(temp);
  temp = NULL;
  return head;
}
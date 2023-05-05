#include <stdio.h>
#include <stdlib.h>
struct cellule{
  int data;
  struct cellule *link;
};


struct cellule* delete_the_last_node(struct cellule *head);

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
   head = delete_the_last_node(head);
   ptr = head;
   printf("{ ");
   while(ptr != NULL){
     printf(" %d, ",ptr->data);
     ptr = ptr->link;
   }
   printf("}");
}
struct cellule* delete_the_last_node(struct cellule *head){
  struct cellule *ptr1 , *ptr2;
  ptr1 = head; ptr2 = head;
  if(head == NULL){
    printf("the list is already empty");
    return head;
  }
  else if(head->link == NULL){
    free(head);
    head = NULL;
    return head;
  }
  else{
  while(ptr1->link != NULL){
    ptr2 = ptr1;
    ptr1 = ptr1->link;
  }
  ptr2->link = NULL;
  free(ptr1);
  ptr1 = NULL;
  return head;
 }
}
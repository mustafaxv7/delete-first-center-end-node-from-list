#include <stdio.h>
#include <stdlib.h>
struct cellule{
  int data;
  struct cellule *link;
};


struct cellule* delete_node_with_position(struct cellule *head, int posb);

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
   head = delete_node_with_position(head,16);
  
   ptr = head;
   printf("{ ");
   while(ptr != NULL){
     printf(" %d, ",ptr->data);
     ptr = ptr->link;
   }
   printf("}");
}
struct cellule* delete_node_with_position(struct cellule *head,int posb){
  struct cellule *ptr1 , *ptr2;
  ptr1= head;
  ptr2= head;
  
  if(head == NULL){
     printf("the list is already empty");
  }
  
  else if(head->link == NULL && head->data == posb){
     head = NULL;
  }
  
  else if(head->link == NULL && head->data != posb){
     printf("this value\' %d \'dosn't inside the list\n",posb);
  }
  
  else{
  while(ptr1->data != posb && ptr1 != NULL){
     ptr2 = ptr1;
     ptr1 = ptr1->link;
   }
   
   if(ptr1 == NULL){
     printf("this %d value doesn't inside this list \n",posb);
   }
   
   else{ 
     ptr2->link = ptr1->link;
     free(ptr1);
     ptr1 = NULL;
    
    }
  }
  return head;
}
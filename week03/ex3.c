#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct linked_list linked_list;

struct node {
   int value;
   struct node* next;
};

struct linked_list {
   node* head;
   int size;
};

void print_list(linked_list* list) {
   node* temp = list->head;

   while (temp != NULL) {
      printf("%d ", temp->value);
      temp = temp->next;
   }

   printf("\n");
}

// takes value and node after new node should be inserted
void insert_node(linked_list* list, node* newnode, node* prevnode) {
   if (list->head == NULL) {
      list->head = newnode;
      list->size += 1;
      return;
   }

   newnode->next = prevnode->next;
   prevnode->next = newnode;
   list->size += 1;
}

void delete_node(linked_list* list, node* node_) {
   node* temp = list->head;
   while (temp->next != node_) {
      temp = temp->next;
   }
   temp->next = node_->next;
   free(node_);
}

int main() {

   linked_list ll;
   ll.head = NULL;//(node*)malloc(sizeof(node*));
   ll.size = 0;
   
   print_list(&ll);

   
   for (int i = 0; i < 5; ++i) {
      node* node_ = (node*)malloc(sizeof(node*));
      node_->next = NULL;
      node_->value = i;
      insert_node(&ll, node_, ll.head);
   }
   
   print_list(&ll);

   node* node_ = (node*)malloc(sizeof(node*));
   node_->next = NULL;
   node_->value = 10;
   insert_node(&ll, node_, ll.head);

   print_list(&ll);

   delete_node(&ll, node_);

   print_list(&ll);

   return 0;
}

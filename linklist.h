#include <stdlib.h>
 struct ll_node {
   void *data;
   struct ll_node *next;
 };
 
 struct ll_list {
   struct ll_node *head;
   struct ll_node *tail;
   int has_dummy_head;
   int has_dummy_tail;
   size_t size;
 };
 /*
   Create a new node with the given data and links
   Returns a pointer to the new node, or NULL on error
 */
 struct ll_node *new_node ( void *data, struct ll_node *next )
 {
   struct ll_node *rv = malloc ( sizeof *rv );
 
   if ( rv != NULL ) {
     rv->data = data;
     rv->next = next;
   }
 
   return rv;
 }
 
 /*
  
 
 /*
   Destroy a single given node, assuming it has been unlinked
   Optionally destroy the data contained in the node
   Returns the next node specified by the link
 */
 struct ll_node *destroy_node (
   struct ll_node *node,
   void (destroy_data) ( void * ) )
 {
   struct ll_node *rv = NULL;
 
   if ( node != NULL ) {
     /*
     Save a reference to the next node
     because we're about to destroy this one
     */
     rv = node->next;
 
     if ( destroy_data != NULL )
       destroy_data ( node->data );
 
     free ( node );
   }
 
   return rv;
 }
 
 /*
   Destroy all nodes in a given list
   Optionally destroy all data in each node
 */
 void destroy_list ( struct ll_list *list, void (destroy_data) ( void * ) )
 {
   while ( list->head != NULL )
     list->head = destroy_node ( list->head, destroy_data );
 }
/*
   Create a new list with an optional dummy head and tail
   Returns a pointer to the new list, or NULL on error
 */
 struct ll_list *new_list (
   int has_dummy_head,
   int has_dummy_tail )
 {
   struct ll_list *rv = malloc ( sizeof *rv );
 
   if ( rv != NULL ) {
     struct ll_node *tail =
       has_dummy_tail ? new_node ( NULL, NULL ) : NULL;
 
     if ( has_dummy_tail && tail == NULL ) {
       /* Release the list if a dummy couldn't be allocated */
       free ( rv );
       rv = NULL;
     }
     else {
       rv->head = has_dummy_head ? new_node ( NULL, tail ) : NULL;
       rv->tail = tail;
 
       rv->has_dummy_head = has_dummy_head;
       rv->has_dummy_tail = has_dummy_tail;
 
       rv->size = 0;
 
       if ( has_dummy_head && rv->head == NULL ) {
         /* Release the list if a dummy couldn't be allocated */
         free ( rv );
         rv = NULL;
       }
     }
   }
 
   return rv;
 }
struct ll_node *insert_after(struct ll_list *, struct ll_node *, void *);
struct ll_node *insert_before (
   struct ll_list *list,
   struct ll_node *pos,
   void *data )
 {
   struct ll_node *rv = NULL;
 
   if ( list != NULL && pos != NULL ) {
     if ( pos != list->head ) {
       /* Find the previous node */
       struct ll_node *it = list->head;
 
       while ( it->next != pos )
         it = it->next;
 
       /* Create a new node and set the next link */
       rv = new_node ( data, it->next );
 
       if ( rv != NULL ) {
         it->next = rv;
         ++list->size;
       }
     }
     else
       rv = insert_after ( list, pos, data );
   }
 
   return rv;
 }

 /*
   Insert a new node after the given node
   Returns a pointer to the new node or NULL on failure
 */
 struct ll_node *insert_after (
   struct ll_list *list,
   struct ll_node *pos,
   void *data )
 {
   struct ll_node *rv = NULL;
 
   if ( list != NULL && pos != NULL ) {
     if ( pos != list->tail ) {
       /* Create a new node and set the next link */
       rv = new_node ( data, pos->next );
 
       if ( rv != NULL ) {
         pos->next = rv;
         ++list->size;
       }
     }
     else
       rv = insert_before ( list, pos, data );
   }
 
   return rv;
 }
 
 /*
   Insert a new node before the given node
   Returns a pointer to the new node or NULL on failure
 */
 /*
   Remove the selected node
   Returns the removed node or NULL on failure
 */
 struct ll_node *remove_node (
   struct ll_list *list,
   struct ll_node *pos )
 {
   struct ll_node *rv = NULL;
 
   if ( list != NULL && pos != NULL ) {
     struct ll_node *it = list->head;
     struct ll_node *prev = NULL;
 
     /* Shift the head by one if removing the dummy */
     if ( pos == list->head )
       pos = pos->next;
 
     /* Find the previous node and its previous node */
     while ( it->next != pos ) {
       prev = it;
       it = it->next;
     }
 
     if ( pos != list->tail ) {
       /* Remove the selected node */
       rv = pos;
       it->next = rv->next;
       rv->next = NULL;
       --list->size;
     }
     else if ( it != list->head ) {
       /* Remove the node before the tail */
       rv = it;
       prev->next = rv->next;
       rv->next = NULL;
       --list->size;
     }
     else {
       /* The list was empty */
     }
   }
 
   return rv;
 }
void ll_print(struct ll_list *list)
{
  struct ll_node *rv=NULL;
  rv=(list->has_dummy_head)?list->head->next:list->head;
  while(rv->next!=NULL)
    {
      printf("%i--->",*((int *)rv->data));
      rv=rv->next;
    }
  printf("(.)");
}

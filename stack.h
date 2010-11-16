struct Stack
{
  int data;
  struct Stack *next;
};
struct Stack* stack_push(struct Stack* stack_start, int e)
{
  struct Stack* new_node = malloc(sizeof (struct Stack));
  if(new_node==NULL)
    return 0;
  new_node->data=e;
  new_node->next=stack_start->next;
  stack_start->next=new_node;
  return new_node;
}
int stack_pop(struct Stack* stack_start)
{
  if(stack_start->next!=NULL)
    { 
      struct Stack* to_be_deleted = stack_start->next;
      stack_start->next=stack_start->next->next;
      int e=to_be_deleted->data;
      free(to_be_deleted);
      return e;
    }
  return (int)(-1);
}
struct Stack* stack_new()
{
  struct Stack* new_one=malloc(sizeof (struct Stack));
  new_one->next=NULL;
  new_one->data=0;
  return new_one;
}
int stack_empty(struct Stack* stack)
{
  return (stack->next==NULL);
}

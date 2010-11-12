#include <stdio.h>
#include "linklist.h"
int main(){
  struct ll_list *list=new_list(1,1);
  if(list){
  int a=5;
  insert_after(list,list->head,(void *)&a);
  a=8;
  insert_after(list,list->head,(void *)&a);

  insert_after(list,list->head,(void *)&a);
  ll_print(list);}
  printf("\nHello\n");
  return 0;
}

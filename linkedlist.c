#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next;};

struct node * print_list(struct node *p){
  
  if(p->next == NULL){
    printf("%d\n", p->i);}
  else{
    printf("%d,", p->i);
    print_list(p->next);}
  
  return p;}

struct node * insert_front(struct node *p, int new){ 
  struct node *add  = (struct node *)calloc(1, sizeof(add));
  add->i  = new;
  add->next = p;
  return add;}

struct node * free_list(struct node *p){
   if(p->next == NULL){
     p->i = NULL;
     free(p);}
  else{
    free_list(p->next);
    p->i = NULL;
    p->next = NULL;
    free(p);}
  
  return p;}

int main(){
  
  struct node test1;
  struct node test2 ;
  struct node test3 ;
  struct node test4 ;
  struct node test5;
  struct node test6 ;
  struct node test8 ;
  struct node test7 ;
  struct node test9 ; 
  struct node test10 ;
  struct node test11 ;
  struct node test12 ;
  test1.i = 3;
  test2.i = 3;
  test3.i = 12;
  test4.i = 11;
  test5.i = 200;
  test1.next = &test2;
  test2.next = &test3;
  test3.next = &test4;
  test4.next = &test5;
  test5.next = NULL;

  printf("Testing print_list for various linked lists starting at different locations\n");
  printf("\n");
  print_list(&test1);
  print_list(&test2);
  print_list(&test3);
  print_list(&test4);
  print_list(&test5);


  printf("Testing insert_front for various linked lists starting at different locations with different ints\n");
  printf("\n");
  print_list(insert_front(&test1, 213));
  print_list(insert_front(&test1, 312));
  print_list(insert_front(&test1, 333));
  print_list(insert_front(&test1, 0));
  printf("\n");
  print_list(insert_front(&test2, 213));
  print_list(insert_front(&test2, 312));
  print_list(insert_front(&test2, 333));
  print_list(insert_front(&test2, 0));
  printf("\n");
  print_list(insert_front(&test3, 213));
  print_list(insert_front(&test3, 312));
  print_list(insert_front(&test3, 333));
  print_list(insert_front(&test3, 0));
  printf("\n");
  print_list(insert_front(&test4, 213));
  print_list(insert_front(&test4, 312));
  print_list(insert_front(&test4, 333));
  print_list(insert_front(&test4, 0));

  struct node *testf1 = (struct node *)calloc(1, sizeof(testf1));
  struct node *holder =insert_front( insert_front( insert_front(testf1,2),3),4);
  printf("\n");
  printf("Test for free_list. Before free_list then after free_list\n");
  print_list(holder);
  free_list(holder);
  print_list(holder);

  
    
    return 0;
}

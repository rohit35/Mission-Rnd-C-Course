#ifndef _MY_LINKED_LIST
#define _MY_LINKED_LIST 1
#include <stdlib.h>
typedef struct list_t
{
    int size;
    struct node_t*head;
} list_t;
typedef struct node_t
{
    void *data;
    struct node_t *next;
} node_t;
char * word(char *source);
char* convert(void *data);
int convert_int(void *data);
list_t *create_list()
{
    list_t *list=(list_t*)calloc(1,sizeof(list_t));
    return list;
}
char* convert(void *data)//Convert void data into a string
{
    char *var = (char*)data;
    return var;
}
char * word(char *source)//convert a string into a void data
{
    int idx;
    char *array = (char*)malloc(512*sizeof(char));
    for(idx=0; source[idx] !='\0'; idx++)
    {
        array[idx] = source[idx];
    }
    array[idx]='\0';
    return array;
}
int convert_int(void *data)//convert a void data into a integer
{
    int *idx = (int*)data;
    return idx;
}
int list_insert(list_t *list,void *data)//inserting a particular account
{
    node_t *new_node=NULL;
    if(list==NULL)return 0;
    new_node=(node_t*)calloc(1,sizeof(new_node));
    if(new_node==NULL)return 0;
    new_node->data=data;
    new_node->next=list->head;
    list->head=new_node;
    list->size++;
    return 1;
}
void list_deleted(node_t * cur,list_t * Users)//Deleting a particular Account
{
    node_t * pos =Users->head;
    node_t * li = (node_t*)cur;
    if(li==Users->head)
            {
                Users->head=li->next;
                Users->size--;
            }
            else if(li->next==NULL)
            {
                while(pos->next!=li)
                {
                    pos=pos->next;
                }
                pos->next = NULL;
                free(li);
                Users->size--;
            }
            else
            {
                while(pos->next!=li)
                {
                    pos=pos->next;
                }
                pos->next=li->next;
                free(li);
                Users->size--;
            }
}
#endif

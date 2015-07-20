#include "LinkList.h"
#include "malloc.h"
#include <assert.h>
#include <stdio.h>

LinkList *initLinkList()
{
  LinkList *newlist;
  
  newlist = malloc(sizeof(LinkList));
  newlist->head = NULL;
  newlist->tail = NULL;
  newlist->ListSize = 0;
  return newlist;
}

/*
  Input : firstNode is the head of the list
*/
void destroyListNode(ListNode *firstNode)
{
  if(firstNode != NULL)
  {
    if(firstNode->next != NULL)
      destroyListNode(firstNode->next);
    free(firstNode);
  }
}

void destroyLinkList(LinkList *list)
{
  if(list != NULL)
    free(list);
}

/*
  Return: 1 if empty
          0 if not
*/
int isListEmpty(LinkList *list)
{
  if(list->head == NULL)
    return 1;
  else 
    return 0;
}


void addToTail(LinkList *list, void *dataToAdd)
{
  ListNode *newNode;
  newNode = malloc(sizeof(ListNode)); 
  
  if(newNode != NULL)
  {
    newNode->data = dataToAdd;
    newNode->next = NULL;

    if( isListEmpty(list) )
      list->head = newNode;
    else
      list->tail->next = newNode;
  
    list->tail = newNode;
    list->ListSize++;
  }
}

/*
  Input: firstNode    is the head of the list
*/
void *removeTail(LinkList *list)
{
  ListNode *del, *previousDel;                //previousDel will point to the node before the node being to delete
                                              //del         will point to the node that is to be delete
                                              
  void *removedValue;
  
  if(!isListEmpty(list))                      //check if list is not empty
  {
    del = list->head;                         //always assume the del to be the head
    previousDel = NULL;
    
    while(del->next != NULL)                  //if there is the next node for the del(head), then travel until the last node
    {
      previousDel = del;
      del = del->next;
    }
    
    if(previousDel == NULL)
    {
      removedValue = del->data;
      list->head = NULL;
      list->tail = NULL;
      free(list->head);
    }
    else
    {
      removedValue = del->data;
      previousDel->next = NULL;
      list->tail = previousDel;
      free(del);
    }
    list->ListSize--;
  }
  
  return removedValue;
}


void addToHead(LinkList *list, void *valueToAdd)
{
  ListNode *newNode;
  newNode = malloc(sizeof(ListNode)); 
  newNode->data = valueToAdd;
  newNode->next = NULL;
  
  if(isListEmpty(list))
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    newNode->next = list->head;
    list->head = newNode;
  }
  
  list->ListSize++;
}


void *removeHead(LinkList *list)
{
  void *removedValue;
  
  if(!isListEmpty(list))
  {
    removedValue = list->head->data;
    list->head = list->head->next;
    if(list->head == NULL)
      list->tail = NULL;
    list->ListSize--;
  }
  
  return removedValue;
}




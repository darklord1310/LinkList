#include "main.h"
#include "LinkList.h"
#include <stdio.h>
#include <windows.h>

void displayList(LinkList *list)
{
  ListNode *ptr;
  
  if(isListEmpty(list))
  {
    printf("No nodes in the list to display\n");
  }
  else
  {
    printf("LinkList: ");
    for (ptr = list->head; ptr != NULL; ptr = ptr->next)
    {    
      printf("%c", ptr->data);
      printf("  ");
    }
    printf("\n");
    printf("ListSize: %d\n", list->ListSize);
    printf("Head: %c\n", list->head->data);
    printf("Tail: %c\n", list->tail->data);
    
  }
}


void main()
{
  int ch;
  char value;
  char ans = 'y';
  LinkList *list = initLinkList();
  
  while (ans == 'Y'||ans == 'y')
  {
        printf("---------------------------------");
        printf("\nOperations on singly linked list\n");
        printf("\n---------------------------------\n");
        printf("\n1.Insert node at first");
        printf("\n2.Insert node at last");
        printf("\n3.Delete Node from first");
        printf("\n4.Delete Node from last");
        printf("\n5.Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\n");
        displayList(list);
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1: 
            printf("\n...Inserting node at first...\n");
            printf("Enter the value: ");
            scanf("%c", &value);
            scanf("%c", &value);
            addToHead(list,(void *)value);
            break;
        case 2: 
            printf("\n...Inserting node at last...\n");
            printf("Enter the value: ");
            scanf("%c", &value);
            addToTail(list,(void *)value);
            break;
        case 3: 
            printf("\n...Delete Node from first...\n");
            removeHead(list);
            break;
        case 4: 
            printf("\n...Delete Node from last...\n");
            removeTail(list);
            break;
        case 5: 
            printf("\n...Exiting...\n");
            exit(1);
            break;
        default: 
            printf("\n...Invalid Choice...\n");
            break;
        }
        printf("\nYOU WANT TO CONTINUE (Y/N)");
        scanf(" %c", &ans);
        system("CLS");
  }
  
}
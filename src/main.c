#include "main.h"
#include "LinkList.h"
#include <stdio.h>
#include <windows.h>

void main()
{
  int ch,value;
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
            scanf("%i", &value);
            addToHead(list,value);
            break;
        case 2: 
            printf("\n...Inserting node at last...\n");
            printf("Enter the value: ");
            scanf("%i", &value);
            addToTail(list,value);
            break;
        case 3: 
            printf("\n...Delete Node from first...\n");
            value = removeHead(list);
            printf("Value removed: %d\n", value);
            break;
        case 4: 
            printf("\n...Delete Node from last...\n");
            value = removeTail(list);
            printf("Value removed: %d\n", value);
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
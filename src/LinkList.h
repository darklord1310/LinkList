#ifndef LinkList_H
#define LinkList_H

typedef struct ListNode ListNode;
typedef struct LinkList LinkList;

struct ListNode
{
    int data;
    ListNode *next;
};

struct LinkList
{
  ListNode *head, *tail;
  
};


LinkList *initLinkList();
void destroyLinkList(LinkList *list);
void destroyListNode(ListNode *firstNode);
void addToTail(LinkList *list, int dataToAdd);
void removeTail(LinkList *list);
void addToHead(LinkList *list, int valueToAdd);

#endif // LinkList_H

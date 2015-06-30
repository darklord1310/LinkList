#ifndef LinkList_H
#define LinkList_H

typedef struct ListNode ListNode;
typedef struct LinkList LinkList;

struct ListNode
{
    void *data;
    ListNode *next;
};

struct LinkList
{
  ListNode *head, *tail;
  int ListSize;
};


LinkList *initLinkList();
void destroyLinkList(LinkList *list);
void destroyListNode(ListNode *firstNode);
void addToTail(LinkList *list, void *dataToAdd);
void removeTail(LinkList *list);
void addToHead(LinkList *list, void *valueToAdd);
void removeHead(LinkList *list);
void displayList(LinkList *list);

#endif // LinkList_H

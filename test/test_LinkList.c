#include "unity.h"
#include "LinkList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_initLinkList_should_return_a_list_with_head_and_tail_point_to_null_and_ListSize_0(void)
{
  LinkList *newlist = initLinkList();
  
  TEST_ASSERT_NOT_NULL(newlist);
  TEST_ASSERT_NULL(newlist->head);
  TEST_ASSERT_NULL(newlist->tail);
  TEST_ASSERT_EQUAL(0,newlist->ListSize);

  destroyListNode(newlist->head);
  destroyLinkList(newlist);
}


void test_isListEmpty_given_empty_list_should_return_1()
{
  LinkList *newlist = initLinkList();
  int check = isListEmpty(newlist);
  
  TEST_ASSERT_EQUAL(1, check); 
  destroyListNode(newlist->head);
  destroyLinkList(newlist);
}



/* Before add 1 :  head --> NULL 
                   tail --> NULL
   
   After add 1  :  head --> 1
                   tail --> 1

*/
void test_addToTail_empty_list_and_add_1_should_get_head_is_1_tail_is_1()
{
  LinkList *list = initLinkList();
  int value1 = 1;
  addToTail(list, (void *)value1);

  TEST_ASSERT_NOT_NULL(list->head);
  TEST_ASSERT_NOT_NULL(list->tail);
  TEST_ASSERT_EQUAL( list->head->data , value1);
  TEST_ASSERT_EQUAL( list->tail->data , value1);
  TEST_ASSERT_EQUAL(1,list->ListSize);
  destroyListNode(list->head);
  destroyLinkList(list);
}

/* Before add 2 :  head --> 1 
                   tail --> 1
   
   After add 2  :  head --> 1
                   tail --> 2

*/
void test_addToTail_given_head_is_1_and_add_2_should_get_head_is_1_tail_is_2()
{
  LinkList *list = initLinkList();
  int value1 = 1;
  int value2 = 2;
  addToTail(list,(void *)value1);
  addToTail(list,(void *)value2);
  
  TEST_ASSERT_EQUAL( list->head->data , value1);
  TEST_ASSERT_EQUAL( list->tail->data , value2);
  TEST_ASSERT_EQUAL(2,list->ListSize);
  destroyListNode(list->head);
  destroyLinkList(list);
}



/* Before add c :  head --> a
                   tail --> b
   
   After add c  :  head --> a
                   tail --> c

*/
void test_addToTail_given_tail_is_2_and_add_3_should_get_head_is_1_tail_is_3()
{
  LinkList *list = initLinkList();
  addToTail(list,(void *)'a');
  addToTail(list,(void *)'b');
  addToTail(list,(void *)'c');
  
  TEST_ASSERT_EQUAL(list->head->data, (void *)'a');
  TEST_ASSERT_EQUAL(list->head->next->data,(void *) 'b');
  TEST_ASSERT_EQUAL(list->tail->data, (void *)'c');
  TEST_ASSERT_EQUAL(3,list->ListSize);
  destroyListNode(list->head);
  destroyLinkList(list);
}

/* List : 1 2 3 4 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_should_get_head_is_1_tail_is_3()
{
  LinkList *list = initLinkList();
  
  //add
  addToTail(list,(void *)1);
  addToTail(list,(void *)2);
  addToTail(list,(void *)3);
  addToTail(list,(void *)4);
  TEST_ASSERT_EQUAL(4,list->ListSize);
  
  //remove
  removeTail(list);
  TEST_ASSERT_EQUAL(3,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)3);
  
  destroyListNode(list->head);
  destroyLinkList(list);
}


/* List : 1 2 3 4 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_remove_2_times_should_get_head_is_1_tail_is_2()
{
  LinkList *list = initLinkList();
  
  //add
  addToTail(list,(void *)1);
  addToTail(list,(void *)2);
  addToTail(list,(void *)3);
  addToTail(list,(void *)4);
  TEST_ASSERT_EQUAL(4,list->ListSize);
  
  //remove
  removeTail(list);
  TEST_ASSERT_EQUAL(3,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)3);
  
  removeTail(list);
  TEST_ASSERT_EQUAL(2,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)2);
  
  destroyListNode(list->head);
  destroyLinkList(list);
}

/* List : 1 2 3 4 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_remove_3_times_should_get_head_is_1_tail_is_1()
{
  LinkList *list = initLinkList();
  
  //add
  addToTail(list,(void *)1);
  addToTail(list,(void *)2);
  addToTail(list,(void *)3);
  addToTail(list,(void *)4);
  TEST_ASSERT_EQUAL(4,list->ListSize);
  
  //remove
  removeTail(list);
  TEST_ASSERT_EQUAL(3,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)3);
  
  removeTail(list);
  TEST_ASSERT_EQUAL(2,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)2);
  
  removeTail(list);
  TEST_ASSERT_EQUAL(1,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)1);
  
  destroyListNode(list->head);
  destroyLinkList(list);
}


/* List : 1 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_should_get_head_is_NULL_tail_is_NULL()
{
  LinkList *list = initLinkList();
  
  //add
  addToTail(list,(void *)1);
  TEST_ASSERT_EQUAL(1,list->ListSize);
  
  //remove
  removeTail(list);
  TEST_ASSERT_EQUAL(0,list->ListSize);
  TEST_ASSERT_NULL(list->head);
  TEST_ASSERT_NULL(list->tail);
  
  destroyListNode(list->head);
  destroyLinkList(list);
}


//boundary test
void test_removeTail_given_empty_list_should_not_do_anything_or_fail()
{
  LinkList *list = initLinkList();
  removeTail(list);
  
  TEST_ASSERT_NULL(list->head);
  TEST_ASSERT_NULL(list->tail);
  TEST_ASSERT_EQUAL(0,list->ListSize);
  destroyListNode(list->head);
  destroyLinkList(list);
}

/* List : 2 3 <-- tail
          ^
          |
        head
*/
void test_addToHead_given_sample_list_above_and_add_1_should_get_head_is_1()
{
  //set up test condition
  LinkList *list = initLinkList();
  addToTail(list,(void *)2);
  addToTail(list,(void *)3);
  TEST_ASSERT_EQUAL(2,list->ListSize);
  
  //test add to tail
  addToHead(list, (void *)1);
  TEST_ASSERT_EQUAL(3,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->head->next->data, (void *)2);
  TEST_ASSERT_EQUAL(list->head->next->next->data, (void *)3);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)3);
}


//boundary test
void test_addToHead_given_empty_list_and_add_1_should_get_head_is_1_tail_is_1()
{
  //set up test condition
  LinkList *list = initLinkList();
  
  //test add to tail
  addToHead(list, (void *)1);
  TEST_ASSERT_EQUAL(1,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)1);
}


/* List : 0 1 2 <-- tail
          ^
          |
        head
*/
void test_removeHead_given_sample_list_above_should_get_head_is_1_tail_is_2()
{
  //set up test condition
  LinkList *list = initLinkList();
  addToTail(list,(void *)0);
  addToTail(list,(void *)1);
  addToTail(list,(void *)2);
  TEST_ASSERT_EQUAL(3,list->ListSize);
  
  removeHead(list);
  TEST_ASSERT_EQUAL(2,list->ListSize);
  TEST_ASSERT_EQUAL(list->head->data, (void *)1);
  TEST_ASSERT_EQUAL(list->tail->data, (void *)2);
}


//boundary test
/* List : 0 <-- tail
          ^
          |
        head
*/
void test_removeHead_given_sample_list_above_should_get_head_is_NULL_tail_is_NULL()
{
  //set up test condition
  LinkList *list = initLinkList();
  addToTail(list,(void *)0);
  TEST_ASSERT_EQUAL(1,list->ListSize);
  
  removeHead(list);
  TEST_ASSERT_EQUAL(0,list->ListSize);
  TEST_ASSERT_NULL(list->head);
  TEST_ASSERT_NULL(list->tail);
}


#include "unity.h"
#include "LinkList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_initLinkList_should_return_a_list_with_head_and_tail_point_to_null(void)
{
  LinkList *newlist = initLinkList();
  
  TEST_ASSERT_NOT_NULL(newlist);
  TEST_ASSERT_NULL(newlist->head);
  TEST_ASSERT_NULL(newlist->tail);

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
  addToTail(list,1);
  
  TEST_ASSERT_NOT_NULL(list->head);
  TEST_ASSERT_NOT_NULL(list->tail);
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 1);
  
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
  addToTail(list,1);
  addToTail(list,2);
  
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 2);
  
  destroyListNode(list->head);
  destroyLinkList(list);
}


/* Before add 3 :  head --> 1 
                   tail --> 2
   
   After add 3  :  head --> 1
                   tail --> 3

*/
void test_addToTail_given_tail_is_2_and_add_3_should_get_head_is_1_tail_is_3()
{
  LinkList *list = initLinkList();
  addToTail(list,1);
  addToTail(list,2);
  addToTail(list,3);
  
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->head->next->data, 2);
  TEST_ASSERT_EQUAL(list->tail->data, 3);
  
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
  addToTail(list,1);
  addToTail(list,2);
  addToTail(list,3);
  addToTail(list,4);
  
  //remove
  removeTail(list);
  
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 3);
  
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
  addToTail(list,1);
  addToTail(list,2);
  addToTail(list,3);
  addToTail(list,4);
  
  //remove
  removeTail(list);
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 3);
  
  removeTail(list);
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 2);
  
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
  addToTail(list,1);
  addToTail(list,2);
  addToTail(list,3);
  addToTail(list,4);
  
  //remove
  removeTail(list);
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 3);
  
  removeTail(list);
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 2);
  
  removeTail(list);
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 1);
  
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
  addToTail(list,1);
  
  //remove
  removeTail(list);
  
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
  addToTail(list,2);
  addToTail(list,3);
  
  //test add to tail
  addToHead(list, 1);
  
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->head->next->data, 2);
  TEST_ASSERT_EQUAL(list->head->next->next->data, 3);
  TEST_ASSERT_EQUAL(list->tail->data, 3);
}


//boundary test
void test_addToHead_given_empty_list_and_add_1_should_get_head_is_1_tail_is_1()
{
  //set up test condition
  LinkList *list = initLinkList();
  
  //test add to tail
  addToHead(list, 1);
  
  TEST_ASSERT_EQUAL(list->head->data, 1);
  TEST_ASSERT_EQUAL(list->tail->data, 1);
}




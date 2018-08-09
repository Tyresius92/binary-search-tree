#include "vendor/unity.h"
#include "../src/basic_bst.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_bst_new(void)
{
        BSTree_T test_tree = bst_new(NULL);
        TEST_ASSERT_NOT_NULL(test_tree);

        bst_free(test_tree); 
}

void test_bst_insert_string(void)
{
        BSTree_T test_tree = bst_new(NULL);
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "Hello")); 

        bst_free(test_tree); 
}

void test_bst_is_empty_on_empty_tree(void)
{
        BSTree_T test_tree = bst_new(NULL);
        TEST_ASSERT_TRUE(bst_is_empty(test_tree));

        bst_free(test_tree); 
}

void test_bst_is_empty_one_item_tree(void)
{
        BSTree_T test_tree = bst_new(NULL);
        bst_insert_value(test_tree, "hello");

        TEST_ASSERT_FALSE(bst_is_empty(test_tree)); 

        bst_free(test_tree); 
}

void test_bst_is_empty_many_items(void)
{
        BSTree_T test_tree = bst_new(NULL);
        bst_insert_value(test_tree, "hello");
        bst_insert_value(test_tree, "bob"); 
        bst_insert_value(test_tree, "what's"); 
        bst_insert_value(test_tree, "your"); 
        bst_insert_value(test_tree, "name"); 

        TEST_ASSERT_FALSE(bst_is_empty(test_tree)); 

        bst_free(test_tree); 
}

void test_bst_insert_several_values(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "hello")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "world"));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "the"));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "earth"));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "says"));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "hello"));

        bst_free(test_tree); 
}

void test_bst_insert_many_times(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "a")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "b")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "c")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "d")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "e")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "f")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "g")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "h")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "i")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "j")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "k")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "l")); 

        bst_free(test_tree); 
}

void test_bst_insert_reversed_order(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "l")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "k")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "j")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "i")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "h")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "g")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "f")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "e")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "d")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "c")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "b")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "a")); 

        bst_free(test_tree); 
}

void test_bst_insert_random_order(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "g")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "l")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "f")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "c")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "a")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "e")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "k")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "b")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "j")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "d")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "i")); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, "h")); 

        bst_free(test_tree); 
}

void test_bst_search(void)
{
        BSTree_T test_tree = bst_new(NULL); 

        bst_insert_value(test_tree, "a"); 
        TEST_ASSERT_NOT_NULL(bst_search(test_tree, "a")); 
        TEST_ASSERT_EQUAL_STRING("a", bst_search(test_tree, "a")); 

        TEST_ASSERT_NULL(bst_search(test_tree, "b")); 
        bst_insert_value(test_tree, "b"); 
        TEST_ASSERT_NOT_NULL(bst_search(test_tree, "b")); 
        TEST_ASSERT_EQUAL_STRING("b", bst_search(test_tree, "b")); 

        TEST_ASSERT_NULL(bst_search(test_tree, "hello")); 
        bst_insert_value(test_tree, "hello"); 
        TEST_ASSERT_NOT_NULL(bst_search(test_tree, "hello")); 
        TEST_ASSERT_EQUAL_STRING("a", bst_search(test_tree, "a")); 


        bst_free(test_tree); 
}

int integer_comparison(void *val_one, void *val_two)
{
        if (*(int *) val_one == *(int *) val_two) {
                return 0; 
        } else if (*(int *) val_one > *(int *) val_two) {
                return 1; 
        } else {
                return -1; 
        }
}

void test_bst_insert_ints(void)
{
        BSTree_T test_tree = bst_new(&integer_comparison);

        int a[] = { 1, 2, 3, 4, 5, 6, 6, 7, 9, 11};

        
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[0])); 
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[1]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[2]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[3]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[4]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[5]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[6]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[7]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[8]));
        TEST_ASSERT_EQUAL(0, bst_insert_value(test_tree, &a[9]));



        bst_free(test_tree); 
}

void test_bst_search_for_ints(void)
{
        BSTree_T test_tree = bst_new(&integer_comparison);

        int *test_ptr = NULL; 

        int a[] = { 214, 25, 64, 4, 7, 729, 34, 28, 9, 11};

        for (int i = 0; i < 10; i++) {
                test_ptr = &a[i]; 
                bst_insert_value(test_tree, test_ptr); 
        }

        int x = 4; 
        int y = 9; 
        int z = 70000000; 

        TEST_ASSERT_NOT_NULL(bst_search(test_tree, &x)); 
        TEST_ASSERT_EQUAL(x, *(int *) bst_search(test_tree, &x)); 
        
        TEST_ASSERT_NOT_NULL(bst_search(test_tree, &y)); 
        TEST_ASSERT_EQUAL(y, *(int *) bst_search(test_tree, &y)); 

        TEST_ASSERT_NULL(bst_search(test_tree, &z)); 

        bst_free(test_tree); 
}

struct string_closure_size_six {
        int index;
        int depth_ray[6];
        char *word_ray[6];
};


void function_to_apply_test_map_string(void *value, int depth, void *cl)
{
        struct string_closure_size_six *closure = (struct string_closure_size_six *) cl;
        int index = closure->index;
        
        closure->depth_ray[index] = depth;
        closure->word_ray[index] = value;
        closure->index = index + 1;
}

void test_bst_map_inorder_string(void)
{
        BSTree_T test_tree = bst_new(NULL);

        int expected_depth[] = { 1, 0, 4, 3, 2, 1 };
        char *expected_words[] = {"earth", "hello", "hello", "says", "the", "world"};

        char *word_ray[] = {"hello", "world", "the", "earth", "says", "hello"};

        for (int i = 0; i < 6; i++) {
                bst_insert_value(test_tree, word_ray[i]);
        }

        struct string_closure_size_six cl;
        cl.index = 0;
        
        bst_map_inorder(test_tree, &function_to_apply_test_map_string, &cl);

        for (int i = 0; i < 6; i++) {
                TEST_ASSERT_EQUAL(expected_depth[i], cl.depth_ray[i]);
                TEST_ASSERT_EQUAL_STRING(expected_words[i], cl.word_ray[i]);
        }

        bst_free(test_tree);
}

void test_bst_map_preorder_string(void)
{
        BSTree_T test_tree = bst_new(NULL);

        int expected_depth[] = { 0, 1, 1, 2, 3, 4 };
        char *expected_words[] = {"hello", "earth", "world", "the", "says", "hello"};

        char *word_ray[] = {"hello", "world", "the", "earth", "says", "hello"};

        for (int i = 0; i < 6; i++) {
                bst_insert_value(test_tree, word_ray[i]);
        }

        struct string_closure_size_six cl;
        cl.index = 0;
        
        bst_map_preorder(test_tree, &function_to_apply_test_map_string, &cl);

        for (int i = 0; i < 6; i++) {
                TEST_ASSERT_EQUAL(expected_depth[i], cl.depth_ray[i]);
                TEST_ASSERT_EQUAL_STRING(expected_words[i], cl.word_ray[i]);
        }

        bst_free(test_tree);
}

void test_bst_map_postorder_string(void)
{
        BSTree_T test_tree = bst_new(NULL);

        int expected_depth[] = { 1, 4, 3, 2, 1, 0 };
        char *expected_words[] = {"earth", "hello", "says", "the", "world", "hello"};

        char *word_ray[] = {"hello", "world", "the", "earth", "says", "hello"};

        for (int i = 0; i < 6; i++) {
                bst_insert_value(test_tree, word_ray[i]);
        }

        struct string_closure_size_six cl;
        cl.index = 0;
        
        bst_map_postorder(test_tree, &function_to_apply_test_map_string, &cl);

        for (int i = 0; i < 6; i++) {
                TEST_ASSERT_EQUAL(expected_depth[i], cl.depth_ray[i]);
                TEST_ASSERT_EQUAL_STRING(expected_words[i], cl.word_ray[i]);
        }

        bst_free(test_tree);
}

void test_bst_delete_value(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        bst_insert_value(test_tree, "hello"); 
        bst_insert_value(test_tree, "world");
        bst_insert_value(test_tree, "the");
        bst_insert_value(test_tree, "earth");
        bst_insert_value(test_tree, "says");

        TEST_ASSERT_EQUAL_STRING("hello", bst_search(test_tree, "hello")); 

        bst_delete_value(test_tree, "hello"); 

        TEST_ASSERT_NULL(bst_search(test_tree, "hello")); 
        TEST_ASSERT_EQUAL_STRING("world", bst_search(test_tree, "world"));
        TEST_ASSERT_EQUAL_STRING("the", bst_search(test_tree, "the"));
        TEST_ASSERT_EQUAL_STRING("earth", bst_search(test_tree, "earth"));
        TEST_ASSERT_EQUAL_STRING("says", bst_search(test_tree, "says"));

        bst_delete_value(test_tree, "the"); 

        TEST_ASSERT_NULL(bst_search(test_tree, "the"));
        TEST_ASSERT_NULL(bst_search(test_tree, "hello")); 
        TEST_ASSERT_EQUAL_STRING("world", bst_search(test_tree, "world"));
        TEST_ASSERT_EQUAL_STRING("earth", bst_search(test_tree, "earth"));
        TEST_ASSERT_EQUAL_STRING("says", bst_search(test_tree, "says"));

        bst_delete_value(test_tree, "earth"); 

        TEST_ASSERT_NULL(bst_search(test_tree, "earth"));
        TEST_ASSERT_NULL(bst_search(test_tree, "the"));
        TEST_ASSERT_NULL(bst_search(test_tree, "hello")); 
        TEST_ASSERT_EQUAL_STRING("world", bst_search(test_tree, "world"));
        TEST_ASSERT_EQUAL_STRING("says", bst_search(test_tree, "says"));

        bst_delete_value(test_tree, "world"); 

        TEST_ASSERT_NULL(bst_search(test_tree, "earth"));
        TEST_ASSERT_NULL(bst_search(test_tree, "the"));
        TEST_ASSERT_NULL(bst_search(test_tree, "hello")); 
        TEST_ASSERT_NULL(bst_search(test_tree, "world"));
        TEST_ASSERT_EQUAL_STRING("says", bst_search(test_tree, "says"));

        bst_delete_value(test_tree, "says"); 

        TEST_ASSERT_NULL(bst_search(test_tree, "earth"));
        TEST_ASSERT_NULL(bst_search(test_tree, "the"));
        TEST_ASSERT_NULL(bst_search(test_tree, "hello")); 
        TEST_ASSERT_NULL(bst_search(test_tree, "world"));
        TEST_ASSERT_NULL(bst_search(test_tree, "says"));

        TEST_ASSERT_TRUE(bst_is_empty(test_tree)); 

        bst_free(test_tree); 
}

void test_bst_delete_value_not_in_tree(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        bst_insert_value(test_tree, "hello"); 
        bst_insert_value(test_tree, "world");
        bst_insert_value(test_tree, "the");
        bst_insert_value(test_tree, "earth");
        bst_insert_value(test_tree, "says");

        TEST_ASSERT_EQUAL_STRING("hello", bst_search(test_tree, "hello")); 
        TEST_ASSERT_EQUAL_STRING("world", bst_search(test_tree, "world"));
        TEST_ASSERT_EQUAL_STRING("the", bst_search(test_tree, "the"));
        TEST_ASSERT_EQUAL_STRING("earth", bst_search(test_tree, "earth"));
        TEST_ASSERT_EQUAL_STRING("says", bst_search(test_tree, "says"));
        TEST_ASSERT_NULL(bst_search(test_tree, "not_in_tree"));

        bst_delete_value(test_tree, "not_in_tree"); 

        TEST_ASSERT_EQUAL_STRING("hello", bst_search(test_tree, "hello")); 
        TEST_ASSERT_EQUAL_STRING("world", bst_search(test_tree, "world"));
        TEST_ASSERT_EQUAL_STRING("the", bst_search(test_tree, "the"));
        TEST_ASSERT_EQUAL_STRING("earth", bst_search(test_tree, "earth"));
        TEST_ASSERT_EQUAL_STRING("says", bst_search(test_tree, "says"));
        TEST_ASSERT_NULL(bst_search(test_tree, "not_in_tree"));

        bst_free(test_tree); 
}

void test_bst_tree_minimum(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        bst_insert_value(test_tree, "hello"); 
        bst_insert_value(test_tree, "world");
        bst_insert_value(test_tree, "the");
        bst_insert_value(test_tree, "earth");
        bst_insert_value(test_tree, "says");

        TEST_ASSERT_EQUAL_STRING("earth", bst_tree_minimum(test_tree)); 

        bst_free(test_tree); 
}

void test_bst_tree_maximum(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        bst_insert_value(test_tree, "hello"); 
        bst_insert_value(test_tree, "world");
        bst_insert_value(test_tree, "the");
        bst_insert_value(test_tree, "earth");
        bst_insert_value(test_tree, "says");

        TEST_ASSERT_EQUAL_STRING("world", bst_tree_maximum(test_tree)); 

        bst_free(test_tree); 
}

void test_bst_successor_of_value(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        bst_insert_value(test_tree, "hello"); 
        bst_insert_value(test_tree, "world");
        bst_insert_value(test_tree, "the");
        bst_insert_value(test_tree, "earth");
        bst_insert_value(test_tree, "says");

        TEST_ASSERT_EQUAL_STRING("world", bst_successor_of_value(test_tree, "the"));
        TEST_ASSERT_EQUAL_STRING("hello", bst_successor_of_value(test_tree, "earth"));
        TEST_ASSERT_EQUAL_STRING("the", bst_successor_of_value(test_tree, "says")); 
        TEST_ASSERT_EQUAL_STRING("says", bst_successor_of_value(test_tree, "not_in_tree"));
        TEST_ASSERT_NULL(bst_successor_of_value(test_tree, "world"));

        bst_free(test_tree); 
}

void test_bst_predecessor_of_value(void)
{
        BSTree_T test_tree = bst_new(NULL); 
        bst_insert_value(test_tree, "hello"); 
        bst_insert_value(test_tree, "world");
        bst_insert_value(test_tree, "the");
        bst_insert_value(test_tree, "earth");
        bst_insert_value(test_tree, "says");

        TEST_ASSERT_EQUAL_STRING("says", bst_predecessor_of_value(test_tree, "the"));
        TEST_ASSERT_EQUAL_STRING("hello", bst_predecessor_of_value(test_tree, "says"));
        TEST_ASSERT_EQUAL_STRING("earth", bst_predecessor_of_value(test_tree, "hello"));  
        TEST_ASSERT_EQUAL_STRING("hello", bst_predecessor_of_value(test_tree, "not_in_tree"));
        TEST_ASSERT_NULL(bst_predecessor_of_value(test_tree, "earth"));

        bst_free(test_tree); 
}

int main(void)
{
        UnityBegin("test/test_basic_bst.c");

        RUN_TEST(test_bst_new); 
        RUN_TEST(test_bst_insert_string); 
        RUN_TEST(test_bst_is_empty_on_empty_tree); 
        RUN_TEST(test_bst_is_empty_one_item_tree); 
        RUN_TEST(test_bst_is_empty_many_items); 
        RUN_TEST(test_bst_insert_several_values); 
        RUN_TEST(test_bst_insert_many_times); 
        RUN_TEST(test_bst_insert_reversed_order); 
        RUN_TEST(test_bst_insert_random_order); 
        RUN_TEST(test_bst_search); 
        RUN_TEST(test_bst_insert_ints); 
        RUN_TEST(test_bst_search_for_ints); 
        RUN_TEST(test_bst_map_inorder_string); 
        RUN_TEST(test_bst_map_preorder_string); 
        RUN_TEST(test_bst_map_postorder_string); 
        RUN_TEST(test_bst_delete_value); 
        RUN_TEST(test_bst_delete_value_not_in_tree); 
        RUN_TEST(test_bst_tree_minimum); 
        RUN_TEST(test_bst_tree_maximum); 
        RUN_TEST(test_bst_successor_of_value); 
        RUN_TEST(test_bst_predecessor_of_value); 

        UnityEnd();
        return 0;
}

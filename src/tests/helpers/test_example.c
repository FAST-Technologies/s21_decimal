#include "tests_s21_main.h"

#define GENERATE_TEST_1(test_name, src, str, start_index, expectation) \
  START_TEST(test_name) {                                              \
    char *result_custom = s21_insert(src, str, start_index);           \
    ck_assert_str_eq(result_custom, expectation);                      \
    free(result_custom);                                               \
  }                                                                    \
  END_TEST

#define GENERATE_TEST_2(test_name, src, str, start_index, expectation) \
  START_TEST(test_name) {                                              \
    char *result_custom = s21_insert(src, str, start_index);           \
    ck_assert_ptr_eq(result_custom, expectation);                      \
    free(result_custom);                                               \
  }                                                                    \
  END_TEST

GENERATE_TEST_1(s21_insert_test_1, "Hello, world!", " samsung ", 7,
                "Hello,  samsung world!")
GENERATE_TEST_1(s21_insert_test_2, "", "world", 0, "world")
GENERATE_TEST_1(s21_insert_test_3, "Hello, world!", "", 5, "Hello, world!")
GENERATE_TEST_1(s21_insert_test_4, "Hello, world!", "Start ", 0,
                "Start Hello, world!")
GENERATE_TEST_1(s21_insert_test_5, "", "", 0, "")
GENERATE_TEST_1(s21_insert_test_6, "Hello", ", world!", 5, "Hello, world!")
GENERATE_TEST_1(s21_insert_test_7, "Hello", " w\0orld", 5, "Hello w")
GENERATE_TEST_2(s21_insert_test_8, "Hello, world!", "hi", 20, S21_NULL)

        Suite *s21_insert_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_insert");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_insert_test_1);
    tcase_add_test(tc_core, s21_insert_test_2);
    tcase_add_test(tc_core, s21_insert_test_3);
    tcase_add_test(tc_core, s21_insert_test_4);
    tcase_add_test(tc_core, s21_insert_test_5);
    tcase_add_test(tc_core, s21_insert_test_6);
    tcase_add_test(tc_core, s21_insert_test_7);
    tcase_add_test(tc_core, s21_insert_test_8);
    suite_add_tcase(s, tc_core);

    return s;
}
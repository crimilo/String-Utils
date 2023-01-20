#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __FUNCTION__
#define TEST_ASSERT(cond) if (!cond) { fprintf(stderr, "Test %s failed.\n", __FUNCTION__); exit(EXIT_FAILURE); }
#else
#define TEST_ASSERT(cond) if (!cond) { fprintf(stderr, "Test failed (%s:%d).\n", __FILE__, __LINE__); exit(EXIT_FAILURE); }
#endif

void test_str_starts_w()
{
   puts("Running test_str_starts_w()...");
   TEST_ASSERT(str_starts_w("hello world", "hello"));
   TEST_ASSERT(!str_starts_w("hello world", "hello world 1234"));
   TEST_ASSERT(!str_starts_w("hello world", "ello"));
   TEST_ASSERT(!str_starts_w("hello world", "world"));
}

void test_str_starts_w_i()
{
   puts("Running test_str_starts_w_i()...");
   TEST_ASSERT(str_starts_w_i("hello world", "hello"));
   TEST_ASSERT(str_starts_w_i("hello world", "heLLo"));
   TEST_ASSERT(str_starts_w_i("HeLlo WORld", "heLLo"));
   TEST_ASSERT(!str_starts_w_i("hello world", "hello world 1234"));
   TEST_ASSERT(!str_starts_w_i("hello world", "ello"));
   TEST_ASSERT(!str_starts_w_i("hello world", "world"));
}


void test_str_ends_w()
{
   puts("Running test_str_ends_w()...");
   TEST_ASSERT(str_ends_w("hello world", "world"));
   TEST_ASSERT(!str_ends_w("hello world", "hello world 1234"));
   TEST_ASSERT(!str_ends_w("hello world", "hello"));
   TEST_ASSERT(!str_ends_w("hello world", "world123"));
}

void test_str_ends_w_i()
{
   puts("Running test_str_ends_w_i()...");
   TEST_ASSERT(str_ends_w_i("hello world", "world"));
   TEST_ASSERT(str_ends_w_i("hello world", "World"));
   TEST_ASSERT(str_ends_w_i("hello WoRlD", "world"));
   TEST_ASSERT(str_ends_w_i("hello WoRlD", "WORLD"));
   TEST_ASSERT(!str_ends_w_i("hello w", "WORLD"));
   TEST_ASSERT(!str_ends_w_i("hello world", "hello world 1234"));
   TEST_ASSERT(!str_ends_w_i("hello world", "hello"));
   TEST_ASSERT(!str_ends_w_i("hello world", "world123"));
}

void test_str_cmp_i()
{
   puts("Running test_str_cmp_i()...");
   TEST_ASSERT(str_cmp_i("hello world", "hello world"));
   TEST_ASSERT(str_cmp_i("hello world", "Hello World"));
   TEST_ASSERT(str_cmp_i("Hello World", "hello world"));
   TEST_ASSERT(str_cmp_i("HeLlO wOrLd", "hElLo WoRlD"));
   TEST_ASSERT(!str_cmp_i("hello world", "1ello 2orld"));
   TEST_ASSERT(!str_cmp_i("hello world", "01234567890123456789"));
   TEST_ASSERT(str_cmp_i("", ""));
}

void test_str_ncmp_i()
{
   puts("Running test_str_ncmp_i()...");
   TEST_ASSERT(str_ncmp_i("hello world", "hello world", 12));
   TEST_ASSERT(str_ncmp_i("hello world", "hello world", 100));
   TEST_ASSERT(str_ncmp_i("hello world", "hello world", 5));
   TEST_ASSERT(str_ncmp_i("hello world", "Hello World", 7));
   TEST_ASSERT(str_ncmp_i("Hello World", "hello world", 12));
   TEST_ASSERT(str_ncmp_i("HeLlO wOrLd", "hElLo WoRlD", 12));
   TEST_ASSERT(!str_ncmp_i("hello world", "1ello 2orld", 12));
   TEST_ASSERT(!str_ncmp_i("hello world", "01234567890123456789", 12));
   TEST_ASSERT(!str_ncmp_i("hello world", "01234567890123456789", 100));
   TEST_ASSERT(str_ncmp_i("", "", 0));
}

void test_str_find()
{
   puts("Running test_str_find()...");
   TEST_ASSERT(str_find("hello world", "world") == 6);
   TEST_ASSERT(str_find("hello world", "rld") == 8);
   TEST_ASSERT(str_find("hello world", "123") == EOS);
   TEST_ASSERT(str_find("hello world", "") == EOS);
   TEST_ASSERT(str_find("hello world", "hello world") == 0);
   TEST_ASSERT(str_find("hello world", "Hello world") == EOS);
}

void test_str_find_i()
{
   puts("Running test_str_find_i()...");
   TEST_ASSERT(str_find_i("hello world", "world") == 6);
   TEST_ASSERT(str_find_i("hello world", "WoRlD") == 6);
   TEST_ASSERT(str_find_i("hello world", "rld") == 8);
   TEST_ASSERT(str_find_i("hello world", "") == EOS);
   TEST_ASSERT(str_find_i("hello world", "123") == EOS);
   TEST_ASSERT(str_find_i("hello world", "hello world") == 0);
   TEST_ASSERT(str_find_i("hello world", "HellO WorlD") == 0);
   TEST_ASSERT(str_find_i("hello world", "Hello world") == EOS);
}

void test_str_rfind()
{
   puts("Running test_str_rfind()...");
   TEST_ASSERT(str_rfind("hello world", "world") == 6);
   TEST_ASSERT(str_rfind("hello world", "rld") == 9);
   TEST_ASSERT(str_rfind("hello world", "123") == EOS);
   TEST_ASSERT(str_rfind("hello world", "") == EOS);
   TEST_ASSERT(str_rfind("hello world", "hello world") == 0);
   TEST_ASSERT(str_rfind("hello world", "Hello world") == EOS);
}

void test_str_rfind_i()
{
   puts("Running test_str_rfind_i()...");
   TEST_ASSERT(str_rfind_i("hello world", "world") == 6);
   TEST_ASSERT(str_rfind_i("hello world", "WoRlD") == 6);
   TEST_ASSERT(str_rfind_i("hello world", "rld") == 9);
   TEST_ASSERT(str_rfind_i("hello world", "RLD") == 9);
   TEST_ASSERT(str_rfind_i("hello world", "123") == EOS);
   TEST_ASSERT(str_rfind_i("hello world", "") == EOS);
   TEST_ASSERT(str_rfind_i("hello world", "hello world") == 0);
   TEST_ASSERT(str_rfind_i("hello world", "HellO WorlD") == 0);
   TEST_ASSERT(str_rfind_i("hello world", "Hello world") == EOS);
}


void test_str_substr()
{
   puts("Running test_str_substr()...");
   char substr[32];
   TEST_ASSERT(str_substr("hello world", 6, 5, substr, 32) == 5);
   TEST_ASSERT(!strcmp(substr, "world"));
   TEST_ASSERT(str_substr("hello world", 0, 11, substr, 32) == 11);
   TEST_ASSERT(!strcmp(substr, "hello world"));
   TEST_ASSERT(str_substr("hello world", 0, 5, substr, 5) == 4);
   TEST_ASSERT(!strcmp(substr, "hell"));
   TEST_ASSERT(!str_substr("hello world", 12, 0, substr, 32));
   TEST_ASSERT(!str_substr("hello world", 6, 1024, substr, 32));
}

void test_str_substr_cnt()
{
   puts("Running test_str_substr_cnt()...");
   TEST_ASSERT(str_substr_cnt("hello world", "l") == 3);
   TEST_ASSERT(str_substr_cnt("aaa bbb aaa ccc aaa ddd", "aaa") == 3);
   TEST_ASSERT(str_substr_cnt("hello world", "X") == 0);
   TEST_ASSERT(str_substr_cnt("hello world", "Hello") == 0);
   TEST_ASSERT(str_substr_cnt("hello world", "hello world 123") == 0);
   TEST_ASSERT(str_substr_cnt("@@@@@@@@@@", "@") == 10);
}

void test_str_substr_cnt_i()
{
   puts("Running test_str_substr_cnt_i()...");
   TEST_ASSERT(str_substr_cnt_i("hello world", "l") == 3);
   TEST_ASSERT(str_substr_cnt_i("AAA bbb aaa ccc AAA ddd", "aAa") == 3);
   TEST_ASSERT(str_substr_cnt_i("hello world", "X") == 0);
   TEST_ASSERT(str_substr_cnt_i("heLLo woRld", "l") == 3);
   TEST_ASSERT(str_substr_cnt_i("hello world", "Hello") == 1);
   TEST_ASSERT(str_substr_cnt_i("hello world", "hello world 123") == 0);
   TEST_ASSERT(str_substr_cnt_i("@@@@@@@@@@", "@") == 10);
   TEST_ASSERT(str_substr_cnt_i("hello world", "L") == 3);
   TEST_ASSERT(str_substr_cnt_i("hello world", "X") == 0);
   TEST_ASSERT(str_substr_cnt_i("hello world", "hello world 123") == 0);
   TEST_ASSERT(str_substr_cnt_i("@@@@@@@@@@", "@") == 10);
}

void test_str_trim()
{
   puts("Running test_str_trim()...");
   char trimmed[32];
   TEST_ASSERT(str_trim(" \thello\n\n", trimmed, 32) == 5);
   TEST_ASSERT(!strcmp(trimmed, "hello"));
}

void test_str_trim_s()
{
   puts("Running test_str_trim_s()...");
   char trimmed[32];
   TEST_ASSERT(str_trim_s(" \t\nhello", trimmed, 32) == 5);
   TEST_ASSERT(!strcmp(trimmed, "hello"));
   TEST_ASSERT(str_trim_s(" \t\nhello  ", trimmed, 32) == 7);
   TEST_ASSERT(!strcmp(trimmed, "hello  "));
}

void test_str_trim_e()
{
   puts("Running test_str_trim_e()...");
   char trimmed[32];
   TEST_ASSERT(str_trim_e("hello \t\n", trimmed, 32) == 5);
   TEST_ASSERT(!strcmp(trimmed, "hello"));
   TEST_ASSERT(str_trim_e("  hello \t\n", trimmed, 32) == 7);
   TEST_ASSERT(!strcmp(trimmed, "  hello"));
}

void test_str_split()
{
   puts("Running test_str_split()...");
   char** tokens = str_split("1,2.3", ".,");

   if (!tokens)
   {
      perror("str_split() failed");
      exit(EXIT_FAILURE);
   }

   TEST_ASSERT(tokens);
   TEST_ASSERT(tokens[0]);
   TEST_ASSERT(tokens[1]);
   TEST_ASSERT(tokens[2]);
   TEST_ASSERT(!tokens[3]);
   TEST_ASSERT(!strcmp(tokens[0], "1"));
   TEST_ASSERT(!strcmp(tokens[1], "2"));
   TEST_ASSERT(!strcmp(tokens[2], "3"));

   for (int i = 0; tokens[i]; i++)
      free(tokens[i]);

   free(tokens);
}

int main()
{
   test_str_starts_w();
   test_str_starts_w_i();
   test_str_ends_w();
   test_str_ends_w_i();
   test_str_cmp_i();
   test_str_ncmp_i();
   test_str_find();
   test_str_find_i();
   test_str_rfind();
   test_str_rfind_i();
   test_str_substr();
   test_str_substr_cnt();
   test_str_substr_cnt_i();
   test_str_split();
   test_str_trim();
   test_str_trim_s();
   test_str_trim_e();

   puts("All tests have passed successfully!");
}
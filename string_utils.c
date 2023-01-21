#include "string_utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int str_starts_w(const char* str, const char* sub)
{
   if (!*sub)
      return 0;

   for (; *sub; sub++, str++)
   {
      if (*str != *sub)
         return 0;
   }

   return !*sub;
}

int str_starts_w_i(const char* str, const char* sub)
{
   if (!*sub)
      return 0;

   for (; *sub; sub++, str++)
   {
      if (tolower(*str) != tolower(*sub))
         return 0;
   }

   return !*sub;
}

int str_ends_w(const char* str, const char* sub)
{
   size_t str_len = strlen(str);
   size_t sub_len = strlen(sub);

   return sub_len <= str_len && !strcmp(str + str_len - sub_len, sub);
}

int str_ends_w_i(const char* str, const char* sub)
{
   size_t str_len = strlen(str);
   size_t sub_len = strlen(sub);

   return sub_len <= str_len && str_cmp_i(str + str_len - sub_len, sub);
}

int str_cmp_i(const char* s1, const char* s2)
{
   for (; *s1; s1++, s2++)
   {
      if (tolower(*s1) != tolower(*s2))
         return 0;
   }

   return *s1 == *s2;
}

int str_ncmp_i(const char* s1, const char* s2, size_t n)
{
   for (; n && *s1; s1++, s2++, n--)
   {
      if (tolower(*s1) != tolower(*s2))
         return 0;
   }

   return !n | !(*s1 ^ *s2);
}

int str_find(const char* str, const char* sub)
{
   char* pos = strstr(str, sub);
   return pos ? pos - str : EOS;
}

int str_rfind(const char* str, const char* sub)
{
   size_t str_len = strlen(str);
   size_t sub_len = strlen(sub);

   for (int i = str_len - sub_len; i >= 0; i--)
   {
      if (!strncmp(str + i, sub, sub_len))
         return i;
   }

   return EOS;
}

int str_find_i(const char* str, const char* sub)
{
   if (!*sub)
      return EOS;

   const char* offset = str;

   for (; *str; str++)
   {
      const char* str_cpy = str;
      const char* sub_cpy = sub;

      for (; *str_cpy; str_cpy++, sub_cpy++)
      {
         if (tolower(*str_cpy) != tolower(*sub_cpy))
            break;
      }

      if (!*sub_cpy)
         return str - offset;
   }

   return EOS;
}

int str_rfind_i(const char* str, const char* sub)
{
   size_t str_len = strlen(str);
   size_t sub_len = strlen(sub);

   for (int i = str_len - sub_len; i >= 0; i--)
   {
      if (str_ncmp_i(str + i, sub, sub_len))
         return i;
   }

   return EOS;
}

size_t str_substr(const char* str, size_t pos, size_t cnt, char* res, size_t res_len)
{
   if (!res_len)
      return 0;

   size_t str_len = strlen(str);

   if (!str_len)
      return 0;

   if (pos + cnt > str_len)
      return 0;

   size_t chrs_to_cpy = cnt >= res_len ? res_len - 1 : cnt;

   memcpy(res, str + pos, chrs_to_cpy);
   res[chrs_to_cpy] = '\0';

   return chrs_to_cpy + 1;
}

size_t str_substr_cnt(const char* str, const char* sub)
{
   if (!*sub)
      return 0;

   size_t str_len = strlen(str);
   size_t sub_len = strlen(sub);

   if (sub_len > str_len)
      return 0;

   size_t cnt = 0;

   for (; *(str + sub_len - 1); str++)
   {
      if (!strncmp(str, sub, sub_len))
      {
         cnt++;
         str += sub_len;
      }
   }

   return cnt;
}

size_t str_substr_cnt_i(const char* str, const char* sub)
{
   if (!*sub)
      return 0;

   size_t str_len = strlen(str);
   size_t sub_len = strlen(sub);

   if (sub_len > str_len)
      return 0;

   size_t cnt = 0;

   for (; *(str + sub_len - 1); str++)
   {
      if (str_ncmp_i(str, sub, sub_len))
      {
         cnt++;
         str += sub_len;
      }
   }

   return cnt;
}

char** str_split(const char* str, const char* delims)
{
   const char* str_cpy = str;
   size_t n_tkns = 0;
   size_t i;

   while ((i = strcspn(str_cpy, delims)))
   {
      n_tkns++;
      str_cpy += i;
      str_cpy += strspn(str_cpy, delims);
   }

   char** res = (char**) malloc((n_tkns + 1) * sizeof(char*));

   if (!res)
      return NULL;

   res[n_tkns] = '\0';
   str_cpy = str;

   for (size_t j = 0; (i = strcspn(str_cpy, delims)); j++)
   {
      res[j] = (char*) malloc((i + 1) * sizeof(char));

      if (!res[j])
      {
         while (j)
            free(res[--j]);

         free(res);
         return NULL;
      }

      memcpy(res[j], str_cpy, i);
      res[j][i] = '\0';
      str_cpy += i;
      str_cpy += strspn(str_cpy, delims);
   }

   return res;
}

int is_trim_char(int c)
{
   return c == ' ' || c == '\n' || c == '\t';
}

size_t str_trim(const char* str, char* res, size_t res_len)
{
   if (!res_len)
      return 0;

   size_t str_len = strlen(str);

   if (!str_len)
   {
      res[0] = '\0';
      return 1;
   }

   size_t start = 0;

   while (is_trim_char(str[start]))
      start++;

   size_t end = str_len - 1;

   while (is_trim_char(str[end]))
      end--;

   size_t trmd_len = end - start + 1;
   size_t chrs_to_cpy = trmd_len >= res_len ? res_len - 1 : trmd_len;

   memcpy(res, str + start, chrs_to_cpy);
   res[chrs_to_cpy] = '\0';

   return chrs_to_cpy + 1;
}

size_t str_trim_s(const char* str, char* res, size_t res_len)
{
   if (!res_len)
      return 0;

   size_t str_len = strlen(str);

   if (!str_len)
   {
      res[0] = '\0';
      return 1;
   }

   size_t i = 0;
   
   while (is_trim_char(str[i]))
      i++;

   size_t chrs_to_cpy = str_len - i >= res_len ? res_len - 1 : str_len - i;

   memcpy(res, str + i, chrs_to_cpy);
   res[chrs_to_cpy] = '\0';

   return chrs_to_cpy + 1;
}

size_t str_trim_e(const char* str, char* res, size_t res_len)
{
   if (!res_len)
      return 0;

   size_t str_len = strlen(str);

   if (!str_len)
   {
      res[0] = '\0';
      return 1;
   }

   size_t i = str_len - 1;
   
   while (is_trim_char(str[i]))
      i--;

   size_t chrs_to_cpy = i + 1 >= res_len ? res_len - 1 : i + 1;

   memcpy(res, str, chrs_to_cpy);
   res[chrs_to_cpy] = '\0';

   return chrs_to_cpy + 1;
}
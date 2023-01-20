#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>

#define EOS -1

/*
* @brief Checks whether a string starts with another string.
*
* @param str String to check.
* @param sub Substring with which str must start.
*
* @return 1 if str starts with sub, 0 otherwise.
*/
int str_starts_w(const char* str, const char* sub);

/*
* @brief Checks whether a string starts with another string case insensitive.
*
* @param str String to check.
* @param sub Substring with which str must start.
*
* @return 1 if str starts with sub, 0 otherwise.
*/
int str_starts_w_i(const char* str, const char* sub);

/*
* @brief Checks whether a string ends with another string.
*
* @param str String to check.
* @param sub Substring with which str must end.
*
* @return 1 if str ends with sub, 0 otherwise.
*/
int str_ends_w(const char* str, const char* sub);

/*
* @brief Checks whether a string ends with another string case insensitive.
*
* @param str String to check.
* @param sub Substring with which str must end.
*
* @return 1 if str ends with sub, 0 otherwise.
*/
int str_ends_w_i(const char* str, const char* sub);

/*
* @brief Compares two strings case insensitive.
*
* @param s1 First string to compare.
* @param s2 Second string to compare.
*
* @return 1 if the strings are equal 0 otherwise.
*/
int str_cmp_i(const char* s1, const char* s2);

/*
* @brief Compares two strings case insensitive.
* At most n characters are compared.
*
* @param s1 First string to compare.
* @param s2 Second string to compare.
* @param n Max number of characters to compare.
*
* @return 1 if the strings are equal, 0 otherwise.
*/
int str_ncmp_i(const char* s1, const char* s2, size_t n);

/*
* @brief Checks whether a string contains another string.
*
* @param str String to check.
* @param sub Substring that str must contain.
*
* @return Index of the first occurrence of sub in str, EOS otherwise.
*/
int str_find(const char* str, const char* sub);

/*
* @brief Checks whether a string contains another string case insensitive.
*
* @param str String to check.
* @param sub Substring that str must contain.
*
* @return Index of the first occurrence of sub in str, EOS otherwise.
*/
int str_find_i(const char* str, const char* sub);

/*
* @brief Checks whether a string contains another string.
* The search starts from the end of the string.
*
* @param str String to check.
* @param sub Substring that str must contain.
*
* @return Index of the first occurrence of sub in str, EOS otherwise.
*/
int str_rfind(const char* str, const char* sub);

/*
* @brief Checks whether a string contains another string case insensitive.
* The search starts from the end of the string.
*
* @param str String to check.
* @param sub Substring that str must contain.
*
* @return Index of the first occurrence of sub in str, EOS otherwise.
*/
int str_rfind_i(const char* str, const char* sub);

/*
* @brief Creates a substring from a string.
* The substring will be null-terminated.
* No more than res_len - 1 characters are stored into res.
*
* @param str String to create a substring from.
* @param pos Position of the first character to include.
* @param cnt Length of the substring.
* @param res Buffer where to store the substring.
* @param res_len Length of res.
*
* @return Number of characters stored into res (excluding null-byte), or 0 if an error occurs.
*/
int str_substr(const char* str, size_t pos, size_t cnt, char* res, size_t res_len);

/*
* @brief Count the number of substring occurrences in a string.
*
* @param str String where to count.
* @param sub Substring to search.
*
* @return Number of occurrences of sub in str.
*/
size_t str_substr_cnt(const char* str, const char* sub);

/*
* @brief Count the number of substring occurrences in a string case insensitive.
*
* @param str String where to count.
* @param sub Substring to search.
*
* @return Number of occurrences of sub in str.
*/
size_t str_substr_cnt_i(const char* str, const char* sub);

/*
* @brief Splits a string into tokens.
*
* @param str String to split.
* @param delim String of delimiters with which to split str.
*
* @return Pointer to a null-terminated list of token strings, or NULL on error.
*
* @note After a successfull call to str_split(), you should always free() each token and the returned pointer.
*
* @example
* char** tokens = str_split("1,2.3", ".,");
* if (!tokens)
*    ; // Handle error
*
* for (int i = 0; tokens[i]; i++)
* {
*    printf("%s\n", tokens[i]);
*    free(tokens[i]);
* }
* free(tokens);
*/
char** str_split(const char* str, const char* delims);

/*
* @brief Removes white spaces, tabs and new line characters from the start and end of a string.
* The trimmed string will be null-terminated.
* No more than res_len - 1 characters are stored into res.

* @param str String to trim.
* @param res Buffer where to store the trimmed string.
* @param res_len Length of res.
*
* @return Number of characters stored into res (excluding null-byte).
*/
int str_trim(const char* str, char* res, size_t res_len);

/*
* @brief Removes white spaces, tabs and new line characters from the start of a string.
* The trimmed string will be null-terminated.
* No more than res_len - 1 characters are stored into res.

* @param str String to trim.
* @param res Buffer where to store the trimmed string.
* @param res_len Length of res.
*
* @return Number of characters stored into res (excluding null-byte).
*/
int str_trim_s(const char* str, char* res, size_t res_len);

/*
* @brief Removes white spaces, tabs and new line characters from the end of a string.
* The trimmed string will be null-terminated.
* No more than res_len - 1 characters are stored into res.

* @param str String to trim.
* @param res Buffer where to store the trimmed string.
* @param res_len Length of res.
*
* @return Number of characters stored into res (excluding null-byte).
*/
int str_trim_e(const char* str, char* res, size_t res_len);

#endif
# String Utils
A C library that provides common string operations that the standard library lacks.

## Features
- C89 compliant.
- Completely thread-safe.
- Immutability oriented.
- Well documented and easy to use.

## Installation
To install the library on your system as a static library using CMake:
```console
$ git clone https://github.com/crimilo/String-Utils.git
$ cd String-Utils && mkdir build && cd build
$ cmake .. && sudo make install
```

## Functions
| Name                 | Description                                                                                                     |
|----------------------|-----------------------------------------------------------------------------------------------------------------|
| `str_starts_w()`     | Checks whether a string starts with another string.                                                             |
| `str_starts_w_i()`   | Checks whether a string starts with another string case insensitive.                                            |
| `str_ends_w()`       | Checks whether a string ends with another string.                                                               |
| `str_ends_w_i()`     | Checks whether a string ends with another string case insensitive.                                              |
| `str_cmp_i()`        | Compares two strings case insensitive.                                                                          |
| `str_ncmp_i()`       | Compares two strings case insensitive. At most n characters are compared.                                       |
| `str_find()`         | Checks whether a string contains another string.                                                                |
| `str_find_i()`       | Checks whether a string contains another string case insensitive.                                               |
| `str_rfind()`        | Checks whether a string contains another string. The search starts from the end of the string.                  |
| `str_rfind_i()`      | Checks whether a string contains another string case insensitive. The search starts from the end of the string. |
| `str_substr()`       | Creates a substring from a string.                                                                              |
| `str_substr_cnt()`   | Count the number of substring occurrences in a string.                                                          |
| `str_substr_cnt_i()` | Count the number of substring occurrences in a string case insensitive.                                         |
| `str_split()`        | Splits a string into tokens.                                                                                    |
| `str_trim()`         | Removes white spaces, tabs and new line characters from the start and end of a string.                          |
| `str_trim_s()`       | Removes white spaces, tabs and new line characters from the start of a string.                                  |
| `str_trim_e()`       | Removes white spaces, tabs and new line characters from the end of a string.                                    |

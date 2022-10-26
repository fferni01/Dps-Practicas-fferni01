/**
 *
 * The student needs to compile, test and comment the source code file.
 *
 * Enumerate those Rules and Recommendation associated that are broken in the
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * gcc -Wall -Wextra -Wpedantic -std=c99 ejemplo1.c
 * gcc -Wall -Wextra -Wpedantic -std=c11 ejemplo1.c
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant
 *     selected (you can remove/change instructions).
 */
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char array1[] = "Foo"
                "bar";
char array2[] = {'F', 'o', 'o', 'b', 'a', 'r', '\0'};

enum
{
  BUFFER_MAX_SIZE = 1024
};
/* RECOMENDATIONS STR10-C & STR05-C*/
wchar_t const *s1 = L"foo("
  L"Hello"
  L"World"
  L")foo";
const char *s2 = "\nHello\nWorld\n";

void gets_example_func(void)
{
  char buf[BUFFER_MAX_SIZE];

  if (fgets(buf, sizeof(buf), stdin) == NULL)
  {
    //return 1
    exit(0);
  }
  buf[strlen(buf)] = '\0';
}

const char *get_dirname(const char *pathname)
{
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash)
  {
    *slash = '\0'; //Undefined behavior 
  }
  return pathname;
}
//STR30-C
/*char *get_dirname(const char *pathname, char *dirname, size_t size) {
  const char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    ptrdiff_t slash_idx = slash - pathname;
    if ((size_t)slash_idx < size) {
      memcpy(dirname, pathname, slash_idx);
      dirname[slash_idx] = '\0';     
      return dirname;
    }
  }
  return 0;
}*/

void get_y_or_n(void)
{
  char response[8];

  printf("Continue? [y] n: ");
  fgets(response, sizeof(response), stdin);

  if (response[0] == 'n')
    exit(0);

  return;
}

int main(int argc, char *argv[])
{

  if (3 != argc)
  {
    fprintf(stderr, "Usage: %s <option> <option>\n", argv[0]);
    exit(1);
  }

  char key[24];
  char response[8];
  char array3[16];
  char array4[16];
  char array5[] = "01234567890123456";
  //STR30-C
  char ptr_char[] = "new string literal";

  // wide characters

   //int size_array1 = strlen("аналитик");
  // int size_array2 = 100;
   //char analitic1 [size_array1];
   //analitic1 = "аналитик";
  // char analitic2[size_array2]="аналитик";
  char analitic3[100]="аналитик";
  printf("%ld",sizeof(analitic3));
 puts(get_dirname(__FILE__));
 
  /*char dirname[260];
  if (get_dirname(__FILE__, dirname, sizeof(dirname))) {
    puts(get_dirname(__FILE__, dirname, sizeof(dirname)));
  }*/
  //str35-c
  strncpy(key, argv[1], sizeof(key)-1);
  strncat(key, " = ",sizeof(key)-1);
  strncat(key, argv[2], sizeof(key)-1);
  key[sizeof(key)-1]='\0';
  puts(key);

  fgets(response, sizeof(response), stdin);
  get_y_or_n();

  printf("%s", array1);
  printf("\n");
  printf("%s", array2);
  printf("\n");

  printf("%ls",s1);
  printf("\n");
  puts(s2);
  printf("\n");

  strncpy(array3, array5, sizeof(array3));
  strncpy(array4, array3, strlen(array3));

  array5[0] = 'M';
  ptr_char[0] = 'N';
  puts(ptr_char);

  array3[sizeof(array3) - 1] = '\0';
  array4[sizeof(array4) - 1] = '\0';

  return 0;
}
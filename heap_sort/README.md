## Requirements

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be compiled on Ubuntu 14.04 LTS
*   Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
*   All your files should end with a new line
*   A `README.md` file, at the root of the folder of the project, is mandatory
*   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
*   You are not allowed to use global variables
*   No more than 5 functions per file
*   Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like _printf, puts, …_ is totally forbidden.
*   In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
*   The prototypes of all your functions should be included in your header file called `sort.h`
*   Don’t forget to push your header file
*   All your header files should be include guarded
*   A list/array does not need to be sorted if its size is less than 2.

## Tasks

### 1.

Write a function that sorts an array of integers in ascending order using the [Heap sort](/rltoken/eYby2kg2-B14tE9HaH3BJg "Heap sort") algorithm

*   Prototype: `void heap_sort(int *array, size_t size);`
*   You must implement the `sift-down` heap sort algorithm
*   You’re expected to print the `array` after each time you swap two elements (See example below)

Write in the file `0-O`, the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:

*   in the best case
*   in the average case
*   in the worst case
```
alex@/tmp/sort$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/\*\*
 \* main - Entry point
 \*
 \* Return: Always 0
 \*/
int main(void)
{
    int array\[\] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size\_t n = sizeof(array) / sizeof(array\[0\]);

    print\_array(array, n);
    printf("\\n");
    heap\_sort(array, n);
    printf("\\n");
    print\_array(array, n);
    return (0);
}
alex@/tmp/sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap\_sort.c print\_array.c -o 0-heap
alex@/tmp/sort$ ./0-heap
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 99, 86, 13, 52, 96, 73, 71, 7
19, 86, 99, 48, 13, 52, 96, 73, 71, 7
19, 86, 99, 73, 13, 52, 96, 48, 71, 7
99, 86, 19, 73, 13, 52, 96, 48, 71, 7
99, 86, 96, 73, 13, 52, 19, 48, 71, 7
7, 86, 96, 73, 13, 52, 19, 48, 71, 99
96, 86, 7, 73, 13, 52, 19, 48, 71, 99
96, 86, 52, 73, 13, 7, 19, 48, 71, 99
71, 86, 52, 73, 13, 7, 19, 48, 96, 99
86, 71, 52, 73, 13, 7, 19, 48, 96, 99
86, 73, 52, 71, 13, 7, 19, 48, 96, 99
48, 73, 52, 71, 13, 7, 19, 86, 96, 99
73, 48, 52, 71, 13, 7, 19, 86, 96, 99
73, 71, 52, 48, 13, 7, 19, 86, 96, 99
19, 71, 52, 48, 13, 7, 73, 86, 96, 99
71, 19, 52, 48, 13, 7, 73, 86, 96, 99
71, 48, 52, 19, 13, 7, 73, 86, 96, 99
7, 48, 52, 19, 13, 71, 73, 86, 96, 99
52, 48, 7, 19, 13, 71, 73, 86, 96, 99
13, 48, 7, 19, 52, 71, 73, 86, 96, 99
48, 13, 7, 19, 52, 71, 73, 86, 96, 99
48, 19, 7, 13, 52, 71, 73, 86, 96, 99
13, 19, 7, 48, 52, 71, 73, 86, 96, 99
19, 13, 7, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
13, 7, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alex@/tmp/sort$
```
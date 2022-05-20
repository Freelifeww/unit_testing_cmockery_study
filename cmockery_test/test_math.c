#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>
#include "cmockery.h"

extern int add(int a, int b);
extern int sub(int a, int b);

/* Ensure add() adds two integers correctly. */
void test_add(void **state) {
    assert_int_equal(add(3, 3), 6);
    assert_int_equal(add(3, -3), 0);
}

/* Ensure sub() subtracts two integers correctly.*/
void test_sub(void **state) {
    assert_int_equal(sub(3, 3), 0);
    assert_int_equal(sub(3, -3), 6);
}


int main(int argc, char *argv[]) 
{
    printf("----cmockery test main-----\n");
    const UnitTest tests[] =  {
        unit_test(test_add),
        unit_test(test_sub),
    };

    run_tests(tests);

    return 0;
}




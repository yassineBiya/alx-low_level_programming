#ifndef _VARIADIC_FUNCTIONS_
#define _VARIADIC_FUNCTIONS_

/**
 * struct op - A struct op.
 * @op: The operator.
 * @f: The function associated.
 */
typedef struct op
{
        char *op;
        int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif

#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>

/**
 * struct operation - Struct operation
 *
 * @op: The operator 
 * @func: The associated function
 *
 */
struct operation
{
	char *op;
	void (*func)(char *format, int *fi, int *pcc, va_list args);
};

/**
 * operation_t - Typedef for struct Operation
 */
typedef struct operation Operation_t;

int _putchar(char c);
int getArgC(char *str);
int _printf(char *format, ...);
void runESSSubroutine(char *format, int *fi, int *pcc);
void runFSSubroutine(char *format, int *fi, int *pcc, va_list args);
void printCharacter(int *pcc, va_list args);
void printString(int *pcc, va_list args);
void printPercentage(int *pcc);
void printInteger(int *pcc, va_list args);
void printEscapeCharacter(char *format, int *fi, int *pcc);
void printDefault(char *format, int *fi, int *pcc);
#endif /** MAIN_H  **/

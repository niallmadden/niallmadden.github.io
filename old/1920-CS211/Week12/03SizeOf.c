/* CS211  SizeOf.c */
#include <stdio.h>

typedef enum {Jan=1, Feb, Mar, Apr, May, Jun, 
    Jul, Aug, Sep, Oct, Nov, Dec} MONTH;
typedef struct 
{
  int DayofMonth;
  MONTH Month;
  int Year;
} Date;

int main(void )
{
  int x=-123,  *p;   char name[6]="CS211";  
  printf("A char takes      %3lu bytes;\n", 
    sizeof(char));
  printf("A float uses      %3lu bytes;\n", sizeof(float));
  printf("but a double uses %3lu bytes;\n",  sizeof(double));
  printf("x is requires     %3lu bytes;\n", sizeof(x));
  printf("A pointer needs   %3lu bytes;\n", sizeof(p));
  printf("Array %s is stored in %3lu bytes;\n", 
	 name, sizeof(name));
  printf("enum MONTH takes  %3lu bytes;\n", sizeof(MONTH));
  printf("struct Date takes %3lu bytes.\n", sizeof(Date));
  return(0);
}

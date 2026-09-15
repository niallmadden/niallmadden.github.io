// Taken from
// https://en.wikipedia.org/wiki/Page_(computer_memory)#Determining_the_page_size_in_a_program

#include <stdio.h>

/* Linux version */
#include <unistd.h> /* sysconf(3) */

int main(void) {
	printf("The page size for this system is %ld bytes.\n",
	       sysconf(_SC_PAGE_SIZE)); 
	return 0;
}


/* Windows  version */
/*
#include <windows.h>
int main(void) {
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  printf("The page size for this system is %u bytes.\n",
     si.dwPageSize);
  return 0;
}
*/

#include "launch.h"

#include <stdio.h>


#define UNUSED
#define UNUSED_T(str) (void) str
#ifdef __GNUC__
#undef UNUSED
#undef UNUSED_T
#define UNUSED __attribute__((unused))
#define UNUSED_T(str) 
#endif

int main(int argv UNUSED, char *argc[] UNUSED)
{
	UNUSED_T(argv);
	UNUSED_T(argc);

	runLoop();

	return 0;
}

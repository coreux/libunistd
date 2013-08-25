#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "../unistd.h"

int
main(int argc, char **argv)
{
	const char *str = "This is a test of write()\n";
	size_t len = 26;
	ssize_t r;

	(void) argc;
	(void) argv;

	/* Write str to stdout */
	r = write(1, str, len);
	if(r != len)
	{
		return 1;
	}
	return 0;
}

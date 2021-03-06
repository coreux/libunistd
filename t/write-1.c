/*
 * Copyright 2013 Mo McRoberts.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "../unistd.h"

#include <errno.h>

extern int dprintf(const char *fmt, ...);

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
	dprintf("r = %d, errno = %d\n", (int) r, (int) errno);
	if(r != (ssize_t) len)
	{
		return errno;
	}
	return 0;
}

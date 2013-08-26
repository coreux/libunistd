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

/*
http://pubs.opengroup.org/onlinepubs/009695399/basedefs/fcntl.h.html
*/

#ifndef __UX_FCNTL_H
# define __UX_FCNTL_H                  1

# include <ux/cdefs.h>
# include <ux/features.h>

# if _XOPEN_SOURCE >= 600
#  include <sys/stat.h>
#  include <unistd.h>
# endif

/* fcntl() cmd values */

/* fcntl() file descriptor flags */

/* fcntl() locking types */

# if _XOPEN_SOURCE >= 600
/* seek modes */
#  include <ux/const/seek.h>
# endif

/* open flags */

/* file status flags */

/* access modes mask */

/* access modes */

# if _XOPEN_SOURCE >= 600
/* file modes */
#  include <ux/const/mode.h>
# endif

# if __UX_OPT_ADV >= 0
/* posix_fadvise() advice values */
#  include <ux/const/advice.h>
# endif

/* mode_t and file mode values */
# include <ux/def/mode.h>

/* off_t */
# include <ux/def/off.h>

/* pid_t */
# include <ux/def/pid.h>

struct flock
{
	/* type of lock: F_RDLCK, F_WRLCK, or F_UNLCK */
	short l_type;
	/* offset mode */
	short l_whence;
	/* relative offset */
	off_t l_start;
	/* size (0 indicates until EOF) */
	off_t l_len;
	/* holder of the lock */
	pid_t l_pid;
};

__UX_BEGIN_DECLS

/* create a new file */
int creat(const char *path, mode_t mode) __UX_SYM03(creat);
/* perform control operations on an open file */
int fcntl(int fd, int cmd, ...) __UX_SYM03(fcntl);
/* open or create a file */
int open(const char *path, int oflag, ...) __UX_SYM03(open);

# if __UX_OPT_ADV >= 0
int posix_fadvise(int fd, off_t offset, off_t len, int advice) __UX_SYM03(posix_fadvise);
int posix_fallocate(int fd, off_t offset, off_t len) __UX_SYM03(posix_fallocate);
# endif

__UX_END_DECLS

#endif /*!__UX_FCNTL_H*/

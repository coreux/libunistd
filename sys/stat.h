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

http://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/stat.h.html

*/

#ifndef __UX_SYS_STAT_H
# define __UX_SYS_STAT_H               1

# include <ux/cdefs.h>

/* blkcnt_t: Used for file block counts */
/* blksize_t: Used for block sizes */
# include <ux/def/block.h>

/* dev_t: Used for device IDs */
# include <ux/def/dev.h>

/* gid_t: Used for group IDs */
/* uid_t: Used for user IDs */

# include <ux/def/ugid.h>

/* ino_t: Used for file serial numbers */
# include <ux/def/ino.h>

/* mode_t: Used for some file attributes */
# include <ux/def/mode.h>

/* nlink_t: Used for link counts */
# include <ux/def/nlink.h>

/* off_t: Used for file sizes */
# include <ux/def/off.h>

/* time_t: Used for time in seconds */
# include <ux/def/time.h>

/* struct stat */
struct stat
{
	dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
#if _XOPEN_SOURCE >= 600
	dev_t st_rdev;
#else
	dev_t __ux_reserved0;
#endif
	off_t st_size;
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
#if _XOPEN_SOURCE >= 600
	blksize_t st_blksize;
	blkcnt_t st_blocks;
#else
	blksize_t __ux_reserved1;
	blkcnt_t __ux_reserved2;
#endif
};

/* mode_t constants */
# include <ux/const/mode.h>

__UX_BEGIN_DECLS

int chmod(const char *, mode_t) __UX_SYM03(chmod);
int fchmod(int, mode_t) __UX_SYM03(fchmod);
int fstat(int, struct stat *) __UX_SYM03(fstat);
int lstat(const char *restrict, struct stat *restrict) __UX_SYM03(lstat);
int mkdir(const char *, mode_t) __UX_SYM03(mkdir);
int mkfifo(const char *, mode_t) __UX_SYM03(mkfifo);
# if _XOPEN_SOURCE >= 600
int mknod(const char *, mode_t, dev_t) __UX_SYM03(mknod);
# endif
int stat(const char *restrict, struct stat *restrict) __UX_SYM03(stat);
mode_t umask(mode_t) __UX_SYM03(umask);

__UX_END_DECLS

#endif /*!__UX_SYS_STAT_H*/

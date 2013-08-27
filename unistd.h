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
http://pubs.opengroup.org/onlinepubs/009695399/basedefs/unistd.h.html
*/

#ifndef __UX_UNISTD_H
# define __UX_UNISTD_H                 1

# include <ux/cdefs.h>
# include <ux/features.h>

# if defined(__UX_darwin__)
#  include <ux/darwin/unistd.h>
# elif defined(__UX_linux__)
#  include <ux/linux/unistd.h>
# else
#  error Unsupported host kernel
# endif

/* version test macros */

# define _POSIX_VERSION                __UX_POSIX_VERSION
# define _POSIX2_VERSION               __UX_POSIX_VERSION
# define _XOPEN_VERSION                __UX_XOPEN_VERSION

/* constants for options and option groups */

/* execution-time symbolic constants */

/* constants for functions */

# include <ux/const/null.h>

/* symbolic constants for use with access() */

# ifndef F_OK
/* test for existence of file */
#  define F_OK                         0
/* test for execute permission */
#  define X_OK                         (1<<0)
/* test for write permission */
#  define W_OK                         (1<<1)
/* test for read permission */
#  define R_OK                         (1<<2)
# endif

/* symbolic constants for use with confstr() */

/* seek mode constants */

# include <ux/const/seek.h>

/* symbolic constants for use with lockf() */

/* symbolic constants for use with pathconf() */

/* symbolic constants for use with sysconf() */

/* file numbers */

# define STDERR_FILENO                 2
# define STDIN_FILENO                  0
# define STDOUT_FILENO                 1

/* size_t: Unsigned integer type of the result of the sizeof operator */
# include <ux/def/size.h>

/* ssize_t: Used for a count of bytes or error indication */
# include <ux/def/ssize.h>

/* gid_t: Used for group IDs */
/* uid_t: Used for user IDs */
#include <ux/def/ugid.h>

/* off_t: Used for file sizes */
# include <ux/def/off.h>

/* pid_t: Used for process IDs and process group IDs */
# include <ux/def/pid.h>

# if _XOPEN_SOURCE >= 600

/* suseconds_t: Used for time in microseconds */
/* useconds_t: Used for for time in microseconds */
#  include <ux/def/useconds.h>

/* intptr_t: integer type capable of holding object pointers */
#  include <ux/def/intptr.h>

# endif

__UX_BEGIN_DECLS

extern char *optarg __UX_SYM03(optarg);
extern int optind __UX_SYM03(optind);
extern int opterr __UX_SYM03(opterr);
extern int optopt __UX_SYM03(optopt);

/* determine accessibility of a file */
int access(const char *path, int amode) __UX_SYM03(access);
/* schedule an alarm signal */
unsigned alarm(unsigned seconds) __UX_SYM03(alarm);
int chdir(const char *) __UX_SYM03(chdir);
int chown(const char *, uid_t, gid_t) __UX_SYM03(chown);
int close(int) __UX_SYM03(close);
size_t confstr(int, char *, size_t) __UX_SYM03(confstr);
# if _XOPEN_SOURCE >= 600
char *crypt(const char *, const char *) __UX_SYM03(crypt);
char *ctermid(char *) __UX_SYM03(ctermid);
# endif
int dup(int) __UX_SYM03(dup);
int dup2(int, int) __UX_SYM03(dup2);
# if _XOPEN_SOURCE >= 600
void encrypt(char[64], int) __UX_SYM03(encrypt);
# endif
int execl(const char *, const char *, ...) __UX_SYM03(execl);
int execle(const char *, const char *, ...) __UX_SYM03(execle);
int execlp(const char *, const char *, ...) __UX_SYM03(execlp);
int execv(const char *, char *const []) __UX_SYM03(execv);
int execve(const char *, char *const [], char *const []) __UX_SYM03(execve);
int execvp(const char *, char *const []) __UX_SYM03(execvp);
void _exit(int) __UX_SYM03(_exit) __UX_NORETURN;
int fchown(int, uid_t, gid_t) __UX_SYM03(fchown);
# if _XOPEN_SOURCE >= 600
int fchdir(int) __UX_SYM03(fchdir);
# endif
# if __UX_OPT_SIO >= 0
int fdatasync(int) __UX_SYM03(fdatasync);
# endif
pid_t fork(void) __UX_SYM03(fork);
long fpathconf(int, int) __UX_SYM03(fpathconf);
# if __UX_OPT_FSC >= 0
int fsync(int) __UX_SYM03(fsync);
# endif
int ftruncate(int, off_t) __UX_SYM03(ftruncate);
char *getcwd(char *, size_t) __UX_SYM03(getcwd);
gid_t getegid(void) __UX_SYM03(getegid);
uid_t geteuid(void) __UX_SYM03(geteuid);
gid_t getgid(void) __UX_SYM03(getgid);
int getgroups(int, gid_t []) __UX_SYM03(getgroups);
# if _XOPEN_SOURCE >= 600
long gethostid(void) __UX_SYM03(gethostid);
# endif
int gethostname(char *, size_t) __UX_SYM03(gethostname);
char *getlogin(void) __UX_SYM03(getlogin);
int getlogin_r(char *, size_t) __UX_SYM03(getlogin_r);
int getopt(int, char * const [], const char *) __UX_SYM03(getopt);
# if _XOPEN_SOURCE >= 600
pid_t getpgid(pid_t) __UX_SYM03(getpgid);
# endif
pid_t getpgrp(void) __UX_SYM03(getpgrp);
pid_t getpid(void) __UX_SYM03(getpid);
pid_t getppid(void) __UX_SYM03(getppid);
# if _XOPEN_SOURCE >= 600
pid_t getsid(pid_t) __UX_SYM03(getsid);
# endif
uid_t getuid(void) __UX_SYM03(getuid);
# if _XOPEN_SOURCE >= 600
char *getwd(char *) __UX_SYM03(getwd) __UX_LEGACY;
# endif
int isatty(int) __UX_SYM03(isatty);
# if _XOPEN_SOURCE >= 600
int lchown(const char *, uid_t, gid_t) __UX_SYM03(lchown);
# endif
int link(const char *, const char *) __UX_SYM03(link);
# if _XOPEN_SOURCE >= 600
int lockf(int, int, off_t) __UX_SYM03(lockf);
# endif
off_t lseek(int, off_t, int) __UX_SYM03(lseek);
# if _XOPEN_SOURCE >= 600
int nice(int) __UX_SYM03(nice);
# endif
long pathconf(const char *, int) __UX_SYM03(pathconf);
int pause(void) __UX_SYM03(pause);
int pipe(int [2]) __UX_SYM03(pipe);
# if _XOPEN_SOURCE >= 600
ssize_t pread(int, void *, size_t, off_t) __UX_SYM03(pread);
ssize_t pwrite(int, const void *, size_t, off_t) __UX_SYM03(pwrite);
# endif
ssize_t read(int, void *, size_t) __UX_SYM03(read);
ssize_t readlink(const char *restrict, char *restrict, size_t) __UX_SYM03(readlink);
int rmdir(const char *) __UX_SYM03(rmdir);
int setegid(gid_t) __UX_SYM03(setegid);
int seteuid(uid_t) __UX_SYM03(seteuid);
int setgid(gid_t) __UX_SYM03(setgid);
int setpgid(pid_t, pid_t) __UX_SYM03(setpgid);
# if _XOPEN_SOURCE >= 600
pid_t setpgrp(void) __UX_SYM03(setpgrp);
int setregid(gid_t, gid_t) __UX_SYM03(setregid);
int setreuid(uid_t, uid_t) __UX_SYM03(setreuid);
# endif
pid_t setsid(void) __UX_SYM03(setsid);
int setuid(uid_t) __UX_SYM03(setuid);
unsigned sleep(unsigned) __UX_SYM03(sleep);
# if _XOPEN_SOURCE >= 600
void swab(const void *restrict, void *restrict, ssize_t) __UX_SYM03(swab);
# endif
int symlink(const char *, const char *) __UX_SYM03(symlink);
# if _XOPEN_SOURCE >= 600
/* schedule file system updates */
void sync(void) __UX_SYM03(sync);
# endif
long sysconf(int) __UX_SYM03(sysconf);
pid_t tcgetpgrp(int) __UX_SYM03(tcgetpgrp);
int tcsetpgrp(int, pid_t) __UX_SYM03(tcsetpgrp);
# if _XOPEN_SOURCE >= 600
int truncate(const char *, off_t) __UX_SYM03(truncate);
# endif
char *ttyname(int) __UX_SYM03(ttyname);
int ttyname_r(int, char *, size_t) __UX_SYM03(ttyname_r);
# if _XOPEN_SOURCE >= 600
useconds_t ualarm(useconds_t, useconds_t) __UX_SYM03(ualarm);
# endif
int unlink(const char *) __UX_SYM03(unlink);
# if _XOPEN_SOURCE >= 600
int usleep(useconds_t) __UX_SYM03(usleep);
pid_t vfork(void) __UX_SYM03(vfork);
# endif
/* write to a file descriptor */
ssize_t write(int fd, const void *buf, size_t buflen) __UX_SYM03(write);

__UX_END_DECLS

#endif /*!__UX_UNISTD_H*/

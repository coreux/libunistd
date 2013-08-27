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

#ifndef P_LIBUNISTD_H_
# define P_LIBUNISTD_H_                

# include <ux/cdefs.h>

# include "errno.h"

# include "fcntl.h"
# include "signal.h"
# include "ucontext.h"
# include "ulimit.h"
# include "unistd.h"
# include "utime.h"
# include "sys/ipc.h"
# include "sys/msg.h"
# include "sys/resource.h"
# include "sys/sem.h"
# include "sys/shm.h"
# include "sys/stat.h"
# include "sys/statvfs.h"
# include "sys/time.h"
# include "sys/timeb.h"
# include "sys/times.h"
# include "sys/uio.h"
# include "sys/utsname.h"
# include "sys/wait.h"

extern char *optarg_ux2003 __UX_SYM03(optarg);
extern int optind_ux2003 __UX_SYM03(optind);
extern int opterr_ux2003 __UX_SYM03(opterr);
extern int optopt_ux2003 __UX_SYM03(optopt);

int access_ux2003(const char *path, int amode) __UX_SYM03(access) __UX_WEAK;
unsigned alarm_ux2003(unsigned seconds) __UX_SYM03(alarm) __UX_WEAK;

int close_ux2003(int fd) __UX_SYM03(close) __UX_WEAK;

int open_ux2003(const char *pathname, int oflag, ...) __UX_SYM03(open) __UX_WEAK;

void sync_ux2003(void) __UX_SYM03(sync) __UX_WEAK;

int unlink_ux2003(const char *pathname) __UX_SYM03(unlink) __UX_WEAK;

ssize_t write_ux2003(int fd, const void *buf, size_t buflen) __UX_SYM03(write) __UX_WEAK;

#endif /*!P_LIBERRNO_H_*/

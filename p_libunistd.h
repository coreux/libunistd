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

void sync_ux2003(void) __UX_SYM03(sync) __UX_WEAK;
ssize_t write_ux2003(int fd, const void *buf, size_t buflen) __UX_SYM03(write) __UX_WEAK;

#endif /*!P_LIBERRNO_H_*/

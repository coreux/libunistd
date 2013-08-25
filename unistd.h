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
# include <ux/sizedef.h>
# include <ux/ssizedef.h>

__UX_BEGIN_DECLS

# if _XOPEN_SOURCE >= 600
void sync(void) __UX_SYM03(sync);
# endif

ssize_t write(int fd, const void *buf, size_t buflen) __UX_SYM03(write);

__UX_END_DECLS

#endif /*!__UX_UNISTD_H*/

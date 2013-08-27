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

#ifndef __UX_DARWIN_FCNTL_H
# define __UX_DARWIN_FCNTL_H           1

/* fcntl() cmd values */

/* fcntl() file descriptor flags */

/* fcntl() locking types */

/* open flags */

/* create file if it does not exist */
# define O_CREAT                       0x000200
/* exclusive use flag */
# define O_EXCL                        0x000800
/* do not assign controlling terminal */
# define O_NOCTTY                      0x020000
/* truncate flag */
# define O_TRUNC                       0x000400
/* set append mode */
# define O_APPEND                      0x000008
# if __UX_OPT_SIO >= 0
/* write according to synchronized I/O data integrity completion */
#  define O_DSYNC                      0x400000
# endif
/* non-blocking mode */
# define O_NONBLOCK                    0x000004
# if __UX_OPT_SIO >= 0
/* synchronised read I/O operations */
#  define O_RSYNC                      0x000000
/* file status flags */
# endif
/* write according to synchronized I/O file integrity completion */
# define O_SYNC                        0x000080

/* access modes mask */

# define O_ACCMODE                     0x000003

/* access modes */

/* open for reading */
# define O_RDONLY                      0x000000
/* open for writing */
# define O_WRONLY                      0x000001
/* open for reading and writing */
# define O_RDWR                        0x000002

#endif /*__UX_DARWIN_FCNTL_H*/

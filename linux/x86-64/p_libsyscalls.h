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

#ifndef P_LIBSYSCALLS_H_
# define P_LIBSYSCALLS_H_              1

# include <ux/cdefs.h>

# define ENTRY_UX03(name) \
	.text ; .globl name##$UX$2003  ; .type name,%function

# define END_UX03(name) \
	.size name##$UX$2003,.-name##$UX$2003

/* The SysV ABI specifies that errors are returned with a value between
 * between -1 and -4095, constituting -errno
 */
# define SET_ERRNO \
	cmpq $-4095, %rax ; \
	jae set_errno$UX$private

# define SYS_sync                      162

#endif /*!P_LIBSYSCALLS_H_*/
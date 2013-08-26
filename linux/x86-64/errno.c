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

#include <ux/cdefs.h>

#if !defined(WITH_UX_ERRNO) && defined(__UX_linux__) && defined(__UX_x86_64__)

#include <stdio.h>
#include <errno.h>

/* Provide an equivalent of set_errno$UX$private */
int set_errno(int err) __UX_PRIVATE(set_errno);

int
set_errno(int err)
{
	int *p;
	
	p = __errno_location();
	*p = err;
	return -1;
}

#endif /* !WITH_UX_ERRNO */

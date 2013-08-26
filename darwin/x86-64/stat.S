/* Generated automatically by gen-syscalls.pl */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "p_libsyscalls.h"

#if defined(__UX_darwin__) && defined(__UX_x86_64__)

ENTRY_PRIVATE(stat)
	SYSCALL_PREAMBLE
	PERFORM_SYSCALL2(stat)
	HANDLE_ERRNO
	ret
	SYSCALL_POSTAMBLE
END_PRIVATE(stat)

#endif

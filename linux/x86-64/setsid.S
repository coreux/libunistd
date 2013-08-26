/* Generated automatically by gen-syscalls.pl */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "p_libsyscalls.h"

#if defined(__UX_linux__) && defined(__UX_x86_64__)

ENTRY_UX03(setsid)
	SYSCALL_PREAMBLE
	PERFORM_SYSCALL0(setsid)
	HANDLE_ERRNO
	ret
	SYSCALL_POSTAMBLE
END_UX03(setsid)

#endif

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

# include "p_callnums.h"

/* Linux is an ELF platform:
 *   local labels are prefixed with 'L'
 *   C-linkage symbols are not prefixed with an underscore
 *
 * On x86-64:
 *   System call numbers are passed in %eax
 *   Parameters are passed in %rdi, %rsi, %rdx, %r10, %r8 and %r9
 *   The kernel destroys %rcx and %r10
 *   The result is returned in %rax
 *   Return values between -4095 and -1 are -errno
 *   User calls pass parameters in %rdi, %rsi, %rdx, %rcx, %r8 and %r9
 */

# define ENTRY(name) \
	.text ; .globl name  ; .type name,@function ; .align 1<<4 ; name:
# define END(name) \
	.size name, .-name

# define ENTRY_SUF(name, suffix)       ENTRY(name##suffix)
# define END_SUF(name, suffix)         END(name##suffix)

# define ENTRY_UX03(name)              ENTRY_SUF(name,$UX$2003)
# define END_UX03(name)                END_SUF(name,$UX$2003)

# define ENTRY_PRIVATE(name)           ENTRY_SUF(name,$UX$private)
# define END_PRIVATE(name)             END_SUF(name,$UX$private)

# define HANDLE_ERRNO \
	cmpq $-4095, %rax ; \
	jae .Lerrno ; \
	.Lend:

# define SYSCALL_PREAMBLE
# define SYSCALL_POSTAMBLE \
	.Lerrno: \
	mov %rsp, %rdx ; \
	and $0xfffffffffffffff0, %rsp ; \
	sub $0x10, %rsp ; \
	mov %rdx, (%rsp) ; \
	mov %rax, %rdi ; \
	neg %rdi ; \
	call set_errno$UX$private ; \
	mov (%rsp), %rsp ; \
	movq $-1, %rax ; \
	jmp .Lend ;

# define PERFORM_SYSCALL0(name) \
	movl $SYS_##name, %eax ; \
	syscall
# define PERFORM_SYSCALL1(name)        PERFORM_SYSCALL0(name)
# define PERFORM_SYSCALL2(name)        PERFORM_SYSCALL0(name)
# define PERFORM_SYSCALL3(name)        PERFORM_SYSCALL0(name)
# define PERFORM_SYSCALL4(name) \
	movq %rcx, %r10 ; \
	PERFORM_SYSCALL0(name)
# define PERFORM_SYSCALL5(name) \
	movq %rcx, %r10 ; \
	PERFORM_SYSCALL0(name)
# define PERFORM_SYSCALL6(name) \
	movq %rcx, %r10 ; \
	PERFORM_SYSCALL0(name)

#endif /*!P_LIBSYSCALLS_H_*/

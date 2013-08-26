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
http://pubs.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html
*/

#ifndef __UX_SIGNAL_H
# define __UX_SIGNAL_H                 1

# include <ux/cdefs.h>
# include <ux/features.h>

/* default signal handlers */

/* sig_atomic_t */

/* sigset_t */
# include <ux/def/sigset.h>

/* pid_t */
# include <ux/def/pid.h>

# if __UX_OPT_RTS >=0

/* sigev_notify values */

/* union sigval */

union sigval
{
	int sigval_int;
	void *sigval_ptr;
};

/* struct sigevent */
struct sigevent
{
	/* notification type */
	int sigev_notify;
	int sigev_signo;
	union sigval sigev_value;
	void (*sigev_notify_function)(union sigval);
	pthread_attr_t *sigev_notify_attributes;
};

/* user application real-time signal range, SIGRTMIN...SIGRTMAX */

# endif

/* signal numbers */

/* sigaction constants */

# if _XOPEN_SOURCE >= 600
/* ucontext_t, mcontext_t */
/* #  include <ux/def/context.h> */
# endif

/* stack_t */

typedef struct __ux_stack_struct stack_t;

struct __ux_stack_struct
{
	/* stack pointer */
	void *ss_sp;
	/* stack size */
	size_t ss_size;
	/* flags */
	int ss_flags;
};

/* struct sigstack */

struct sigstack
{
	/* non-zero when in use */
	int ss_onstack;
	/* stack pointer */
	void *ss_sp;
};

/* siginfo_t */

typedef struct __ux_siginfo_struct siginfo_t;

struct __ux_siginfo_struct
{
	/* signal number */
	int si_signo;
	/* signal code */
	int si_code;
# if _XOPEN_SOURCE >= 600
	/* associated errno value */
	int si_errno;
	/* sending process ID */
	pid_t si_pid;
	/* real user ID of sending process */
	uid_t si_uid;
	/* address of faulting instruction */
	void *si_addr;
	/* exit value */
	int si_status;
	/* SIGPOLL band event */
	long si_band;
# else
	int __ux_reserved0;
	pid_t __ux_reserved1;
	uid_t __ux_reserved2;
	void *__ux_reserved3;
	int __ux_reserved4;
	long __ux_reserved5;
# endif
# if __UX_OPT_RTS >= 0
	union sigval si_value;
# else
	int __ux_reserved6;
# endif
};

/* siginfo code values */

/* struct sigaction */

struct sigaction
{
	/* signal-catching function or SIG_xxx */
	union
	{
		void (*sa_handler)(int);
		void (*sa_sigaction)(int, siginfo_t *, void *);
	};
	/* mask of signals to block during execution of handler */
	sigset_t sa_mask;
	/* signal handling flags */
	int sa_flags;
};

__UX_BEGIN_DECLS

# if _XOPEN_SOURCE >= 600
void (*bsd_signal(int, void (*)(int)))(int) __UX_SYM03(bsd_signal);
# endif
int kill(pid_t, int) __UX_SYM03(signal);
# if _XOPEN_SOURCE >= 600
int killpg(pid_t, int) __UX_SYM03(killpg);
# endif
# if __UX_OPT_THR >= 0
int pthread_kill(pthread_t, int) __UX_SYM03(pthread_kill);
int pthread_sigmask(int, const sigset_t *, sigset_t *) __UX_SYM03(pthread_sigmask);
# endif
int raise(int) __UX_SYM03(raise);
int sigaction(int, const struct sigaction *restrict, struct sigaction *restrict) __UX_SYM03(sigaction);
int sigaddset(sigset_t *, int) __UX_SYM03(sigaddset);
# if _XOPEN_SOURCE >= 600
int sigaltstack(const stack_t *restrict, stack_t *restrict) __UX_SYM03(sigaltstack);
# endif
int sigdelset(sigset_t *, int) __UX_SYM03(sigdelset);
int sigemptyset(sigset_t *) __UX_SYM03(sigemptyset);
int sigfillset(sigset_t *) __UX_SYM03(sigfillset);
# if _XOPEN_SOURCE >= 600
int sighold(int) __UX_SYM03(sighold);
int sigignore(int) __UX_SYM03(sigignore);
int siginterrupt(int, int) __UX_SYM03(siginterrupt);
# endif
int sigismember(const sigset_t *, int) __UX_SYM03(sigismember);
void (*signal(int, void (*)(int)))(int) __UX_SYM03(signal);
# if _XOPEN_SOURCE >= 600
int sigpause(int) __UX_SYM03(sigpause);
# endif
int sigpending(sigset_t *) __UX_SYM03(sigpending);
int sigprocmask(int, const sigset_t *restrict, sigset_t *restrict) __UX_SYM03(sigprocmask);
# if __UX_OPT_RTS >= 0
int sigqueue(pid_t, int, const union sigval) __UX_SYM03(sigqueue);
# endif
# if _XOPEN_SOURCE >= 600
int sigrelse(int) __UX_SYM03(sigrelse);
void (*sigset(int, void (*)(int)))(int) __UX_SYM03(sigset);
# endif
int sigsuspend(const sigset_t *) __UX_SYM03(sigsuspend);
# if __UX_OPT_RTS >= 0
int sigtimedwait(const sigset_t *restrict, siginfo_t *restrict, const struct timespec *restrict) __UX_SYM03(sigtimedwait);
# endif
int sigwait(const sigset_t *restrict, int *restrict) __UX_SYM03(sigwait);
# if __UX_OPT_RTS >= 0
int sigwaitinfo(const sigset_t *restrict, siginfo_t *restrict __UX_SYM03(sigwaitinfo);
# endif

__UX_END_DECLS

#endif /*!__UX_SIGNAL_H*/

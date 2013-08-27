## Copyright 2013 Mo McRoberts.
##
##  Licensed under the Apache License, Version 2.0 (the "License");
##  you may not use this file except in compliance with the License.
##  You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
##  Unless required by applicable law or agreed to in writing, software
##  distributed under the License is distributed on an "AS IS" BASIS,
##  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
##  See the License for the specific language governing permissions and
##  limitations under the License.

AC_INIT([libunistd],[master],[https://github.com/coreux/libunistd/issues],,[https://github.com/coreux/libunistd])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_MACRO_DIR([.])
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
BT_PROG_XCODE
AC_PROG_CC
AC_PROG_CC_C99
BT_PROG_CC_WARN
AM_PROG_AS
CCASFLAGS="\${CFLAGS} -DASSEMBLY"
AC_SUBST([CCASFLAGS])
BT_ENABLE_XSI
AC_CONFIG_HEADER([config.h])
LT_INIT

AC_ARG_WITH([ux],[AS_HELP_STRING([--with-ux=PREFIX],[Specify UX installation prefix])],[ux_prefix="$withval"],[ux_prefix="yes"])
if test x"$ux_prefix" = x"no" ; then
	true
elif test x"$ux_prefix" = x"yes" ; then
	old_prefix="$prefix"
	old_exec_prefix="$exec_prefix"
	if test x"$prefix" = x"NONE" ; then
		prefix="$ac_default_prefix"
	fi
	if test x"$exec_prefix" = x"NONE" ; then
		exec_prefix="$prefix"
	fi
	uxincdir=`eval echo $includedir`
	if test -d "$uxincdir/ux" && test -r "$uxincdir/ux/cdefs.h" ; then
		UX_CPPFLAGS="$UX_CPPFLAGS -I`eval echo $includedir`"
	fi
	prefix="$old_prefix"
	exec_prefix="$old_exec_prefix"
else
	UX_CPPFLAGS="$UX_CPPFLAGS -I$ux_prefix/include"
fi
AC_SUBST([UX_CPPFLAGS])
old_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$UX_CPPFLAGS"
AC_CHECK_HEADER([ux/cdefs.h],,[AC_MSG_ERROR([cannot locate required ux/cdefs.h; ensure the UX include package is installed])],[-])
CPPFLAGS="$old_CPPFLAGS"

CPPFLAGS="$UX_CPPFLAGS"
AC_CHECK_HEADER([errno.h],,[AC_MSG_ERROR([cannot locate required errno.h])],[-])
AC_CHECK_DECL([__ux_get_errno],[
  AC_DEFINE_UNQUOTED([WITH_UX_ERRNO],[1],[Define if using UX errno.h])
],,[#include <errno.h>])
CPPFLAGS="$old_CPPFLAGS"

# Override docdir
if test x"$docdir" = x'${datarootdir}/doc/${PACKAGE_TARNAME}' ; then
	docdir='${datarootdir}/doc/ux'
fi

AC_PATH_PROG([PERL], [perl], [perl])
AC_SUBST([PERL])

AC_CANONICAL_HOST

case "$host_os" in
	linux-*)
		ux_kern=linux
		;;
	darwin1*)
		ux_kern=darwin
		;;
	*)
		ux_kern="$host_os"
		;;
esac
AC_SUBST([ux_kern])
case "$host_cpu" in
	amd64|x86_64)
		ux_arch=x86-64
		;;
	i[3456]86|ix86|x86)
		ux_arch=x86
		;;
esac
AC_SUBST([ux_arch])

AC_DEFUN([UX_CHECK_SYSCALL],[
	AC_MSG_CHECKING([for the $ux_kern/$ux_arch/$1])
	if test -r "$srcdir/$ux_kern/$ux_arch/$1.c" || test -r "$srcdir/$ux_kern/$ux_arch/$1.S" ; then
		AC_MSG_RESULT([yes])
		AC_DEFINE_UNQUOTED([HAVE_SYS_$1],[1],[Define if the $1 system call is present])
	else
		AC_MSG_RESULT([no])
	fi
])
m4_include([syscalls.m4])

AC_CONFIG_FILES([Makefile
t/Makefile
stubs/Makefile
ux/Makefile
ux/linux/Makefile
ux/darwin/Makefile
linux/Makefile
linux/x86-64/Makefile
darwin/Makefile
darwin/x86-64/Makefile
])

AC_OUTPUT

case "$ux_kern" in
	darwin)
		AC_MSG_WARN([the system call interface between Darwin user-space and the XNU kernel is subject to change by Apple at any point, including minor releases, and should be considered unstable.])
		;;
esac

	

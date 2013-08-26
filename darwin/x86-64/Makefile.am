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

EXTRA_DIST = syscalls.conf

noinst_LTLIBRARIES = libsyscalls.la

libsyscalls_la_SOURCES = p_libsyscalls.h p_callnums.h errno.c \
	_exit.S access.S chdir.S chmod.S chown.S close.S dup.S dup2.S execve.S \
	fchdir.S fchmod.S fchown.S fcntl.S fdatasync.S fork.S fpathconf.S fstat.S \
	fsync.S ftruncate.S getegid.S geteuid.S getgid.S getgroups.S getlogin.S \
	getpgid.S getpgrp.S getpid.S getppid.S getsid.S getuid.S lchown.S \
	link.S lseek.S lstat.S mkdir.S mkfifo.S mknod.S open.S pathconf.S \
	pipe.S pread.S pwrite.S read.S readlink.S rmdir.S setegid.S seteuid.S \
	setgid.S setpgid.S setregid.S setreuid.S setsid.S setuid.S stat.S \
	symlink.S sync.S truncate.S umask.S unlink.S vfork.S write.S

libsyscalls_la_CPPFLAGS = @AM_CPPFLAGS@ @UX_CPPFLAGS@

p_callnums.h: ${srcdir}/syscalls.conf ${top_srcdir}/gen-syscalls.pl
	${PERL} ${top_srcdir}/gen-syscalls.pl darwin x86_64 < ${srcdir}/syscalls.conf

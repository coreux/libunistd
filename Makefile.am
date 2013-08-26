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

ACLOCAL_AMFLAGS = -I .

EXTRA_DIST = regen-acinclude.sh README \
	test.pl tests.conf \
	gen-syscalls.pl syscalls.conf syscalls.m4

SUBDIRS = linux . t

noinst_LTLIBRARIES = libunistd.la

libunistd_la_SOURCES = p_libunistd.h \
	sync.c write.c

libunistd_la_LIBADD = \
	linux/x86-64/libsyscalls.la

libunistd_la_CPPFLAGS = @AM_CPPFLAGS@ @UX_CPPFLAGS@

dist_doc_DATA = LICENSE-2.0

tests: all
	$(PERL) ${srcdir}/test.pl < ${srcdir}/tests.conf

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
##

AM_CPPFLAGS = @AM_CPPFLAGS@ @UX_CPPFLAGS@ -I${top_builddir} -I${top_srcdir}

LDADD = libutil.la ${top_builddir}/libunistd.la

noinst_PROGRAMS = \
	write-1 write-2 open-1 unlink-1

noinst_LTLIBRARIES = libutil.la

libutil_la_SOURCES = dprintf.c

libutil_la_CPPFLAGS = @AM_CPPFLAGS@

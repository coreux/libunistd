#! /bin/sh

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

# This script regenerates acinclude.m4 from a checked out copy of the m4
# macro repository. See:
#
# https://github.com/nevali/m4.git
#
# It should only be necessary to change this script when the list of macro
# files to be included, or the macros themselves, change.

if test x"$1" = x"" ; then
	echo "Usage: $0 M4DIR" >&2
	exit 1
fi

cat \
	"$1/xcode.m4" \
	"$1/cc.m4" \
	"$1/posix.m4" \
	>acinclude.m4
exit $?

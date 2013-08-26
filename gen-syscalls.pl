#! /usr/bin/env perl -w

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

use Config;
use Date::Format;

if($#ARGV != 1)
{
	print STDERR "Usage: $0 KERNEL ARCH\n";
	exit 1;
}
my $kern = $ARGV[0];
my $arch = $ARGV[1];

open(my $output, '>', "p_callnums.h");

print $output "/* Generated automatically by gen-syscalls.pl */\n\n";
print $output "#ifndef P_CALLNUMS_H_\n";
print $output "# define P_CALLNUMS_H_                 1\n\n";

while(<STDIN>)
{
	if(/^#/ || /^\s+$/s)
	{
		next;
	}
	my ($name, $nargs, $num, $namespace) = split(/\s+/);
	$num ||= "X";
	$namespace ||= "UX03";
	if($num eq "X")
	{
		next;
	}
	printf $output "# define SYS_%-25s %d\n", $name, $num;
	open(my $call, '>', "$name.S");
	print $call "/* Generated automatically by gen-syscalls.pl */\n\n";
	print $call "#ifdef HAVE_CONFIG_H\n";
	print $call "# include \"config.h\"\n";
	print $call "#endif\n\n";
	print $call "#include \"p_libsyscalls.h\"\n\n";
	print $call "#if defined(__UX_" . $kern . "__) && defined(__UX_" . $arch . "__)\n\n";
	print $call "ENTRY_$namespace($name)\n";
	print $call "\tSYSCALL_PREAMBLE\n";
	print $call "\tPERFORM_SYSCALL$nargs($name)\n";
	print $call "\tHANDLE_ERRNO\n";
	print $call "\tret\n";
	print $call "\tSYSCALL_POSTAMBLE\n";
	print $call "END_$namespace($name)\n\n";
	print $call "#endif\n";
	close($call);
}

print $output "\n#endif /*!P_CALLNUMS_H_*/\n";

close($output);

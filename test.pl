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

open(my $output, ">&STDOUT");
open(STDOUT, '>', "tests.log");
open(STDERR, ">&STDOUT");

@signals = split(' ', $Config{sig_name});
%siglist = ();
$n = 0;
$err = 0;
foreach(@signals)
{
	$siglist{$_} = $n;
	$n++;
}

print $output "Running tests: ";
$now = time2str("%Y-%m-%d %H:%M:%S", time);
print "Beginning test run at $now\n";
print "\n-----------------------------------------------------------------------------\n\n";

while(<>)
{
	if(/^#/ || /^\s+$/s)
	{
		next;
	}
	my ($prog, $expected, $status) = split(/\s+/);
	my $result = 0;
	my $outcome = 'ERR';
	my $indicator = '!';
	
	$expected ||= "PASS";
	$status ||= 0;
	if($status =~ /^-([a-z].*)$/i)
	{
		$signame = $1;
		if(defined $siglist{$signame})
		{
			$signum = $siglist{$signame};
			$status = -$signum;
		}
		else
		{
			die "failed to match signal $signame\n";
		}
	}
	print ">> Running test $prog\n\n";
	qx("$prog");
	if($? == -1)
	{
		$result = 128;
	}
	elsif($? & 127)
	{
		$result = -($? & 127);
	}
	else
	{
		$result = ($? >> 8);
	}
	if($result == $status)
	{
		$outcome = "PASS";
	}
	else
	{
		$outcome = "FAIL";
	}
	if($expected eq $outcome)
	{
		$indicator = ($outcome eq "PASS" ? "." : "X");
	}
	else
	{
		$indicator = "!";
		$err++;
	}
	print "\n+ Exit code: $result\n+ Expected code: $status\n+ Result: $outcome\n+ Expected result: $expected\n";
	print "\n-----------------------------------------------------------------------------\n\n";
	print $output $indicator;
}
print $output "\n";

$now = time2str("%Y-%m-%d %H:%M:%S", time);
print "Test run completed at $now\n";

if($err)
{
	print $output "\n*** $err test" . ($err == 1 ? '' : 's') . " did not produce expected results.\n*** See tests.log for more information\n";
}

exit $err ? 1 : 0;

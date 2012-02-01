#!/usr/bin/ruby

temp = ""
STDIN.each do |line|
	line.chomp!
	if line =~ /^\d+$/ then
		print line+" "+temp+"\n"
	elsif line =~ /^==>.*/ then
		temp = line.scan(/a\d+/)[0]
	end
end

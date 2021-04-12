use strict;
use warnings;


sub fread{
	my ($fname) = @_;
	
	open(FH, "<", $fname) or die "Fail to open file!";
	
	my $out = "";
	while(<FH>){
		$out .= $_;
	}
	
	close(FH);
	
	return $out;
}

sub fwrite{
	my ($fname, $data) = @_;
	
	open(FH, ">", $fname) or die "Fail to open file!";
	
	print FH $data;
	
	close(FH);
}

sub mapval{
	my($x, $in_min, $in_max, $out_min, $out_max) = @_;
	
	return ($x - $in_min) * ($out_max - $out_min) / ($in_max - $in_min) + $out_min;
}


sub convert{
	my ($file) = @_;
	
	my $data = fread($file);
	
	my $out = "";
	
	if($data =~ /<path\s*style=".*"\s*d="(.*)"\s*id=".*"\s*\/>/g){
		foreach my $x ($1 =~ /(\d+\.\d*,\d+\.\d*)/g){
			my @vals = split ",", $x;
			@vals = map {mapval($_, 0, 100, -100, 100)} @vals;
			
			my $line = $vals[0].",".$vals[1];
			
			$out = "$out$line\n";
		}
	}
	
	chomp $out;
	
	if($file =~ s/\.svg/\.txt/g){
		fwrite($file, $out);
	}else{
		print "FAIL\n";
	}
}



sub main{
	foreach my $f (<*.svg>){
		convert($f);
	}
}

&main;

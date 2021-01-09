# About

This program generates the __MTD data text file__ required for LHDN PCB submission (for example via online banking portal). 

#### Program Limitation

- Supports only one employer number
- Supports only one employee entry

### Reference

- [MTD Data specification](http://lampiran1.hasil.gov.my/pdf/pdfam/FormatDataCP39BI.pdf)
- [Specification for MTD Calculations Using Computerised Calculation for 2019](http://lampiran1.hasil.gov.my/pdf/pdfam/Spesifikasi_Kaedah_Pengiraan_Berkomputer_PCB_2019.pdf)


### Build steps

Use `make` to build the program with the `Makefile` provided.

Below example specify the user's home directory for `prefix`, `$HOME/etc` where the configuration file can be found and `$HOME/Desktop` to store the output file. Note the default configuration directory is `/etc` and the default output directory is `/tmp`.

```  
$ make prefix=$HOME sysconfdir=$HOME/etc outputdir=$HOME/Desktop all
cd src && /Applications/Xcode.app/Contents/Developer/usr/bin/make all
gcc -DCFGDIR="\"/Users/lcs/etc\"" -DOUTPUTDIR="\"/Users/lcs/Desktop\"" -g -O0 -o mypcb main.c Helper.c PCBData.c PCBFile.c  
```

Run `make install` to install the program to the directory specified.

```
$ make prefix=$HOME install                                         
cd src && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
install -d /Users/lcs/bin
install -m 0755 mypcb /Users/lcs/bin
 
$ ls -l ~/bin/mypcb
-rwxr-xr-x  1 lcs  staff  53872 Oct 23 19:52 /Users/lcs/bin/mypcb* 
```

### Usage

```
./mypcb --help
Usage: my_pcb YEAR MONTH PCB_AMOUNT

	YEAR         from 1970 to 2020
	MONTH        from 1 to 12
	PCB_AMOUNT   from 0 (0.00) to 1000000 (10000.00)

	e.g.
	 PCB for 2018 Jan is $1234.56, so enter:
	 my_pcb 2018 01 123456
```

For example, below generate the data file for November 2020 with monthly PCB contribution 1234.56.

```
19:55:23 69  ./mypcb 2020 11 123456
Data file written to /Users/lcs/Desktop/PCB_202011.txt
```

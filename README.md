## About

This program generates the MTD data text file required for LHDN submission (for example via online banking portal). 

Limitation:

- Supports only one employer number
- Supports only one employee entry

### Reference

- [MTD Data specification](http://lampiran1.hasil.gov.my/pdf/pdfam/FormatDataCP39BI.pdf)
- [Specification for MTD Calculations Using Computerised Calculation for 2019](http://lampiran1.hasil.gov.my/pdf/pdfam/Spesifikasi_Kaedah_Pengiraan_Berkomputer_PCB_2019.pdf)


### Build steps

Edit `my_pcb.c` and modify the constant `PCB_CONF_DIR` to the relative path from your home directory.

For example, if your home directory is `/home/foo`, and the configuration file is in `/home/foo/bin/mypcb/conf`, then change the `PCB_CONF_DIR` to `bin/mypcb/conf`, else you will see runtime error that the program is not able to chdir to the configuration directory.

Use make to build the program with the makefile provided.

```
$ make
cc -g -Wall -O3   -c -o Helper.o Helper.c
cc -g -Wall -O3   -c -o PCBData.o PCBData.c
cc -g -Wall -O3   -c -o PCBFile.o PCBFile.c
cc -g -Wall -O3    mypcb.c Helper.o PCBData.o PCBFile.o   -o mypcb

```

Usage example:

```
17:36:20:244 ~/Data/github/mypcb ./my_pcb
Usage: my_pcb YEAR MONTH PCB_AMOUNT

	YEAR         from 1970 to 2020
	MONTH        from 1 to 12
	PCB_AMOUNT   from 0 (0.00) to 1000000 (10000.00)

	e.g.
	 PCB for 2018 Jan is $1234.56, so enter:
	 my_pcb 2018 01 123456

17:36:23:244 ~/Data/github/mypcb ./my_pcb 2019 08 123456
Data file written to /Users/cs/Desktop/PCB_201908.txt

17:36:34:244 ~/Data/github/mypcb
```
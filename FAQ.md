### Using `make check`

> Note: We need to specify the config and output directories.

```
 4:03:01 355  make prefix=/tmp sysconfdir=/tmp/etc outputdir=/tmp check all
gcc -DCFGDIR="\"/tmp/etc\"" -DOUTPUTDIR="\"/tmp\"" -g -O0 -o mypcb main.c Helper.c PCBData.c PCBFile.c
mkdir /tmp/etc
cp ../etc/mypcb.conf /tmp/etc/
./mypcb 2020 12 999988; ls -l /tmp/PCB_202012.txt
Data file written to /private/tmp/PCB_202012.txt
-rw-r--r--  1 lcs  wheel  195 Jan 10 04:03 /tmp/PCB_202012.txt
*** ALL TEST PASSED ***
make: Nothing to be done for `all'.
 4:03:33 355 
```

### Using `make checkclean`

Clean up the test directories.

```
 4:03:55 355  make checkclean
rm /tmp/PCB_202012.txt
rm -rf /tmp/etc
 4:07:19 355  
```

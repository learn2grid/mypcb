all: mypcb

sources = main.c Helper.c PCBData.c PCBFile.c

mypcb: $(sources)
	gcc -DCFGDIR="\"$(sysconfdir)\"" -DOUTPUTDIR="\"$(outputdir)\"" -g -O0 -o $@ $(sources)

check: all
	mkdir /tmp/etc
	cp ../etc/mypcb.conf /tmp/etc/
	./mypcb 2020 12 999988; ls -l /tmp/PCB_202012.txt
	@echo "*** ALL TEST PASSED ***"

install:
	install -d $(DESTDIR)$(bindir)
	install -m 0755 mypcb $(DESTDIR)$(bindir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/mypcb
	-rmdir $(DESTDIR)$(bindir) > /dev/null 2>&1

checkclean:
	-rm /tmp/PCB_202012.txt
	rm -rf /tmp/etc

clean:
	-rm mypcb

.PHONY: all clean check checkclean install uninstall
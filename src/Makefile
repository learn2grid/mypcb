all: mypcb

sources = main.c Helper.c PCBData.c PCBFile.c

mypcb: $(sources)
	gcc -DCFGDIR="\"$(sysconfdir)\"" -DOUTPUTDIR="\"$(outputdir)\"" -g -O0 -o $@ $(sources)

check: all
	#./mypcb | grep "Hello from .*jupiter!"
#	@echo "*** ALL TEST PASSED ***"
	@echo "*** NOTHING TO TEST ***"

install:
	install -d $(DESTDIR)$(bindir)
	install -m 0755 mypcb $(DESTDIR)$(bindir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/mypcb
	-rmdir $(DESTDIR)$(bindir) > /dev/null 2>&1

clean:
	-rm mypcb

.PHONY: all clean check install uninstall
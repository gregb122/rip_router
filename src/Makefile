#Grzegorz Bielecki 288388

CFLAGS = -std=gnu17 -Wall -Wextra

traceroute: $(obj)
	gcc $(CFLAGS) -c -o router.o router.c
	gcc $(CFLAGS) -c -o record.o record.c
	gcc $(CFLAGS) -c -o table.o table.c
	gcc $(CFLAGS) -c -o receiver.o receiver.c
	gcc $(CFLAGS) -c -o broadcaster.o broadcaster.c
	gcc $(CFLAGS) -c -o helpers.o helpers.c
	gcc $(CFLAGS) -o router helpers.o receiver.o broadcaster.o record.o table.o router.o
	cp router out/

.PHONY: clean distclean
clean:
	rm -f *.o

distclean:
	rm  -f router out/* *.o
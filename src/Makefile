#Grzegorz Bielecki 288388

CFLAGS = -std=gnu17 -Wall -Wextra

traceroute: $(obj)
	gcc $(CFLAGS) -c -o router.o router.c
	gcc $(CFLAGS) -c -o record.o record.c
	gcc $(CFLAGS) -c -o table.o table.c
	gcc $(CFLAGS) -c -o connect.o connect.c
	gcc $(CFLAGS) -o router record.o table.o connect.o router.o

.PHONY: clean distclean
clean:
	rm -f *.o

distclean:
	rm  -f traceroute *.o
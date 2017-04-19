CFLAGS=-O2 --static

all: main1.libc main2.libc main3.libc main4.bare main5.bare main5.ldscript

clean:
	@rm -rf *.o *.src *.map *.libc *.bare *.ldscript

%.libc: %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
	strip $@
	readelf -h -l -S -s -r -V -A -I -W $@ >$@.map
	objdump -d $@ >$@.src

%.bare: %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -nostdlib -o $@ $<
	strip $@
	readelf -h -l -S -s -r -V -A -I -W $@ >$@.map
	objdump -d $@ >$@.src

%.ldscript: %.o
	$(LD) -nostdlib -T$*.ld -s -o $@ $<
	strip $@
	readelf -h -l -S -s -r -V -A -I -W $@ >$@.map
	objdump -d $@ >$@.src


%.o: %.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) -o $@ $<
	objdump -d $@ >$@.src

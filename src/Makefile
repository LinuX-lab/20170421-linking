CFLAGS=-Os --static
OBJDUMPFLAGS=-d -Mintel -s
OBJDUMPFLAGS2=-tr
READELFFLAGS=-e -W

all: main1.libc main2.libc main3.libc main4.bare main5.bare main5.ldscript

clean:
	@rm -rf *.o *.src *.map *.libc *.bare *.ldscript *.rel

%.libc: %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
	strip $@
	readelf $(READELFFLAGS) $@ >$@.map
	objdump $(OBJDUMPFLAGS) $@ >$@.src

%.bare: %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -nostdlib -o $@ $<
	strip $@
	readelf $(READELFFLAGS) $@ >$@.map
	objdump $(OBJDUMPFLAGS) $@ >$@.src
	objdump $(OBJDUMPFLAGS2) $@ >$@.rel

%.ldscript: %.o
	$(LD) -nostdlib -T$*.ld -s -o $@ $<
	strip $@
	readelf $(READELFFLAGS) $@ >$@.map
	objdump $(OBJDUMPFLAGS) $@ >$@.src
	objdump $(OBJDUMPFLAGS2) $@ >$@.rel


%.o: %.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) -o $@ $<
	objdump $(OBJDUMPFLAGS) $@ >$@.src
	objdump $(OBJDUMPFLAGS2) $@ >$@.rel

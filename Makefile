include makefile.conf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

dep :
	gccmakedep $(INC) $(SRCS)

red:
	./$(TARGET) 2 > $(OUT)

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

# DO NOT DELETE
main.o: main.c /usr/include/stdc-predef.h server.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/bits/byteswap-16.h /usr/include/sys/types.h \
 /usr/include/time.h /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h jmp.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h \
 /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/sys/ipc.h \
 /usr/include/bits/ipctypes.h /usr/include/bits/ipc.h \
 /usr/include/sys/msg.h /usr/include/bits/msq.h /usr/include/sys/shm.h \
 /usr/include/bits/shm.h client.h
server.o: server.c /usr/include/stdc-predef.h server.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/bits/byteswap-16.h /usr/include/sys/types.h \
 /usr/include/time.h /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h jmp.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h \
 /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/sys/ipc.h \
 /usr/include/bits/ipctypes.h /usr/include/bits/ipc.h \
 /usr/include/sys/msg.h /usr/include/bits/msq.h /usr/include/sys/shm.h \
 /usr/include/bits/shm.h
client.o: client.c /usr/include/stdc-predef.h client.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/stdlib.h /usr/include/bits/waitflags.h \
 /usr/include/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/bits/byteswap-16.h /usr/include/sys/types.h \
 /usr/include/time.h /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/sigset.h /usr/include/bits/time.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h \
 /usr/include/alloca.h /usr/include/bits/stdlib-float.h jmp.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h \
 /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/sys/ipc.h \
 /usr/include/bits/ipctypes.h /usr/include/bits/ipc.h \
 /usr/include/sys/msg.h /usr/include/bits/msq.h /usr/include/sys/shm.h \
 /usr/include/bits/shm.h
jmp.o: jmp.c /usr/include/stdc-predef.h jmp.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdint.h \
 /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h \
 /usr/include/sys/types.h /usr/include/time.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h \
 /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
 /usr/include/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/bits/stdlib-float.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/sys/ipc.h \
 /usr/include/bits/ipctypes.h /usr/include/bits/ipc.h \
 /usr/include/sys/msg.h /usr/include/bits/msq.h /usr/include/sys/shm.h \
 /usr/include/bits/shm.h

const char MSG[] = "Hello world!\n";
#define __NR_write 1
#define __NR_exit 60

static int inline my_write(int fd, const void *buf, int size)
{
    int ret;
    asm volatile
    (
        "syscall"
        : "=a" (ret)
        : "0"(__NR_write), "D"(fd), "S"(buf), "d"(size)
        : "cc", "rcx", "r11", "memory"
    );
    return ret;
}

static void __attribute__((noreturn)) my_exit(int rc)
{
    asm volatile ( "syscall" :: "a"(__NR_exit), "D"(rc) : );
    __builtin_unreachable();
}


void __attribute__((noreturn)) _start()
{
    my_write(1,MSG,sizeof(MSG));
    my_exit(0);
}

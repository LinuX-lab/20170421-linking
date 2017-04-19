const char MSG[] = "Hello world!\n";
#define __NR_write 1


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

void _start()
{
    my_write(1,MSG,sizeof(MSG));
}

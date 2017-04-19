#include <unistd.h>

const char MSG[] = "Hello world!\n";

int main( int argc, char **argv )
{
    write(1,MSG,sizeof(MSG));
    return 0;
}

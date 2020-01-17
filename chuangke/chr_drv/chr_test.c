#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int fd;
    int value;

    fd = open(argv[1], O_RDWR);    
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    read(fd,&value,sizeof(value));
    printf("____USER____: value = %d\r\n", value);

    value = 666;
    write(fd,&value,sizeof(value));
    close(fd);
static inline void __iomem *iounmap(phys_addr_t offset, size_t size)
	static inline void iounmap(void __iomem *addr)
    return 0;
}
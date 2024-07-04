
// OPEN
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

extern int errno;

int main() {
    int fd = open("foo.txt", O_RDONLY | O_CREAT);
    printf("fd = %d\n", fd);
    if (fd == -1) {
        printf("Error Number %d\n", errno);
        perror("Program");
    }
    return 0;
}

// CLOSE
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1 = open("foo.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("c1");
        exit(1);
    }
    printf("opened the fd = %d\n", fd1);

    if (close(fd1) < 0) {
        perror("c1");
        exit(1);
    }
    printf("closed the fd.\n");
}


//READ
#include <unistd.h>

int main() {
    int fd, sz;
    char* c = (char*)calloc(100, sizeof(char));
    fd = open("foo.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    sz = read(fd, c, 10);
    printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);
    return 0;
}

// WRITE
#include<stdio.h>
#include <fcntl.h>

main() {
    int sz;
    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    sz = write(fd, "hello skillvertex\n", strlen("hello skillvertex\n"));
    printf("called write(%d, \"hello skillvertex\\n\", %d). It returned %d\n", fd, strlen("hello skillvertex\n"), sz);
    close(fd);
}


// FORK
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t p = fork();
    if(p < 0){
        perror("fork fail");
        exit(1);
    }
    printf("Hello world!, process_id(pid) = %d \n", getpid());
    return 0;
}

// EXAMPLE
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd[2];
    char buf1[12] = "hello world";
    char buf2[12];

    fd[0] = open("foobar.txt", O_RDWR);
    fd[1] = open("foobar.txt", O_RDWR);

    write(fd[0], buf1, strlen(buf1));
    write(1, buf2, read(fd[1], buf2, 12));

    close(fd[0]);
    close(fd[1]);

    return 0;
}


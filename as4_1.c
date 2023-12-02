#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret, err, s, fd;
    printf("program started.\n");
    ret = fork();
    if(ret == 0) {
        // output redirection
        // fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0664);
        fd = open("out.txt",O_RDONLY, 0664);
        // if( fd == 0)
        // {
        //     printf("open() failed ");
        // }
        close(0);
        dup(fd);
        close(fd);

        // err = execlp("/usr/bin/ls", "ls", "-l", "/home", NULL);
        err = execlp("cat", "cat", NULL);
        if(err < 0) {
            perror("exec() failed");
            _exit(1);
        }
    }
    else
        waitpid(ret, &s, 0);
    printf("program completed.\n");
    return 0;
}

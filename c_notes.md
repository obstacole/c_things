// notes on threads
// notes on dup()
// notes on pipe()
// notes on fork()
// notes on semaphores
// notes on mutexes
// open and fopen

<!--

 -->

# Notes on C

## Processes
Libraries: `<unistd.h>`, `sys/wait.h`, `fnctl.h`

`dup2(new_fd, old_fd)` - A system call to change stdin, stdout, and stderr to a different file descriptor (fd). For example, you can change the standard output to file.txt so whenever you call "printf", it will write to file.txt by calling `int new_fd = open("file.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU)` and `dup2(new_fd, 1)`

`new_fd`: a new file descriptor integer (stream) that you open with `open()`

`old_fd` is represented in integers:
 - 0 - stdin
 - 1 - stdout
 - 2 - stderr


`pipe(pipe_fd[2])` - A system call to open up a read/write pipe for interprocess communication. Read end of pipe: `pipe_fd[0]`, write end of pipe: `pipe_fd[1]`. If it fails, it returns -1

`fork()` - A system call to fork the process into two processes: the parent and the child. The child process will continue execution from where the call to fork happened.

Fork call return values

- negative number - failed fork
- 0 - child process
- positive number - parent process

`wait(&status)` - A system call for the parent to 

## Threads
Library: `<pthread.h>`

`pthread_create()`

`pthread_cancel()`


`pthread_join()`

`pthread_exit()`

## IO
Library: `<stdio.h>`

`fopen()`

`open()`

`fclose()`

`close()`

## Resource Access

### Mutexes

### Semaphores
Library: `<semaphore.h>`

`sem_t`

`sem_init`

`sem_wait`

`sem_post`

`sem_destroy`

# Notes on C

Useful notes for the C language.

Created by: Cole McReynolds

Date Last Updated: 04/17/2020

## Strings
Library: `<string.h>`

`strstr(string, substring)` - looks through `string` for `substring` and returns the pointer of the first occurance of the substring. Returns `NULL` if no substring exists

`strlen(string)` - returns the length of the string

`strtok(string, delimiters)` - tokenizes a string based on the delimiters. Returns a pointer to the first tokenized value. Call the function again with `NULL` in place of the string to get the next tokenized value. Will return `NULL` when you reach the end of the tokenized string

`strcpy(newVal, oldVal)` - copies `oldVal` into `newVal`. Think of it as being in the same order as `newVal = oldVal`

`strncat(baseString, toBeAdded)` - concatenates `toBeAdded` to `baseString`

`strcmp(string1, string2)` - compares `string1` to `string2` as if it were `string1 == string2`. Returns 0 if equal, non-zero if not equal


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

`scanf("format string" , &variable to store in)` - a dumb way of reading input from a user, stops reading input after the enter character. It sucks because there is no buffer, so you can get all kinds of problems. Use `fgets()` or `sscanf()`

ISSUES:

- When reading in a character, you might need to put a space after the %c to make sure it reads it in properly. You can also substitute %c with %d
- Reading in strings with spaces is fine, but if you have multiple strings you want to read in, just use fgets()

`fgets(*whereToPutValue, bufferLength, FILE *)` - a buffered way of reading input from a specified location

`fprintf(FILE *, string, format values)` - a way of writing to a specific location

`fopen("file path", "r, w, or a" or FLAGS)` - opens a file stream and returns a `FILE *` pointer

`open("file path", "r, w, or a" or FLAGS)` - opens a file stream and returns an integer corresponding to the file opened

`fclose(FILE *)` - closes a file pointer

`close(int)` - closes a file directory integer

## Resource Access

### Mutexes

### Semaphores
Library: `<semaphore.h>`

`sem_t` - semaphore variable. Usually global

`sem_init(&semPointer, isShared, value)` - initializes the semaphore stored in the `semPointer` pointer to `value`. `isShared` tells if the semaphore is shared between processes (NOT THREADS)

`sem_wait(&semaphore)` - suspends the current thread until another thread calls `sem_post()`

`sem_post(&semaphore)` - tells the threads that have been suspended by `sem_wait()` that they can continue execution

`sem_destroy(&semaphore)` - destroys the semaphore

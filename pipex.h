#ifndef PIPEX_H
# define PIPEX_H


#include <unistd.h>   // fork(), pipe(), execve(), access(), dup2(), close()
#include <sys/types.h> // pid_t
#include <sys/wait.h>  // wait(), waitpid()
#include <fcntl.h>     // open(), O_CREAT, O_TRUNC, O_RDONLY, O_WRONLY
#include <stdlib.h>    // malloc(), free(), exit()
#include <stdio.h>     // perror(), printf()
#include <string.h>    // strerror()
 #endif
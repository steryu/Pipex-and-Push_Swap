#ifndef PIPEX_H
#define PIPEX_H

# define STDIN 0
# define STDOUT 1

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp);

#endif
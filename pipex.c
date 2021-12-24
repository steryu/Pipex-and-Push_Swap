#include "pipex.h"

int  execute(char *cmd, char **envp)
{
    char *Path_from_envp;
    char **mypaths;
    char **mycmdargs;

    Path_from_envp = //ft_substr of ft_strncmp; stuur envp door
    mypaths = ft_split(Path_from_envp, ':');

    mycmdargs = ft_split(cmd, " ");    

    int i;
    char *path;
    
    i = 0;
    while(mypaths[i])
    {
        path = ft_strjoin(ft_strjoin(mypaths[i], "/"), cmd);
        if (access(path, F_OK) == 0)
        {
            execve(path, mycmdargs, envp);
            write(2, "failed", 6);
            exit(0);
        }
        free(path);
        i++;
    }

    return (0);
}

void pipex(int f1, int f2, char **envp, char **argv)
{
    int end[2];
    pid_t parent;

    pipe(end);
    if (pipe < 0)
    {
        perror("Pipe error..");
        exit(1);
    }
    parent = fork();
    if (parent < 0)
        perror("Fork error...");
    if (!parent)
    {
        dup2(end[1], STDOUT);
        close(end[0]);
        close(f1);
        execute(argv[2], envp);
    }
    else 
    {
        waitpid(parent, NULL, 0);
        dup2(end[0], STDIN);
        close(end[1]);
        close(f2);
        execute(argv[3], envp);
    }
}

int main(int argc, char **argv, char **envp)
{
    int f1;
    int f2;
 
    if (argc == 5)
    {
        dup2(f1, STDIN);
        f1 = open(argv[1], O_RDONLY);
        f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644); //users read/write, others/groups can read
        if (f1 < 0 || f2 < 0)
            return (-1);
        pipex(f1, f2, envp);
    }
    else
        write(1, "Function failed..", 15);

    return (0);
}
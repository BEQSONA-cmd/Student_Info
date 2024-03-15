# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include  <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putstr_fd(const char *s, int fd)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] != ';') {
            ft_putchar_fd(s[i], fd);
        }
        i++;
    }
}

void find_USER(char **env , int fd)
{
    int i = 0;
    int j = 0;
    while(env[i])
    {
        if (env[i][0] == 'U' && env[i][1] == 'S' && env[i][2] == 'E' && env[i][3] == 'R')
        {
            j = j + 5;
            while(env[i][j])
            {
                ft_putchar_fd(env[i][j], fd);
                j++;
            }
            return;
        }
        i++;
    }
}

int main(int ac, char **av, char **env)
{
    int fd = open("user.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    int fd2 = open("userinfo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    find_USER(env, fd);
    close(fd);
    int i = 0;
    while(env[i])
    {
        ft_putstr_fd(env[i], fd2);
        ft_putstr_fd("\n", fd2);
        i++;
    }
    close(fd2);
    return 0;
}

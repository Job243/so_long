#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int file_exists(const char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 0;
    }
    close(fd);
    return (1);
}

char *read_file(const char *filename)
{
    int fd;
    int bytes_read;
    char *buffer;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;
    buffer = malloc(BUFFER_SIZE);
    if (!buffer)
        return NULL;

    bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read <= 0)
    {
        free(buffer);
        close(fd);
        return NULL;
    }
    buffer[bytes_read] = '\0';
    close(fd);
    return (buffer);
}


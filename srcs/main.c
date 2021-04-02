#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libasm.h"

void test_strlen()
{
	printf("\033[0;32m\n=== ft_strlen === \n\033[0m");
	printf("M: Vide => %zu\n", ft_strlen(""));
	printf("R: Vide => %zu\n", strlen(""));
	printf("M: Normal => %zu\n", ft_strlen("Hello"));
	printf("R: Normal => %zu\n", strlen("Hello"));
	printf("M: Long => %zu\n", ft_strlen("Hello world; test1; test2; test3; test4; test5\n"));
	printf("R: Long => %zu\n", strlen("Hello world; test1; test2; test3; test4; test5\n"));
}

void test_strcpy()
{
	char dest[100];
	printf("\033[0;32m\n=== ft_strcpy ===\n\033[0m");
	printf("Vide => %s\n", ft_strcpy(dest, ""));
	printf("Normal => %s\n", ft_strcpy(dest, "Hello"));
	printf("Long => %s\n", ft_strcpy(dest, "Hello world; test1; test2; test3; test4; test5"));
}

int     _strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void test_strcmp()
{
	printf("\033[0;32m\n=== ft_strcmp === \n\033[0m");
	printf("M: Vide, Vide => %d\n", ft_strcmp("", "c"));
	printf("R: Vide, Vide => %d\n", _strcmp("", "c"));
	printf("M: Normal, Vide => %d\n", ft_strcmp("Hello", ""));
	printf("R: Normal, Vide => %d\n", _strcmp("Hello", ""));
	printf("M: Vide, Normal => %d\n", ft_strcmp("", "World"));
	printf("R: Vide, Normal => %d\n", _strcmp("", "World"));
	printf("M: Normal, Normal: same => %d\n", ft_strcmp("Hello", "Hello"));
	printf("R: Normal, Normal: same => %d\n", _strcmp("Hello", "Hello"));
	printf("M: Normal, Normal: diff => %d\n", ft_strcmp("Hello", "Hel"));
	printf("R: Normal, Normal: diff => %d\n", _strcmp("Hello", "Hel"));
	printf("M: Normal, Normal: diff => %d\n", ft_strcmp("Hel", "Hello"));
	printf("R: Normal, Normal: diff => %d\n", _strcmp("Hel", "Hello"));
}

void test_strdup()
{
	printf("\033[0;32m\n=== ft_strdup ===\n\033[0m");
	printf("Vide => %s\n", ft_strdup(""));
	printf("Normal => %s\n", ft_strdup("Hello"));
	printf("Long => %s\n", ft_strdup("Hello world; test1; test2; test3; test4; test5"));
}

void test_write()
{
	int fd;
	char *str = "Hello world\n";

	printf("\033[0;32m\n=== ft_write ===\n\033[0m");

	ft_write(1, str, 12);
	write(1, str, 12);

	ft_write(1, &"", 1);
	ft_write(1, &"\n", 1);
	write(1, &"", 1);
	write(1, &"\n", 1);

	fd = open("write.txt", O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
	ft_write(fd, str, 12);
	write(fd, str, 12);
	close(fd);

	errno = 0;
	ft_write(-1, str, 12);
	printf("errno => %d\n", errno);

	errno = 0;
	write(-1, str, 12);
	printf("errno => %d\n", errno);

	fd = open("write.txt", O_WRONLY);
	errno = 0;
	ft_write(fd, str, 12);
	printf("errno => %d\n", errno);
	errno = 0;
	write(fd, str, 12);
	printf("errno => %d\n", errno);
	printf("fd => %d\n", fd);
	close(fd);
}

void test_read()
{
	int	fd;
	int ret;
	char *buf;

	printf("\033[0;32m\n=== ft_read ===\n\033[0m");

	errno = 0;
	fd = open("write.txt", O_RDONLY);
	buf = calloc(100, sizeof(char));
	ret = read(fd, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", fd, ret, buf, errno);
	free(buf);
	close(fd);

	errno = 0;
	fd = open("write.txt", O_RDONLY);
	buf = calloc(100, sizeof(char));
	ret = ft_read(fd, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", fd, ret, buf, errno);
	free(buf);
	close(fd);

	errno = 0;
	buf = calloc(100, sizeof(char));
	ret = read(-1, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", -1, ret, buf, errno);
	free(buf);

	errno = 0;
	buf = calloc(100, sizeof(char));
	ret = ft_read(-1, buf, 50);
	buf[50] = '\0';
	printf("fd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", -1, ret, buf, errno);
	free(buf);
}

int main()
{
	printf("\033[0;34m===== TEST LIBASM =====\n\033[0m");

//	test_strlen();
//	test_strcpy();
//	test_strcmp();
	test_strdup();
//	test_read();
//	test_write();
	return (0);
}
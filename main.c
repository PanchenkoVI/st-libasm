/*
* Created: 2020/11/02
*/

#include "libasm.h"

void	strlen_test(const char *s, const char *test)
{
	int	or;
    int	ft;

    or = strlen(s);
    ft = ft_strlen(s);
    if (or == ft)
        printf("%s :OK\n", test);
    else
        printf("%s :KO\n", test);
}

void strcpy_test(const char *src, const char *test)
{
	char	dest1[BUFFER_SIZE];
	char	dest2[BUFFER_SIZE];

	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("%s :OK\n", test);
	else
		printf("%s :KO\n", test);
}

void write_test(int fd, char *buf, size_t count, const char *test)
{
    int     or;
    int     ft;
    int		ft_err;
    int		or_err;

    or = write(fd, buf, count);
    or_err = errno;
    ft = ft_write(fd, buf, count);
    ft_err = errno;
    if (or == ft)
        printf("%s : OK\n", test);
    else
        printf("%s :KO\n", test);
    if (ft == -1 || or == -1)
    {
    	if (ft_err == or_err)
    		printf("ERRNO [FT:%d]||[OR:%d] : %s OK\n", ft_err, or_err, test);
    	else
    		printf("ERRNO [FT:%d]||[OR:%d] : %s KO\n", ft_err, or_err, test);
    }
}

void read_test(int fd, size_t count, const char *test)
{
	int		or;
	int		ft;
	int		ft_err;
	int		or_err;
	char	buf1[BUFFER_SIZE];
	char	buf2[BUFFER_SIZE];

	bzero(buf1, BUFFER_SIZE);
	bzero(buf2, BUFFER_SIZE);
	or = read(fd, buf1, count);
	or_err = errno;
	ft = ft_read(fd, buf2, count);
	ft_err = errno;
	if (or == ft && strcmp(buf1, buf2) == 0)
        printf("%s : OK\n", test);
    else
        printf("%s :KO\n", test);
    if (ft == -1 || or == -1)
    {
    	if (ft_err == or_err)
    		printf("ERRNO [FT:%d]||[OR:%d] : %sOK\n", ft_err, or_err, test);
    	else
    		printf("ERRNO [FT:%d]||[OR:%d] : %sKO\n", ft_err, or_err, test);
    }
}

void strcmp_test(const char *s1, const char *s2, const char *test)
{
	int		or = strcmp(s1, s2);
	int		ft = ft_strcmp(s1, s2);

	if ((or == 0 && ft == 0) || (or >= 1 && ft >= 1) || (or <= 0 && ft <= 1))
		printf("%s :OK\n", test);
	else
		printf("%s :KO\n", test);
}

void strdup_test(const char *src, const char *test)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup(src);
	str2 = strdup(src);
	if (!strcmp(str1, str2))
		printf("%s :OK\n", test);
	else
		printf("%s :KO\n", test);
	free(str1);
	free(str2);
}

void	test_strlen(char *s)
{
	printf("\n");
	printf("-----------------------strlen------------------------\n");
	printf("strlen test\n");
	printf("string: %s\n", s);
	printf("ft_strlen: %lu\n", ft_strlen(s));
	printf("-----------------------------------------------------\n");
}

void	test_strcmp(char *s1, char *s2)
{
	printf("\n");
	printf("-----------------------strcmp------------------------\n");
	printf("strcmp test\n");
	printf("s1: %s\ns2: %s\n", s1, s2);
	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("-----------------------------------------------------\n");
}

void	test_strcpy(char *s1, char *s2)
{
	printf("\n");
	printf("-----------------------strcpy------------------------\n");
	printf("strcpy test\n");
	printf("string: %s\n", s2);
	printf("ft_strcpy: %s\n", ft_strcpy(s1, s2));
	printf("-----------------------------------------------------\n");
}

void	test_strdup(char *s1)
{
	printf("\n");
	printf("-----------------------strdup------------------------\n");
	printf("strdup test\n");
	printf("string: %s\n", s1);
	printf("ft_strdup: %s\n", ft_strdup(s1));
	printf("-----------------------------------------------------\n");
}

void	test_read_write(int fd, void *buf, size_t nbyte)
{
	printf("\n");
	printf("-----------------------read------------------------\n");
	printf("read & write test\n");
	while (ft_read(fd, buf, nbyte))
	{
		ft_write(1, buf, nbyte);
	}
	printf("-----------------------------------------------------\n");
}


int main (void)
{
	
    printf("FT_WRITE TESTS \n");
	int		fd;

	fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("open() error");
		return 1;
	}
	write_test(fd, "Hello_world\n", 12, "basic");
	write_test(-2, "Hello_world", 11, "bad fd");
	write_test(fd, NULL, 11, "NULL ptr");
	write_test(fd, "Hello_world", -2, "bad len");
	printf("-----------------------------------------------------\n");
	// FT_READ TESTS
	printf("FT_READ TESTS \n");
	read_test(fd, 12, "basic");
	read_test(-2, 11, "bad fd");
	read_test(fd, 11, "NULL ptr");
	read_test(fd, -2, "bad len");
	if (close(fd) == -1)
	{
		printf("close() error");
		return 1;
	}

	printf("-----------------------------------------------------\n");
	printf("------------------>ft_strcmp<------------------------\n");	
	printf("0 & 0 = %d\n", ft_strcmp("", ""));
	printf("0 & 0 = %d\n", strcmp("", ""));
	printf("1 & 0 = %d\n", ft_strcmp("A", ""));
	printf("1 & 0 = %d\n", strcmp("A", ""));
	printf("0 & 1 = %d\n", ft_strcmp("", "\200"));
	printf("0 & 1 = %d\n", strcmp("", "\200"));

	printf("WWW & WWW = %d\n", ft_strcmp("WWW", "WWW"));
	printf("WWW & WWW = %d\n", strcmp("WWW", "WWW"));

	printf("rgb & rgb = %d\n", ft_strcmp("rgb", "rgb"));
	printf("rgb & rgb = %d\n", strcmp("rgb", "rgb"));

	printf("wwwD & www = %d\n", ft_strcmp("wwwD", "www"));
	printf("wwwD & www = %d\n", strcmp("wwwD", "www"));

	printf("wwwD & www = %d\n", ft_strcmp("wwwDDDwwwDDDwwwDDD", "wwwDDD"));
	printf("wwwD & www = %d\n", strcmp("wwwDDDwwwDDDwwwDDD", "wwwDDD"));
	printf("-----------------------------------------------------\n");
	printf("------------------>ft_strcpy<------------------------\n");
	char *my_str;
	char	dest1[BUFFER_SIZE];
	char	dest2[BUFFER_SIZE];
	char *s1;
	char *s2;

	s1 = (char *)malloc(300);
	s2 = (char *)malloc(300);
	my_str = (char *)malloc(300);	
	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	printf("zero %s\n", ft_strcpy(my_str, ""));
	printf("zero %s\n", strcpy(my_str, ""));
	printf("1 %s\n", ft_strcpy(my_str, "pop"));
	printf("1 %s\n", strcpy(my_str, "pop"));
	printf("much %s\n", ft_strcpy(my_str, "El español o castellano es una lengua romance procedente del latín hablado. Pertenece al grupo ibérico y es originaria de Castilla, reino medieval de la"));
	printf("much %s\n", strcpy(my_str, "El español o castellano es una lengua romance procedente del latín hablado. Pertenece al grupo ibérico y es originaria de Castilla, reino medieval de la"));
	ft_strcpy(dest1, "\x12\xff");
	strcpy(dest2, "\x12\xff");
	if (!strcmp(dest1, dest2))
		printf("ft_strcpy :OK\n");
	else
		printf("ft_strcpy :KO\n");
	ft_strcpy(s1, "\x12\xff");
	strcpy(s2, "\x12\xff");
	if (!strcmp(s1, s2))
		printf("ft_strcpy :OK\n");
	else
		printf("ft_strcpy :KO\n");		
	free(s1);
	free(s2);		
	printf("-----------------------------------------------------\n");


	printf("------------------>ft_strdup<------------------------\n");
	char	*str1;
	char	*str2;

	str1 = (char *)malloc(300);
	str2 = (char *)malloc(300);	
	printf("zero %s\n", ft_strdup(""));
	printf("zero %s\n", strdup(""));
	printf("1 %s\n", ft_strdup("pop"));
	printf("1 %s\n", strdup("pop"));
	printf("much %s\n", ft_strdup("El español o castellano es una lengua romance procedente del latín hablado. Pertenece al grupo ibérico y es originaria de Castilla, reino medieval de la"));
	printf("much %s\n", strdup("El español o castellano es una lengua romance procedente del latín hablado. Pertenece al grupo ibérico y es originaria de Castilla, reino medieval de la"));
	str1 = ft_strdup("\x12\xff");
	str2 = strdup("\x12\xff");
	if (!strcmp(str1, str2))
		printf("ft_strdup :OK\n");
	else
		printf("ft_strdup :KO\n");
	free(str1);
	free(str2);		
	printf("-----------------------------------------------------\n");
	
	printf("------------------>ft_stlen<------------------------\n");
	printf("0 = %lu\n", ft_strlen(""));
	printf("0 = %lu\n", strlen(""));
	printf("3 = %lu\n", ft_strlen("pop"));
	printf("3 = %lu\n", strlen("pop"));
	printf("155 = %lu\n", ft_strlen("El español o castellano es una lengua romance procedente del latín hablado. Pertenece al grupo ibérico y es originaria de Castilla, reino medieval de la"));
	printf("155 = %lu\n", strlen("El español o castellano es una lengua romance procedente del latín hablado. Pertenece al grupo ibérico y es originaria de Castilla, reino medieval de la"));
	printf("-----------------------------------------------------\n");

	printf("-----------------------------------------------------\n");
	// STRLEN TESTS
    printf("FT_STRLEN TESTS :\n");
	strlen_test("Hello world", "basic1");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh ", "long");
	strlen_test("", "empty");
	strlen_test("\n", "new line");
	strlen_test("\n\n", "new line2");
	strlen_test("111+}Te'st!wi/th*[<<As:c2ii3", "strange string");
	strdup_test("FIZZ\0BUZZ", "Unsigned char1");
	strdup_test("\x12\xff", "unsigned char2");
	printf("-----------------------------------------------------\n");

    // FT_STRCMP TESTS 	
	printf("FT_STRCMP TESTS \n");
	strcmp_test("hello World", "hello World", "basic1");
	strcmp_test("hello World", "Hello World", "basic2");
	strcmp_test("hello World", "", "empty1");
	strcmp_test("", "", "empty2");
	strcmp_test("", "Hello world", "empty3");
	strcmp_test("", "\n", "new line 1");
	strcmp_test("\n", "Hello world", "new line 2");
	strcmp_test("\n", "\n", "new line 3");
	strcmp_test("111+}Te'st!wi/th*[<<As:c2ii3", "111+}Te'st!wi/th*[<<As:c2ii3" ,"strange strings");
	strcmp_test("FIZZ\0BUZZ","FIZ\0BUZZ", "Unsigned char1");
	strcmp_test("\x12\xff","\x12\0", "unsigned char2");
	printf("-----------------------------------------------------\n");

	// STRCPY TESTS 
    printf("FT_STRCPY TESTS :\n");
    strcpy_test("Hello world", "basic1");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh ", "long");
	strcpy_test("", "empty");
	strcpy_test("\n", "new line");
	strcpy_test("\n\n", "new line2");
	strcpy_test("111+}Te'st!wi/th*[<<As:c2ii3", "strange string");
	strcpy_test("FIZZ\0BUZZ", "Unsigned char1");
	strcpy_test("\x12\xff", "unsigned char2");
	printf("-----------------------------------------------------\n");

	// FT_STRDUP TESTS
	printf("FT_STRDUP TESTS \n");
	strdup_test("Hello world", "basic1");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate. In hac habitasse platea dictumst. In a nibh ", "long");
	strdup_test("", "empty");
	strdup_test("\n", "new line");
	strdup_test("\n\n", "new line2");
	strdup_test("111+}Te'st!wi/th*[<<As:c2ii3", "strange string");
	strdup_test("FIZZ\0BUZZ", "Unsigned char1");
	strdup_test("\x12\xff", "unsigned char2");
	printf("-----------------------------------------------------\n");

	//all
	//int		fd4;
	//char	bufe;
	char	ss[15] = "Hello World!";
	char	test[15];

	//fd4 = open("test", O_RDONLY);
	test_strlen(ss);
	test_strcpy(test, ss);
	test_strcmp(ss, "Hello world");
	test_strdup(ss);
	//test_read_write(fd4, &bufe, 1);
	//close(fd4);
	
	int fd5;
	int bytes;
	char buf[8000];
	
	ft_write(1, "New test\n", 9);
	fd5 = open("./hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	printf("Writing six bytes: %lu\n", ft_write(fd5, "Hello!", 6));
	close(fd5);
	bytes = ft_write(-1, "What?", 3);
	printf("Trying bad descriptor %d\n\n", bytes);
	fd5 = open("./hello.txt", O_RDONLY);
	bytes = ft_read(fd5, buf, 100);
	buf[bytes] = '\0';
	printf("Read: %s\n", buf);
	close(fd5);
	bytes = ft_read(-1, buf, 100);
	printf("Trying bad descriptor: %d\n", bytes);
	printf("Please  enter some test:\n");
	bytes = ft_read(0, buf, 8000);
	buf[bytes] = '\0';
	printf("Read from stdin: %s (%d bytes)\n", buf, bytes);
    return (0);
}
/* создает текст. файл с заданным числом строк и переводом строки */
#include <stdio.h>
#include <stdlib.h>
#define MAX 60

int main(void)
{
    FILE *fp;
    char words[MAX] = "Alexander 75 85 77 59 0 85 75 89"; // задаем нужную строку
//Функция fopen открывает файл, указанный аргументом filename с режимом доступа, указанным в аргументе mode и связывает с открытым файлом поток данных. 
    if ((fp = fopen("test10000", "w+")) == NULL)
    {
        fprintf(stdout,"Can't open \"test file\" file.\n");
        exit(1);
    }

    rewind(fp);           /* вернуться в начало файла */

    for ( int i = 0; i < 10000; i++)
    {
        fprintf(fp, "%s\n", words);
    }
     
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
     
    return 0;
}

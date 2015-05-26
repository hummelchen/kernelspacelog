#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

extern keycode codes[];

void print_char(int code) {
    int i;
    if((code < FIRST_CD || code > LAST_CD) && code != KEY_SPACE)
    {
        for(i = 0; i < sizeof(codes)/sizeof(keycode); i++)   
            if (codes[i].code == code)
                printf("%s", codes[i].string);
    }
    else
        printf("%c",ch_table[(code-FIRST_CD)]);
}

int main(int argc, char *argv[])
{
	FILE * fp;
    int tmp;
    if (argc == 1)
    {
        printf("Usage: %s log.bin\n", argv[0]); 
        exit(EXIT_SUCCESS);
    }
    if((fp=fopen(argv[1], "rb")) == 0)
    {
        fprintf(stderr,"fopen failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    while(fread(&tmp, sizeof(int), 1, fp) != 0)
    {
        print_char(tmp);
    }
    fclose(fp);
	return 0;
}

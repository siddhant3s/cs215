#include<stdio.h>
char* strcat(char* dest, char* src)
{
    while (*dest++);
    dest--;
    while (*dest++ = *src++);
    return dest;
}
char* strncat(char* dest, char* src, int n)
{
    while (*dest++);
    dest--;
    while ((--n>=0) && (*dest++ = *src++));
    *dest='\0';
    return dest;
}

int strcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
char toupper(char c)
{
    if (c>='a' && c<='z') return 'A'+(c-'a');
    else return c;
}
int stricmp(char *s, char *t)
{
    for ( ; toupper(*s) == toupper(*t); s++, t++)
        if (*s == '\0')
            return 0;
    return toupper(*s) - toupper(*t);
}


void strcpy(char *s, char *t)
{
    while (*s++ = *t++);
}
void strncpy(char *s, char *t,int n)
{
    while ( --n>=0 && (*s++ = *t++));
}
size_t strlen(char *s)
{
    char* t=s;
    while (*t++);
    t--;
    return t-s;
}
void strrev(char* s)
{
    size_t l=-1, i=0;
    while (s[++l]);
    for (i=0;i<l/2;++i)
    {
        char t=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=t;
    }
}
int main(void)
{
    const size_t MAXLEN=50;
    char s1[50]="The First String";
    char s2[]="Second String";
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);



    printf("Concatanating s1 and s2 to s1. Now,\n");
    strcat(s1,s2);
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);


    printf("Reversing s2:\n");
    strrev(s2);
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);

    printf("Copying s2 to s1:\n");
    strcpy(s1,s2);
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);


    printf("Concatenating first 5 character from s2 to s1:\n");
    strncat(s1,s2,5);
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);


    printf("Reversing s1:\n");
    strrev(s1);
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);

    printf("The length of s1=%i\n",strlen(s1));

    strcpy(s1,"ME");
    strcpy(s2,"me");

    printf("strcmp over s1 and s2=%i",strcmp(s1,s2));
    printf("stricmp over s1 and s2=%i",stricmp(s1,s2));

    return 0;
}


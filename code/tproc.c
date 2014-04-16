# include <stdio.h>
int cad_procurar_str ( char s1 [] , char s2 [])
{
//    int i, j;
//   for (i =0; s2[i]; i++) {
//       for(j = 0; s2[j]&&(s2 [j+i] == s1 [j]) ; j++);
//       if(j > 0 && s1 [j]=='\0')
//           return i;
//   }
//   return -1;
    int i, j, k;
    for (i = 0; s2[i] != '\0'; i++) {
        for (j=i, k=0; s1[k]!='\0' && s2[j]==s1[k]; j++, k++)
            ;
        if (k > 0 && s1[k] == '\0')
            return i;
    }
    return -1;

}

int main()
{
    char s1 [1000];
    char s2 [1000];
    int n;
    char c;
    scanf ("%s", s1);
    scanf ("%s", s2);


    printf ("%d\n", cad_procurar_str(s1, s1));
    return 0;
}

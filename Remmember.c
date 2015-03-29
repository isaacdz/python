       while (c != '\n'){

         c = getc(p);

          printf("i'm readinn \n");
           a++;

           }
           
           struct  page {

   int  numpg ;
   int nbrocc ;
   struct  page *next ;
 };

 typedef struct page page ;

struct mot1  {

    page *prempg ;
    page *derpg ;
    char *motindex;
    struct mot1 *next ;
};

typedef struct mot1 mot ;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main () {
int s = 0;
char chain[100],chain1[100];
FILE *fp, *ft;
 fp = fopen("isaac.txt","rt");



if (fp == NULL) {

exit (1);

} else  {

   while (fgets (chain,100,fp)!= NULL) {
     s = s +1 ;
     printf("the words of line %d \n",s);

        if (strlen(chain) != 1 ) {
        ft = fopen("tmp.txt","w");
        fputs(chain,ft);
        fclose(ft);
         ft = fopen("tmp.txt","rt");
        while (fscanf(ft,"%s",chain1) != EOF) {
         printf("%s\n",chain1);

          }fclose(ft);

    } else {

        printf("oulesh klaam \n");
    }


}

}
return 0 ;
}
int check (char chain[11]) {

int i=0 ,max = 30,pos,cond=0;

char forb[30][11]={"ainsi","aussi","aussitot","avant","bien","cependant","ces","cet","cette","comme","donc","elles","enfin","ils"
               ,"jusqu'a","lorsque","mais","malgre","neamoins","parce","pourtant","puis","puisque","que","quoi","sinon","soit","tandis"
               ,"tant","toutefois"};
        while (i < max) {
            pos = (i + max) /2  ;
            if ((cond=strcmp(chain,forb[pos]))== 0) {
             return  1 ;
            }  else if (cond < 0) {

                max = pos -1 ;
            }  else  {

               i = pos + 1 ;
            }

        }
        return 0 ;
}

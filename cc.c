#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

struct page {
            int numpg ;
            int nbrocc ;
            struct page *next ;
            };
typedef struct page page ;


struct mot1 {
            page *prempg ;
            page *derpg ;
            char *motindex;
            struct mot1 *next ;
};



typedef struct mot1 mot ;

void  write (char ch[100]){
  FILE *ft;
  ft = fopen("tmp.txt","w");
  fputs(ch,ft);
  fclose(ft);

}



int main () {
   int s = 0;
   char chain[100],chain1[100];
   FILE *fp;


fp = fopen("isaac.txt","rt");
    if (fp == NULL) {
        exit (1);
       } else {
            while (fgets (chain,100,fp)!= NULL) {
                      s = s +1 ;
                      printf("the words of line %d \n",s);
                      if (strlen(chain) != 1 ) {
                                                write(chain);

                                                FILE *ft ;
         
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

2 eme test  : 


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct page {
            int numpg ;
            int nbrocc ;
            struct page *next ;
            };
typedef struct page page ;


struct mot1 {
            page *prempg ;
            page *derpg ;
            char *motindex;
            struct mot1 *next ;
           };



typedef struct mot1 mot ;

void  write (char ch[100]){
  FILE *ft;
  ft = fopen("tmp.txt","w");
  fputs(ch,ft);
  fclose(ft);

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



int main () {
   int s = 0;
   char chain[100],chain1[100];
   FILE *fp;
   mot *tabtet[26], *ptr;
   page *pg;
   int j ;
   for (j =0 ; j<26 ; j++) {

      tabtet[j]=NULL;

   }


fp = fopen("isaac.txt","rt");
    if (fp == NULL) {
        exit (1);
       } else {
            while (fgets (chain,100,fp)!= NULL) {
                      s = s +1 ;
                      if (strlen(chain) != 1 ) {
                                                write(chain);

                                                FILE *ft ;
                                                ft = fopen("tmp.txt","rt");
                                                while (fscanf(ft,"%s",chain1) != EOF) {


                                                if (check(chain1)==0 && strlen(chain1) > 2 && isalpha(chain1[0])){

                                                if (tabtet[tolower(chain1[0])-'a']== NULL) {

                                                ptr = (mot *)malloc(sizeof(mot *));
                                                ptr->motindex=chain1;
                                                ptr->prempg->nbrocc = 1 ;
                                                ptr->prempg->numpg = ceil((float )s/3);
                                                ptr->prempg->next = NULL ;
                                                ptr->next = NULL ;
                                                printf("%s \n",ptr->motindex);

                                                }  else {
                                                         ptr = tabtet[tolower(chain1[0])-'a'] ;
                                                         while (ptr != NULL) {

                                                          if (strcmp(ptr->motindex,chain1)== 0) {


                                                          if (ptr->derpg->numpg == ceil((float )s/3))
                                                          ptr->derpg->nbrocc++;


                                                          } else {

                                                                  pg = (page *)malloc(sizeof(page));
                                                                  ptr->derpg->next= pg ;
                                                                  pg->nbrocc= 1;
                                                                  pg ->next = NULL ;
                                                                  pg->numpg = ceil((float )s/3) ;

                                                                  }

                                                                  ptr = ptr->next ;

                                                         }


                                                }

                                                };




                                                }fclose(ft);
                                                }
                                                } remove("tmp.txt");
}
return 0 ;
}

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


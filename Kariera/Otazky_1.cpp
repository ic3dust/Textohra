#include <stdio.h>
#include <stdlib.h>

int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int otazka(int vek )
{
    int x= rand_range(0,10);
    int y= rand_range(0,10);
    int spolu = x+y;
    int odpoved= 0;
    printf("Vyrieš príklad máš na to 3 pokusy \n");
    for(int i=1;i<4;i++)
    {

        printf(" %d .pokus-koľko je %d + %d =",i,x,y);
        scanf("%d",&odpoved);
        if (odpoved == spolu)
        {
            printf("správne \n");
            return 0;
        }

    }
    return 0;


}


int prvocisla (){
    int x= rand_range(0,10);



}
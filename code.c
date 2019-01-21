/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <malloc.h>

typedef struct elt {
    int Nombre;
    int Taille; 
    int Tab[];
    int type;
}

Tas * CreerTAS (int N, int type)
{
    TAS T;
    T= (TAS *)malloc(Sizeof (TAS));
    T.Taille = N;
    T.Nombre= 0;
    T.Tab= (int *)malloc (N*Sizeof(int));
    T.type=type;
}

int FilsGauche(TAS T, int i)
{ int FG = i*2+1;
    if (FG > T.Nombre) return(-1);
    return (FG);
}


int FilsDroit(TAS T, int i)
{ int FD = i*2+2;
    if (FG > T.Nombre) return(-1);
    return (FD);
}

PercollerBAs (TAS T, int i)
{
    int FG, FD, MAX, temp;
    FG = FilsGauche(T,i);
    FG = FilsDroit(T,i);
    MAX =i;
    if ((FG != -1)&&(T.Tab[MAX]< T.Tab[FG])) MAX =FG;
    if ((FD != -1)&&(T.Tab[MAX]< T.Tab[FD])) MAX =FD;
    if (MAX != i) { temp = T.Tab[i];
                    T.Tab[i]=T.Tab[MAX];
                    T.Tab[MAX]= temp;
                   }
    
}

int Supprimer (TAS T)
{
    int val,;
    
    if (T.Nombre=0) return(-1);
    val = T.Tab[T.Nombre];
    T.Nombre--;
    PercollerBAs(T,0);
    return(val);
    
}

Resize (T TAS)
{
    int Tem[]= T.Tab;
    
     T.Tab= (int *)malloc ((T.Taille*2)*Sizeof(int));
     T.Taille=(T.Taille*2);
    
    for (i=0;i<T.Taille/2;i++)
    {T.Tab[i]=Temp[i];}
    free(Tem);
}


Inserer (T TAS, int val)
{
    if (T.Taille==T.Nombre) Resize (T);
    T.Nombre++;
    i=T.Nombre-1;
    while ((i>0)&&(T.Tab[(i-1)/2]<val)) {T.Tab[i]=Tab[(i-1)/2]; i=(i-1)/2;}
    T.Tab[i]=val;
}

ConstruireTAS ()
{
    for (i=(T.Nombre-1)/2; i>0; i--) {PercollerBAs(T,i);}
    
}


/***********************************************************************
 * EXox TD 
 * 
 * 
 * ******************************************************************/


int main()
{
    printf("Hello World");

    return 0;
}
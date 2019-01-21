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
    int *Tab;
    int type;
}TAS;

TAS * CreerTAS (int N, int type)
{
    TAS *T;
    T= (TAS *)malloc(sizeof (TAS));
    T->Taille = N;
    T->Nombre= 0;
    T->Tab= (int *)malloc (N*sizeof(int));
    T->type=type;
    return (T);
}

int FilsGauche(TAS *T, int i)
{ int FG = (i*2)+1;
    if (FG > T->Nombre) return(-1);
    return (FG);
}


int FilsDroit(TAS *T, int i)
{ int FD = (i*2)+2;
    if (FD > T->Nombre) return(-1);
    return (FD);
}

void PercollerBAs (TAS *T, int i)
{
    int FG, FD, MAX, temp;
    FG = FilsGauche(T,i);
    FD = FilsDroit(T,i);
    MAX =i;
    if ((FG != -1)&&(T->Tab[MAX]< T->Tab[FG])) MAX =FG;
    if ((FD != -1)&&(T->Tab[MAX]< T->Tab[FD])) MAX =FD;
    if (MAX != i) { temp = T->Tab[i];
                    T->Tab[i]=T->Tab[MAX];
                    T->Tab[MAX]= temp;
                    PercollerBAs(T,MAX);
                   }
    
}

int Supprimer (TAS *T)
{
    int val;
    
    if (T->Nombre==0) return(-1);
    val = T->Tab[0];
    T->Tab[0]=T->Tab[T->Nombre-1];
    T->Nombre=T->Nombre-1;
    PercollerBAs(T,0);
    return(val);
    
}

void Resize (TAS *T)
{
    int *Tem,i;
    Tem= T->Tab;
    
     T->Tab= (int *)malloc ((T->Taille*2)*sizeof(int));
     T->Taille=(T->Taille*2);
    
    for (i=0;i<T->Taille/2;i++)
    {T->Tab[i]=Tem[i];}
    free(Tem);
}


void Inserer (TAS *T, int val)
{ int i;
    if (T->Taille==T->Nombre) Resize (T);
    T->Nombre++;
    i=(T->Nombre)-1;
    while ((i>0)&&(T->Tab[(i-1)/2]<val)) {T->Tab[i]=T->Tab[(i-1)/2]; i=(i-1)/2;}
    T->Tab[i]=val;
}

TAS * ConstruireTAS ( int Temp[], int N )
{   int i;
    TAS *T;
    T=CreerTAS(N*2, 1);
     for (i=0; i<N; i++) T->Tab[i]= Temp[i];
     T->Taille=N;
    for (i=(T->Nombre-1)/2; i>0; i--) {PercollerBAs(T,i);}
    return (T);
}


/***********************************************************************
 * EXox TD 
 * 
 * 
 * ******************************************************************/






int main()
{   int i, val;
   /** quesion 1 ***/ 
    TAS *T= CreerTAS(20,1);
   
    for (i=0;i<9;i++) {//scanf("%d",&val);Inserer(T,val);
                       Inserer(T,i);}
    for (i=0;i<T->Nombre-1; i++) printf("%d ",T->Tab[i]);
    
    /*** question 3 **/
    val = Supprimer(T);
    
    printf ("\nla valeur suprimer est : %d\n",val);
    for (i=0;i<T->Nombre-1; i++) printf("%d ",T->Tab[i]);
    
     printf("Hello World");

    return 0;
}

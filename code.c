/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <limits.h> 





typedef struct elt {
    int Nombre;
    int Taille; 
    int *Tab;
    int type;
}TAS;



typedef int bool;
#define true 1
#define false 0


typedef struct node
{
int info;
struct node * left;
struct node * right;
}tree;

typedef struct sNode 
{ 
  tree *t; 
  struct sNode *next; 
}pile; 


/******************************************************************************
                            Fonctions de bases sur pile pour arbre 
*******************************************************************************/

/* initialiser la pile */ 

void Init_stack(pile **p)
{
    (*p)=NULL;
}

/* vC)rifier si la pile est vide */ 

bool PisEmpty (pile *p)
{
    if (p==NULL) return (true); else return (false);
}



/* Fonction qui Empile un C)lement dans la pile */

void push(pile ** Sommet, tree *t) 
{ 
  /* allocate tNode */
  pile * new_tNode = 
            (pile *) malloc(sizeof(pile)); 
  
  if(new_tNode == NULL) 
  { 
     printf("Stack Overflow \n"); 
     getchar(); 
     exit(0); 
  }   
 /* mettre l'@ de l'arbre  */
  new_tNode->t  = t; 
  
  /* faire le chainage dans la pile  */
  new_tNode->next = (*Sommet);    
  
  /* changer le sommet  */
  (*Sommet)    = new_tNode; 
} 

/* Fonction qui depiler une C)lement de la pile*/
tree *pop(pile ** Sommet) 
{ 
  tree *res; 
  pile *top; 
  
  /*si la pile est vide afficher une erreur */
  if(PisEmpty(*Sommet)) 
  { 
     printf("Stack Underflow \n"); 
     getchar(); 
     exit(0); 
  } 
  else
  { 
     top = *Sommet; 
     res = (*Sommet)->t; 
     *Sommet = top->next; 
     free(top); 
     return res; 
  } 
} 
 
 /******************************************************************************
                            Fonctions de bases sur arbre
*******************************************************************************/


bool IsEmpty( tree *T)
{
   if (T==NULL) return (true);
   return (false);
}


tree * Left( tree *T)
{
if ( IsEmpty(T) )
return NULL;
else
return T->left;
}

tree * Right( tree *T)
{
if ( IsEmpty(T) )
return NULL;
else
return T->right;
}

bool IsLeave(tree *T)
{
if (IsEmpty(T))
return false;
else if ((IsEmpty(Left(T))) && (IsEmpty(Right(T))))
return true;
else
return false;
}


bool IsInternalNode(tree *T)
{
return (! IsLeave(T) );
}



 
 
 
 
/******************************************************************************
                            Fonctions de bases sur TAS
*******************************************************************************/





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
    if (FG >= T->Nombre) return(-1);
    return (FG);
}


int FilsDroit(TAS *T, int i)
{ int FD = (i*2)+2;
    if (FD >= T->Nombre) return(-1);
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


tree * Rand_Tree()
{   tree *T;
   // time_t t;
    
   // srand((unsigned) time(&t));  // Initialization, should only be called once.
   /* if (i==0) return NULL;
         else { T=(tree *)malloc (sizeof(tree));
                //if (i%2==0) {T->info= rand()%20; T->left=NULL; T->right=Rand_Tree(i-1);}
                    // else {
                    T->info= rand()%20; T->left=NULL; T->right=Rand_Tree(i-1); T->left=Rand_Tree(i-1);//}
                      return (T);
                  }*/
    T=(tree *)malloc (sizeof(tree));
    T->info =10;
    T->left=(tree *)malloc (sizeof(tree));
    T->left->info =5;
    T->left->left=(tree *)malloc (sizeof(tree));
    T->left->left->info =4;T->left->left->left=NULL; T->left->left->right=NULL;
    T->left->right=(tree *)malloc (sizeof(tree));
    T->left->right->info =6;T->left->right->left=NULL; T->left->right->right=NULL;
    
    T->right=(tree *)malloc (sizeof(tree));
    T->right->info =15;
    T->right->left=(tree *)malloc (sizeof(tree));
    T->right->left->info =14;T->right->left->left=NULL; T->right->left->right=NULL;
    T->right->right=(tree *)malloc (sizeof(tree));
    T->right->right->info =16;T->right->right->left=NULL; T->right->right->right=NULL;
    return (T);
}

void afficher (tree *T)
{
    if (!IsEmpty (T)) { printf ("%d  ", T->info );
                        afficher(T->left);
                        afficher(T->right);
                        
                              }
}

void PercollerBAsMin (int *T, int i, int N)
{
    int FG, FD, MIN, temp;
    FG =  (i*2)+1;
    if (FG >= N) FG=-1;
    FD =  (i*2)+2;
    if (FD >= N) FD=-1;
    MIN =i;
    if ((FG != -1)&&(T[MIN]> T[FG])) MIN =FG;
    if ((FD != -1)&&(T[MIN]> T[FD])) MIN =FD;
    if (MIN != i) { temp = T[i];
                    T[i]=T[MIN];
                    T[MIN]= temp;
                    PercollerBAsMin(T,MIN,N);
                   }
    
}

/***********************************************************************
 * EXox TD 
 * 
 * 
 * ******************************************************************/


TAS * ABRtoTAS (tree *T)
{
  unsigned var=0;
  pile *p;
  tree *ABR;
  
  ABR =T;
  
  TAS *Ta=CreerTAS(30,1);
  
  Init_stack(&p);
  push (&p, ABR); 
  
  while  (!PisEmpty(p))
  {
      ABR = pop (&p);
      Inserer(Ta,ABR->info);
      if (!IsEmpty(ABR->left)) push (&p, ABR->left); 
      if (!IsEmpty(ABR->right)) push (&p, ABR->right); 
      
  }
  
  return (Ta);
}


int MinInTASMAX (TAS *T)
{
    int min,i; 
    
    min = T->Tab[T->Nombre-1];
    for (i=T->Nombre-2;i>=(T->Nombre-1/2); i--)
    {if (T->Tab[i]<min) min=T->Tab[i];}
    return(min);
}


TAS * Deletekeme (TAS *T,  int k)
{
 if (T==NULL) return (NULL);
 if ((k>=T->Nombre)||(k<0)) return(T);
 if (k==T->Nombre-1){T->Nombre--; return (T);}
 T->Tab[k]= T->Tab[T->Nombre-1];
 T->Nombre--;
 PercollerBAs(T,k);
 return (T);
    
}

int kemepetit(TAS *T, int k)
{  int tab[T->Nombre];
   int i,j, temp,N;
   
    if (T==NULL) return (-1);
    if ((k>T->Nombre)||(k <0)) return (-1);
    for (i=0;i<T->Nombre; i++) tab[i]= T->Tab[i];
      N=T->Nombre;
     for(i=0;i<k;i++)
     {
        for(j=((N-1)/2);j>-1;j--) {PercollerBAsMin(tab,j,N);}
        temp=tab[0];
        tab[0]=tab[N-1];
        tab[N-1]=temp;
        N--;
     }
     temp=tab[N];
     for (i=0;i<T->Nombre; i++) printf("%d  ",tab[i]);
     printf("\n");
     for (i=0;i<T->Nombre; i++) printf("%d  ",T->Tab[i]);
     return(temp);
}


int main()
{   int i, val;
   /** quesion 1 ***/ 
    TAS *T= CreerTAS(20,1);
    TAS *T2;
    tree *ABR;
    for (i=0;i<9;i++) {//scanf("%d",&val);Inserer(T,val);
                       Inserer(T,i);}
    for (i=0;i<T->Nombre; i++) printf("%d ",T->Tab[i]);
    
    /*** question 3 **/
    val = Supprimer(T);
    
    printf ("\nla valeur suprimer est : %d\n",val);
    for (i=0;i<T->Nombre; i++) printf("%d ",T->Tab[i]);
    
    printf("\n Question 4 :\n Avant:  ");
    ABR=Rand_Tree();
    afficher(ABR);
    printf("\n AprC)s : ");
    T2= ABRtoTAS(ABR);
     for (i=0;i<T2->Nombre; i++) printf("%d  ",T2->Tab[i]);
    
    printf("\n Question 5: Le min est %d\n", MinInTASMAX(T2));
    
    printf("\n Question 6: Supprimer le 2 C)me C)lement\n");
    T2=Deletekeme(T2,2);
    for (i=0;i<T2->Nombre; i++) printf("%d  ",T2->Tab[i]);
    
    printf ("\n Question 7: Trouvez le kC)me C)lC)ment plus petit dans un TASMAX \n");
    scanf("%d",&val);
    printf("Le %d C)me C)lC)ment est :%d ",val,kemepetit(T,val));
    

    return 0;
}

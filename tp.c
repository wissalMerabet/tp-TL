#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

//!______________________les constates:

#define MAX_ETATS 100


//!______________________déclaration d'un automate:

typedef struct rtrt {//declaration d'un automate
int num_etats;
int etats_initiaux[MAX_ETATS]; //tableaux d'etat initiaux
int num_etats_initiaux; //nbr d'etat initial
int etats_finaux[MAX_ETATS];  //tableaux d'etat finaux
int num_etats_finaux;//nbr d'etat finaux
int MAT[20][20];   //la matrice
int nbr;//la taille de votre alphbet
char alp[100];// Table d'alphabet
}automate;




int transition(automate *a,int x, char mot) {                      //transition
    int h;
    for (int i = 1; i <= a->nbr; i++) {
        if(mot == a->alp[i]){  //un boucle pour teste le mot
            h = i;
            break;
        }
    }
    return a->MAT[x][h];
}

void teste_lettre(automate a, char p) {

    int s = 0;
    for ( int i = 1; i <= a.nbr; i++) {
        if (p!= a.alp[i]) {           //ntastiw 7rf b 7rf m3a la l'alphabet ta3na
          s++;    //S le nmbre ta3 chhal mn mera mtsawach m3a l'alphabet
        }
        if (s == a.nbr) {             
          printf(" %c n'existe pas en votre alphabet \n",p);   //the wrong letter
        }

    }

}


void teste_mot(automate a) {
    char p;
    char q;
    char mot[20];
    char continuer = 'o';
    int E_T[a.num_etats_initiaux];
    while (continuer == 'o') {
        //metter l'atat initiaux 
        for (int i = 0; i <a.num_etats_initiaux ; i++) {
            a.etats_initiaux[i] =E_T[a.num_etats_initiaux ];
        }
        int j =0;
        int T[a.num_etats_initiaux ];
        printf("\t\tTESTER UN MOT\n\n");
        printf("donner moi un mot === \n" );
        scanf("%s",&mot);
        int t =0;
        /*tester de laph les tettre */
        while (mot[t] != '\0') {
            teste_lettre(a,mot[t]);
            t++;
        }
        for (int i = 0; i < a.num_etats_initiaux ; i++) {
            while (mot[j] != '\0'){
                T[i] = transition(&a, a.etats_initiaux[i],mot[j]);
                a.etats_initiaux[i] = T[i];
                j++;
            }
        }
        for (int i = 0; i < a.num_etats_initiaux   ; i++) {
            for (int j = 0; j < a.num_etats_finaux; j++) {
                if (T[i] == a.etats_finaux[j]){
                    printf("le mot est acceptee\n");
                    break;

                }else{
                    printf("le mot n'est pas acceptee\n");
                }
                T[i] = '\0';

            }
            printf("Voulez-vous ajouter un autre automate ? (o/n)\n");
            scanf(" %c", &continuer);
        }
    }
}







// saisir l'alphabet :

void alphabet(automate*a) {
  printf("Donner la taille de l'Alphabet de votre automate =");
  scanf("%d",&a->nbr);
  for (int i = 1; i <= a->nbr; i++) {  //saisir l'alphabet dans un tableau des caracteres
    printf("l'alphabet  %d =",i);
    scanf("%s",&a->alp[i] );
  }
}


//saisir l'automate:

void initialiser_automate(automate*a) {
    int i, j;
    //le nombre d'etat
    printf("Entrez le nombre d'etats : ");     
    scanf("%d", &a->num_etats);
    //le nmbr d'etat initial
    printf("Entrez le nombre d'etats initiaux : "); 
    scanf("%d", &a->num_etats_initiaux);
    if (a->num_etats_initiaux >a->num_etats) {   //!le nombre des etat toujour superieur if not exit 
        printf("le nbr d'etat_i superieur \n");  
        exit(0);
    }
    printf("Entrez les etats initiaux : ");
    for (int i = 0; i < a->num_etats_initiaux; i++) {      //boucle nmchiw fkaml les etat initial
        scanf("%d", &a->etats_initiaux[i]);               //saisir les etat initial dans un tableau
        if ((a->num_etats -1<a->etats_initiaux[i])||(a->etats_initiaux[i] < 0)) {    //!pour l'etats soit positive et inferieur a le nombre des etats
            printf("l'etat n'est pas accepter\n");
            exit(0);
        }

    }

    //nmbr d'etat finaux
    printf("Entrez le nombre d'etats finaux : ");  
    scanf("%d", &a->num_etats_finaux);
    if (a->num_etats_finaux > a->num_etats) {    //!le nombre des etat toujour superieur if not exit
        printf("le nbr d'etat_f superieur \n");
        exit(0);
    }

    printf("Entrez les etats finaux : ");
    for (i = 0; i < a->num_etats_finaux; i++) { //boucle nmchiw fkaml les etat finaux
        scanf("%d", &a->etats_finaux[i]);   //saisir les etat finaux dans un tableau
        if ((a->num_etats -1<a->etats_finaux[i])||(a->etats_finaux[i] < 0)) {    //!pour l'etats soit positive et inferieur a le nombre des etats
            printf("l'etat n'est pas accepter\n");
            exit(0);
        }  
    }

    //!LA MATRICE DE TRANSITION:

    printf("\t\nLa matrice \n");              
    for(int i=0;i< a->num_etats;i++){
        printf("E%d :\n",i);
        for(int j=1;j<=a->nbr;j++){
            printf(" %c : ",a->alp[j]);
            printf("=>E" );
            scanf("%d", &a->MAT[i][j]);

        }
    }

}

void afficher_automate(automate*a) {
    int i, j;
    printf(" la taille de votre alphabet est  %d\n",a->nbr );
    printf(" Nombre d'etats  %d\n", a->num_etats);
    printf(" votre alphabet est\t\20\n" );
    for (int i = 1; i <= a->nbr; i++) {
        printf("%c\t",a->alp[i]);
    }
    printf("\n");
    printf(" le nombre de votre etats initiaux est  %d\n",a->num_etats_initiaux );
    printf(" Etats initiaux  ");
    for (i = 0; i < a->num_etats_initiaux; i++) {
        printf("%d ", a->etats_initiaux[i]);
    }
    printf("\n");
    printf(" le nombre de votre etats finaux est  %d\n",a->num_etats_finaux );
    printf("Etats finaux  ");
    for (i = 0; i < a->num_etats_finaux; i++) {
        printf("%d ", a->etats_finaux[i]);
    }
    printf("\n");

    printf(" la matrice d'adjacence :\n");
    for (int i = 1; i <= a->nbr; i++)
    printf("\t%c",a->alp[i]);
    printf("\n");
    for (int i = 0; i < a->num_etats ; i++) {
        printf("E%d",i);
        for (int j = 1; j <= a->nbr; j++)
        printf("\tE%d", a->MAT[i][j]);
        printf("\n");
    }



}

void union_at(automate *L3 , automate L1, automate L2) {

    //alphbet
    L3->nbr = L1.nbr+L2.nbr+2;
    for (int i = 1; i < L3->nbr; i++) {
        L3->alp[i] = 'a'+i-1;
    }
    L3->alp[L3->nbr-1] = '#';//epsilon 1          lkhana m9bl lkhra nhato fiha epsilon 1
    L3->alp[L3->nbr] = '&';  //epsilon 2          lkhana lkhra nhato fiha epsilon 2
    //NB des etat
    L3->num_etats =L1.num_etats+L2.num_etats+1;

   //union etat inisial
    L3->num_etats_initiaux = L1.num_etats_initiaux+L2.num_etats_initiaux;
    //etat_i L1
    for (int i = 0; i < L1.num_etats_initiaux; i++) {
        L3-> etats_initiaux[i] = L1. etats_initiaux[i];
    }
    //etat_i L2
    for (int i = L1.num_etats_initiaux; i < L2.num_etats_initiaux; i++) {
        L3-> etats_initiaux[i] = L2. etats_initiaux[i-L1.num_etats_initiaux];
    }
    //union etat_f
    L3->num_etats_finaux = L1.num_etats_finaux+L2.num_etats_finaux;
    //etat_f L1
    for (int i = 0; i < L1.num_etats_finaux; i++) {
        L3->etats_finaux[i] = L1.etats_finaux[i];
    }
    //etat_fL2
    for (int i =  L1.num_etats_finaux; i < L3->num_etats_finaux; i++) {
        L3->etats_finaux[i] = L2.etats_finaux[i-L1.num_etats_finaux];
    }
    //saisir -1
    for(int i=0;i<L3->num_etats;i++){
        for(int j=1;j<=L3->nbr;j++){
            L3->MAT[i][j] =-1;
        }
    }
    //matrice de L1
    for(int i=0;i< L1.num_etats;i++){
        for(int j=1;j<=L1.nbr;j++){
            L3->MAT[i][j] = L1.MAT[i][j]; //saisir la matrice L1
        }
    }
    //matrice de L2
    for(int i=L1.num_etats ;i<L3->num_etats-1;i++){
        for(int j=L1.nbr+1;j<=L3->nbr-2;j++){
            L3->MAT[i][j] = L2.MAT[i-L1.num_etats][j-L1.nbr]+L1.num_etats; //saisir la matrice L2
        }
    }
    L3->MAT[L3->num_etats-1][L3->nbr-1] = L1.etats_initiaux[0];// pour e1
    L3->MAT[L3->num_etats-1][L3->nbr] = L2.etats_initiaux[0]+L1.num_etats;//pour e2


}



void deterministe(automate *L3 ,automate L1, automate L2 ){

    for (int i = 1; i <L3->nbr; i++) {
        L3->MAT[L3->num_etats-1][i] =L3->MAT[0][i];  //pour saisir en etats final 
        L3->MAT[0][i]=-1;

    }
    for (int i = 1+L2.nbr; i <L3->nbr; i++) {
        L3->MAT[L3->num_etats-1][i] =L3->MAT[L1.num_etats][i];
        L3->MAT[L1.num_etats][i]=-1;
    }


    L3->nbr= L3->nbr-2; //suprimer e1 et e2
     
  afficher_automate(L3);
}





//todo________________________________________________ le programme _______________________________________________!//

int main() {
    automate L1 , L2 , L3;

    printf("\n\n");
    printf("saisire l'automate 1:________________________________________\n");
    printf("\n\n");
    alphabet(&L1);
    initialiser_automate(&L1);
    printf("\n\n");
    /*
    printf("saisire l'automate 2:_________________________________________\n");
    printf("\n\n");
    alphabet(&L2);
    initialiser_automate(&L2);
    printf("\n\n");
    printf("le resulta :____________________________________________________\n");
    union_at(&L3 , L1 , L2);
    afficher_automate(&L3);
    printf("\n\n");
    printf("l'automate avant élimination epsilon transition \n");
    deterministe(&L3 ,L1 , L2);*/

    teste_mot(L1);

    return 0;
}






#include <stdio.h>
#include <string.h>

//!______________________les constates:

#define longugeur_mot_max 50 //* longueur maximale d’un mot
#define nb_etats_max 5     //*nombre maximal d’états autorisé pour un autom ate
#define taille_alphabet 2 //* nombre de lettres dans l’alphabet

//!______________________déclaration d'un automate:

typedef struct { 
    int nb_etats;   //* nombre d'états de l'automate
    int etat_initial;  //* numéro de l’état initial
    int etat_acceptant;   //* numéro de l'état acceptant(FINAL)
    int matrice_transition[nb_etats_max][taille_alphabet]; //*matrice de transition
}t_automate;

//!________________________afficher l'automate:

void affiche_automate(t_automate a){
    int i,j;
    printf(" le nombre d'etats de l'automate est %d \n",a.nb_etats);
    printf("l'etat initiale est E%d \n" ,a.etat_initial);
    printf("l'etat acceptant est E%d \n",a.etat_acceptant);
    printf("la matrice transition est :\n");
    for(i=0 ; i<taille_alphabet ; i++) {   //*affiche la matrice:
        printf("\t%c",'a' +i);     //* L'alphabet -> A   B .... +i
    } 
    printf("\n"); 
    for(i=0;i<a.nb_etats;i++){
        printf("E%d",i);  //* afficher le nombre d'état E0  E1 E2 ....
        for(j=0 ; j<taille_alphabet ; j++){ 
            printf("\tE%d", a.matrice_transition[i][j]);  //* afficher la matrice :
        }    
        printf("\n"); 
    }  
} 

//!_______________________saisir un automate:

void saisis_automate(t_automate* a) {  
    int i,j;
    do{    //*le cas ou le nombre d'etat superieur a le nombre max d'etats autorise ou inferieur a zero 
        printf("\n\nDonner le nombre de l'etate de l'automate:" ); //* entre les etat de l'automat
        scanf("%d",&a->nb_etats);
        if(a->nb_etats >= nb_etats_max){ //* pour afficher le message d'erreur
            printf("\nErreur!! --------> \n -->donner le nombre de l'etate de l'automate inferieure a le  nombre maximal d'etats autorise \n");
        }
        if(a->nb_etats <= 0){
            printf("\nErreur!! --------> \n -->donner le nombre de l'etate de l'automate superieur a zero \n");
        }
    }while ( a->nb_etats <= 0 || a->nb_etats >= nb_etats_max );
    do{
        printf("\nDonner l'etat initiale :");
        scanf("%d",&a->etat_initial);
        if(a->etat_initial >= nb_etats_max){ //* pour afficher le message d'erreur
            printf("\nErreur!! --------> \n -->donner le nombre de l'etate de l'automate inferieure a le  nombre maximal d'etats autorise \n");
        }
        if(a->etat_initial < 0){
            printf("\nErreur!! --------> \n -->donner le nombre de l'etate de l'automate superieur a zero \n");
        }
    }while(a->etat_initial < 0 || a->etat_initial >= nb_etats_max );
    
    do{
         printf("Donner l'etat acceptant :");
         scanf("%d",&a->etat_acceptant);
        if(a->etat_acceptant >= nb_etats_max){ //* pour afficher le message d'erreur
            printf("\nErreur!! --------> \n -->donner le nombre de l'etate de l'automate inferieure a le  nombre maximal d'etats autorise \n");
        }
        if(a->etat_acceptant < 0){
            printf("\nErreur!! --------> \n -->donner le nombre de l'etate de l'automate superieur a zero \n");
        }
    }while(a->etat_acceptant < 0 || a->etat_acceptant >= nb_etats_max );
   
    //*saisis les transition d'etats:
    for(i=0 ; i < a->nb_etats ; i++){ 
        printf("Entrez les transitions de l'etat E%d :\n",i); //* (message) les transition de l'état E0:... ect 
        for(j=0 ; j < taille_alphabet ; j++){ 
            printf(" %c : ",'a' +j); //* alphabet a .. b..
            scanf("%d", &a->matrice_transition[i][j]); //* enter l'état suivent par A puis par B ect ...
        } 
    } 
}

//!________________________________la fonction de transition de l'automate:

int applique_transition(t_automate a, int etat_courant, char lettre){
    int n;
    
    n = a.matrice_transition[etat_courant][lettre-'a']; //*lettre-'a' || lettre-'b' 
    return n;
}

//!_________________________________teste si un mot accepter par l'automat:

void teste_mot(t_automate a){
    char chaine[longugeur_mot_max]; //*le mot qui on va tester par l'automat
    char rep[longugeur_mot_max];  //* pour la répétition
    int etat_courant; 
    char *lettre_chaine ; //*pointeur
    int i,cpt;
    affiche_automate(a); //* on affiche l'automate 
    do{
        do{
            printf("\nEntrez une  chaine de caractaire contenant les lettres a et b : "); 
            scanf("%s",&chaine);
            for(i = 0 ; chaine[i] != '\0' ; i++){ //* parcourir la chaine
                cpt = 0;
                if(chaine[i] != 'a' && chaine[i] != 'b' ){  //*si le mot contenant les lettres different a a ou b
                    cpt++;
                }
            }
            if(cpt != 0){  //* pour afficher le message d'erreur
                printf("\nErreur!!!! ----> \n --> Entrez une  chaine de caractaire contenant les lettres a et b\n ");
            }
        }while(cpt != 0);//*  répéter si le mot non valid
        lettre_chaine= chaine; //*pointer sur le premier lettre de la chaine
        etat_courant = a.etat_initial; //* commencons par l'etat initial
        do{
            etat_courant = applique_transition(a,etat_courant,*lettre_chaine); //*appliquer la fonction de transition pour savoir l'etat suivent
            lettre_chaine++; //*passer a la deuxième lettre 
        }while(*lettre_chaine != '\0'); //* jusqu à le dernière lettre
        if(etat_courant == a.etat_acceptant){ //* Ese que l'etat courant egale l'etat acceptant (le mot accepter par l'automat ) 
            printf("\nLe mot %s accepter\n",chaine); 
        }else{ 
            printf("\nLe mot %s refuser \n",chaine); 
        } 
        printf("\nVoulez vous essayez un autre mot ? (oui / non)\n"); //*répéter par un autre mot
	    scanf("%s",rep);
    }while(strcmp(rep,"non")!=0); //* strcmp() pour comparez deux chaine de caractaire (rep et non) / if egale a zero les deux chaine sont egale 


}

//todo________________________________________________ le programme _______________________________________________!//

int main(){  
    int x;
    t_automate a;
    printf("\n______________________________________________________/ WISSAL_MERABAT /____________________________________________________________________\n");
    do{
        saisis_automate(&a); //*saisir un automate 
        teste_mot(a); //* tester un mot 

        printf("\n cliquer 0 pour quitter, sinon cliquer sur n'importe quelle nombre ");
        scanf("%d",&x);

    }while (x!=0); //* pour quitter le programme 
   
    return 0;

}



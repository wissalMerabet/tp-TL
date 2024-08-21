#include <stdio.h>

#define NB_ETATS_MAX 10
#define TAILLE_ALPHABET 10

typedef struct {
    int nb_etats;
    int etats[NB_ETATS_MAX];
    char lettre_Alphapit[TAILLE_ALPHABET];
    int nb_Alphapit;
    int nb_etat_initial;
    int etat_initial[NB_ETATS_MAX];
    int nb_etat_acceptant;
    int etat_Acceptan[NB_ETATS_MAX];
    int matrice_transition[NB_ETATS_MAX][TAILLE_ALPHABET];
} t_automate;

void saisis_automate(t_automate* a) {
    printf("Saisie de l'automate :\n");

    // Saisie du nombre d'états
    printf("Nombre d'etats : ");
    scanf("%d", &a->nb_etats);

    // Saisie des états
    printf("Liste des etats : ");
    for (int i = 0; i < a->nb_etats; i++) {
        scanf("%d", &a->etats[i]);
    }
    // Saisie du nombre d'états initial
    printf("Nombre d'etats initial: ");
    scanf("%d", &(a->nb_etat_initial));

    // Saisie de l'état initial
    printf("Liste des etats initial : ");
    for (int i = 0; i < a->nb_etat_initial; i++) {
        scanf("%d", &a->etat_initial[i]);
    }

    // Saisie du nombre d'états finaux
    printf("Nombre d'etats finaux: ");
    scanf("%d", &(a->nb_etat_acceptant));


    // Saisie des états finaux
    printf("Liste des etats finaux : ");
    for (int i = 0; i < a->nb_etat_acceptant; i++) {
        scanf("%d", &a->etat_Acceptan[i]);
    }

    // Saisie du nombre de symboles
    printf("Nombre de symboles : ");
    scanf("%d", &(a->nb_Alphapit));

    // Saisie des symboles
    printf("Liste des symboles : ");
    for (int i = 0; i < a->nb_Alphapit; i++) {
        scanf("%s", &a->lettre_Alphapit[i]);
    }

    // Saisie de la table de transition
    printf("Table de transition :\n");
    for(int i=0 ; i < a->nb_etats ; i++){ 
        printf("Entrez les transitions de l'etat E%d :\n",i); //* (message) les transition de l'état E0:... ect 
        for(int j=0 ; j < a->nb_Alphapit ; j++){ 
            printf(" %c : ",'a' +j); //* alphabet a .. b..
            scanf("%d", &a->matrice_transition[i][j]); //* enter l'état suivent par A puis par B ect ...
        } 
    } 
}
// Fonction pour afficher les champs d'un automate
void affiche_automate(t_automate a) {
    
    printf("Nombre d'Etats de l'automate est : %d\n", a.nb_etats);
    printf("la taill de la alphabit est : %d\n", a.nb_Alphapit);
    printf("Etats initial : ");
    for (int i = 0; i < a.nb_etat_initial; i++) {
        printf("%d ", a.etat_initial[i]);
    }
    printf("\n");
    printf("Etats finaux : ");
    for (int i = 0; i < a.nb_etat_acceptant; i++) {
        printf("%d ", a.etat_Acceptan[i]);
    }
    printf("\n");
     printf("la matrice transition est :\n");
    for(int i=0 ; i<a.nb_Alphapit ; i++) {   //*affiche la matrice:
        printf("\t%c",'a' +i);     //* L'alphabet -> A   B .... +i
    } 
    printf("\n"); 
    for(int i=0;i<a.nb_etats;i++){
        printf("E%d",i);  //* afficher le nombre d'état E0  E1 E2 ....
        for(int j=0 ; j<a.nb_Alphapit ; j++){ 
            printf("\tE%d", a.matrice_transition[i][j]);  //* afficher la matrice :
        }    
        printf("\n"); 
    }  
}
t_automate concatenateAutomates(t_automate automate1, t_automate automate2) {
    t_automate result;

    // Fusion des alphabets
    result.nb_Alphapit = automate1.nb_Alphapit + automate2.nb_Alphapit;
    int k = 0;
    for (int i = 0; i < automate1.nb_Alphapit; i++) {
        result.lettre_Alphapit[k++] = automate1.lettre_Alphapit[i];
    }
    for (int i = 0; i < automate2.nb_Alphapit; i++) {
        result.lettre_Alphapit[k++] = automate2.lettre_Alphapit[i];
    }

    // Copie des états de l'automate 1
    result.nb_etats = automate1.nb_etats;
    for (int i = 0; i < automate1.nb_etats; i++) {
        result.etats[i] = automate1.etats[i];
    }

    // Copie des états de l'automate 2 en ajustant les indices des états
    for (int i = 0; i < automate2.nb_etats; i++) {
        result.etats[result.nb_etats++] = automate2.etats[i] + automate1.nb_etats;
    }

    // Copie des états initiaux de l'automate 1
    result.nb_etat_initial = automate1.nb_etat_initial;
    for (int i = 0; i < automate1.nb_etat_initial; i++) {
        result.etat_initial[i] = automate1.etat_initial[i];
    }

    // Copie des états initiaux de l'automate 2 en ajustant les indices des états
    for (int i = 0; i < automate2.nb_etat_initial; i++) {
        result.etat_initial[result.nb_etat_initial++] = automate2.etat_initial[i] + automate1.nb_etats;
    }

    // Copie des états acceptants de l'automate 1
    result.nb_etat_acceptant = automate1.nb_etat_acceptant;
    for (int i = 0; i < automate1.nb_etat_acceptant; i++) {
        result.etat_Acceptan[i] = automate1.etat_Acceptan[i];
    }

    // Copie des états acceptants de l'automate 2 en ajustant les indices des états
    for (int i = 0; i < automate2.nb_etat_acceptant; i++) {
        result.etat_Acceptan[result.nb_etat_acceptant++] = automate2.etat_Acceptan[i] + automate1.nb_etats;
    }

    // Initialisation de la matrice de transition à -1
    for (int i = 0; i < result.nb_etats; i++) {
        for (int j = 0; j < result.nb_Alphapit; j++) {
            result.matrice_transition[i][j] = -1;
        }
    }

    // Copie de la matrice de transition de l'automate 1
    for (int i = 0; i < automate1.nb_etats; i++) {
        for (int j = 0; j < automate1.nb_Alphapit; j++) {
             result.matrice_transition[i][j] = automate1.matrice_transition[i][j];
        }
    }
    // Copie de la matrice de transition de l'automate 2 en ajustant les indices des états
    for (int i = 0; i < automate2.nb_etats; i++) {
        for (int j = 0; j < automate2.nb_Alphapit; j++) {
            result.matrice_transition[i + automate1.nb_etats][j + automate1.nb_Alphapit] = automate2.matrice_transition[i][j];
        }
    }

    return result;
}



int main(){

    t_automate a , b , d ;

    saisis_automate(&a);
    affiche_automate(a);
    saisis_automate(&b);
    affiche_automate(b);

    d = concatenateAutomates(a,b);
    affiche_automate(d);


    return 0;
}
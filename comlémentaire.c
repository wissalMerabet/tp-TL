#include <stdio.h>
#include <stdlib.h>



//!______________________les constates:

#define NB_ETATS_MAX 10
#define TAILLE_ALPHABET 10

//!______________________déclaration d'un automate:

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

//! entrer la matrice d'un Aut:

void saisie_matrice_transition(t_automate *automate) {
    // Saisie de la matrice de transition
    printf("Saisie de la matrice de transition :\n");
    for (int i = 0; i < automate->nb_etats; i++) {
        for (int j = 0; j < automate->nb_Alphapit; j++) {
            printf("Transition de l'etat %d avec le symbole %c : ", automate->etats[i], automate->lettre_Alphapit[j]);
            scanf("%d", &automate->matrice_transition[i][j]);
        }
    }
}

//!afficher la matrice de l'aut :

void affichage_matrice_transition(t_automate *automate) {
    // Affichage de la matrice de transition
    printf("\nMatrice de transition de l'automate :\n");
    printf("     ");
    for (int j = 0; j < automate->nb_Alphapit; j++) {
        printf("  %c  ", automate->lettre_Alphapit[j]);
    }
    printf("\n");
    for (int i = 0; i < automate->nb_etats; i++) {
        printf("  %d  ", automate->etats[i]);
        for (int j = 0; j < automate->nb_Alphapit; j++) {
            printf("[%d] ", automate->matrice_transition[i][j]);
        }
        printf("\n");
    }
}

//! le complémentaire de Aut: 

void complement_automate(t_automate *automate) {
    // Complément de l'automate
    for (int i = 0; i < automate->nb_etats; i++) {
        for (int j = 0; j < automate->nb_Alphapit; j++) {
            automate->matrice_transition[i][j] = automate->nb_etats - 1 - automate->matrice_transition[i][j];
        }
    }
}

//todo____________________________________________________le programme :

int main() {
    t_automate automate;

    // Saisie de l'automate
    printf("Saisie de l'automate :\n");
    // le nombre d'etats :
    printf("Nombre d'etats : ");
    scanf("%d", &automate.nb_etats);
    for (int i = 0; i < automate.nb_etats; i++) {
        printf("Etat %d : ", i);
        scanf("%d", &automate.etats[i]);
    }
    //nomber de symboles
    printf("Nombre de symboles de l'alphabet : ");
    scanf("%d", &automate.nb_Alphapit);
    for (int i = 0; i < automate.nb_Alphapit; i++) {
        printf("Symbole %d : ", i);
        scanf(" %c", &automate.lettre_Alphapit[i]);
    }
    //appeles des fonction:
    saisie_matrice_transition(&automate);
    affichage_matrice_transition(&automate);
    complement_automate(&automate);
    affichage_matrice_transition(&automate); 



    return 0;
}
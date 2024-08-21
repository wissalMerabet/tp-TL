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

void enterTransitionMatrix(t_automate *automate) {
    printf("Enter the transition matrix:\n");
    for (int i = 0; i < automate->nb_etats; i++) {
        for (int j = 0; j < automate->nb_Alphapit; j++) {
            printf("Enter the transition for state %d and alphabet %c: ", i, automate->lettre_Alphapit[j]);
            scanf("%d", &automate->matrice_transition[i][j]);
        }
    }
}

//!afficher la matrice de l'aut :

void printTransitionMatrix(t_automate automate) {
    printf("Transition Matrix:\n");
    for (int i = 0; i < automate.nb_etats; i++) {
        for (int j = 0; j < automate.nb_Alphapit; j++) {
            printf("%d ", automate.matrice_transition[i][j]);
        }
        printf("\n");
    }
}

//! miroir de l'aut :

void mirrorTransitionMatrix(t_automate *automate) {
    for (int i = 0; i < automate->nb_etats; i++) {
        for (int j = 0; j < automate->nb_Alphapit / 2; j++) {
            int temp = automate->matrice_transition[i][j];
            automate->matrice_transition[i][j] = automate->matrice_transition[i][automate->nb_Alphapit - 1 - j];
            automate->matrice_transition[i][automate->nb_Alphapit - 1 - j] = temp;
        }
    }
}

//todo____________________________________________________le programme :

int main() {
    t_automate automate;

    printf("Enter le nombre d'etats: ");
    scanf("%d", &automate.nb_etats);

    printf("Enter le nombre alphabets: ");
    scanf("%d", &automate.nb_Alphapit);

    enterTransitionMatrix(&automate);

    printf("Original ");
    printTransitionMatrix(automate);

    mirrorTransitionMatrix(&automate);

    printf("Miroir ");
    printTransitionMatrix(automate);

    return 0;
}

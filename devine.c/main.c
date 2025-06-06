#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, essai, compteur = 0;

    // Initialiser le générateur de nombre aléatoire
    srand(time(NULL));
    secret = rand() % 100 + 1;  // Génère un nombre entre 1 et 100

    printf("🎮 Bienvenue dans le jeu 'Devine le nombre' !\n");
    printf("J'ai choisi un nombre entre 1 et 100. Essaie de le deviner !\n");

    do {
        printf("Entre un nombre : ");
        scanf("%d", &essai);
        compteur++;

        if (essai < secret) {
            printf("Trop petit !\n");
        } else if (essai > secret) {
            printf("Trop grand !\n");
        } else {
            printf("🎉 Bravo ! Tu as trouvé le nombre %d en %d essais.\n", secret, compteur);
        }

    } while (essai != secret);

    return 0;
}


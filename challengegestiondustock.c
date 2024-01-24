#include <stdio.h>

int codes[100];
int quantites[100];
int stock = 0;


void ajouterProduit();
void retirerProduit();
void afficheStock();

int main() {

    int choix;

    do {
        printf("\nMenu:\n");
        printf("1. ajouter un produit au stock \n");
        printf("2. retirer un produit au stock\n");
        printf("3. afficher le stock total\n");
        printf("Entrer votre choix :");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterProduit();
                break;
            case 2:
                retirerProduit();
                break;
            case 3:
                afficheStock();
                break;
            default:
                printf("votre choix invalid !");
        }
    } while (choix != 3);

    return 0;
}

void ajouterProduit() {
    int code;
    int quantite;
    int i;

    printf("Entrer ID du produit :");
    scanf("%d", &code);
    printf("Entrer la quantite a ajouter :");
    scanf("%d", &quantite);

    for (i = 0; i < stock; i++) {
        if (codes[i] == code) {
            quantites[i] = quantites[i] + quantite;
            printf("Mise a jour de quantite avec le code %d \n", code);
            return;
        }
    }

    codes[stock] = code;
    quantites[stock] = quantite;
    stock++;
    printf("la quantite de produit %d avec le code %d a etait ajoute", code, quantite);
}

void retirerProduit() {
    int code;
    int quantite;
    int i;

    printf("Entrer le code du produit :");
    scanf("%d", &code);
    printf("Entrer la quantite a retirer :");
    scanf("%d", &quantite);

    for (i = 0; i < stock; i++) {
        if (codes[i] == code) {
            if (quantite > quantites[i]) {
                printf("la quantite insuffisante en stock pour le produit avec le code %d\n ", code);
                return;
            }
            quantites[i] = quantites[i] - quantite;
            printf("la quantite retiree pour le produit avec le code %d\n", code);
            return;
        }
    }
}

void afficheStock() {
    int i;

    printf("stock total : \n ");

    for (i = 0; i < stock; i++) {
        printf("Produit avec le code %d : et Quantite = %d\n", codes[i], quantites[i]);
    }
}

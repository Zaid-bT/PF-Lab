#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

void addSupply(char ***speciesSupplies, int *numSupplies, int speciesIndex) {
    char supply[MAX_NAME_LENGTH];
    printf("Enter the name of the supply to add: ");
    getchar();
    fgets(supply, MAX_NAME_LENGTH, stdin);
    supply[strcspn(supply, "\n")] = '\0';
    
    (*numSupplies)++;
    speciesSupplies[speciesIndex] = realloc(speciesSupplies[speciesIndex], (*numSupplies) * sizeof(char *));
    speciesSupplies[speciesIndex][*numSupplies - 1] = malloc(strlen(supply) + 1);
    strcpy(speciesSupplies[speciesIndex][*numSupplies - 1], supply);
}

void updateSupply(char ***speciesSupplies, int numSupplies, int speciesIndex) {
    int supplyIndex;
    printf("Enter the index of the supply to update (0 to %d): ", numSupplies - 1);
    scanf("%d", &supplyIndex);

    if (supplyIndex >= 0 && supplyIndex < numSupplies) {
        char supply[MAX_NAME_LENGTH];
        printf("Enter the new name for the supply: ");
        getchar();
        fgets(supply, MAX_NAME_LENGTH, stdin);
        supply[strcspn(supply, "\n")] = '\0';

        free(speciesSupplies[speciesIndex][supplyIndex]);
        speciesSupplies[speciesIndex][supplyIndex] = malloc(strlen(supply) + 1);
        strcpy(speciesSupplies[speciesIndex][supplyIndex], supply);
    } else {
        printf("Invalid supply index!\n");
    }
}

void removeSpecies(char ***speciesSupplies, int *numSpecies, int speciesIndex) {
    for (int i = 0; i < *numSpecies; i++) {
        if (i == speciesIndex) {
            for (int j = 0; speciesSupplies[i] != NULL && speciesSupplies[i][j] != NULL; j++) {
                free(speciesSupplies[i][j]);
            }
            free(speciesSupplies[i]);
            speciesSupplies[i] = speciesSupplies[*numSpecies - 1];
            (*numSpecies)--;
            return;
        }
    }
}

void displayInventory(char ***speciesSupplies, char **speciesNames, int numSpecies) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species: %s\n", speciesNames[i]);
        printf("Supplies:\n");
        for (int j = 0; speciesSupplies[i] != NULL && speciesSupplies[i][j] != NULL; j++) {
            printf("- %s\n", speciesSupplies[i][j]);
        }
    }
}

int main() {
    int numSpecies = 0;
    int maxSpecies = 10;
    int numSupplies = 0;

    char **speciesNames = malloc(maxSpecies * sizeof(char *));
    char ***speciesSupplies = malloc(maxSpecies * sizeof(char **));

    int choice;
    while (1) {
        printf("\n1. Add Species\n2. Add Supply\n3. Update Supply\n4. Remove Species\n5. Display Inventory\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (numSpecies >= maxSpecies) {
                    maxSpecies *= 2;
                    speciesNames = realloc(speciesNames, maxSpecies * sizeof(char *));
                    speciesSupplies = realloc(speciesSupplies, maxSpecies * sizeof(char **));
                }

                char speciesName[MAX_NAME_LENGTH];
                printf("Enter the species name: ");
                getchar();
                fgets(speciesName, MAX_NAME_LENGTH, stdin);
                speciesName[strcspn(speciesName, "\n")] = '\0';

                speciesNames[numSpecies] = malloc(strlen(speciesName) + 1);
                strcpy(speciesNames[numSpecies], speciesName);

                speciesSupplies[numSpecies] = NULL;
                numSupplies = 0;
                numSpecies++;
                break;
            }
            case 2: {
                int speciesIndex;
                printf("Enter the species index (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);

                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    addSupply(speciesSupplies, &numSupplies, speciesIndex);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 3: {
                int speciesIndex;
                printf("Enter the species index (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);

                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    updateSupply(speciesSupplies, numSupplies, speciesIndex);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 4: {
                int speciesIndex;
                printf("Enter the species index (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);

                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    removeSpecies(speciesSupplies, &numSpecies, speciesIndex);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 5: {
                displayInventory(speciesSupplies, speciesNames, numSpecies);
                break;
            }
            case 6:
                for (int i = 0; i < numSpecies; i++) {
                    free(speciesNames[i]);
                    for (int j = 0; speciesSupplies[i] != NULL && speciesSupplies[i][j] != NULL; j++) {
                        free(speciesSupplies[i][j]);
                    }
                    free(speciesSupplies[i]);
                }
                free(speciesNames);
                free(speciesSupplies);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


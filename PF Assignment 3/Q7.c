#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int runtime;
    char encodingFormats[100];
} ContentMetadata;

void initializeEngagementMatrix(double ***engagementMatrix, int numUsers, int numCategories) {
    *engagementMatrix = (double **)malloc(sizeof(double *) * numUsers);
    for (int i = 0; i < numUsers; i++) {
        (*engagementMatrix)[i] = (double *)malloc(sizeof(double) * numCategories);
        for (int j = 0; j < numCategories; j++) {
            (*engagementMatrix)[i][j] = 0.0;
        }
    }
}

void initializeDeviceMatrix(double ****deviceMatrix, int numUsers, int numDevices, int numPreferences) {
    *deviceMatrix = (double ***)malloc(sizeof(double **) * numUsers);
    for (int i = 0; i < numUsers; i++) {
        (*deviceMatrix)[i] = (double **)malloc(sizeof(double *) * numDevices);
        for (int j = 0; j < numDevices; j++) {
            (*deviceMatrix)[i][j] = (double *)malloc(sizeof(double) * numPreferences);
            for (int k = 0; k < numPreferences; k++) {
                (*deviceMatrix)[i][j][k] = 0.0;
            }
        }
    }
}

void initializeContentMetadataMatrix(ContentMetadata ****contentMetadataMatrix, int numCategories, int numContent) {
    *contentMetadataMatrix = (ContentMetadata ***)malloc(sizeof(ContentMetadata **) * numCategories);
    for (int i = 0; i < numCategories; i++) {
        (*contentMetadataMatrix)[i] = (ContentMetadata **)malloc(sizeof(ContentMetadata *) * numContent);
        for (int j = 0; j < numContent; j++) {
            (*contentMetadataMatrix)[i][j] = (ContentMetadata *)malloc(sizeof(ContentMetadata));
            snprintf((*contentMetadataMatrix)[i][j]->title, 100, "Content %d", j + 1);
            (*contentMetadataMatrix)[i][j]->rating = 7.5 + (rand() % 5);
            (*contentMetadataMatrix)[i][j]->runtime = 90 + (rand() % 60);
            snprintf((*contentMetadataMatrix)[i][j]->encodingFormats, 100, "MP4, MKV");
        }
    }
}

void updateEngagement(double **engagementMatrix, int userIndex, int categoryIndex, double score) {
    engagementMatrix[userIndex][categoryIndex] = score;
}

void updateDevicePreference(double ***deviceMatrix, int userIndex, int deviceIndex, int preferenceIndex, double value) {
    deviceMatrix[userIndex][deviceIndex][preferenceIndex] = value;
}

void printEngagementMatrix(double **engagementMatrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }
}

void printDevicePreferencesMatrix(double ***deviceMatrix, int numUsers, int numDevices, int numPreferences) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            for (int k = 0; k < numPreferences; k++) {
                printf("%.2f ", deviceMatrix[i][j][k]);
            }
            printf("\n");
        }
    }
}

void printContentMetadataMatrix(ContentMetadata ***contentMetadataMatrix, int numCategories, int numContent) {
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContent; j++) {
            printf("Title: %s, Rating: %.2f, Runtime: %d min, Formats: %s\n",
                contentMetadataMatrix[i][j]->title,
                contentMetadataMatrix[i][j]->rating,
                contentMetadataMatrix[i][j]->runtime,
                contentMetadataMatrix[i][j]->encodingFormats);
        }
        printf("\n");
    }
}

int main() {
    int numUsers = 3;
    int numCategories = 3;
    int numDevices = 2;
    int numPreferences = 3;
    int numContent = 5;

    double **engagementMatrix = NULL;
    double ***deviceMatrix = NULL;
    ContentMetadata ***contentMetadataMatrix = NULL;

    initializeEngagementMatrix(&engagementMatrix, numUsers, numCategories);
    initializeDeviceMatrix(&deviceMatrix, numUsers, numDevices, numPreferences);
    initializeContentMetadataMatrix(&contentMetadataMatrix, numCategories, numContent);

    updateEngagement(engagementMatrix, 0, 0, 5.5);
    updateEngagement(engagementMatrix, 1, 2, 8.2);

    updateDevicePreference(deviceMatrix, 0, 0, 0, 1080.0);
    updateDevicePreference(deviceMatrix, 1, 1, 2, 1500.0);

    printEngagementMatrix(engagementMatrix, numUsers, numCategories);
    printDevicePreferencesMatrix(deviceMatrix, numUsers, numDevices, numPreferences);
    printContentMetadataMatrix(contentMetadataMatrix, numCategories, numContent);

    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix[i]);
    }
    free(engagementMatrix);

    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);

    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContent; j++) {
            free(contentMetadataMatrix[i][j]);
        }
        free(contentMetadataMatrix[i]);
    }
    free(contentMetadataMatrix);

    return 0;
}


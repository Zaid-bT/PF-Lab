#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;

typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    Weather *weatherForecast;
} Crop;

typedef struct {
    char equipmentType[50];
    int operationalStatus;
    float fuelLevel;
    char schedule[100];
} Equipment;

typedef struct {
    float soilNutrients;
    float soilPH;
    int pestActivity;
} Sensor;

typedef struct {
    float gpsLatitude;
    float gpsLongitude;
    float soilHealth;
    float moistureLevel;
    Crop *crops;
    Equipment *equipments;
    Sensor *sensors;
    int numCrops;
    int numEquipments;
    int numSensors;
} Field;

typedef struct {
    Field *fields;
    int numFields;
    float regionalYieldPrediction;
} RegionalHub;

void initializeField(Field *field, float latitude, float longitude, float soilHealth, float moistureLevel, int numCrops, int numEquipments, int numSensors);
void initializeCrop(Crop *crop, char *cropType, char *growthStage, float expectedYield, Weather *weatherForecast);
void initializeEquipment(Equipment *equipment, char *equipmentType, int operationalStatus, float fuelLevel, char *schedule);
void initializeSensor(Sensor *sensor, float soilNutrients, float soilPH, int pestActivity);
void initializeWeather(Weather *weather, float temperature, float rainfall, float windSpeed);
void printFieldDetails(Field *field);
void cleanupField(Field *field);

int main() {
    Weather *weather = (Weather *)malloc(sizeof(Weather));
    initializeWeather(weather, 25.5, 12.0, 15.0);

    Crop *crop = (Crop *)malloc(sizeof(Crop));
    initializeCrop(crop, "Corn", "Flowering", 1000.0, weather);

    Equipment *equipment = (Equipment *)malloc(sizeof(Equipment));
    initializeEquipment(equipment, "Tractor", 1, 80.0, "Plowing schedule: 8 AM - 12 PM");

    Sensor *sensor = (Sensor *)malloc(sizeof(Sensor));
    initializeSensor(sensor, 7.5, 6.0, 0);

    Field *field = (Field *)malloc(sizeof(Field));
    initializeField(field, 40.7128, -74.0060, 80.0, 30.0, 1, 1, 1);

    field->crops[0] = *crop;
    field->equipments[0] = *equipment;
    field->sensors[0] = *sensor;

    printFieldDetails(field);

    cleanupField(field);
    free(weather);
    free(crop);
    free(equipment);
    free(sensor);

    return 0;
}

void initializeWeather(Weather *weather, float temperature, float rainfall, float windSpeed) {
    weather->temperature = temperature;
    weather->rainfall = rainfall;
    weather->windSpeed = windSpeed;
}

void initializeCrop(Crop *crop, char *cropType, char *growthStage, float expectedYield, Weather *weatherForecast) {
    strcpy(crop->cropType, cropType);
    strcpy(crop->growthStage, growthStage);
    crop->expectedYield = expectedYield;
    crop->weatherForecast = weatherForecast;
}

void initializeEquipment(Equipment *equipment, char *equipmentType, int operationalStatus, float fuelLevel, char *schedule) {
    strcpy(equipment->equipmentType, equipmentType);
    equipment->operationalStatus = operationalStatus;
    equipment->fuelLevel = fuelLevel;
    strcpy(equipment->schedule, schedule);
}

void initializeSensor(Sensor *sensor, float soilNutrients, float soilPH, int pestActivity) {
    sensor->soilNutrients = soilNutrients;
    sensor->soilPH = soilPH;
    sensor->pestActivity = pestActivity;
}

void initializeField(Field *field, float latitude, float longitude, float soilHealth, float moistureLevel, int numCrops, int numEquipments, int numSensors) {
    field->gpsLatitude = latitude;
    field->gpsLongitude = longitude;
    field->soilHealth = soilHealth;
    field->moistureLevel = moistureLevel;
    field->numCrops = numCrops;
    field->numEquipments = numEquipments;
    field->numSensors = numSensors;

    field->crops = (Crop *)malloc(sizeof(Crop) * numCrops);
    field->equipments = (Equipment *)malloc(sizeof(Equipment) * numEquipments);
    field->sensors = (Sensor *)malloc(sizeof(Sensor) * numSensors);
}

void printFieldDetails(Field *field) {
    printf("Field Details:\n");
    printf("GPS Coordinates: (%.4f, %.4f)\n", field->gpsLatitude, field->gpsLongitude);
    printf("Soil Health: %.2f\n", field->soilHealth);
    printf("Moisture Level: %.2f%%\n", field->moistureLevel);

    for (int i = 0; i < field->numCrops; i++) {
        printf("\nCrop %d Details:\n", i + 1);
        printf("Crop Type: %s\n", field->crops[i].cropType);
        printf("Growth Stage: %s\n", field->crops[i].growthStage);
        printf("Expected Yield: %.2f kg\n", field->crops[i].expectedYield);
        printf("Weather - Temperature: %.2f°C, Rainfall: %.2f mm, Wind Speed: %.2f km/h\n",
               field->crops[i].weatherForecast->temperature,
               field->crops[i].weatherForecast->rainfall,
               field->crops[i].weatherForecast->windSpeed);
    }

    for (int i = 0; i < field->numEquipments; i++) {
        printf("\nEquipment %d Details:\n", i + 1);
        printf("Equipment Type: %s\n", field->equipments[i].equipmentType);
        printf("Operational Status: %s\n", field->equipments[i].operationalStatus ? "Operational" : "Not Operational");
        printf("Fuel Level: %.2f liters\n", field->equipments[i].fuelLevel);
        printf("Schedule: %s\n", field->equipments[i].schedule);
    }

    for (int i = 0; i < field->numSensors; i++) {
        printf("\nSensor %d Details:\n", i + 1);
        printf("Soil Nutrients: %.2f\n", field->sensors[i].soilNutrients);
        printf("Soil pH: %.2f\n", field->sensors[i].soilPH);
        printf("Pest Activity: %s\n", field->sensors[i].pestActivity ? "Detected" : "None");
    }
}

void cleanupField(Field *field) {
    free(field->crops);
    free(field->equipments);
    free(field->sensors);
}


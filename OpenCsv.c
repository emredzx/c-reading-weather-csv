#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE* stream = fopen("weatherHistory.csv", "r");

    char Summary[30];
    char PrecipType[15];
    char TemperatureChar[15];
    char HumidityChar[4];
    char WindSpeedChar[15];
    float Temperature;
    float Humidity;
    float WindSpeed;
    int TotalEntry;

    int PartlyCloudyCounter = 0;
    int MostlyCloudyCounter = 0;
    int OvercastCounter = 0;
    int ClearCounter = 0;
    int FoggyCounter = 0;

    int rainCounter = 0;
    int snowCounter = 0;

    float TemperatureTotal = 0.0;
    float HumidityTotal = 0.0;
    float WindspeedTotal = 0.0;

    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strtok(line, ",");
        tmp = strtok(NULL, ",");
        strcpy(Summary, tmp);
        if (strcmp(Summary,"Partly Cloudy") == 0) {
            PartlyCloudyCounter++;
        }
        else if (strcmp(Summary,"Mostly Cloudy") == 0) {
            MostlyCloudyCounter++;
        }
        else if (strcmp(Summary,"Overcast") == 0) {
            OvercastCounter++;
        }
        else if (strcmp(Summary,"Clear") == 0) {
            ClearCounter++;
        }
        else if (strcmp(Summary,"Foggy") == 0) {
            FoggyCounter++;
        }


        tmp = strtok(NULL, ",");
        strcpy(PrecipType, tmp);
        if (strcmp(PrecipType, "rain") == 0) {
            rainCounter++;
        }
        if (strcmp(PrecipType, "snow") == 0){
            snowCounter++;
        }


        tmp = strtok(NULL, ",");
        strcpy(TemperatureChar,tmp);
        Temperature = atof(TemperatureChar);
        TemperatureTotal += Temperature;


        tmp = strtok(NULL, ",");
        tmp = strtok(NULL, ",");
        strcpy(HumidityChar,tmp);
        Humidity = atof(HumidityChar);
        HumidityTotal += Humidity;


        tmp = strtok(NULL, ",");
        strcpy(WindSpeedChar,tmp);
        WindSpeed = atof(WindSpeedChar);
        WindspeedTotal += WindSpeed;
        
        if (tmp != NULL) {
            TotalEntry++;
        }     
    }

    printf("\n************************************************************");
    printf("\nSummary");
    printf("\n------------------------------------------------------------\n");
    printf("\n Partly Cloudy: %d%%", (PartlyCloudyCounter*100)/TotalEntry);
    printf("\n Mostly Cloudy: %d%%", (MostlyCloudyCounter*100)/TotalEntry);
    printf("\n Overcast: %d%%", (OvercastCounter*100)/TotalEntry);
    printf("\n Clear: %d%%", (ClearCounter*100)/TotalEntry);
    printf("\n Foggy: %d%%\n", (FoggyCounter*100)/TotalEntry);
    printf("\n************************************************************");
    printf("\n Precip Type");
    printf("\n------------------------------------------------------------\n");
    printf("\n Rain: %d%%", (rainCounter*100)/TotalEntry);
    printf("\n Snow: %d%%\n", (snowCounter*100)/TotalEntry);
    printf("\n************************************************************\n");
    printf("\n Average Temperature(C): %.6f", TemperatureTotal/TotalEntry);
    printf("\n Average Humidity: %.6f", HumidityTotal/TotalEntry);
    printf("\n Average Wind Speed(km/h): %.6f\n", WindspeedTotal/TotalEntry);
    printf("\n************************************************************");

    fclose(stream);
    return 0;
}
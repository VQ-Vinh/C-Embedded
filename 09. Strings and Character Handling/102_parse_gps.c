/*
You are given a $GPRMC NMEA string from a GPS module in the following simplified format:
    $GPRMC,<time>,<status>,<lat>,<NS>,<long>,<EW>,...
Your task is to:
    Extract and print:
        UTC time in HH:MM:SS format (first field after $GPRMC)
        Latitude with direction (lat NS) : NS- North South
        Longitude with direction (long EW) : EW- East West
Assume:
    Input will always follow this format
    You only need to extract and print the first 7 fields
    Do not validate checksum or GPS fix status
 
Example-1
    Input:
        $GPRMC,123519,A,4807.038,N,01131.000,E
    Output:
        Time: 12:35:19  
        Latitude: 4807.038 N  
        Longitude: 01131.000 E

Example-2
    Input:
        $GPRMC,083559,A,3745.678,N,12227.890,W
    Output:
        Time: 08:35:59  
        Latitude: 3745.678 N  
        Longitude: 12227.890 W
*/
#include <stdio.h>
#include <string.h>

void parse_gprmc(char *nmea) {
    int field_index = 0;
    char *token = strtok(nmea, ",");
    char *lat = NULL;
    char *longi = NULL;

    while (token != NULL)
    {
        if (field_index == 1) {
            printf("Time: %c%c:%c%c:%c%c\n", token[0], token[1], token[2], token[3], token[4], token[5]);
        } else if (field_index == 3) {
            lat = token;
        } else if (field_index == 4) {
            printf("Latitude: %s %s\n", lat, token);
        } else if (field_index == 5) {
           longi = token;
        } else if (field_index == 6) {
            printf("Longitude: %s %s", longi, token);
        }
        field_index++;
        token = strtok(NULL, ",");
    }
}

int main() {
    char nmea[100];
    fgets(nmea, sizeof(nmea), stdin);
    parse_gprmc(nmea);
    return 0;
}
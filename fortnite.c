#include "fortnite.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

FortniteItem fortniteItemCreate(char *name, char *rarity, int vbucks) {
    FortniteItem item;
    strcpy(item.name, name);
    strcpy(item.rarity, rarity);
    item.vbucks = vbucks;
    item.owned = false;
    return item;
}

void fortniteItemPrint(PtFortniteItem item) {
    printf("%-30s | %-20s | %d | %s\n", item->name, item->rarity, 
            item->vbucks, (item->owned) ? "Owned" : "Buy");
}

void fortniteArrayPrint(FortniteItem arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        fortniteItemPrint(&arr[i]);
    }    
}

int fortniteLoadShop(FortniteItem arr[], int howMany) {
    FILE* stream = fopen("fortniteshop.csv", "r");

    /* If file does not exist, abort */ 
    if(stream == NULL) return -1;

    int count = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        if(count == howMany) break;

        char* tmp = strdup(line);
        
        /* creates tokens[3] array, with tokens read from the file line */
        char** tokens = splitString(tmp, 3, ",");
        
        int vbucks = atoi(tokens[2]);
        arr[count++] = fortniteItemCreate(tokens[0], tokens[1], vbucks);

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}

//--------------------

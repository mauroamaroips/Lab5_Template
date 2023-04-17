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

//Nível 1

bool fortniteItemBuy(const char* name, FortniteItem arr[], int arrLength){
    for (int i = 0; i < arrLength; i++)
    {
        if(strcmp(arr[i].name, name) == 0){
            return arr[i].owned = true;
        }
    }
    
    return false;
}

//Nível 2

PtFortniteItem fortniteItemSearch(const char* name, FortniteItem arr[], int arrLength){

    FortniteItem *ptrItem;

    for (int i = 0; i < arrLength; i++)
    {
        if(strcmp(arr[i].name, name) == 0){
            ptrItem = &arr[i];
            return ptrItem;
        } 
    }
    return ptrItem = NULL;
}

//Nível 3

FortniteItem* fortniteArrayCopy(FortniteItem arr[], int arrLength){

    FortniteItem* newArr = (FortniteItem*) malloc(arrLength * sizeof(FortniteItem));

    for (int i = 0; i < arrLength; i++)
    {
        //newArr[i] = arr[i];
        strcpy(newArr[i].name, arr[i].name);
        strcpy(newArr[i].rarity, arr[i].rarity);
        newArr[i].vbucks = arr[i].vbucks;
        newArr[i].owned = arr[i].owned;
    }

    return newArr;
    
}

//Nível 4

   FortniteItem* fortniteFindFreeItems(FortniteItem arr[], int arrLength, int *itemSize){

        FortniteItem *freeItems = (FortniteItem *) calloc(arrLength, sizeof(FortniteItem));

        int countSize = 0;

        for (int i = 0; i < arrLength; i++)
        {
            if(arr[i].vbucks == 0){
                
            
                strcpy(freeItems[countSize].name, arr[i].name);
                strcpy(freeItems[countSize].rarity, arr[i].rarity);
                freeItems[countSize].vbucks = arr[i].vbucks;
                freeItems[countSize].owned = arr[i].owned;
                
                countSize++;
            }
        }

        freeItems = (FortniteItem*) realloc(freeItems, countSize * sizeof(FortniteItem));

        *itemSize = countSize;
        return freeItems;
        
    }

//Nível 5

FortniteItem* fortniteFindRarityItems(FortniteItem arr[], int arrLength, const char* rarity, int *itemSize){

    FortniteItem *rarityArr = (FortniteItem*) calloc(arrLength, sizeof(FortniteItem));
    int countSize = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if(strcmp(arr[i].rarity, rarity) == 0){
            strcpy(rarityArr[countSize].name, arr[i].name);
            strcpy(rarityArr[countSize].rarity, arr[i].rarity);
            rarityArr[countSize].vbucks = arr[i].vbucks;
            rarityArr[countSize].owned = arr[i].owned;
            
            countSize++;
        }
    }

    rarityArr = (FortniteItem*) realloc(rarityArr, countSize * sizeof(FortniteItem));

    *itemSize = countSize;
    return rarityArr;

}

//Nível 5

bool fortniteAddNewItem(FortniteItem item, FortniteItem *arr[], int *pArrLength){

    PtFortniteItem arr2 = *arr;
    int length = *pArrLength;
    
    FortniteItem *newArr = (FortniteItem *) calloc(*pArrLength, sizeof (FortniteItem));

}




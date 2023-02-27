#pragma once

#include <stdbool.h>

typedef struct fortniteItem {
    char name[40];
    char rarity[12];
    int vbucks;
    bool owned;
} FortniteItem;

typedef struct fortniteItem* PtFortniteItem;

FortniteItem fortniteItemCreate(char *name, char *rarity, int vbucks);
void fortniteArrayPrint(FortniteItem arr[], int arrLength);
void fortniteItemPrint(PtFortniteItem item);

/**
 * @brief Loads contents of fortnite shop from csv file.
 * 
 * The caller states 'howMany' records are to be loaded.
 * If less are available, then only those are loaded into the array.
 * 
 * @param arr an array with at least capacity for 'howMany'
 * @param howMany how many items to load. 
 * @return int number of items loaded into 'arr'
 */
int fortniteLoadShop(FortniteItem arr[], int howMany);

//---------------

//Nível 1
//bool fortniteItemBuy(const char* name, FortniteItem arr[], int arrLength);

//Nível 2
//PtFortniteItem fortniteItemSearch(const char* name, FortniteItem arr[], int arrLength);

//Nível 3
//FortniteItem* fortniteArrayCopy(FortniteItem arr[], int arrLength);

//Nível 4
//FortniteItem* fortniteFindFreeItems(FortniteItem arr[], int arrLength, int *itemSize);
//adaptação - critério de seleção
//FortniteItem* fortniteFindRarityItems(FortniteItem arr[], int arrLength, const char* rarity, int *itemSize);


//Nível 5
//bool fortniteAddNewItem(FortniteItem item, FortniteItem *arr[], int *pArrLength);






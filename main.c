#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "fortnite.h"

int main() {
    
    //array em memória stack
    FortniteItem shop[100];

    int shopSize = fortniteLoadShop(shop, 100);
    printf("Imported %d fortnite items:\n", shopSize);
    fortniteArrayPrint(shop, shopSize);

    //-----------

    //Nível 1

    char itemName[50];
    printf("Insira o nome do item: ");
    readString(itemName, 100);

    fortniteArrayPrint(shop, shopSize);

    int checkBuy = fortniteItemBuy(itemName, shop, 100);

    if(checkBuy == false){
        printf("Erro! O item não foi encontrado na shop!\n");
    }
    fortniteArrayPrint(shop, shopSize);

    //Nível 2

    PtFortniteItem checkItemSearch = fortniteItemSearch(itemName, shop, shopSize);
    printf("%p\n", checkItemSearch);

    //Nível 3

    FortniteItem* shopCopy = fortniteArrayCopy(shop, shopSize);
    fortniteArrayPrint(shopCopy, shopSize);

    //Nível 4
    
    int itemSize = 0;
    FortniteItem* freeItems = fortniteFindFreeItems(shop, shopSize, &itemSize);
    //printf("%d", itemSize); Print value on address
    fortniteArrayPrint(freeItems, itemSize);


    for (int i = 0; i < shopSize; i++)
    {
        fortniteItemBuy(freeItems[i].name, shop, shopSize);
    }

    fortniteArrayPrint(shop, shopSize);

    //Nível 4 - 11

    FortniteItem* items = fortniteFindRarityItems(shop,shopSize,"Rare", &itemSize);
    printf("%d\n", itemSize); //Print value on address
    fortniteArrayPrint(items, itemSize);

    //Nível 5
    printf("Adding a new item to the shop...\n");

    FortniteItem newItem = fortniteItemCreate("Spider Gwen", "Legendary", 2000);
    //FortniteItem newItem = fortniteItemCreate("NBA Beacon", "Rare", 400);

    int success = fortniteAddNewItem(newItem, &shopCopy, &shopSize);
    //success = fortniteAddNewItem(newItem, &shop, &shopSize);

    if(success) {
        fortniteArrayPrint(shopCopy, shopSize);
        //fortniteArrayPrint(shop, shopSize);
    } else {
        printf("Não foi possível adicionar o novo item à shop! \n");
    }

    free(freeItems);
    free(items);
    free(shopCopy);

    return EXIT_SUCCESS;
}

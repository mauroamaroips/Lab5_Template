#include <stdio.h> 
#include <stdlib.h>
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

    FortniteItem* newArr = fortniteArrayCopy(shop, shopSize);
    fortniteArrayPrint(newArr, shopSize);

    free(newArr);

    //Nível 4
    
    int itemSize = 0;
    FortniteItem* newFreeItems = fortniteFindFreeItems(shop, shopSize, &itemSize);
    //printf("%d", itemSize); Print value on address
    fortniteArrayPrint(newFreeItems, itemSize);


    for (int i = 0; i < shopSize; i++)
    {
        fortniteItemBuy(newFreeItems[i].name, shop, shopSize);
    }

    fortniteArrayPrint(shop, shopSize);

    free(newFreeItems);

    //Nível 4 - 11

    FortniteItem* newRarityItems = fortniteFindRarityItems(shop,shopSize,"Rare", &itemSize);
    printf("%d\n", itemSize); //Print value on address
    fortniteArrayPrint(newRarityItems, itemSize);

    return EXIT_SUCCESS;
}

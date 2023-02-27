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
    
    return EXIT_SUCCESS;
}

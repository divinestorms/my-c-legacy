#include <stdio.h>

#include "punk.h"


void print_punk(const struct punk* punk) {
    printf("\t\t(%s, %d, %d)\n", punk->name, punk->age, punk->cash);
}

void print_band(const struct band* band) {
    printf("%s : %d\n", band->name, band->rep);
    printf("\t(Name, Age, Cash)\n");
    const struct punk* punk = band->punks;
    while (punk != NULL) {
        print_punk(punk);
        punk = punk->next;
    }
}


int main() {
	struct band* band = band_create("Shit Bucket Union", 30);
	band_append_punk(&band, punk_create("Letov", 30, 0));
    band_append_punk(&band, punk_create("Drunked Punk", 30, 0));
    band_append_punk(&band, punk_create("Junk Punk", 30, 0));


    printf("SCIENCE IS VERY FUN!!!\n\n");
    print_band(band);
    printf("GLORY TO UNION!!!!\n\n");


    band_delete(&band);
	return 0;
}

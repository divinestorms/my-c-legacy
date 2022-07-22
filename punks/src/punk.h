#include <stdlib.h>
#include <string.h>

#ifndef PUNK_H
#define PUNK_H

struct punk {
	char* name;
	int age;
	int cash;

	struct punk* next; /* used if we need list of punks */
};

struct punk*
punk_create(const char* name, int age, int cash) 
{
	struct punk* punk = (struct punk*) malloc(sizeof(struct punk));

	punk->name = (char*) malloc(strlen(name));
	strcpy(punk->name, name);

	punk->age = age;
	punk->cash = cash;
	punk->next = NULL;

	return punk;
}

void 
punk_delete(struct punk* punk)
{
    free(punk->name);
	free(punk);
	punk = NULL;
}



struct band {
	struct punk* punks;
	char* name;
	int rep;
};

struct band*
band_create(const char* name, int rep) 
{
	struct band* band = (struct band*) malloc(sizeof(struct band));

	band->name = (char*) malloc(strlen(name));
    strcpy(band->name, name);

    band->rep = rep;
	band->punks = NULL;

	return band;
}

void
band_append_punk(struct band** band, struct punk* punk)
{
	if (!(*band)->punks) {
		(*band)->punks = punk;
		return;
	}

	struct punk** freepunk = &(*band)->punks;
	while (*freepunk) {
		freepunk = &(*freepunk)->next;
	}

	(*freepunk) = punk;
}

void
band_delete(struct band** band)
{
    struct punk* next;
    while ((*band)->punks != NULL) {
        next = (*band)->punks;
        (*band)->punks = (*band)->punks->next;
        punk_delete(next);
    }
    free((*band)->name);
    free(*band);
    *band = NULL;
}


#endif
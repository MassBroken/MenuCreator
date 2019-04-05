#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct menu{
    int number;
    char *colour;
    char *options;
};

typedef struct menu menuSetting;

int createMenu(menuSetting *m);
void setOptions(menuSetting *m, char* o);
void setColour(menuSetting *m, char *c);
char* getOptions(menuSetting *m);

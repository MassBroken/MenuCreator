#include "Menu.h"
int createMenu(menuSetting *m){
    /*
    this first part of the function provides the tokening of the options string
     */

    int i=0;
    int exit=10;
    char *p= strtok(m->options,"\n");
    char *array[40];
    int j=0,k=0;
    while(p!=NULL){
        array[j++]=p;
        p = strtok(NULL,"\n");
        k++;
    }
    //printing the menu. this is cleared at every event, in order to select the proper option
    //DON'T MOVE THE SYSTEM CALL INTO THE LOOP. IT WILL SLOW EVERYTHING DOWN
    system("cls");
    while (exit!=0){
        printf(" _____________________________________________________\n");
        printf("|                                                     |\n");
        printf("|\t\t\tMENU                          |\n");
        printf("|_____________________________________________________|\n");
        for(int t=0; t<k; t++){
            if( t == i){
                printf(m->colour);
                for(int bs=0; bs<26-(strlen(array[i])/2);bs++){
                    printf(" ");
                }
                printf(array[i]);
                printf("\x1b[0m\n");
            }
            else{
               for(int bs=0; bs<26-(strlen(array[t])/2);bs++){
                    printf(" ");
                }
                printf("%s\n",array[t]);
            }
        }
        //keyboard listener, to manage arrows and ENTER event
        switch(getch()){
            case 0xE0:
                switch(getch()){
                    case 72:
                        system("cls");
                        if(i!=0){
                            i--;
                        }
                        break;
                    case 80:
                        system("cls");
                        if(i<k-1){
                            i++;
                        }
                        //exit --;
                    }
                break;
            case '\r':
                            exit=0;
            }
    }
    return i;
}

//Functions developed in order to properly use the menu ADT
void setOptions(menuSetting* m, char* o){
    m->options=o;
}

void setColour(menuSetting* m, char* c){

    if(strcmp(c,"Blue") || strcmp(c, "blue")){
        char *col="\x1b[34m";
        m->colour=col;
    }
    else if(strcmp(c,"Red")||strcmp(c,"red")){
        char *col="\x1b[31m";
        m->colour=col;
    }
    else if(strcmp(c,"Green")||strcmp(c,"green")){
        char *col="\x1b[32m";
        m->colour=col;
    }
    return m;
}

char* getOptions(menuSetting *m){
    return m->options;
}

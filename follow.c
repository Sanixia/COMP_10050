//
// Created by chant on 03/05/2022.
//

#include <stdio.h>
#include <string.h>
#include "definitions_and_prototype_file.h"


void follow_user(twitter * twitter_system, int userNumber){
    int i, j, k;
    int checkIfInList = 0, checkValidUsername = 0;
    char name[30];


    printf("\nHere is a list of users you haven't followed yet:");

    for (i = 0; i < twitter_system->num_users; i++){

        if (strcmp( twitter_system->max_users[userNumber].username, twitter_system->max_users[i].username) != 0){
            checkIfInList = 0;

            for (j = 0; j < MAX_FOLLOWING; j++){
                if (strcmp( twitter_system->max_users[userNumber].following[j], twitter_system->max_users[i].username) == 0){
                    checkIfInList = 1;
                    j = MAX_FOLLOWING;
                }
            }

            if (checkIfInList == 0){
                printf("\nUser %d: %s",i , twitter_system->max_users[i].username );
            }
        }
    }


    if (checkIfInList == 1){
        printf("\nExcept it looks like you followed everyone!\n");
    }

    else{

        while(checkValidUsername == 0){
            printf("\n\nPlease enter the valid username of the person you want to follow: ");

            fgets(name, USR_LENGTH, stdin);

            if(name[strlen(name) - 1] == '\n'){
                name[strlen(name) - 1] = '\0';      //replaces the end of each input with \0 instead of \n otherwise it wouldn't work correctly
            }

            for(k = 0;k < twitter_system->num_users;k++){
                if ((strcmp(twitter_system->max_users[k].username, name) == 0) && (strcmp( twitter_system->max_users[userNumber].username, twitter_system->max_users[k].username) != 0)){
                    checkValidUsername = 1;
                    k = twitter_system->num_users;
                }
            }
        }


        strcpy( twitter_system->max_users[userNumber].following[twitter_system->max_users[userNumber].num_following], name);
        twitter_system->max_users[userNumber].num_following++;
        printf("\n%s has been added to your following list!\n", name);
    }

}


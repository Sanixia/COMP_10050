//
// Created by chant on 04/05/2022.
//

#include <stdio.h>
#include <string.h>

#include "definitions_and_prototype_file.h"

void unfollow_user(twitter * twitter_system, int userNumber) {
    int i, k, l, m;
    int checkValidUsername = 0;
    char name[30];

    printf("\nHere is your list of people you follow: ");

    if (twitter_system->max_users[userNumber].num_following == 0) {
        printf("\nExcept it looks like you don't follow anyone!");
    } else {
        for (i = 0; i < twitter_system->max_users[userNumber].num_following; i++) {
            printf("\n-> %s", twitter_system->max_users[userNumber].following[i]);
        }



        while (checkValidUsername == 0) {
            printf("\n\nPlease enter the valid username of the person you want to unfollow: ");


            fgets(name, USR_LENGTH, stdin);

            if (name[strlen(name) - 1] == '\n') {
                name[strlen(name) - 1] = '\0';      //replaces the end of each input with \0 instead of \n otherwise it wouldn't work correctly
            }

            for(k = 0;k < twitter_system->num_users;k++) {
                if ((strcmp(twitter_system->max_users[k].username, name) == 0) &&
                    (strcmp(twitter_system->max_users[userNumber].username, twitter_system->max_users[k].username) != 0)) {
                    checkValidUsername = 1;
                    k = twitter_system->num_users;
                }
            }


            for(l = 0; l < twitter_system->max_users[userNumber].num_following; l++){
                if(strcmp(twitter_system->max_users[userNumber].following[l], name) == 0){

                    for(m = l; m < twitter_system->max_users[userNumber].num_following; m++){

                        strcpy(twitter_system->max_users[userNumber].following[m], twitter_system->max_users[userNumber].following[m+1]);
                    }
                }
            }

            twitter_system->max_users[userNumber].num_following--;
        }

    }
}

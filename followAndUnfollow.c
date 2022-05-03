//
// Created by chant on 03/05/2022.
//

#include <stdio.h>
#include <string.h>
#include "twitter_create.h"
#include "followAndUnfollow.h"

void follow_user(twitter * twitter_system, int userNumber){
    int i;
    char name[30];


    printf("\nHere is a list of users you haven't followed yet:\n");

    for (i = 0; i < twitter_system->num_users; i++){
        if ( (strcmp( twitter_system->max_users[userNumber].followers[i], twitter_system->max_users[i].username) != 0) && (strcmp( twitter_system->max_users[userNumber].username, twitter_system->max_users[i].username) != 0)){
            printf("%s\n",twitter_system->max_users[i].username );
        }
    }

    printf("\nPlease enter the username of the person you want to follow: ");

    fgets(name, USR_LENGTH, stdin);
    if (strlen(name) - 1 == '\n'){
        name[strlen(name) - 1] = '\0';
    }


    strcpy( twitter_system->max_users[userNumber].following[twitter_system->max_users[userNumber].num_following], name);
    twitter_system->max_users[userNumber].num_following++;
    printf("%s", (twitter_system->max_users[userNumber].following[twitter_system->max_users[userNumber].num_following]));
    printf("%d",(twitter_system->max_users[userNumber].num_following));

}
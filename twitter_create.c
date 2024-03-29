//
// Created by Lili on 30/03/2022.
//

#include <stdio.h>
#include <string.h>
#include "definitions_and_prototype_file.h"

void create_twitter_system(twitter * twitter_system){

    int i, numOfUsers = 101;
    twitter_system->num_users = 0;
    twitter_system->num_tweets = 0;

    printf("Welcome to Twitter!\n");

    while(numOfUsers > 100){
        printf("\nPlease enter the amount of users (1-100) that you want to input into Twitter: ");
        scanf("%d", &numOfUsers);

        if (numOfUsers < 1){
            numOfUsers = 101;
        }
    }
    scanf("%c", (char *) stdin); //needed this code to flush out the leftover /n otherwise fgets won't work properly

    for(i = 0;i < numOfUsers;i++){

        printf("\nPlease input the username of the current user (max length of a username is 100 characters) and press enter to finish:\n");


        fgets(twitter_system->max_users[i].username, USR_LENGTH, stdin);
        if(twitter_system->max_users[i].username[strlen(twitter_system->max_users[i].username) - 1] == '\n'){
            twitter_system->max_users[i].username[strlen(twitter_system->max_users[i].username) - 1] = '\0';      //replaces the end of each input with \0 instead of \n otherwise it wouldn't work correctly
        }


        twitter_system->max_users[i].num_followers = 0;
        twitter_system->max_users[i].num_following = 0;
        twitter_system->num_users += 1;
    }



}



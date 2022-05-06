//unfollow a user from follow list and the other user's follower list

#include <stdio.h>
#include <string.h>

#include "definitions_and_prototype_file.h"

void unfollow_user(twitter * twitter_system, int userNumber) {
    int i, k, j;                               //loop variables
    int checkValidUsername = 0, followerNumber = 0;
    char name[30];

    printf("\nHere is your list of people you follow: ");

    if (twitter_system->max_users[userNumber].num_following == 0) {
        printf("\nExcept it looks like you don't follow anyone!\n");



    } else {
        for (i = 0; i < twitter_system->max_users[userNumber].num_following; i++) {
            printf("\n-> %s", twitter_system->max_users[userNumber].following[i]);
        }



        while (checkValidUsername == 0) {
            printf("\n\nPlease enter the valid username of the person you want to unfollow: ");
            fgets(name, USR_LENGTH, stdin);

            if (name[strlen(name) - 1] == '\n') {
                name[strlen(name) - 1] = '\0';
            }


            for (k = 0; k < twitter_system->num_users; k++) {                                                                  //checks for valid inputted username
                if ((strcmp(twitter_system->max_users[k].username, name) == 0) &&
                    (strcmp(twitter_system->max_users[userNumber].username, twitter_system->max_users[k].username) !=0)){

                    for (j = 0; j < twitter_system->max_users[userNumber].num_following;j++){
                        if (strcmp(twitter_system->max_users[userNumber].following[j], name) == 0){
                            checkValidUsername = 1;
                            followerNumber = k;
                            k = twitter_system->num_users;
                        }
                    }
                }

            }
        }





            //functions remove person from user's following list and user from follower's list respectively

            removal(&twitter_system->max_users[userNumber].num_following, name, &twitter_system->max_users[userNumber].following[0]);
            removal(&twitter_system->max_users[followerNumber].num_followers, twitter_system->max_users[userNumber].username, &twitter_system->max_users[followerNumber].followers[0]);



            printf("%s has been removed from your following list!\n", name);

            printf("\nCurrent number of followers: %d \nCurrent number of users following: %d\n",
                   twitter_system->max_users[userNumber].num_followers,
                   twitter_system->max_users[userNumber].num_following);

        }


    }



void removal(int  *numberOf, char name[], char characters[][USR_LENGTH]){

    int m, l;
    for(l = 0; l < *numberOf; l++){
        if(strcmp(characters[l], name) == 0){

            for(m = l; m < *numberOf; m++){

                strcpy(characters[m], characters[m+1]);  //once person is found, everything after the person's
                                                                    //index in list is copied back by one to reduce the list and remove the person
            }
            (*numberOf)--; //decrements the user followings/followers
        }
    }
}
//follow a user and add to the other user's follower list


#include <stdio.h>
#include <string.h>
#include "definitions_and_prototype_file.h"


void follow_user(twitter * twitter_system, int userNumber){
    int i, j, k;                                                                     //variables for loops
    int checkIfInList = 0, checkAgain = 0, checkValidUsername = 0, followerNumber = 0, isFollower = 0;
    char name[30];                                                                      //user input name variable


    printf("\nHere is a list of users you haven't followed yet:");

    for (i = 0; i < twitter_system->num_users; i++){   //loop for people the user hasn't followed yet

        if (strcmp( twitter_system->max_users[userNumber].username, twitter_system->max_users[i].username) != 0){   //checks if current username doesn't match the user's name
            checkIfInList = 0;

            for (j = 0; j < MAX_FOLLOWING; j++){
                if (strcmp( twitter_system->max_users[userNumber].following[j], twitter_system->max_users[i].username) == 0){   //checks if the user has followed a person and stops loop if they do
                    checkIfInList = 1;
                    checkAgain += 1;                                                                                            //this variable is keep track if the user has followed everyone
                    j = MAX_FOLLOWING;
                }
            }

            if (checkIfInList == 0){                                                    //if j loop doesn't terminate, then it prints out the user i that hasn't been followed yet
                printf("\n* %s", twitter_system->max_users[i].username);
            }
        }
    }


    if (checkAgain == twitter_system->num_users - 1){                                  //- 1 to exclude the user itself from total amount of users
        printf("\nExcept it looks like you followed everyone!\n");
    }

    else{

        while(checkValidUsername == 0){
            printf("\n\nPlease enter the valid username of the person you want to follow: ");         //will keep looping until a valid username is inputted to follow

            fgets(name, USR_LENGTH, stdin);

            if(name[strlen(name) - 1] == '\n'){
                name[strlen(name) - 1] = '\0';
            }

            for(k = 0;k < twitter_system->num_users;k++){                //will check if inputted username is a valid username

                if ((strcmp(twitter_system->max_users[k].username, name) == 0) &&
                (strcmp( twitter_system->max_users[userNumber].username, twitter_system->max_users[k].username) != 0)){
                    isFollower = 0;

                    for (j = 0; j <= twitter_system->max_users[userNumber].num_following;j++){
                        if (strcmp(twitter_system->max_users[userNumber].following[j], name) == 0){
                            isFollower += 1;                                                            //checks to see if given user is a follower
                        }
                    }
                    if (isFollower == 0){  //if not, then ends while loop

                        checkValidUsername = 1;
                        followerNumber = k;
                        k = twitter_system->num_users;

                    }
                }
            }
        }


        strcpy( twitter_system->max_users[userNumber].following[twitter_system->max_users[userNumber].num_following], name);   //copies the person the user wants to follow into their following list
        twitter_system->max_users[userNumber].num_following++;

        strcpy( twitter_system->max_users[followerNumber].followers[twitter_system->max_users[followerNumber].num_followers], twitter_system->max_users[userNumber].username);  //copies the user into the other persons follower list
        twitter_system->max_users[followerNumber].num_followers++;

        printf("\n%s has been added to your following list!\n", name);

        printf("\nCurrent number of followers: %d \nCurrent number of users following: %d\n",
               twitter_system->max_users[userNumber].num_followers,
               twitter_system->max_users[userNumber].num_following);
    }

}


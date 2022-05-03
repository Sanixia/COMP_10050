#include <stdio.h>
#include "twitter_create.h"
#include "followAndUnfollow.h"



int main() {

    twitter twitter_system;
    create_twitter_system(&twitter_system);
    printf("test 4");


    for(int i = 0; i < twitter_system.num_users; i++){  //for loop to print out the username, followers and users following for each user

        printf("User: %s; Followers: %d; Following: %d\n",
               twitter_system.max_users[i].username,
               twitter_system.max_users[i].num_followers,
               twitter_system.max_users[i].num_followers );
    }












    // michal section



    int j;
    int check = 0;
    int choice;


    for (j=0; j!=twitter_system.num_users; j++)
    {
        while (check == 0)
        {
            printf("\nPlease choose from one of these functions\n");
            printf("1) Follow\n");
            printf("2) Unfollow\n");
            printf("3) PostFeed\n");
            printf("4) Delete Account\n");
            printf("5) End Turn\n\n");


            printf("Type in the digit of the function that you'd like to access: ");
            scanf("%d", &choice);


            if (choice <= 5 && choice >= 1) {
                check = 1;

            } else {
                printf("\n\n------ INVALID INPUT ------\n");
                printf("Returning to Main Menu...\n\n\n\n");
            }
        }
    }


}

#include <stdio.h>
#include "twitter_create.h"
#include "followAndUnfollow.h"



int main() {

    twitter twitter_system;
    create_twitter_system(&twitter_system);



    for(int i = 0; i < twitter_system.num_users; i++){  //for loop to print out the username, followers and users following for each user

        printf("User: %s; Followers: %d; Following: %d\n",
               twitter_system.max_users[i].username,
               twitter_system.max_users[i].num_followers,
               twitter_system.max_users[i].num_followers );
    }












    // Michal section



    int j;
    int check = 1;
    int choice;


    for (j=0; j<twitter_system.num_users; j++)
    {
        check = 1;
        while (check == 1)
        {
            printf("\nPlease choose from one of these functions\n");
            printf("1) Follow\n");
            printf("2) Unfollow\n");
            printf("3) Post Feed\n");
            printf("4) Get News Feed\n");
            printf("5) Delete Account\n");
            printf("6) End Turn\n");
            printf("7) End Twitter\n");



            printf("Type in the digit of the function that you'd like to access: ");
            scanf("%d", &choice);


            if (choice <= 7 && choice >= 1) {
                check = 1;
            }

            else {
                printf("\n\n------ INVALID INPUT ------\n\n\n");
            }


            // Service 1 - Follow
            if (choice == 1)
            {

            }



            // Service 2 - Unfollow
            if (choice == 2)
            {

            }



            // Service 3 - PostFeed
            if (choice == 3)
            {

            }


            // Service 4 - Get News Feed
            if (choice == 4)
            {

            }


            // Service 5 - Delete Account
            if (choice == 5)
            {

            }


            // Service 6 - End Turn
            if (choice == 6)
            {
                if (j!=twitter_system.num_users-1) {
                    printf("\nMoving onto next user");
                }

                check = 0;
            }


            // Service 7 - End Twitter
            if (choice == 7)
            {
                printf("\nTwitter has Terminated");
                j = twitter_system.num_users;
                check = 0;
            }
        }
    }


}

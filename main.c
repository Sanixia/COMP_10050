#include <stdio.h>
#include "definitions_and_prototype_file.h"
#include "feedStack.h"




int main() {



    twitter twitter_system;
    create_twitter_system(&twitter_system);

    twitter_system.num_tweets = 0;




    for(int i = 0; i < twitter_system.num_users; i++){  //for loop to print out the username, followers and users following for each user

        printf("User: %s; Followers: %d; Following: %d\n",
               twitter_system.max_users[i].username,
               twitter_system.max_users[i].num_followers,
               twitter_system.max_users[i].num_followers );
    }



    //
    // Main Twitter menu system
    //


    int j;
    int check = 1, check2 = 1, firsttime=1;
    int choice;



    // Made to work with link list
    /*
    ListNodePtr startPtr = NULL; // initially there are no nodes
    char item; // char entered by user
    */
    while (check2 == 1) {
        // Menu system loops through each user

        if (firsttime==0) {
            printf("\nMoving onto next user\n");
        }


        for (j = 0; j < twitter_system.num_users; j++) {

            // error check loop, make sures the user only enter anything from 1 to 7

            check = 1;
            while (check == 1) {
                printf("\nPlease choose from one of these functions\n");
                printf("1) Follow\n");
                printf("2) Unfollow\n");
                printf("3) Post Feed\n");
                printf("4) Get News Feed\n");
                printf("5) Delete Account\n");
                printf("6) End Turn\n");
                printf("7) End Twitter\n");


                // users choice

                printf("Type in the digit of the function that you'd like to access: ");
                scanf("%d", &choice);


                // error check for valid input

                if (choice <= 7 && choice >= 1) {
                    check = 1;
                } else {
                    printf("\n\n------ INVALID INPUT ------\n\n\n");
                }



                //// Service 1 - Follow

                // Twitter_system (mother struct) and the users identifier number are sent as arguments to follow function
                // User is presented with the list of other users that he hasn't yet followed and is given a choice of who to follow

                if (choice == 1) {
                    scanf("%c", (char *) stdin);
                    follow_user(&twitter_system, j);
                }



                //// Service 2 - Unfollow

                // Twitter_system and the user number are sent as arguments to unfollow function
                // User is presented with the list users currently following and is given a choice of who to unfollow

                if (choice == 2) {
                    scanf("%c", (char *) stdin);
                    unfollow_user(&twitter_system, j);
                }



                //// Service 3 - PostFeed

                // Twitter_system, the user number, and number of tweets on the system are sent as arguments to the postFeed function
                // User is prompted a char array message to post

                if (choice == 3) {
                    // This section of the code is the current working postFeed, which is stored in newsFeed

                    scanf("%c", (char *) stdin);
                    postTweet(&twitter_system, j, twitter_system.num_tweets);
                    twitter_system.num_tweets++;


                    // This section is the work-in-progress postFeed that should utilize a link list for its tweets

                    /*
                    printf("\n\nEnter a character to add to the feed: " );
                    scanf( "\n%c", &item );
                    insert( &startPtr, item ); // insert item in list
                    printList( startPtr );
                    */
                }



                //// Service 4 - Get News Feed

                // Twitter_system and the user number are sent as arguments to GetNewsFeed function
                // Currently implemented to work for the newsFeed array
                // Retrieves up to the 10 most recent tweets from yourself or users followed

                if (choice == 4) {
                    getNewsFeed(&twitter_system, j);

                    //getNewsFeed (&twitter_system, twitter_system->max_users[j]);
                }



                //// Service 5 - Delete Account

                if (choice == 5) {
                    scanf("%c", (char *) stdin);
                    deleteAccount(&twitter_system, j, twitter_system.max_users[j].username);
                    printf("\nAccount deleted, moving onto next user..\n");
                    check = 0;
                }



                //// Service 6 - End Turn

                // This service simply escapes the inner loop and goes to the next user

                if (choice == 6) {
                    if (j != twitter_system.num_users - 1) {
                        printf("\nMoving onto next user\n");
                    }

                    check = 0;
                }



                //// Service 7 - End Twitter

                // This service exits both loops and terminates the Twitter system

                if (choice == 7) {
                    printf("\nTwitter has Terminated");
                    j = twitter_system.num_users;
                    check = 0;
                    check2 = 0;
                }
            }
            firsttime=0;
        }
    }
}
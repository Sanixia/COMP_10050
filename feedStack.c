//
// Created by User01 on 03/05/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "definitions_and_prototype_file.h"
#include "feedStack.h"




// Currently a sample link list , working with individual characters

// Takes in elements, they will go to the front
// Elements can be deleted from any point of the listNode

// Working on version for tweets instead of character nodes
// Switch cases need to replaced with their correct functions




/* self-referential structure */
struct listNode {
    char data;
    struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */


typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );

/* For now main is commented out as two can't exist at the same time
 * big rework as switch cases wont be used
 * Once this section is done we'll be able to post Tweet's here successfuly then modify the functions
 *
 *
int main( void )
{
    ListNodePtr startPtr = NULL; // initially there are no nodes
    int choice; // user's choice
    char item; // char entered by user

    instructions(); // display the menu
    printf( "? " );
    scanf( "%d", &choice );

    //// !! Switch case menu system , needs to be replaced by according fucntions
    while ( choice != 4 ) {
        switch ( choice ) {
            case 1:
                printf( "Enter a character: " );
                scanf( "\n%c", &item );
                insert( &startPtr, item ); //insert item in list
                printList( startPtr );
                break;
            case 2: // delete an element
                // if list is not empty
                if ( !isEmpty( startPtr ) ) {
                    printf( "Enter character to be deleted: " );
                    scanf( "\n%c", &item );
                    // if character is found, remove it
                    if ( delete( &startPtr, item ) ) { // remove item
                        printf( "%c deleted.\n", item );
                        printList( startPtr );
                    } // end if
                    else {
                        printf( "%c Is not as the beginning of the queue.\n\n", item );
                    } // end else
                } // end if
                else {
                    printf( "List is empty.\n\n" );
                } // end else
                break;
            case 3:
                printList( startPtr );  //// choice 3 added to print list
                break;
            default:
                printf( "Invalid choice.\n\n" );
                instructions();
                break;
        } // end switch

        printf( "? " );
        scanf( "%d", &choice );
    } // end while



    printf( "End of run.\n" );
    return 0; // indicates successful termination
} // end main
*/










/* display program instructions to user */
void instructions( void )
{
    printf( "Enter your choice:\n"
            " 1 to insert an element into the list.\n"
            " 2 to delete an element from the list.\n"
            " 3 to print queue.\n"            //// Option 3 was added
            " 4 to end.\n" );
} /* end function instructions */


/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} /* end function isEmpty */





//// PrintList function will be replaced by getNewsFeed,
//// a) instead of printing the whole list only 10 items will be printed
//// b) only posts of your followers


/* Print the list */
void printList( ListNodePtr currentPtr )
{
    /* if list is empty */
    if ( currentPtr == NULL ) {
        printf( "List is empty.\n\n" );
    } /* end if */
    else {
        printf( "The list is:\n" );

        /* while not the end of the list */
        while ( currentPtr != NULL ) {
            printf( "%c --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        } /* end while */

        printf( "NULL\n\n" );
    } /* end else */
} /* end function printList */




//// Insert function allows thing to be put in at the top of the list
//// No work here other than replacing nodes with tweets


/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value )
{
    ListNodePtr newPtr = malloc( sizeof( ListNode ) ); /* create node */
    if ( newPtr != NULL )          /* is space available */
    {

        newPtr->data = value; /* place value in node */
        newPtr->nextPtr = NULL; /* node does not link to another node */

        ListNodePtr previousPtr = NULL;  /* pointer to previous node in list */
        ListNodePtr currentPtr = *sPtr; /* pointer to current node in list */



        //// Will loop until it finds a NULL spot i.e. top of the queue
        while ( currentPtr != NULL ) {
            previousPtr = currentPtr; /* walk to ... */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */

        /* insert new node at beginning of list */
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } /* end if */
        else { /* insert new node between previousPtr and currentPtr */
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } /* end else */
    } /* end if */

    else {
        printf( "%c not inserted. No memory available.\n", value );
    } /* end else */
} /* end function insert */




//// A lot of work with delete, currently deletes selected element
//// a) if a user deletes their account all their posts must be tracked then deleted
//// b) the nodes then must be moved up to fill in the empty space


char delete( ListNodePtr *sPtr, char value )
{
    /* delete first node */
    if ( value == ( *sPtr )->data ) {
        ListNodePtr tempPtr = *sPtr; /* hold onto node being removed */
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* free the de-threaded node */
        return value;
    } /* end if */

    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = ( *sPtr )->nextPtr;

        /* loop to find the correct location in the list */
        while ( currentPtr != NULL && currentPtr->data != value ) {
            previousPtr = currentPtr; /* walk to ... */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */

        /* delete node at currentPtr */
        if ( currentPtr != NULL ) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            return value;
        } /* end if */
    } /* end else */

    return '\0';
} /* end function delete */
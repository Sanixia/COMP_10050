//
// Created by User01 on 03/05/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "definitions_and_prototype_file.h"
#include "feedStack.h"




//// Linked list in development
////






/*


//// Insert function allows thing to be put in at the top of the list
//// No work here other than replacing nodes with tweets


// Insert a new value into the list in sorted order
void insert( ListNodePtr *sPtr, char value[USR_LENGTH] )
{
    ListNodePtr newPtr = malloc( sizeof( ListNode ) ); // creates node


    if ( newPtr != NULL )
    {

        newPtr->msg = value; // place value in node
        newPtr->nextPtr = NULL;

        ListNodePtr previousPtr = NULL;  // pointer to previous node
        ListNodePtr currentPtr = *sPtr;  // pointer to current node



        //// Will loop until it finds a NULL spot i.e. top of the queue
        while ( currentPtr != NULL ) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // insert new node at beginning of list
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }

    else {
        printf("%c not inserted. No memory available.\n", value );
    }
} // end function insert







//// A lot of work with delete, currently deletes selected element
//// a) if a user deletes their account all their posts must be tracked then deleted
//// b) the nodes then must be moved up to fill in the empty space


char delete( ListNodePtr *sPtr, char value )
{
    // deletes first node
    if ( value == ( *sPtr )->msg ) {
        ListNodePtr tempPtr = *sPtr;
        *sPtr = ( *sPtr )->nextPtr;
        free( tempPtr );
        return value;
    }

    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = ( *sPtr )->nextPtr;

        // loop to find the empty location in the list
        while ( currentPtr != NULL && currentPtr->msg != value ) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // delete node at currentPtr
        if ( currentPtr != NULL ) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            return value;
        }
    }

    return '\0';
} // function delete ends




//// PrintList

// Return 1 if the list is empty, 0 otherwise
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} // function isEmpty ends



// Function should print out all elements of the linked list

void printList( ListNodePtr currentPtr )
{
    // if list is empty
    if ( currentPtr == NULL ) {
        printf("\nThere are no tweets.\n\n");
    }
    else {
        printf("\nThe tweets are:\n");

        // while not the end of the list
        while ( currentPtr != NULL ) {
            printf("%c --> ", currentPtr->msg);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
} // function printList ends



*/

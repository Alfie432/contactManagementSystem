#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(void)
{   
    Contact *head = (Contact *) malloc(sizeof(Contact)); // an empty linked list
    head->next = NULL;
    int choice;
    int length;
    int contactNum;

    // keep on asking for user choice until they decide to exit
    while (1)
    {
        printf("\n1) Add Contact\n2) View Contact\n3) View All Contacts\n4) Remove Contact\n5) Restore\n6) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearBuffer();

        // decide what to do based of input
        switch (choice)
        {
        case 1:
            getInfo();
            addContact(head, storage.name, storage.email, storage.phone);
            break;
        case 2:
            length = countLength(head);
            contactNum = getContactNum();
            printContact(head, contactNum, length);
            break;
        case 3:
            printAllContacts(head);
            break;
        case 4:
            // error handling if the user tries to remove a contact from an empty list
            if (head->next == NULL)
            {
                printf("\nContact List Empty.\n\n");
                break;
            }

            length = countLength(head);
            contactNum = getContactNum();
            removeContact(head, contactNum, length);
            break;
        case 5: 
            // error handling if the user tries to restore an empty list
            if (head->next == NULL)
            {
                printf("\nContact List Empty.\n\n");
                break;
            }

            restore(head, length);
            break;
        case 6:
            free(head);
            return 0;
            break;
        default:
            continue;
        }
    }

    free(head); // just in case
    return 0;
}
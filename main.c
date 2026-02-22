#include <stdio.h>
#include <stdlib.h>

// macros


// define the contact struct, each contact will have this info stored in the contacts file
typedef struct Contact
{
    char name[24];
    char email[32];
    char phone[16];
    Contact next;
} Contact;

char filename[] = "contacts.txt";
FILE *file; // declare the file here, so it can be accessed anywhere

// functions prototypes
Contact *addContact(Contact head, char name, char email, char phone);

int main(void)
{   
    Contact *head = NULL;
    Contact *temp;

    int choice;

    // keep on asking for user choice until they decide to exit
    while (1)
    {
        printf("1) Add Contact\n2) View Contact\n3) View All Contacts\n4) Remove Contact\n5) Restore\n6) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);


        // decide what to do based of input
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5: 
            break;
        case 6:
            return 0;
            break;
        default:
            continue;
        }
    }


    return 0;
}

Contact *addContact(Contact head, char name, char email, char phone)
{
    Contact *temp = malloc(sizeof(Contact));
    // temp->name = name;
    // temp->email = email;
    // temp->phone = phone;
    // temp->next = head;
}
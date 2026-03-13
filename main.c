#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// macros
#define N_MAX 24
#define E_MAX 32
#define P_MAX 20

// define the contact struct, each contact will have this info stored in the contacts file
typedef struct node
{
    char name[N_MAX];
    char email[E_MAX];
    char phone[P_MAX];
    struct node *next;
} Contact;

typedef struct Values
{
    char name[N_MAX];
    char email[E_MAX];
    char phone[P_MAX];
} Values;

// functions prototypes
void clearBuffer(void);
void addContact(Contact *head, char nameToEnter[], char emailToEnter[], char phoneToEnter[]);
void getInfo(void);
void printAllContacts(Contact *head);
void restore(Contact *head, int length);
int countLength(Contact *head);

// define it here so it can be accessed by any function
Values storage;

int main(void)
{   
    Contact *head = (Contact *) malloc(sizeof(Contact)); // an empty linked list
    head->next = NULL;
    int choice = 0;
    int counter;

    // keep on asking for user choice until they decide to exit
    while (1)
    {
        printf("1) Add Contact\n2) View Contact\n3) View All Contacts\n4) Remove Contact\n5) Restore\n6) Exit\n");
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
            break;
        case 3:
            printAllContacts(head);
            break;
        case 4:
            break;
        case 5: 
            // error handling if the user tries to restore an empty list
            if (head->next == NULL)
            {
                printf("\nContact List Empty.\n\n");
            }

            counter = countLength(head);
            restore(head, counter);
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


void clearBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && (ch != EOF))
    {
        // do nothing
    }
}


void addContact(Contact *head, char nameToEnter[], char emailToEnter[], char phoneToEnter[])
{
    Contact *current = head; // create a current struct, and it starts at the head element
    current = head; // set it at the start of the linked list


    // go to the last node
    while (current->next != NULL) 
    {
        current = current->next;
    }

    current->next = (Contact *) malloc(sizeof(Contact)); // create the new node
    
    // asign values to it
    // start at the memory address of current, go to the next node (the created one), and access the name/email/phone property
    strcpy(current->next->name, nameToEnter);
    strcpy(current->next->email, emailToEnter);
    strcpy(current->next->phone, phoneToEnter);
    current->next->next = NULL;
}


void getInfo(void)
{
    printf("\n"); // just for spacing

    // get the input
    printf("Enter the contact's name: ");
    fgets(storage.name, N_MAX, stdin);
    storage.name[strcspn(storage.name, "\n")] = '\0'; // removes the newline so the formatting isn't messed up

    printf("Enter the contact's email: ");
    fgets(storage.email, E_MAX, stdin);
    storage.email[strcspn(storage.email, "\n")] = '\0';

    printf("Enter the contact's phone: ");
    fgets(storage.phone, P_MAX, stdin);
    storage.phone[strcspn(storage.phone, "\n")] = '\0';

    printf("\n"); // just for spacing
}


void printAllContacts(Contact *head)
{
    printf("\nContact List:\n");
    printf("-------------\n"); 

    // check if list is empty or not
    if (head->next == NULL)
    {
        printf("\nNo saved contacts.\n\n");
        return;
    }


    // traverse until the end of the linked list
    Contact *current = head;

    while (current->next != NULL)
    {
        current = current->next;
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);

        printf("\n"); // just for spacing
    }

    printf("\n"); // just for spacing
}


void restore(Contact *head, int length)
{
    Contact *current = head;

    // traverse the linked list
    for (int i = 0; i < length; i++)
    {
        if (current->next == NULL)
        {   
            printf("\nSystem Restored, all contacts deleted.\n\n"); // ! this line doesn't seem to be working
            return; // we are at the end
        }

        current = current->next;
        free(current);
    }

    head->next = NULL; // points to nothing again
}


int countLength(Contact *head)
{
    int counter = 0;
    Contact *current = head;

    while (current->next != NULL)
    {
        current = current->next;
        counter++;
    }

    return counter;
}

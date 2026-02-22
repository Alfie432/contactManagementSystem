#include <stdio.h>

// macros


// define the contact struct, each contact will have this info stored in the contacts file
typedef struct Contact
{
    char name[24];
    char email[32];
    char phone[16];
} Contact;

char filename[] = "contacts.txt";
FILE *file; // declare the file here, so it can be accessed anywhere

// functions prototypes

int main(void)
{   


    return 0;
}
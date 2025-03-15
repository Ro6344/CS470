
#include "Rocio_libFS.h" //header for function declarations 
#include <stdio.h> 
#include <stdlib.h> 

//function to display menu and handle user input 
void menu() {
    FILE *file = NULL; //pointer to manage file operations 
    char filename[] = "Rocio_Introduction.txt";
    int choice;
    char content[] = "Hello! My name is Rocio. I am a Computer Science major. I will be graduating this Spring (hopefully). In my free time I enjoy reading, drawind and coding. Once I graduate I am hoping to get a software enginneering job. I am particularly interested in startup companies";

    //loop to show menu and process user input 
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Write to File\n");
        printf("4. Read File\n");
        printf("5. Close File\n");
        printf("6. Delete File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        //process the user's menu choice 
        switch (choice) {
            case 1:
                //create a file 
                fileCreate(filename);
                break;
            case 2:
                //open a file 
                fileOpen(filename, "r+", &file);
                break;
            case 3:
                //write contents to file 
                if (file)
                    fileWrite(file, content);
                else
                    //must have been opened first
                    printf("Error: Open the file first!\n");
                break;
            case 4:
                if (file)
                    //read file 
                    fileRead(file);
                else
                    //file must be opened first
                    printf("Error: Open the file first!\n");
                break;
            case 5:
                if (file) {
                    //close file and reset pointer
                    fileClose(file);
                    file = NULL;
                } else
                    printf("Error: No file is open!\n");
                break;
            case 6:
                //function to delete file 
                fileDelete(filename);
                break;
            case 7:
                if (file) {
                    //ensure files are closed before exiting
                    fileClose(file);
                }
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu(); //call menu to start
    return 0;
}

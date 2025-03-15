
#include "Rocio_libFS.h"

int fileCreate(const char *filename) {
    //open file in write mode or create if it doesn't exist 
    FILE *file = fopen(filename, "w");
    if (!file) { //check if file pointer is null
        perror("Error creating file");
        return -1;
    }
    fclose(file);//close file after creating it 
    printf("File '%s' created successfully.\n", filename);
    return 0;
}

int fileOpen(const char *filename, const char *mode, FILE **file) {
    //open the file with the given mode read or write 
    *file = fopen(filename, mode);
    if (!*file) { //check if file pointer is null
        perror("Error opening file");
        return -1;
    }
    printf("File '%s' opened successfully.\n", filename);
    return 0;
}

int fileWrite(FILE *file, const char *content) {
    //write given content to file 
    if (fprintf(file, "%s", content) < 0) { //check if write was successful
        perror("Error writing to file");
        return -1;
    }
    printf("Content written successfully.\n");
    return 0;
}

int fileRead(FILE *file) {
    char buffer[1024]; //buffer to store chucks of the files content for reading
    rewind(file); //move file pointer back to the beginning of the file 
    printf("File contents:\n");
    while (fgets(buffer, sizeof(buffer), file)) { //read and print the file's content lnine by line
        printf("%s", buffer);
    }
    printf("\n");
    return 0;
}

int fileClose(FILE *file) {
    //check if an error occrred while closing the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return -1;
    }
    printf("File closed successfully.\n");
    return 0;
}

int fileDelete(const char *filename) {
    //attempt to delete the specified file and check for errors 
    if (remove(filename) != 0) {
        perror("Error deleting file");
        return -1;
    }
    printf("File '%s' deleted successfully.\n", filename);
    return 0;
}

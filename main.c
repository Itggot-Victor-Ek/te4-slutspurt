#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *readFile(){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    int j = 0;
    fp = fopen("./names.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        j++;
    }
    fclose(fp);
    printf("%i\n", j);
    char *words[sizeof(j)];
    fp = fopen("./names.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
        words[i] = line;
        i++;
    }
    printf("Cant close file");
    fclose(fp);
    printf("cant free line");
    if (line)
        free(line);
    printf("I got trouble randomizing! :(");
    int r = rand() % i;
    printf("%i", r);
    return words[r];
}

void draw(char* word){
    printf("%s", word);
}

int main(){
    printf("hello world!\n");
    srand(time(NULL));
    char *word = readFile();
    // int run = 0;
    // while (run){
        draw(word);

    // }

    return 0;
}

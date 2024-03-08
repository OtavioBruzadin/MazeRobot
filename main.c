#include <stdio.h>
#include <string.h>
#include <malloc.h>

char fieldContent[40];
FILE *maze;



void startFile(){
    //reseta o arquivo que ira receber a lista de alunos ordenada
    maze = fopen("maze.txt","w");
    fclose(maze);
}
int getFileSize() {
    char linha[90];
    int index=0;
    maze = fopen("maze.txt", "r");
    while (fscanf(maze, "%s", linha) != EOF) {
        index++;
    }
    fclose(maze);
    return index;
};

int getBiggestLine() {
    char linha[90];
    int size;
    int maxSize =0;
    maze = fopen("maze.txt", "r");
    while (fscanf(maze, "%s", linha) != EOF) {
        size = strlen(linha);
        if(size>maxSize){
            maxSize = size;
        }
    }
    fclose(maze);
    return maxSize;
};
char** createCharMatrix() {
    int rows = getFileSize();
    int columns = getBiggestLine();
    char** matrix = (char**)malloc(rows * sizeof(char*));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(columns * sizeof(char));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }


    char value = '#';
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = value;
        }
    }

    return matrix;
}

char** createMaze(){
    char ** matrix = createCharMatrix();
    char linha[23];
    maze = fopen("maze.txt", "r");
        int i = 0;
        while(fscanf(maze, "%s", linha) != EOF){;
        for (int j = 0; j < strlen(linha); ++j) {
            matrix[i][j]=linha[j];
        }
        i++;
    }
    fclose(maze);
    return matrix;
}

void printCharMatrix(char** matrix) {
    int rows = getFileSize();
    int cols = getBiggestLine();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char** Maze = createMaze();
    printCharMatrix(Maze);
}

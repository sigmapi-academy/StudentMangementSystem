#include<stdio.h>
#include<string.h>

# define SIZE 100

typedef struct Student
{
    /* data */
    int roll;
    char name[50];
    float marks;
} STUDENT;

void insertRecord(char* fileName){
    FILE* fp;
    STUDENT s;
    // DataFiles
    char path[SIZE] = "../DataFiles/";
    strcat(path, fileName);
    printf("%s", path);
    fp = fopen(path, "ab");
    if(!fp){
        printf("File is not present or created in the specified path!");
        return; //exit from function
    }
    printf("\nEnter roll number: ");
    scanf("%d", &s.roll);
    fflush(stdin);
    printf("\nEnter name: ");
    fgets(s.name, 50, stdin);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void displayRecords(char* fileName){
    FILE* fp;
    STUDENT s;
    // DataFiles
    char path[SIZE] = "../DataFiles/";
    strcat(path, fileName);
    printf("%s", path);
    fp = fopen(path, "rb");
    if(!fp){
        printf("File is not present or created in the specified path!");
        return; //exit from function
    }
    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("\n======================================");
        printf("\nRoll number = %d", s.roll);
        printf("\nName = %s", s.name);
        printf("\nMarks = %f", s.marks);
        printf("\n======================================");
    }
    
    fclose(fp);
}

int main(int argc, char const *argv[])
{
    int ch;
    char fileNm[SIZE];
    while (1)
    {
        printf("\n======================================");
        printf("\n1. Add records");
        printf("\n2. Display Records");
        printf("\n3. Search a specific record");
        printf("\n4. Update a specific record");
        printf("\n5. Delete a specific record");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        printf("\n======================================");
        switch (ch)
        {
        case 1:
            printf("\nEnter the file name to append the record: ");
            scanf("%s", fileNm);
            insertRecord(fileNm);
            break;
        
        case 2:
            printf("\nEnter the file name to display the records: ");
            scanf("%s", fileNm);
            displayRecords(fileNm);
            break;
        
        case 0:
            printf("\nGood Bye!");
            return 0; //exit from main()
        default:
            printf("\nWrong option selected!");
            break;
        }
    }
    
    return 0;
}


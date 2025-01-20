#include "School.h"

void scanString(char *str, int maxSize)
{
    int i = 0;
    // printf("Enter your name: ");
    fflush(stdin);
    scanf("%c", &str[i]);
    for (; str[i] != '\n' && i < maxSize - 1;)
    {
        i++;
        scanf("%c", &str[i]);
    }
    str[i] = 0;
}
void add_NewStudent(student *s)
{
    welcomeMessage();
    printf("Please Enter Student Data\n--------------------------------\n");
    printf("Student First Name: ");
    // scanString(s.name, 20);
    scanf("%s", &(*s).name);
    printf("Enter Student Age: ");
    scanf("%d", &(*s).age);
    /*printf("Student Grade: ");
    scanf(" %c", &(*s).grade);*/

    printf("Last name: ");
    scanf(" %s", &(*s).father.name);
    printf("Student ID: ");
    scanf("%d", &(*s).ID);
    printf("Student Father Age: ");
    scanf("%d", &(*s).father.age);
    printf("Father Phone number: ");
    // scanf("%s", &(*s).father.phone);
    scanString(s->father.phone, 12);
    printf("Student Mother name: ");
    scanf("%s", &(*s).mother.name);
    printf("Student Mother Age: ");
    scanf("%d", &(*s).mother.age);
    printf("Student Mother Phone number: ");
    // scanf("%s", &(*s).mother.phone);
    scanString(s->mother.phone, 12);
    printf("Student Num of Brothers: ");
    scanf("%d", &(*s).NoOfbrothers);
    s->brothers = malloc((s->NoOfbrothers) * sizeof(person));
    if (s->NoOfbrothers >= 1)
    {
        for (int i = 0; i < s->NoOfbrothers; i++)
        {
            printf("Brother no. %d name : ", i + 1);
            scanf("%s", &s->brothers[i].name);
            printf("Brother no. %d age : ", i + 1);
            scanf("%d", &s->brothers[i].age);
            // printf("Brother no. %d phone : " , i+1);
            fflush(stdin);
        }
    }
    printf(ANSI_COLOR_GREEN "\n------------------------------\n--> The Student data has been to registered ! <-- \n---------------------------\n" ANSI_COLOR_RESET);
}
void editingOptions(student *school, int option, int size, int *exitFlag)
{
    int i = 0;
    student std;
    switch (option)
    {
    case 1:
        add_NewStudent(&school[i++]);
        break;
    case 2:
        removeStudent(school, &size);
        break;
    case 3:
        printAll(school, size);
        break;
    case 4:
        editStudent(school, size, &std);
        break;
    case 0:
        *exitFlag = 1;
        break;

    default:
        break;
    }
}
void editStudent(student *arr, int size, student *s)
{
    int select, found = 0, index = -1, options = 0, firstEntry = 0;
    char continueEditing;
    ;
    printf(ANSI_COLOR_GREEN "Please Enter the name of student or ID number to edit him from the School:\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Press:\n1: ID          2: Name\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "=====\n==> Choice No. ");
    scanf("%d", &select);
    printf("=====\n" ANSI_COLOR_RESET);

    switch (select)
    {
    case 1:
        printf(ANSI_COLOR_GREEN "ID: ");
        scanf("%d", &(s->ID));
        printf("========\n" ANSI_COLOR_RESET);
        break;
    case 2:
        printf(ANSI_COLOR_GREEN "Name: ");
        scanf("%s%s", s->name, s->father.name);
        printf("==========\n" ANSI_COLOR_RESET);
        break;

    default:
        break;
    }
    for (int i = 0; i < size; i++)
    {
        if (((select == 1) && (arr[i].ID == s->ID)) ||
            (select == 2) && (((string_CompareNotSensetiveCase(arr[i].name, s->name) == 1) && (string_CompareNotSensetiveCase(arr[i].father.name, s->father.name) == 1))))

        {
            found = 1;
            index = i;
            firstEntry = 1;
            delay(1);
            printf(ANSI_COLOR_GREEN "====================================================\n");
            printf("It's Found !\n");
            printf("====================================================\n" ANSI_COLOR_RESET);
            printf("Now you can update your data:\n--------------------------------\n");
            printf("1. First Name.                 2. Last Name.\n3. Student Age.                4. Student Father Age.\n5. Student Grade.              6. Student ID.\n7. Father Phone number.        8. Mother Phone number.\n9. Student Mother age.         10. Num of Brothers.\n0. Back to main menu\n");
            while (1)
            {
                if (firstEntry == 1)
                {
                    printf("Your Choice: ");
                    scanf("%d", &options);
                }
                else if (continueEditing == 'y')
                {
                    printf("Your Choice: ");
                    scanf("%d", &options);
                }
                else if (continueEditing == 'n')
                    break;
                switch (options)
                {
                case 1:
                    printf("Student First Name: ");
                    scanf("%s", arr[i].name);
                    break;
                case 2:
                    printf("Last name: ");
                    scanf(" %s", arr[i].father.name);
                    break;
                case 3:
                    printf("Enter Student Age: ");
                    scanf("%d", &(arr[i].age));
                    break;
                case 4:
                    printf("Student Father Age: ");
                    scanf("%d", &(arr[i].father.age));
                    break;
                case 5:
                    printf("Student Grade: ");
                    scanf(" %c", &(arr[i].grade));
                    break;
                case 6:
                    printf("Student ID: ");
                    scanf("%d", &(arr[i].ID));
                    break;
                case 7:
                    printf("Father Phone number: ");
                    scanf("%s", &(arr[i].father.phone));
                    break;
                case 8:
                    printf("Mother Phone number: ");
                    scanf("%s", arr[i].mother.phone);
                    break;
                case 9:
                    printf("Student Mother Age: ");
                    scanf("%d", &(arr[i].mother.age));
                    break;
                case 10:
                    printf("Student Num of Brothers: ");
                    scanf("%d", &(arr[i].NoOfbrothers));
                    break;
                case 0:
                    break;
                default:
                    printf("Invalid Data Entry!\n");
                    break;
                }
                firstEntry++;
                printf("Do you want to continue editing other students? (y/n): ");
                scanf(" %c", &continueEditing);
            }

            /*arr[i].brothers = malloc((arr[i].NoOfbrothers) * sizeof(person));
            if (arr[i].NoOfbrothers >= 1)
            {
                for (int i = 0; i < arr[i].NoOfbrothers; i++)
                {
                    printf("Brother no. %d name : ", i + 1);
                    scanf("%s", arr[i].brothers[i].name);
                    printf("Brother no. %d age : ", i + 1);
                    scanf("%d", &(arr[i].brothers[i].age));
                    // printf("Brother no. %d phone : " , i+1);
                    fflush(stdin);
                }
            }*/
        }
    }
    if (found == 0)
    {
        delay(1);
        printf(ANSI_COLOR_RED "====================================================\n");
        printf("This Student doesn't exist\n");
        printf("====================================================\n" ANSI_COLOR_RESET);
    }
}

int removeStudent(student *arr, int *size)
{
    student studentToDel;
    int select, found = 0, index = -1;
    printf(ANSI_COLOR_CYAN "Please Enter the name of student or ID number to delete him from the School:\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Press:\n1: ID          2: Name\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "===> ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        printf(ANSI_COLOR_GREEN "ID: ");
        scanf("%d", &studentToDel.ID);
        printf("========\n" ANSI_COLOR_RESET);
        break;
    case 2:
        printf(ANSI_COLOR_GREEN "Name: ");
        scanf("%s%s", studentToDel.name, studentToDel.father.name);
        printf("==========\n" ANSI_COLOR_RESET);
        break;
    default:
        printf("Invalid option.\n");
        return -1;
    }
    for (int i = 0; i < *size; i++)
    {
        if (((select == 1) && (arr[i].ID == studentToDel.ID)) ||
            (select == 2) && (((string_CompareNotSensetiveCase(arr[i].name, studentToDel.name) == 1) && (string_CompareNotSensetiveCase(arr[i].father.name, studentToDel.father.name) == 1))))
        {
            delay(1);
            index = i;
            found = 1;
            for (int j = i; j < *size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            printf(ANSI_COLOR_GREEN "====================================================\n");
            printf("|| It's Found !                                   ||\n");
            printf("|| The Student Data is removed successfully       ||\n");
            printf("====================================================\n" ANSI_COLOR_RESET);
            break;
        }
    }
    if (found == 0)
    {
        delay(1);
        printf(ANSI_COLOR_RED "====================================================\n");
        printf("This Student doesn't exist\n");
        printf("====================================================\n" ANSI_COLOR_RESET);
    }

    return index;
}

void printStudent(const student s)
{
    /*printf("  FName   |   LName  |  Age  | Grade | Father Age | Phone number | Mother name | Mother Age | Phone number | Num of Brothers\n");

    printf("%-10s|  %-9s|%5d|%5c|%11d|%-13s|%-12s|%5d|%-13s|%5d\n",
           s.name, s.father.name, s.age, s.grade, s.father.age, s.father.phone,
           s.mother.name, s.mother.age, s.mother.phone, s.NoOfbrothers);*/
    printf("Student Name: %s\n", s.name);
    printf("Student Age: %d\n", s.age);
    printf("Student Grade: %c\n", s.grade);
    printf("Student ID: %d\n", s.ID);
    printf("Student Father name: %s\n", s.father.name);
    printf("Student Father Age: %d\n", s.father.age);
    printf("Student Father Phone number: %s\n", s.father.phone);
    printf("Student Mother name: %s\n", s.mother.name);
    printf("Student Mother Age: %d\n", s.mother.age);
    printf("Student Mother Phone number: %s\n", s.mother.phone);
    printf("Student Num of Brothers: %d\n", s.NoOfbrothers);
    printf("==============================================\n");

    /*if (s.NoOfbrothers >= 1)
    {
        for (int i = 0; i < s.NoOfbrothers; i++)
        {   printf("Brother no. %d name: %s: \n" , i+1 , s.brothers[i].name);
            printf("Brother no. %d age %d:   \n" , i+1 , s.brothers[i].age);
        }
    }*/
}
int printAll(student *arr, int size)
{
    int i;
    printf(ANSI_COLOR_YELLOW "==============================================\n");
    printf("||         The School Student list:         ||\n");
    printf("==============================================\n" ANSI_COLOR_RESET);
    for (i = 0; i < size && (arr[i].age != 0); i++)
    {
        printf("%d. ", i + 1);
        printStudent(arr[i]);
    }
    // return Real Number of student (Real Size)
    return i;
}
void string_UppertoLower(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}
int string_CompareNotSensetiveCase(char *str1, char *str2)
{
    int flag = 0;
    for (int i = 0; str1[i] || str2[i]; i++)
    {
        flag = 0;
        if ((str1[i] == str2[i]) || (str1[i] == str2[i] - 'A' + 'a') || (str2[i] == str1[i] - 'A' + 'a'))
        {
            flag = 1;
        }
        else
        {
            // printf("Not Same\n");
            return 0;
        }
    }
    if (flag == 1)
    {
        // printf("Same\n");
        return 1;
    }
}

int saveStudents(const student *arr, int size)
{
    FILE *file = fopen(FILENAME, "w"); // Open the file for writing
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return 0; // Return 0 to indicate failure
    }

    // Write each student's data to the file
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%s %d %d %c %d %s %d %s %d %d", arr[i].name, arr[i].age, arr[i].ID, arr[i].grade,
                arr[i].NoOfbrothers, arr[i].father.name, arr[i].father.age, arr[i].father.phone,
                arr[i].mother.name, arr[i].mother.age);

        // Write data of brothers if they exist
        if (arr[i].NoOfbrothers >= 1)
        {
            for (int j = 0; j < arr[i].NoOfbrothers; j++)
            {
                fprintf(file, " %s %d", arr[i].brothers[j].name, arr[i].brothers[j].age);
            }
        }

        fprintf(file, "\n"); // Add a newline after each student's data
    }

    fclose(file); // Close the file
    return 1;     // Return 1 to indicate success
}

// Function to load student data from a text file
int loadStudents(student *arr, int *size)
{
    FILE *file = fopen(FILENAME, "r"); // Open the file for reading
    if (file == NULL)
    {
        perror("Error opening file for reading");
        return 0; // Return 0 to indicate failure
    }

    // Read data from the file and populate the student array
    while (*size < MAX_STUDENTS && fscanf(file, "%s %d %d %c %d %s %d %s %d %d",
                                          arr[*size].name, &arr[*size].age, &arr[*size].ID, &arr[*size].grade,
                                          &arr[*size].NoOfbrothers, arr[*size].father.name, &arr[*size].father.age,
                                          arr[*size].father.phone, arr[*size].mother.name, &arr[*size].mother.age) != EOF)
    {
        // Read data of brothers if they exist
        if (arr[*size].NoOfbrothers >= 1)
        {
            arr[*size].brothers = malloc((arr[*size].NoOfbrothers) * sizeof(person));
            for (int j = 0; j < arr[*size].NoOfbrothers; j++)
            {
                fscanf(file, " %s %d", arr[*size].brothers[j].name, &arr[*size].brothers[j].age);
            }
        }
        (*size)++;
    }

    fclose(file); // Close the file
    return 1;     // Return 1 to indicate success
}

void options()
{
    printf(ANSI_COLOR_CYAN "Please Select your option:\n");
    printf("--------------------------\n");
    printf("0: Exit From the App\n1: Add new Student to School\n2: Remove Student from the School\n3: View all registered students Data\n4: Edit Data of Student\n" ANSI_COLOR_RESET);
}
void delay(int seconds)
{
    int numDots = 14; // Number of dots in the loading animation
    printf(ANSI_COLOR_YELLOW "Loading " ANSI_COLOR_RESET);
    for (int i = 0; i < numDots; i++)
    {

        printf(ANSI_COLOR_YELLOW "." ANSI_COLOR_RESET);

        // fflush(stdout); // Flush the output to make sure dots are displayed immediately

        // Delay for 1 second (adjust the sleep time as needed)
        usleep(300000); // 1 second in microseconds
    }

    printf(ANSI_COLOR_CYAN "\n            <>-------- Done! --------<>\n" ANSI_COLOR_RESET);
}
void welcomeMessage()
{
    printf(ANSI_COLOR_GREEN "====================================================\n");
    printf("||                 Welcome to X School !           ||\n");
    printf("====================================================\n" ANSI_COLOR_RESET);
}
void byeMessage()
{
    printf(ANSI_COLOR_GREEN "====================================================\n");
    printf("||                  Thank You!                    ||\n");
    printf("||                My Best Wishes                  ||\n");
    printf("====================================================\n");
}

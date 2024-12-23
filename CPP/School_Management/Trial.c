#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Include the usleep function
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%2d  ", arr[i]);
    printf("\n");
}
int deleteMember(int *arr, int *size, int numToDelete)
{
    int flag = 0;
    int index, i;
    for (i = 0; i < *size; i++)
    {
        if (arr[i] == numToDelete)
        {
            flag = 1;
            // index = i;
            for (int j = i; j < *size; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            break;
        }
    }

    return i;
}
void delay(int seconds)
{
    int numDots = 7; // Number of dots in the loading animation
    printf("Loading ");
    for (int i = 0; i < numDots; i++)
    {
        printf(".");
        //fflush(stdout); // Flush the output to make sure dots are displayed immediately

        // Delay for 1 second (adjust the sleep time as needed)
        sleep(seconds); // 1 second in microseconds
    }

    printf("\nDone!\n");
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);
    int index = 0, newSize = 0;
    index = deleteMember(arr, &size, 3);
    printf("index = %d\n", index);
    delay(1);
    print_array(arr, size);

    return 0;
}
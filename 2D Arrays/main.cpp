#include <iostream>

int main() {

    //simple arrays of arrays
    //traverses y and then x
    //like stored as a descending table of arrays

    //pointer to an array of size 50
    int* array = new int[50];

    //pointer to 50 integer pointers
    int** a2d = new int*[50];

    //pointer to 50 integers pointers which point to arrays
    for(int i = 0; i < 50; i++)
        a2d[i] = new int[50];

    //pointer to 50 pointers of 50 integer pointer which point to arrays
    //last part +1 dimension basically
    //reminder: *** means a pointer to a pointer to a pointer
    int*** a3d = new int**[50];
    for(int i = 0; i < 50; i++)
    {
        a3d[i] = new int*[50];
        for(int j = 0; j < 50; j++)
        {
            int** ptr = a3d[i];
            ptr[j] = new int[50];
        }
    }

    //access
    a3d[0][0][0] = 0;
    a3d[49][49][49] = 49^3;

    for(int i = 0; i < 50; i++)
        delete[] a2d[i];

    //uses "[]" in delete for all array involved deletions
    delete[] a2d;

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            delete[] a3d[i][j];
        }
        delete[] a3d[i];
    }
    delete[] a3d;


    //USES HEAP: IS SLOW
    //much simpler to just store a single array of 50^3 indexes if possible
    int* arr = new int[5 * 5];
    for(int y = 0; y < 5; y++)
    {
        for(int x = 0; x < 5; x++)
            arr[y*5 + x] = y*5 + x;
    }
}

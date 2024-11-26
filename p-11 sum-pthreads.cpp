#include <pthread.h>
#include <math.h>
#include <iostream>
using namespace std;
// tNum depicts the number of threads the problem is divided into
//  Array is divided into 5 parts
int tNum = 5;
// initializing the sum array
int sumArray[5] = {0};
int arr[15] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
// Calculating the maximum number of elements in each thread
int tSize = ceil(15 / tNum), tPart = 0;
// function used by each thread to compute sum
void *sum(void *arg)
{
    // defining the part of array for which sum is being computed
    int part = tPart;
    tPart++;
    for (int i = part * tSize; i < (part + 1) * tSize; i++)
    {
        sumArray[part] += arr[i];
    }
    pthread_exit(NULL);
}
// main() block that calls upon various threads for executing parallelly
int main()
{
    pthread_t threadID[tNum];
    // 5 threads are created and executed
    for (int i = 0; i < tNum; i++)
    {
        pthread_create(&threadID[i], NULL, sum, (void *)NULL);
    }
    // 5 threads are joined
    for (int i = 0; i < tNum; i++)
    {
        pthread_join(threadID[i], NULL);
    }
    // the sum of all the subparts is added
    int sum = 0;
    for (int i = 0; i < tNum; i++)
    {
        sum += sumArray[i];
    }
    cout << "Sum of array = " << sum;
    return 0;
}
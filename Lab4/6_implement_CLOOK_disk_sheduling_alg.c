// Write a program to implement CLOOK disk scheduling algorithm
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int RQ[100], i, j, n, TotalHeadMoment = 0, inital, size, move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the requests sequence\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&RQ[i]);
    }
    printf("Enter the inital head position\n");
    scanf("%d",&inital);
    printf("Enter the head movement direction for 1 and for low 0\n");
    scanf("%d",&move);
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j + 1] = temp;
            }
        }
    }
    int index;
    for ( i = 0; i < n; i++)
    {
        if (inital < RQ[i])
        {
            index = 1;
            break;
        }
    }
    if(move == 1)
    {
        for(i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - inital);
            inital = RQ[i];
        }
        for ( i = 0; i < index; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - inital);
            inital = RQ[i];
        }
    }
    else
    {
        for ( i = index; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - inital);
            inital = RQ[i];
        }
        for ( i = n; i >= index; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - inital);
            inital = RQ[i];
        }
    }
    printf("Total head movement is %d", TotalHeadMoment);
    return 0;
}
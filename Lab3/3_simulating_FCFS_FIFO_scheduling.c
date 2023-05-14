//simulating First Come First Serve(FCFS) FIFO scheduling in c.
#include<stdio.h>
int main()
{
	int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
	printf("Enter total number of processes(maximum 20) ");
	scanf("%d", &n);
	printf("Enter Process Burst Time \n");
	for(i = 0; i < n; i++)
	{
		printf("P[%d] ",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0] = 0; //waiting time for first process is 0
	for(i = 1; i < n; i++) //calculation waiting time
	{
		wt[i] = 0;
		for(j = 0; j < i; j++)
		{
			wt[i] = wt[i] + bt[j];
		}
	}
	printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");
	for(i = 0; i < n; i++)//calculating turnaround time
	{
		tat[i] = bt[i] + wt[i];
		avwt += wt[i];
		avtat += tat[i];
		printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
	}
	avwt /= i;
	avtat /= i;
	printf("Average Waiting Time %d\n", avwt);
	printf("Average Turnaround Time %d\n", avtat);
	return 0;
}

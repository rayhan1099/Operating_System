#include<stdio.h>
#include<conio.h>
#define  max 30
void main()
{
    int i,j,n,t,pos;
    int p[max],bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    printf("Enter the number of proccess: ");
    scanf("%d",&n);
    printf("Enter the proccess number: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the brust time of the proccess: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    { pos=i;

        for(j=i+1;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    printf("PID\t BT \t WT \t TAT\t\n");


    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t %d\t%d\t %d\t\t \n",p[i],bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Avarage waiting time=%f\n",awt);
    printf("Avarage turn around time=%f",atat);
}

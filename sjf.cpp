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
    {   pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]>bt[pos])
                pos=j;
            {
                t=bt[i];
                bt[i]=bt[pos];
                bt[pos]=t;

                t=p[i];
                p[i]=p[pos];
                p[pos]=t;
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

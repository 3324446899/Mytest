#include <stdio.h>
#include <stdlib.h>

int n;//�ʺ���������̹�ģ��
int a[1000][1000]={0};//����
int c=0;

int judge(int i,int j)//���Էŷ���1�����򷵻�0
{
    int x,y;
    for(x=0;x<n;x++)
    {
        if(a[x][j]==1) return 0;
    }
    for(x=i-1,y=j-1;x>=0&&y>=0;x--,y--)
    {
        if(a[x][y]==1) return 0;
    }
    for(x=i+1,y=j+1;x<n&&y<n;x++,y++)
    {
        if(a[x][y]==1) return 0;
    }
    for(x=i,y=j;x>=0&&y<n;x--,y++)
    {
        if(a[x][y]==1) return 0;
    }
    for(x=i,y=j;x<n&&y>=0;x++,y--)
    {
        if(a[x][y]==1) return 0;
    }
    return 1;
}

void output(int c)
{
    int i,j;
    printf("��%d�ַŷ���\n",c);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("%d\n",a[i][n-1]);
    }
}

void eightqueue(int i)
{
    int j,jud;
    if(i<n)
    {
        for(j=0;j<n;j++)
        {
            jud=judge(i,j);
            if(jud==1)
            {
                a[i][j]=1;
                eightqueue(i+1);
                a[i][j]=0;//�˲��ܱ�Ҫ
            }
        }
    }
    else
    {
        c++;
        output(c);
    }
}

int main()
{
    int j,i,k;
    printf("������ʺ������___\b\b");
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        a[0][j]=1;
        eightqueue(1);
        for(i=0;i<n;i++)
            for(k=0;k<n;k++)
                a[i][k]=0;
    }
    printf("\n%d�ʺ����⹲������%d�ֽⷨ��\n",n,c);
    system("pause");
    return 0;
}

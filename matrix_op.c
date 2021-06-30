#include "hdrfile.h"

void pushleft()
{
    int i=0;
    int j=0;
    int func_temp[4][4];
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            func_temp[i][j]=mat[i][j];
            mat[i][j]=INT_MIN;
        }
    }
    for(i=0;i<4;i++)
    {
        int k=0;
        for(j=0;j<4;j++)
        {
            if(func_temp[i][j]!=INT_MIN)
            {
                
                mat[i][k]=func_temp[i][j];
                if(k!=j)
                {
                    change_val=1;
                strcat(names[i][k],names[i][j]);
               memset(names[i][j],0,sizeof(names[i][j]));
                }
              
                
                  k=k+1;
            }
        }
    }
}
void do_operation(int i,int j)
{
    if(op==1)
    {
        mat[i][j]=2*mat[i][j];
    }
    else if(op==2)
    {
        mat[i][j]=0;
    }
    else if(op==3)
    {
        mat[i][j]=mat[i][j]*mat[i][j];
    }
    else if(op==4)
    {
        mat[i][j]=1;
    }
}
void combineleft()
{
    int i=0;
    int j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(mat[i][j]!=INT_MIN & mat[i][j]==mat[i][j+1])
            {
                do_operation(i,j);
                change_val=1;
                mat[i][j+1]=INT_MIN;
                strcat(names[i][j],names[i][j+1]);
               memset(names[i][j+1],0,sizeof(names[i][j+1]));
            }
        }
    }
}
void transpose()
{
    int func_temp[4][4];
    char temp_names[4][4][200];
    int i=0;
    int j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            func_temp[i][j]=mat[i][j];
            mat[i][j]=INT_MIN;
            strcpy(temp_names[i][j],names[i][j]);
            memset(names[i][j],0,sizeof(names[i][j]));
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            mat[i][j]=func_temp[j][i];
            strcpy(names[i][j],temp_names[j][i]);
            
        }
    }
}
void rotate_func()
{
    int func_temp[4][4];
    char temp_names[4][4][200];
    int i=0;
    int j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            func_temp[i][j]=mat[i][j];
            mat[i][j]=INT_MIN;
            strcpy(temp_names[i][j],names[i][j]);
             memset(names[i][j],0,sizeof(names[i][j]));
            
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            mat[i][j]=func_temp[i][3-j];
            strcpy(names[i][j],temp_names[i][3-j]);
        }
    }
}
void left_operation()
{
    int i=0;
    int j=0;
    pushleft();
    combineleft();
    pushleft();
}
void right_operation()
{
    rotate_func();
    pushleft();
    combineleft();
    pushleft();
    rotate_func();
}
void up_operation()
{
    transpose();
    pushleft();
    combineleft();
    pushleft();
    transpose();
}
void down_operation()
{
    transpose();
    rotate_func();
    pushleft();
    combineleft();
    pushleft();
    rotate_func();
    transpose();
}
void addtile()
{
    int ar[16];
    int cnt=0;
    int i=0;
    int j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==INT_MIN)
            {
                ar[cnt]=(i*4)+j;
                cnt++;
            }
        }
    }
        if(cnt==0)
        return;
        srand(time(0));
        int rand_int=rand()%(cnt);
        int ind1=ar[rand_int]/4;
        int ind2=ar[rand_int]%4;
        int val=ind1%2;
        if(val==0)
        val=2;
        else
        val=4;
        mat[ind1][ind2]=(rand()%2+1)*2;
    
}
void combinefunction()
{
    int i=0;
    int j=0;
    if(dir==4)
    {
        left_operation();
    }
    else if(dir==3)
    {
        right_operation();
    }
    else if(dir==2)
    {
        down_operation();
    }
    else if(dir==1)
    {
        up_operation();
    }
}
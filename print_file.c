#include "hdrfile.h"
void printoutput()
{
    char ans[1000]="";
    char temp[100]="";
    int i=0;int j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]!=INT_MIN)
            {
                char x[20];
                sprintf(x,"%d ",mat[i][j]);
                strcat(temp,x);
            }
            else
            {
                strcat(temp,"0 ");
            }
        }
    }
    temp[strlen(temp)]='\0';
    strcat(ans,temp);
    int p=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            char buff[200]="\0";
            int c=sizeof(names[i][j])/sizeof(names[i][j][0]);
            if(c>0)
            {
                p=1;
                char x[20]="\0";
                sprintf(x,"%d",i+1);
                strcat(buff,x);
                strcat(buff,",");
                sprintf(x,"%d",j+1);
                strcat(buff,x);
                char string_ar[200];
                strcpy(string_ar,names[i][j]);
                string_ar[strlen(string_ar)-1]=' ';
                strcat(buff,string_ar);
                if(strlen(names[i][j])>1)
                strcat(ans,buff);
            }
        }
    }
      if(p)
        ans[strlen(ans)-1]='\0';
    fprintf(stderr,"%s\n",ans);
}
void pointer()
{

    printf("2048 > ");
}
void printstring()
{
    int i=0;
    int j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%s|",names[i][j]);
        }
        printf("\n");
    }
}
void printmatrix()
{
    int i=0;
    int j=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j]!=INT_MIN)
            printf(" %d |",mat[i][j]);
            else
                printf(" 0 |");
        }
        printf("\n.................");
        printf("\n");
    }
    printf("\n");
}
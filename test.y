%{
    #include "hdrfile.h"
%}
%union{int num; char s[200];}
%start first
%token ADD
%token SUBTRACT
%token MULTIPLY
%token DIVIDE
%token LEFT
%token RIGHT
%token UP
%token DOWN
%token ASSIGN
%token TO
%token <s> VAR
%token IS
%token VALUE
%token IN
%token NEXTLINE
%token <num> NUMBERS
%token FULLSTOP
%token SPACE
%token COMMA
%token <cordinates> CORDINATES
%token ERRORF
%token <s>NAME
%%

first: whitespace stmt {
    pointer();
}| first whitespace stmt
{
    pointer();
}
;
stmt: arth_stmt endline
{
     combinefunction();
     if(change_val==1)
     {
         addtile();
         change_val=0;
     }
     int i=0;
     int j=0;
     for(i=0;i<4;i++)
     {
         for(j=0;j<4;j++)
         {
             if(mat[i][j]==0)
             {
                 mat[i][j]=INT_MIN;
                 memset(names[i][j],0,sizeof(names[i][j]));
             }
         }
     }
    printmatrix();
    printoutput();
}
| assignment endline
{
      add_val(val_of,ind1,ind2);
}
| value endline
{
      value_disp(ind1,ind2);
}
| assignment_value endline
{
        if(ind1>4 || ind2>4)
    {
        printf("There is no such tile as the cordinates are not within range\n");
        //fprintf(stderr, "%d\n",-1);
    }
    else
    {
        int p1=ind3;
        int p2=ind4;
        if(p1>4 || p2>4)
        {
            printf("Cannot assign value to given cordinates as it is out of range\n");
            //fprintf(stderr, "%d\n",-1);
        }
        else{
            if(mat[ind1-1][ind2-1]!=INT_MIN)
            {
            mat[p1-1][p2-1]=mat[ind1-1][ind2-1];
            printf("assignmnet done\n");
            printmatrix();
            printoutput();
            }
            else
            {
                printf("Value of the tile mentioned is empty\n");
                fprintf(stderr, "%d\n",-1);
            }
        }
    }
}
| keyprob endline
{

}
| variable endline
{
    int i=0;
    int f=0;
     assign_string(temp_c,ind1,ind2);
     
}
| wrongend noendline {
    printf("Please finish the statement with a FULLSTOP\n");
       // fprintf( stderr, "%d\n",-1);
} 
| error noendline
{
    printf("syntax error\n");
    //fprintf(stderr, "%d\n",-1);
}
;
wrongend: arth_stmt | assignment | value | assign_value | variable
;
arth_stmt: operation SPACE whitespace direction {
    
}
;
assignment: ASSIGN SPACE whitespace NUMBERS SPACE whitespace TO SPACE whitespace NUMBERS whitespace COMMA whitespace NUMBERS {
    val_of=$4;
    ind1=$10;
    ind2=$14;

}
; 
assignment_value: ASSIGN SPACE whitespace assign_value SPACE whitespace TO SPACE whitespace NUMBERS whitespace COMMA whitespace NUMBERS {
ind3=$10;
ind4=$14;
}
; 
value: VALUE SPACE whitespace IN SPACE whitespace NUMBERS whitespace COMMA whitespace NUMBERS{
    ind1=$7;
    ind2=$11;
}
;
assign_value: VALUE SPACE whitespace IN SPACE whitespace NUMBERS whitespace COMMA whitespace NUMBERS{
    ind1=$7;
    ind2=$11;

}
;
keyprob: VAR SPACE whitespace wrongvar SPACE whitespace IS SPACE whitespace NUMBERS whitespace COMMA whitespace NUMBERS
{
    printf("Variable name cannot be a keyword\n");
       // fprintf( stderr, "%d\n",-1);
}
;
variable: VAR SPACE whitespace NAME SPACE whitespace IS SPACE whitespace NUMBERS whitespace COMMA whitespace NUMBERS{
    strcpy(temp_c,$4);
    ind1=$10;
    ind2=$14;
    }
;
operation: ADD {op=1;}| SUBTRACT{op=2;} | MULTIPLY{op=3;} | DIVIDE {op=4;}
;
direction: UP {dir=1;}| DOWN{dir=2;} | RIGHT{dir=3;} | LEFT{dir=4;}
;
wrongvar: ADD | SUBTRACT |MULTIPLY | DIVIDE | LEFT | RIGHT | UP | DOWN | ASSIGN| TO | VAR | IS | VALUE | IN
;
endline: whitespace FULLSTOP NEXTLINE
;
noendline: whitespace NEXTLINE
;
whitespace: | SPACE whitespace
; 
%%
void add_val(int v,int x1,int y1)
{
    if(x1>4 || y1>4)
    {
        printf("There is no such tile as the cordinates are not within range\n");
       // fprintf( stderr, "%d\n",-1);
        return;
    }
    
        mat[x1-1][y1-1]=v;
        printf("%d is assigned to tile %d , %d\n",v,x1,y1);

         printoutput();
         printmatrix();
    
    return;
}
void value_disp(int x,int y)
{
    if(x>4 || y>4)
    {
         printf("There is no such tile as the cordinates are not within range\n");
             //fprintf( stderr, "%d\n",-1);
        return;
    }
    if(mat[x-1][y-1]==INT_MIN)
    {
        printf("No value assigned to this tile\n");
            //fprintf( stderr, "%d\n",-1);
        return;
    }
    printf("Value is %d\n",mat[x-1][y-1]);
}
void assign_string(char str[],int i,int j)
{
    if(i>4 || j>4)
    {
        printf("Cordinates of the tile is out of range\n");
            //fprintf( stderr, "%d\n",-1);
    }
      if(mat[i-1][j-1]!=INT_MIN)
    {
    strcat(names[i-1][j-1],str);
    char x[1]=",";
    strcat(names[i-1][j-1],x);
    printoutput();
   
    }
    else{
        printf("Empty tile cannot be named\n");
        //fprintf( stderr, "%d\n",-1);
    }
}
int main(void)
{
    change_val=0;
      int i=0;
    int j=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            mat[i][j]=INT_MIN;
        }
    }
    addtile();
    printmatrix();
    printoutput();
    pointer();
    return yyparse ( );
}
void yyerror(char* s)
{
    return;
}
    int yylex();
    void yyerror(char* s);
    void add_val(int v,int x1,int y1);
    void printmatrix();
    void value_disp(int x,int y);
    void combinefunction();
    void pushleft();
    void do_operation();
    void combineleft();
    void transpose();
    void left_operation();
    void right_operation();
    void up_operation();
    void down_operation();
    void rotate_func();
    void addtile();
    void assign_string(char str[],int x,int y);
    void printstring();
    void printoutput();
    void tiletoempty();
    void pointer();
    #include<stdio.h>
    #include<stdlib.h>
    #include<limits.h>
    #include<string.h>
    #include<time.h>
    int mat[4][4];
    int temp[4][4];
    char names[4][4][200];
    int ind1;
    int ind2;
    int op;
    int dir;
    int val_of;
    int ind3;
    int ind4;
    int change_val;
    char temp_c[200];
    char keywords[14][200];

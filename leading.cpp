#include<stdio.h>
#include<conio.h>
#include<ctype.h>
struct leadT
{
    int n;
    char lead[5];
};
struct leadT leading[7];
char ip[7][7];
int col,cnt=0;
char Sym[5]={ '+','(',')','*','#','i' };
int isSym(char);
void findLeading(char,int);
void leadTabOp(char,int);
int main()
{
    int i,j,c;
    char b[4];
    for(i=0;i<=5;i++)
    {
        scanf("%s",&ip[i]);
    }
    printf("\n");
     for(i=0;i<6;i++)
       {    c=0;
        for(j=0;j<i+1;j++)
        {
            if(ip[i][0] == b[j])
            {
                c=1;
                break;
            }
        }
        if(c !=1)
        {
          b[cnt] = ip[i][0];
          cnt++;
        }

        }   
    for(i=cnt-1;i>=0;i--)
    {   leading[i].n=0;
        col=1;
        leading[i].lead[0]=b[i];
        findLeading(b[i],i);
    }

    printf("\n");

    for(i=0;i<cnt;i++)
    {
        for(j=0;j<=leading[i].n;j++)
        {
            if(j==0)
            {
                    printf("leading(%c) = { ",leading[i].lead[j]);
             }
           else if(j == leading[i].n)
           {
               printf("%c ",leading[i].lead[j]);
           }
           else
           {
               printf("%c,",leading[i].lead[j]);
           }

        }
        printf("}");
        printf("\n");
    }

}
int isSym(char ip)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(ip==Sym[i])
        {
            return 1;
        }
    }

    return 0;
}
void findLeading(char p,int row)
{
    int i;
    for(i=5;i>=0;i--)
    {
        if(p == ip[i][0])
        {
            if((ip[i][2] == '>') && (ip[i][4]=='\0'))
            {
                if(isupper(ip[i][3]))
                {
                                leadTabOp(ip[i][3],row);
                }
                else
                {
                                leading[row].lead[col]=ip[i][3];
                                leading[row].n++;
                                col++;
                }
            }
            if( (ip[i][2] == '>') && ( isupper(ip[i][3]) ) && ( isSym( ip[i][4] ) ) )
            {
                            leading[row].lead[col]=ip[i][4];
                            col++;
                            leading[row].n++;
            }
            if( ( ip[i][2] == '>') && ( isSym( ip[i][3] ) ) && ( isupper( ip[i][4] ) ) )
            {
                            leading[row].lead[col]=ip[i][3];
                            col++;
                                leading[row].n++;
            }
        }
    }   
}
void leadTabOp(char p,int row)
{   int i,j;
    for(i=0;i<cnt;i++)
    {
        if(p == leading[i].lead[0])
        {
            for(j=1;j<=leading[i].n;j++)
            {
                leading[row].lead[col]=leading[i].lead[j];
                col++;
                leading[row].n++;
            }
        }
    }
}

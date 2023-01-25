%{
int flag=0;
%}

%%

[a-z.0-9_]+@[a-z]+".com"|".in"
flag=1;

%%
int yywrap(){}

int main()
{
printf("enter the mail:");
yylex();
if(flag==1)
printf("accepted");
else
printf("not accepted");
return 0;
}

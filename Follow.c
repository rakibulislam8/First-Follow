#include<stdio.h>
#include<ctype.h>
#include<string.h>

int limit, x = 0;
char arr[10][10], array[10];

void first(char ch);
void follow(char ch);
void arraycal(char ch);

int main()
{
      int count;
      char option, ch;
           printf("\nEnter Total Number for Follow:\t");
      scanf("%d", &limit);
      for(count = 0; count < limit; count++)
      {
            printf("nEnter Value for finding Follow [%d]:\t", count + 1);
            scanf("%s", arr[count]);
      }
      do
      {
            x = 0;
            printf("\nEnter production Value to Find Follow:\t");
            scanf(" %c", &ch);
            follow(ch);
            printf("\nFollow Value of %c:\t{ ", ch);
            for(count = 0; count < x; count++)
            {
                  printf("%c ", array[count]);
            }
            printf("}\n");
            printf("To Continue, Press Y:\t");
            scanf(" %c", &option);
      }while(option == 'y' || option == 'Y');
      return 0;
}

void follow(char ch)
{
      int i, j;
      int length = strlen(arr[i]);
      if(arr[0][0] == ch)
      {
            arraycal('$');
      }
      for(i = 0; i < limit; i++)
      {
            for(j = 2; j < length; j++)
            {
                  if(arr[i][j] == ch)
                  {
                        if(arr[i][j + 1] != '\0')
                        {
                              first(arr[i][j + 1]);
                        }
                        if(arr[i][j + 1] == '\0' && ch != arr[i][0])
                        {
                              follow(arr[i][0]);
                        }
                  }
            }
      }
}

void first(char ch)
{
      int i, k;
      if(!(isupper(ch)))
      {
            arraycal(ch);
      }
      for(k = 0; k < limit; k++)
      {
            if(arr[k][0] == ch)
            {
                  if(arr[k][2] == '$')
                  {
                        follow(arr[i][0]);
                  }
                  else if(islower(arr[k][2]))
                  {
                        arraycal(arr[k][2]);
                  }
                  else
                  {
                        first(arr[k][2]);
                  }
            }
      }
}

void arraycal(char ch)
{
      int count;
      for(count = 0; count <= x; count++)
      {
            if(array[count] == ch)
            {
                  return;
            }
      }
      array[x++] = ch;
}

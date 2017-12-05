#include<stdio.h>
#include<ctype.h>

void First(char[], char);
void arraycal(char[], char);

int limit;
char arr[25][25];

int main()
{
      char option;
      char ch;
      char array[25];
      int count;
      printf("\nEnter Total Number for First:\t");
      scanf("%d", &limit);
      for(count = 0; count < limit; count++)
      {
            printf("\nValue for finding First  [%d]:\t", count + 1);
            scanf("%s", arr[count]);
      }
      do
      {
            printf("\nEnter a Value to Find First:\t");
            scanf(" %c", &ch);
            First(array, ch);
            printf("\nFirst Value of %c:\t{ ", ch);
            for(count = 0; array[count] != '\0'; count++)
            {
                  printf(" %c ", array[count]);
            }
            printf("}\n");
            printf("To Continue, Press A or a:\t");
            scanf(" %c", &option);
      }while(option == 'a' || option == 'A');
      return 0;
}

void First(char* array, char ch)
{
      int count, j, k;
      char temporary_result[20];
      int x;
      temporary_result[0] = '\0';
      array[0] = '\0';
      if(!(isupper(ch)))
      {
            arraycal(array, ch);
            return ;
      }
      for(count = 0; count < limit; count++)
      {
            if(arr[count][0] == ch)
            {
                  if(arr[count][2] == '$')
                  {
                        arraycal(array, '$');
                  }
                  else
                  {
                        j = 2;
                        while(arr[count][j] != '\0')
                        {
                              x = 0;
                              First(temporary_result, arr[count][j]);
                              for(k = 0; temporary_result[k] != '\0'; k++)
                              {
                                    arraycal(array,temporary_result[k]);
                              }
                              for(k = 0; temporary_result[k] != '\0'; k++)
                              {
                                    if(temporary_result[k] == '$')
                                    {
                                          x = 1;
                                          break;
                                    }
                              }
                              if(!x)
                              {
                                    break;
                              }
                              j++;
                        }
                  }
            }
      }
      return;
}

void arraycal(char array[], char value)
{
      int temp;
      for(temp = 0; array[temp] != '\0'; temp++)
      {
            if(array[temp] == value)
            {
                  return;
            }
      }
      array[temp] = value;
      array[temp + 1] = '\0';
}

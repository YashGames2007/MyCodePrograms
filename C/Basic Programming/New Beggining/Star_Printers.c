#include <stdio.h>

// Compiler version gcc  6.3.0
void f1(int n);
void f2(int n);
void f3(int n);
void f4(int n);
void f5(int n);
void f6(int n);
void f7(int n);
void f8(int n);
void f9(int n);
void f10(int n);
void f11(int n);
void f12(int n);
void f13(int n);
void f14(int n);
void f15(int n);
void f16(int n);

int main()
{
  int n = 5;
  printf("\nEnter The Number: ");
  scanf("%d", &n);
  printf("\n");
  f16(n);
  printf("\n");
  return 0;
}
void f16(int n)
{
  // Part 1
  for (int i = 0; i < n; i++)
  {
    for (int j = (n * 3) - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || j == i)
      {
        printf("* ");
      }
      else
      {
        printf("  ");
      }
    }
    printf("\n");
  }
  // Part 2
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < i; j++)
    {
      printf(" ");
    }

    for (int j = 0; j < ((n * 3) - i) + 1; j++)
    {
      if(i != 0)
      {
        if (j == 0 || j == ((n * 3) - i))
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
      else
      {
        if (j <= n || j >= (((n * 3) - i) - n))
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
  // Part 3
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }

    for (int j = 1; j <= (n * 2) + 1 + i; j++)
    {
      if(i != n)
      {
        if (j == 1 || j == ((n * 2) + i + 1))
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
      else
      {
        if (j <= n + 1 || j >= (((n * 2) + i + 1) - n))
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
  // Part 4
  for (int i = n; i > 0; i--)
  {
    for (int j = (n * 3) - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf(" *");
      }
      else
      {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void f15(int n)
{
  // Part 1
  for (int i = 0; i < n; i++)
  {
    for (int j = (n * 3) - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j <= i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  // Part 2
  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < i; j++)
    {
      printf(" ");
    }

    for (int j = 0; j < ((n * 3) - i) + 1; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  // Part 3
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }

    for (int j = 1; j <= (n * 2) + 1 + i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  // Part 4
  for (int i = n; i > 0; i--)
  {
    for (int j = (n * 3) - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf(" *");
    }
    printf("\n");
  }

  /*
  n = 1
   *
* * * *
 * * *
* * * *
   *

n = 2

      *
     * *
* * * * * * *
 * * * * * *
  * * * * *
 * * * * * *
* * * * * * *
     * *
      *
n = 3
         *
        * *
       * * *
* * * * * * * * * *
 * * * * * * * * *
  * * * * * * * *
   * * * * * * *
  * * * * * * * *
 * * * * * * * * *
* * * * * * * * * *
       * * *
        * *
         *

  */
}

void f1(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

void f2(int n)
{
  for (int i = n; i >= 1; i--)
  {
    for (int j = 0; j < i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

void f3(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

void f4(int n)
{
  for (int i = n; i >= 1; i--)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

void f5(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
}

void f6(int n)
{
  for (int i = n; i >= 1; i--)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
}

void f7(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  for (int i = n - 1; i >= 1; i--)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
}

void f8(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        printf("  ");
      }
    }
    printf("\n");
  }
  for (int i = n - 1; i >= 1; i--)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        printf("  ");
      }
    }
    printf("\n");
  }
}

void f9(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        if (i == n)
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

void f10(int n)
{
  for (int i = n; i >= 1; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        if (i == n)
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

void f11(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf("  ");
    }
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        if (i == n)
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

void f12(int n)
{
  for (int i = n; i >= 1; i--)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf("  ");
    }
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        if (i == n)
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

void f13(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        if (i == n)
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

void f14(int n)
{
  for (int i = n; i >= 1; i--)
  {
    for (int j = n - i; j > 0; j--)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      if (j == 0 || j == i - 1)
      {
        printf("* ");
      }
      else
      {
        if (i == n)
        {
          printf("* ");
        }
        else
        {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}
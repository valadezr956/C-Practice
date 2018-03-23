#include <stdio.h>
#include <stdlib.h>

double randf(double min, double max);

int main()
{
int x, y, i, j;
double minZ, maxZ;
double **Arr2D;
double sum, row, col;

printf("Enter X Y minZ maxZ:\n");
scanf("%d %d %lf %lf", &x, &y, &minZ, &maxZ);

Arr2D =(double **)malloc(x * sizeof(double *));
for (i=0; i<x; i++)
{
    Arr2D[i] =(double *)malloc(y * sizeof(double));
}

for (i=0; i<x; i++)
    for (j=0; j<y; j++)
    {
        if (minZ == maxZ)
            Arr2D[i][j] = minZ;
        else Arr2D[i][j] = randf(minZ, maxZ);
    }

for (i=0; i<x; i++)
    for (j=0; j<y; j++)
    {
        sum += Arr2D[i][j];
    }

printf("Overall sum = %.1lf\n", sum);


printf("Sum of each row\n");
for (i=0; i<x; i++)
{
    printf("Row%d = ",i);
    for (j=0; j<y; j++)
    {
        row += Arr2D[i][j];
    }
    printf("%.1lf\n", row);
    row = 0.0;
}

printf("Sum of each column\n");
for (i=0; i<y; i++)
{
    for (j=0; j<x; j++)
        col += Arr2D[j][i];
    printf("%.1lf ", col);
    col = 0.0;
}


}

double randf(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

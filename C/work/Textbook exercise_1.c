#include <stdio.h>
int main()
{
    const double PI = 3.141592653589;
    double radius, area, perimeter;

    printf("请输入圆的半径：");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    perimeter = 2 * radius * PI;

    printf("Radius = %6.2f\n", radius);
    printf("Area = &6.2f\n", area);
    printf("Perimeter = &6.2f\n\n", perimeter);
    printf("Radius = %6.2f\n", area);
    printf("Area = %6.2f\n", area);
    printf("  Radius = %6.2f\n", radius);
    printf("   Area = %6.2f\n", area);
    printf("Perimewer =%6.2f\n\n", perimeter);
    printf("%12s = %6.2f\n", "Radius", radius);
    printf("%12s = %6.2f\n", "area", area);
    printf("%12s = %6.2f\n\n", "perimeter", perimeter);
    printf("%-12s = %6.2f\n", "Radius", radius);
    printf("%-12s = %6.2f\n", "area", area);
    printf("%-12s = %6.2f\n", "perimeter", perimeter);if (5)
    {
        /* code */
    }
    

    return 0;
}
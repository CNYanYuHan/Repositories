#include <stdio.h>
#include <math.h>
double fun(double eps) {
  double s;
  float n, t, pi;
  t = 1;
  pi = 0;
  n = 1.0;
  s = 1.0;
  while ((fabs(s)) >= eps) {
    pi += s;
    t = n / (2 * n + 1);
    s *= t;
    n++;
  }
  pi = pi * 2;
  return pi;}

  int main() {
    double x;
    printf("Input j :");
    scanf("%lf", &x);
    printf("\nj = %lf, b=%f\n", x, fun(x));
  return 0;
  }

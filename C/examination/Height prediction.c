#include <stdio.h>
int main() {
  int sex, sport, eat;
  float father, mother, height;
  /**********begin**********/
  scanf("%f %f %d %d %d", &father,&mother,&sex,&sport,&eat);
  if (sex == 1) {
    height = (father + mother) * 1.08 / 2;
  } else {
    height = (father * 0.923 + mother) / 2;
  }
  if (sport == 1) {
    height *= 1.02;
  }
  if (eat == 1) {
    height *= 1.03;
  }
  /**********end**********/
  printf("%.2f", height);
  return 0;
}
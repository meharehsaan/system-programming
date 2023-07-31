#include <stdio.h>
#include <mymath.h>
int main(){
   double x, y;
   printf("Enter first number: ");
   scanf("%lf",&x);
   printf("Enter second number: ");
   scanf("%lf",&y);
   double ans1 = myadd(x,y);
   double ans2 = mysub(x,y);
   printf("a + b = %7.2lf\n",ans1);
   printf("a - b = %7.2lf\n",ans2);
   return 0;
}

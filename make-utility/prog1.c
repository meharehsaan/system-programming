#include <stdio.h>
#include <mymath.h>
#include <d1/mymod.h>

int main(){
   double x, y;
   printf("Enter first number: ");
   scanf("%lf",&x);
   printf("Enter second number: ");
   scanf("%lf",&y);
   double ans1 = myadd(x,y);
   double ans2 = mysub(x,y);
   double ans3 = mymul(x,y);
   double ans4 = mydiv(x,y);
   printf("a + b = %7.2lf\n",ans1);
   printf("a - b = %7.2lf\n",ans2);
   printf("a * b = %7.2lf\n",ans3);
   printf("a/b   = %7.2lf\n",ans4);

   int ans5 = mymod((int)x,(int)y);
   printf("a%%b   = %d\n",ans5);

   return 0;
}

#include<stdio.h>

#include<math.h>

#include<stdlib.h>

int main()

{

int k,n,i=0,a[100],s=0,d=0,t=1,c=0;

scanf("%d",&t);

if(t<=10)

{

while(c<t)

{

printf("enter the no of elemnets");

scanf("%d",&n);

printf("enter the kth element");

scanf("%d",&k);

printf("enter the array");

for(i=0;i<n;i++)

scanf("%d",&a[i]);

s=a[0];

for(i=0;i<n;i++)

{

if(a[i]<s)

{

s=a[i];

}
}

if(s==k)

{

printf("%d",d);

}

else
{
while(s<k)

{

s++;
d++;

}
printf("%d",d);
s=0;
d=0;
c++;
}
}
}
}





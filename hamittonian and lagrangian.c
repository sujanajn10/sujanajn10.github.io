void main()
{
    long long int n;
    scanf("%lld",&n);
    long int a[n],i,j=0,m=n-1;//printf("%ld",m);
    for(i=0;i<n;i++)
    {
     scanf("%ld",&a[i]);   
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>=a[j]){
                continue;}
                else
                break;
            }//printf("%ld",j);
            //printf("%ld",a[i]);printf("\n");
            if(j==n)
            printf("%ld ",a[i]);
           
            else
            continue;
        } //printf("%ld",a[n-1]);
    }

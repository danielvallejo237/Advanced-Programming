#include <cstdio>
using namespace std;

int main(){
    double length,width,height,weight;
    int allowed=1;
    int n;
    int total=0;
    scanf("%d",&n);
    while(n--){
        scanf("%lf %lf %lf %lf",&length,&width,&height,&weight);
        allowed=1;
        if((length+width+height<=125.00)&&(weight<=7.00)){
            allowed=1;
        }
        else if(length>56.00){
            allowed=0;
        }
        else if(width>45.00){
            allowed=0;
        }
        else if(height>25.00){
            allowed=0;
        }
        else if(weight>7.00){
            allowed=0;
        }
        printf("%d\n",allowed);
        total=total+allowed;
    }
    printf("%d\n",total);
    return 0;
}

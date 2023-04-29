#include <bits/stdc++.h>
using namespace std;

long SZ, P;

int main(){
    while(scanf("%ld %ld", &SZ, &P), (SZ || P)){
        long a = ceil(sqrt(P))*ceil(sqrt(P));
        long line_center = (SZ+1)/2;
        long column_center = (SZ+1)/2;
        long line_coordinate;
        long column_coordinate;
        long b = sqrt(a);
        long corner = a - b + 1;
        if(P >= SZ*SZ){
            line_coordinate = SZ;
            column_coordinate = SZ;
        }else{
            if(a % 2 == 0){
                line_coordinate = line_center + 1 - b/2;
                column_coordinate = column_center - b/2;
                while(a != P){
                    if(a > corner){
                        line_coordinate++;
                    }else{
                        column_coordinate++;
                    }
                    a--;
                }
            }else{
                line_coordinate = line_center + b/2;
                column_coordinate = column_center + b/2;
                while(a != P){
                    if(a > corner){
                        line_coordinate--;
                    }else{
                        column_coordinate--;
                    }
                    a--;
                }
            }
        }

        printf("Line = %ld, column = %ld.\n", line_coordinate, column_coordinate);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int limit = 1000001;
int prefix[limit] = {0};

void prefixCreator(){
    int primes[limit];
    fill_n(primes, limit, 1);

    for(int j=2; j<limit; j++){
        if(primes[j]){
            for(int i=j+j; i<limit; i+=j){
                primes[i]=0;
            }
        }
    }

    vector<int> finalprimes;
    for(int i=2; i<limit; i++){
        if(primes[i]){
            finalprimes.push_back(i);
        }
    }

    int sieve4[limit]={0};
    int shouldFindCube = 1;
    for(int i=0;i<finalprimes.size();i++){
        int value=finalprimes[i];
        if(shouldFindCube){
            long long cube=1LL*value*value*value;
            if(cube<=limit){
                sieve4[cube]=1;
            }
            else{
                shouldFindCube=0;
            }
        }

        for(int j=i+1; j<finalprimes.size();j++)
        {
            int value2 = finalprimes[j];
            long long mul = 1LL*value*value2;
            if(mul > limit){
                break;
            }

            sieve4[mul]=1;
        }   
    }

    for(int i=1; i<limit;i++){
        prefix[i]=prefix[i-1];
        if(sieve4[i]){
            prefix[i]++;
        }
    }
    
}

int main(){
    
    prefixCreator();
    cout<<"Enter";
	int t;
    cin >> t;
    
    for(int i=0;i < t; i++)
    {
    	int l,r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1];

    }
    return 0;
}

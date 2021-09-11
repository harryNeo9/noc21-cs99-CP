/*
Problem
There are N houses for sale. The i-th house costs Ai dollars to buy. 
You have a budget of B dollars to spend.

What is the maximum number of houses you can buy?

Input
The first line of the input gives the number of test cases, T. T test cases follow. 
Each test case begins with a single line containing the two integers N and B. 
he second line contains N integers. The i-th integer is Ai, the cost of the i-th house.

Output
For each test case, output one line containing Case #x: y, where x is the test 
case number (starting from 1) and y is the maximum number of houses you can buy.
    
*/
    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>

    int allocate(vi a, int B){
      int n=0,sum=0;
      sort(a.begin(),a.end());
      for(int i=0;i<a.size(); i++){
        sum+=a[i];
        if(sum<=B)
          n++;
      }

      return n;
    }


    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin>>T;
         for(int c=1; c< T+1; c++){
            int  N,B,ans;
            cin>>N>>B;

            vi A;
            for(int i=0; i<N; i++){
              int cost;
              cin>>cost;
              A.push_back(cost);
            }

            ans = allocate(A,B);
            cout<<"Case #"<<c<<": "<<ans<<endl;

          }

    }
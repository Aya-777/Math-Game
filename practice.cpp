#include<bits/stdc++.h>
using namespace std; 

int ReadPositiveNumber(string msg){

  int n=0;
  do {
    cout << msg << "\n";
    cin>>n;
  } while(n<=0);

  return n;
}

int RandomNumber(int From, int To){

  return (rand() % (To-From+1)+From);
}

int ReadNumber(string msg){

  int n;
  cout << msg << "\n";
  cin>>n;
  return n;

}

int main(){
  
}
//	|		|		|
//	|		|		|
//	|		|		|
//----------------------
//	L 		R 		C


#include <iostream>
using namespace std;

void hanoi(int n,char L,char R,char C)
{
    if(n==1)
    {
        cout <<"\nMove disk "<<n<<" from tower "<<L<<" to tower "<<R;
    }
    else 
    {
 hanoi (n-1,L,C,R);
    cout <<"\nMove disk "<<n<<" from tower "<<L<<" to tower "<<R;
 hanoi (n-1,C,R,L);  
    }
}
int main() {
int n;
cout <<"How many disks : ";
cin>>n;
cout<<n<<endl;
hanoi (n,'A','C','B');
    return 0;
}
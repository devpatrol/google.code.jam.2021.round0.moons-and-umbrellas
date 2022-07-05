#include <iostream>
#include <string>

using namespace std;

int moons_and_umbrellas ( int x, int y, string data )
{
    cout << x << " : " << y << " : " << data;
    return 0;
}

int main( int argc, const char** argv ) 
{
    int cases, i = 0;
    int x, y;
    string data;
        cin >> cases;
        while ( i < cases )
        {
            cin >> x;
            cin >> y;
            cin >> data;
            moons_and_umbrellas( x, y, data );
            i++;
        }
    return 0;
}
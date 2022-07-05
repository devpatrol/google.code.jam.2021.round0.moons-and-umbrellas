#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int moons_and_umbrellas( int x, int y, string data )
{
    int cj = 0, jc = 0, length = data.length();
    string sub_1, sub_2;

        if ( length <= 1 )
        {
            return 0;
        }

        for ( int i = 0; i < length; i++ )
        {
            if ( data[ i ] == '?' )
            {
                sub_1 = sub_2 = data;
                sub_1[ i ] = 'C';
                sub_2[ i ] = 'J';
                cout << sub_1 << endl;
                return min(
                    moons_and_umbrellas( x, y, sub_1 ),
                    moons_and_umbrellas( x, y, sub_2 )
                );
            }
            else{
                if ( i < length - 1 ) 
                {
                    if ( data[ i ] == 'C' && data[ i+1 ] == 'J' ) 
                    {
                        cj++;
                    }
                    else if ( data[ i ] == 'J' && data[ i+1 ] == 'C' )
                    {
                        jc++;
                    }
                } 
            }
        }
    return ( x * cj ) + ( y * jc );
}

int main( int argc, const char** argv ) 
{
    int cases, i = 0;
    int x, y;
    vector<int> arr; 
    string data;
        cin >> cases;
        while ( i < cases )
        {
            cin >> x;
            cin >> y;
            cin >> data;
            arr.push_back( moons_and_umbrellas( x, y, data ) );
            i++;
        }

        for ( i = 0; i < arr.size(); i++ )
        {
            cout << "Case " << i + 1 << "#: " << arr[ i ] << endl;
        }
        
    return 0;
}
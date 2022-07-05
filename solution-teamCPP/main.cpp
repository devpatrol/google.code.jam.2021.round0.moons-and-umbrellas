#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int count( string data )
{
    int 
        length = data.length(), q = 0;
            for ( int i = 0; i < length; i++ )
            {
                if ( data[ i ] == '?' )
                {
                    q++;
                }
            }
    return q;
}

int moons_and_umbrellas( int x, int y, string data )
{
    int length = data.length(), q = count( data );
    string item;

    if ( length <= 1 || ( q == length && x + y > 0 ) )
    {
        return 0;
    }

    if ( q == length )
    {
        if ( length % 2 == 0 ) 
        {
            return ( x < y ? x : y ) * ( length / 2 ) + ( x < y ? y : x ) * ( ( length / 2 ) - 1 );
        }
        else 
        {
            return ( x < y ? x : y ) * ( length - 1 );
        }
    }

    for ( int i = 1; i < length; i++ )
    {
        if ( data[ i ] != '?' && data[ i - 1 ] != '?'  )
        {
            if ( data[ i - 1 ] == data[ i ] ) 
            {
                return (
                    moons_and_umbrellas( x, y, data.substr( 0, i ) ) + 
                    moons_and_umbrellas( x, y, data.substr( i ) )
                );
            }
            else 
            {
                return ( data[ i ] == 'J' ? x : y ) + (
                    moons_and_umbrellas( x, y, data.substr( 0, i ) ) + 
                    moons_and_umbrellas( x, y, data.substr( i ) )
                );
            }
        }
        else if ( data[ i - 1 ] == '?' && data[ i ] != '?' && i < length - 1 )
        {
            return (
                moons_and_umbrellas( x, y, data.substr( 0, i + 1 ) ) + 
                moons_and_umbrellas( x, y, data.substr( i ) )
            );
        }
    }

    if ( data[ 0 ] == '?' )
    {
        if ( ( x >= 0 && data[ 1 ] == 'J' ) || ( y >= 0 && data[ 1 ] == 'C' ) )
        {
            return moons_and_umbrellas( x, y, data.substr( 1 ) );
        }

        return min(
            moons_and_umbrellas( x, y, "C" + data.substr( 1 ) ),
            moons_and_umbrellas( x, y, "J" + data.substr( 1 ) )
        );
    }
    else 
    {
        if ( data[ 1 ] == '?' ) 
        {
            if ( length != 2 && data[ 0 ] == data[ 2 ] && x + y >= 0 )
            {
                return moons_and_umbrellas( x, y, data.substr( 2 ) );
            }

            item = "";
            item.push_back( data[ 0 ] );

            return min(
                moons_and_umbrellas( x, y, item + "C" + ( length == 2 ? "" : data.substr( 2 ) ) ),
                moons_and_umbrellas( x, y, item + "J" + ( length == 2 ? "" : data.substr( 2 ) ) )
            );
        }
        else if ( data[ 0 ] == data[ 1 ] )
        {
            return moons_and_umbrellas( x, y, data.substr( 1 ) );
        }
        else 
        {
            return ( data[ 1 ] == 'J' ? x : y ) + moons_and_umbrellas( x, y, data.substr( 1 ) );
        } 
    }
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
            cout << "Case " << "#" << i + 1 << ": " << arr[ i ] << endl;
        }
        
    return 0;
}
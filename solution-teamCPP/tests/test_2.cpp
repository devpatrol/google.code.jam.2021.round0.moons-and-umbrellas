#include <iostream>
#include <string>
#include <vector>

using namespace std;

void count( string data, int &cj, int &jc, int &q )
{
    int 
        length = data.length();
        cj = jc = q = 0;
    for ( int i = 0; i < length; i++ )
    {
        if ( data[ i ] == '?' )
        {
            q++;
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
}

int moons_and_umbrellas( int x, int y, string data )
{
    int cj, jc, q, length = data.length();
    int start = ( x > 0 && y > 0 ) || ( x + y > 0 && y < 0 ) ? 0 : length;

        count( data, cj, jc, q );

        if ( length <= 1 || ( q == 0 && !cj && !jc ) || ( q == length && x + y > 0 ) ) 
        {
            return 0;
        }
        else if ( q == length )
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

        //cout << ( x * cj ) + ( y * jc );
        cout << start;

        for ( int i = start; ( start == 0 && i < length ) || ( start > 0 && i >= 0 ); start == 0 ? i++ : i-- )
        {
            if ( data[ i ] == '?' ) 
            {
                if ( i > 0 && i < length - 1 && data[ i - 1 ] != '?' && data[ i + 1 ] != '?' )
                {
                    if ( data[ i - 1 ] != data[ i + 1 ] )
                    {
                        data[ i ] = data[ i - 1 ];
                    } 
                    else 
                    {
                        if ( ( x >= 0 && y >= 0 ) || ( x + y ) > 0 )
                        {
                            data[ i ]  = data[ i - 1 ];
                            continue;
                        }
                        data[ i ]  = ( data[ i - 1 ] == 'C' ) ? 'J' : 'C';
                    }
                }
                else if ( ( i == 0 || data[ i - 1 ] == '?' ) && ( i < length - 1 && data[ i + 1 ] != '?' ) )
                {
                    if ( x + y > 0 || i == 0 ) 
                    {
                        if ( data[ i + 1 ] == 'C' ) 
                        {
                            data[ i ] = y < 0 ? 'J' : 'C';
                        }
                        else
                        {
                            data[ i ] = x < 0 ? 'C' : 'J';   
                        }
                    } 
                    else  
                    {
                        data[ i ] = data[ i + 1 ] == 'C' ? 'J' : 'C';
                    }
                } 
                else if ( ( i == length - 1 || data[ i + 1 ] == '?' ) && ( i > 0  && data[ i - 1  ] != '?' ) )
                {
                    if ( x + y > 0 || i == length - 1 ) 
                    {
                        if ( data[ i - 1 ] == 'C' ) 
                        {
                            data[ i ] = x < 0 ? 'J' : 'C';
                        }
                        else
                        {
                            data[ i ] = y < 0 ? 'C' : 'J';   
                        }
                    } 
                    else  
                    {
                        data[ i ] = data[ i - 1 ] == 'C' ? 'J' : 'C';
                    }
                }
            }
        }

        count( data, cj, jc, q );
        cout << data << endl;

        if ( q ) 
        {
            return moons_and_umbrellas( x, y, data );
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
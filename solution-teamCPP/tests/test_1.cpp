#include <iostream>
#include <string>

using namespace std;

void count( string data, int &cj, int &jc, int &q )
{
    int 
        length = data.length();
        cj = 0;
        jc = 0;
        q = 0;

    for ( int i = 0; i < data.length(); i++ )
    {
        if ( data[ i ] == '?' )
        {
            q++;
        }
        else if ( i < data.length() - 1 ) 
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

int moons_and_umbrellas( int x, int y, string data )
{
    int cj, jc, q, missing = 0;
    char store;
        count( data, cj, jc, q );
        if ( q == data.length() || ( q == 0 && !cj && !jc ) ) 
        {
            return 0;
        }

        for ( int i = 0; i < data.length(); i++ )
        {
            if ( data[ i ] == '?' ) 
            {
                if ( store )
                {
                    data[ i ] = store;
                    continue;
                }

                missing++;
                continue;
            }

            store = data[ i ];

            if ( missing ) 
            {
                for ( int j = i - 1; j >= 0 ; j-- )
                {
                    if ( data[ j ] != '?' ) 
                    {
                        break;
                    }

                    data[ j ] = data[ i ];
                    missing--;
                }
            }
        }
        count( data, cj, jc, q );
    return ( x * cj ) + ( y * jc );
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
            cout << "Case " << i + 1 << "# " << moons_and_umbrellas( x, y, data ) << endl;
            i++;
        }
    return 0;
}
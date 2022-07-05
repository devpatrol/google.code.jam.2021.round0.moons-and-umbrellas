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

void calc( int &cj, int &jc, int x, int y, int num, int start, int end )
{
    if ( start == -1 )
    {
        if ( x + y < 0 )
        {
            if ( num % 2 == 0 ) 
            {
                cj += num / 2;
                jc += num / 2;
            } 
            else  
            {
                cj += end ? ( num + 1 ) / 2 : ( num - 1 ) / 2;
                jc += !end ? ( num + 1 ) / 2 : ( num - 1 ) / 2;
            }
        } 
        else 
        {
            cj += x < 0 && end ? 1 : 0;
            jc += y < 0 && !end ? 1 : 0;
        }
    }
    else if ( end == -1 )
    {
        if ( x + y < 0 )
        {
            if ( num % 2 == 0 ) 
            {
                cj += num / 2;
                jc += num / 2;
            } 
            else  
            {
                cj += !start ? ( num + 1 ) / 2 : ( num - 1 ) / 2;
                jc += start ? ( num + 1 ) / 2 : ( num - 1 ) / 2;
            }
        } 
        else 
        {
            cj += x < 0 && !start ? 1 : 0;
            jc += y < 0 && start ? 1 : 0;
        }
    }
    else
    {
        if ( start == end )
        {
            if ( x + y < 0 )
            {
                cj += num % 2 == 0 ? num / 2 : ( num + 1 ) / 2;
                jc += num % 2 == 0 ? num / 2 : ( num + 1 ) / 2;
            }
        }
        else 
        {
            if ( x + y < 0 )
            {
                if ( num % 2 == 0 )
                {
                    num--;
                }

                jc += start ? ( num + 2 ) / 2 : num / 2;
                cj += !start ? ( num + 2 ) / 2 : num / 2;
            }
            else 
            {
                if ( num >= 2 )
                {
                    jc += start && y < 0 ? 2 : 1;
                    cj += !start && x < 0 ? 2 : 1;
                } 
                else 
                {
                    jc += start ? 1 : 0;
                    cj += !start ? 1 : 0;
                }
            }
        }
    }
}

int moons_and_umbrellas( int x, int y, string data )
{
    int cj = 0, jc = 0, q = 0, length = data.length();
    int start = -1, num = 0;

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

        for ( int i = 0; i < length; i++ )
        {
            if ( data[ i ] == '?' )
            {
                num++;
            }
            else 
            {
                if ( num )
                {
                    calc( cj, jc, x, y, num, start, data[ i ] == 'C' ? 0 : 1 );
                    start = -1;
                    num = 0;
                }
                start = data[ i ] == 'C' ? 0 : 1;
            }
        }

        if ( num ) 
        {
            calc( cj, jc, x, y, num, start, -1 );
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
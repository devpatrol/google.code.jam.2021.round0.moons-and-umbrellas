const readline = require( 'readline' );

function moons_and_umbrellas( x: number, y: number, data: string[] ) : number {
    const length : number = data.length;
    let q : number = data.length - data.filter( item => item != '?' ).length;
    let item: string;

    data = data.filter( item => item != '' );

    if ( length <= 1 || ( q == length && x + y > 0 ) ) {
        return 0;
    }

    if ( q == length ) {
        if ( length % 2 == 0 ) {
            return ( x < y ? x : y ) * ( length / 2 ) + ( x < y ? y : x ) * ( ( length / 2 ) - 1 );
        }
        else {
            return ( x < y ? x : y ) * ( length - 1 );
        }
    }

    for ( let i : number = 1; i < length; i++ ) {
        if ( data[ i ] != '?' && data[ i - 1 ] != '?'  ) {
            if ( data[ i - 1 ] == data[ i ] ) {
                return (
                    moons_and_umbrellas( x, y, data.slice( 0, i ) ) + 
                    moons_and_umbrellas( x, y, data.slice( i ) )
                );
            }
            else {
                return ( data[ i ] == 'J' ? x : y ) + (
                    moons_and_umbrellas( x, y, data.slice( 0, i ) ) + 
                    moons_and_umbrellas( x, y, data.slice( i ) )
                );
            }
        }
        else if ( data[ i - 1 ] == '?' && data[ i ] != '?' && i < length - 1 ) {
            return (
                moons_and_umbrellas( x, y, data.slice( 0, i + 1 ) ) + 
                moons_and_umbrellas( x, y, data.slice( i ) )
            );
        }
    }

    if ( data[ 0 ] == '?' ) {
        if ( ( x >= 0 && data[ 1 ] == 'J' ) || ( y >= 0 && data[ 1 ] == 'C' ) ) {
            return moons_and_umbrellas( x, y, data.slice( 1 ) );
        }

        return Math.min(
            moons_and_umbrellas( x, y, [ "C" ].concat( data.slice( 1 ) ) ),
            moons_and_umbrellas( x, y, [ "J" ].concat( data.slice( 1 ) ) )
        );
    }
    else {
        if ( data[ 1 ] == '?' ) {
            if ( length != 2 && data[ 0 ] == data[ 2 ] && x + y >= 0 ) {
                return moons_and_umbrellas( x, y, data.slice( 2 ) );
            }

            item = data[ 0 ];

            return Math.min(
                moons_and_umbrellas( x, y, [ item, "C" ].concat( length == 2 ? "" : data.slice( 2 ) ) ),
                moons_and_umbrellas( x, y, [ item, "J" ].concat( length == 2 ? "" : data.slice( 2 ) ) )
            );
        }
        else if ( data[ 0 ] == data[ 1 ] ) {
            return moons_and_umbrellas( x, y, data.slice( 1 ) );
        }
        else {
            return ( data[ 1 ] == 'J' ? x : y ) + moons_and_umbrellas( x, y, data.slice( 1 ) );
        } 
    }
}

function main() : number {
    let cases : number = 0, i : number = 0;
    let x : number, y : number;
    let line : string[] = [];
    const arr: number[] = []; 
    const terminal = readline.createInterface( process.stdin, process.stdout );
    let data: string;

        terminal.on( 'line', ( l : string ) => {
            if ( !cases ) {
                cases = parseInt( l );
            } else {
                i++;
                line = l.split( ' ' );
                x = parseInt( line.shift() || "0" );
                y = parseInt( line.shift() || "0" );
                data = line.shift() || "";
                arr.push( moons_and_umbrellas( x, y, data.split( '' ) ) );
    
                if ( i == cases ) {
                    terminal.close();
                }
            }
        } );

        terminal.on( 'close', () => {
            for ( i = 0; i < arr.length; i++ ) {
                console.log( "Case " + "#" + ( i + 1 ) + ": " + arr[ i ] );
            }
            process.exit( 0 );
        } );
    return 0;
}

main();
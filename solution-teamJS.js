const readline = require('readline').createInterface(process.stdin, process.stdout);

const traitement = (liste = []) => {
    var x = parseInt(liste[0])
    var y = parseInt(liste[1])
    var chaine = liste[2].substring(0)
        //chaine = chaine.split('')
    var taille = chaine.length;

    /*    boucle de traitement:  */


}




















var max = 0;
var line = 0;


readline.on('close', () => process.exit(0));
readline.on('line', (data) => {
    line++;
    if (!max) max = parseInt(data);
    else {
        //if (line % 2) {
        data = data.split(' ')
            //var liste = data.map(i => parseInt(i));
        console.log(`Case #${ ( line - 1 )  }: ${traitement( data ) }`)
        line - 1 === max ? readline.close() : {};
        //}
    }
});
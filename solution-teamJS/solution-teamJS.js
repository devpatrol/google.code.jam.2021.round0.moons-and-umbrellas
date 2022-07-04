const { count } = require('console');

const readline = require('readline').createInterface(process.stdin, process.stdout);
/*


determination des arrangements ordonnes de n elements dans k position


*/

function permute_ordre(index = 0, output = [], solution = [], box = []) {
    var count = 0;
    if (index == output.length) {
        var temp = new Array(output.length)
        temp = output.slice(0, output.length)
        solution.push(temp);
        return;
    } else {
        for (var b = 0; b < box.length; b++) {
            output[index] = box[b]
            permute_ordre(index + 1, output, solution, box);
        }
    }
    return solution
}


/*

fonction de calcul du montant a payer pour les droits d'auteurs

*/
const montant = (liste = [], cj, jc) => {
    var liste_cjjc = []
    var couple = '',
        x = 0,
        y = 0,
        nb_cjjc = [];
    for (var i = 0; i < liste.length - 1; i++) {

        couple = liste[i] + liste[i + 1]
        liste_cjjc.push(couple)
    }
    for (var i = 0; i < liste_cjjc.length; i++) {
        if (liste_cjjc[i] == 'cj' || liste_cjjc[i] == 'CJ') {
            x++;
        }
        if (liste_cjjc[i] == 'jc' || liste_cjjc[i] == 'JC') {
            y++;
        }
    }
    var mont = (x * cj) + (y * jc)
    return mont

}


/*  

fonction de determination s'il ya  vide

*/

const testvide = (liste1 = []) => {
        var liste = liste1
        for (var i = 0; i < liste.length; i++) {
            if (liste[i] == '?') {
                return true
            }
        }
        return false;
    }
    /*  

    fonction de determination du nombre d'indices vide

    */
const vide = (liste = []) => {
        var count = 0;
        for (var i = 0; i < liste.length; i++) {
            if (liste[i] == '?') {
                count++;
            }

        }
        return count;
    }
    /*  

    fonction de determination  des indice vide

    */
const indice_vide = (liste = []) => {
    var indice = [];
    for (var i = 0; i < liste.length; i++) {
        if (liste[i] == '?') {
            indice.push(i);
        }

    }
    return indice
}

/*  

fonction combler vide

*/
const combler_vide = () => {

}

/*  

fonction principale de traitement

*/
const traitement = (liste = []) => {
    var x = parseInt(liste[0]),
        y = parseInt(liste[1]),
        chainet = liste[2];
    var chaine = chainet.split('')
    var nb_vide = vide(chaine),

        indice = indice_vide(chaine);
    var output = new Array(nb_vide),
        solution = [],
        value = ['c', 'j']
    arrangements = permute_ordre(0, output, solution, value);
    //console.log(arrangements)
    // repalcement par les differente permutation:
    var mont = 0
    var all_mont = []
    var all_chaine = []
    for (var j = 0; j < arrangements.length; j++) {
        var ligne = arrangements[j]
        for (var i = 0; i < nb_vide; i++) {
            chaine[indice[i]] = ligne[i]
            all_chaine.push(chaine);

            // console.log(chaine)
        }
        //console.log(chaine)

        console.log(all_chaine)
            //console.log(montant(chaine, x, y))
        all_mont.push(montant(chaine, x, y))
    }
    //console.log(all_mont)
    var Mmin = all_mont[0]
    for (var i = 0; i < all_mont.length; i++) {
        if (all_mont[i] < Mmin) {
            Mmin = all_mont[i]
        }
    }
    return Mmin;
    //return montant(chaine);
}


/*

execution du programme:

*/

var max = 0,
    line = 0;


readline.on('close', () => process.exit(0));
readline.on('line', (data) => {
    line++;
    if (!max) max = parseInt(data);
    else {
        //if (line % 2) {
        data = data.split(' ')
        var temp = data[2]
        var liste1 = temp.split('')
            //console.log(liste1, " test vide: ", testvide(liste1))
            //var liste = data.map(i => parseInt(i));
        if (testvide(liste1)) {
            console.log(`Case #${ ( line - 1 )  }: ${traitement( data ) }`)
        } else {

            cj = parseInt(data[0]),
                jc = parseInt(data[1]);
            console.log(`Case #${ ( line - 1 )  }: ${montant( liste1,cj,jc) }`)
        }
        line - 1 === max ? readline.close() : {};
        //}
    }
});
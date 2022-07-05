System.register("main", ["readline"], function (exports_1, context_1) {
    "use strict";
    var readline_1;
    var __moduleName = context_1 && context_1.id;
    function moons_and_umbrellas(x, y, data) {
        var length = data.length;
        var q = data.length - data.filter(function (item) { return item != '?'; }).length;
        var item;
        data = data.filter(function (item) { return item != ''; });
        if (length <= 1 || (q == length && x + y > 0)) {
            return 0;
        }
        if (q == length) {
            if (length % 2 == 0) {
                return (x < y ? x : y) * (length / 2) + (x < y ? y : x) * ((length / 2) - 1);
            }
            else {
                return (x < y ? x : y) * (length - 1);
            }
        }
        for (var i = 1; i < length; i++) {
            if (data[i] != '?' && data[i - 1] != '?') {
                if (data[i - 1] == data[i]) {
                    return (moons_and_umbrellas(x, y, data.slice(0, i)) +
                        moons_and_umbrellas(x, y, data.slice(i)));
                }
                else {
                    return (data[i] == 'J' ? x : y) + (moons_and_umbrellas(x, y, data.slice(0, i)) +
                        moons_and_umbrellas(x, y, data.slice(i)));
                }
            }
            else if (data[i - 1] == '?' && data[i] != '?' && i < length - 1) {
                return (moons_and_umbrellas(x, y, data.slice(0, i + 1)) +
                    moons_and_umbrellas(x, y, data.slice(i)));
            }
        }
        if (data[0] == '?') {
            if ((x >= 0 && data[1] == 'J') || (y >= 0 && data[1] == 'C')) {
                return moons_and_umbrellas(x, y, data.slice(1));
            }
            return Math.min(moons_and_umbrellas(x, y, ["C"].concat(data.slice(1))), moons_and_umbrellas(x, y, ["J"].concat(data.slice(1))));
        }
        else {
            if (data[1] == '?') {
                if (length != 2 && data[0] == data[2] && x + y >= 0) {
                    return moons_and_umbrellas(x, y, data.slice(2));
                }
                item = data[0];
                return Math.min(moons_and_umbrellas(x, y, [item, "C"].concat(length == 2 ? "" : data.slice(2))), moons_and_umbrellas(x, y, [item, "J"].concat(length == 2 ? "" : data.slice(2))));
            }
            else if (data[0] == data[1]) {
                return moons_and_umbrellas(x, y, data.slice(1));
            }
            else {
                return (data[1] == 'J' ? x : y) + moons_and_umbrellas(x, y, data.slice(1));
            }
        }
    }
    function main() {
        var cases = 0, i = 0;
        var x, y;
        var line = [];
        var arr = [];
        var terminal = readline_1["default"].createInterface(process.stdin, process.stdout);
        var data;
        terminal.on('line', function (l) {
            if (!cases) {
                cases = parseInt(l);
            }
            else {
                i++;
                line = l.split(' ');
                x = parseInt(line.shift() || "0");
                y = parseInt(line.shift() || "0");
                data = line.shift() || "";
                arr.push(moons_and_umbrellas(x, y, data.split('')));
                if (i == cases) {
                    terminal.close();
                }
            }
        });
        terminal.on('close', function () {
            for (i = 0; i < arr.length; i++) {
                console.log("Case " + "#" + (i + 1) + ": " + arr[i]);
            }
            process.exit(0);
        });
        return 0;
    }
    return {
        setters: [
            function (readline_1_1) {
                readline_1 = readline_1_1;
            }
        ],
        execute: function () {
            main();
        }
    };
});

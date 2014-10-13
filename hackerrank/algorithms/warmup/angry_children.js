
function compareNumbers (a, b) {
    return a-b;
}

function getUnfairness (arr) {
    return (arr[arr.length-1] - arr[0]);
}

function getMinUnfairness (n, k, o) {
    o.sort (compareNumbers);
    var minUnfairness = 99999999;
    for (var i = 0; i < n-k; i++){
        minUnfairness = Math.min (minUnfairness, getUnfairness(o.slice(i, i+k)));
    }
    return minUnfairness;
}

function processData(input) {
    var n, k, o;
    var lines = input.split ('\n').map( function (item) {
        return parseInt (item, 10);
    });
    n = lines[0]; k = lines[1];
    o = lines.slice (2, lines.length);
    console.log (getMinUnfairness (n, k, o));
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
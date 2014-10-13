
function getSquaresBetween (a, b) {
    //console.log ("a:"+a + " b:"+b);
    var i = 1, s = 1, n = 0;
    while( s <= b ){
        if (s >= a){
            n++;
        }
        i++;
        s = i*i;
    }
    return n;
}

function processData(input) {
    var lines = input.split ('\n');
    for (var i = 1; i < lines.length; i++) {
    	var line = lines[i].split(' ').map (function (item){
            return parseInt (item, 10);
        });
        console.log (getSquaresBetween(line[0], line[1]));
    }
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

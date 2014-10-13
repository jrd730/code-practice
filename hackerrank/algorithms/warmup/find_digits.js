
function findDigits (d) {
	var n = 0;
	for (var i = 0; i < d.length; i++) {
		if (parseInt (d, 10) % parseInt (d[i]) == 0){
			n++;
		}
	}
	return n;
}

function processData(input) {
    var lines = input.split ('\n');
    for (var i = 1; i < lines.length; i++) {
        console.log (findDigits (lines[i]));
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
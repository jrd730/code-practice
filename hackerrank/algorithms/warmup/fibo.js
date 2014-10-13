
var fibs = {};

function calcFibs (mx) {
	fibs[0] = 1;
	fibs[1] = 1;
	var a = 1, b = 1;
	while (b <= mx){
		var c = b;
		b = a + b;
		fibs[b] = 1;
		a = c;
	}
}

function processData(input) {
    var lines = input.split ('\n');
    calcFibs (10000000001);
    for (var i = 1; i < lines.length; i++) {
    	if ((parseInt(lines[i], 10)) in fibs){
    		console.log ("IsFibo");
    	}
    	else{
    		console.log ("IsNotFibo");
    	}
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
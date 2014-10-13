var lc = {};

function processData(input) {
	//console.log (input);
	
	for (var i = 0; i < input.length; i++){
		var ch = input[i];
		if (ch in lc){
			lc[ch] += 1;
		}
		else {
			lc[ch] = 1;
		}
	}
	delete lc['\n'];

	//console.log (lc);
	var odd1 = false;
	var isPali = true;
	for (var c in lc) {
		var odd = (lc[c] % 2);
		if (odd == 1){
			if (odd1 == true) {
				isPali = false;
				break;
			}
			else {
				odd1 = true;
			}
		}
	}
	if (isPali == true) {
		console.log ('YES');
	}
	else {
		console.log ('NO');
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
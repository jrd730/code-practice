// the love letter mystery

// return the number of operations to make the string a palindrome
function paliOps (s) {
	var min_ops = 0;
	var half = s.length/2;
	for (var i = 0; i < half; i++) {
		if (s[i] != s[s.length-i-1]) {
			min_ops += Math.abs(s.charCodeAt (i) - s.charCodeAt (s.length-i-1));
		}
	}
	return min_ops;
}

function processData(input) {
    var lines = input.split ("\n");
    for (var i = 1; i < lines.length; i++) {
   		console.log (paliOps(lines[i])); 
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
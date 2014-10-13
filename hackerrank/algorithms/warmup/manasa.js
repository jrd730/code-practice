
function getPossibleValues (n, a, b) {
	var values = {};
	for (var i = n; i >= 0; i--){
		values[(i*a)+((n-i)*b)] = 1;
	}
	var answer = '';
	for (key in values){
		answer += key + " ";
	}
	return answer;
}

function processData(input) {
	var lines = input.split ('\n').map( function (item) {
		return parseInt (item, 10);
	});
	for (var i = 1; i <= 3*lines[0]; i += 3){
		console.log (getPossibleValues (lines[i]-1, lines[i+1], lines[i+2]));
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

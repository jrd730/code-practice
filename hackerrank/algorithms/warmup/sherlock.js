
function f (n, m, A, B, C) {
	for (var i = 0; i < m; i++){
		for (var j = 0; j < n; j++){
			if ((j+1) % B[i] == 0){
				A[j] = A[j] * C[i];
			}
		}
	}
	return A;
}

function processData(input) {
	var lines = input.split('\n');
	for (var i=0; i < lines.length; i++){
		lines[i] = lines[i].split (' ').map (function (item){
			return parseInt (item, 10);
		});
	}

	//console.log (lines);
	var A = f (lines[0][0], lines[0][1], lines [1], lines[2], lines[3]);
	var answer = '';
	for (var i = 0; i < A.length; i++){
		answer += (A[i]%1000000009) + ' ';
	}
	answer.slice (answer.length-1, 1);
	//console.log (lines);
	console.log (answer);
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

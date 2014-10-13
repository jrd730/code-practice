
function getLargestDecentNumber (n) {
	var answer = '';
	var five_digits = n;
	var three_digits = 0;
	
	while ( (five_digits%3 != 0) && (five_digits >= 0) ) {
		three_digits += 5;
		five_digits -= 5;
	}
	
	if ( (five_digits >= 0) && (three_digits >= 0) ) {
		answer += new Array (five_digits + 1).join ('5');
		answer += new Array (three_digits + 1).join ('3');
		return answer;
	}
	else {
		return '-1';
	}
}

function processData(input) {
    var lines = input.split ('\n').map( function (item) {
		return parseInt (item, 10);
	});
	for (var i = 1; i < lines.length; i++) {
		console.log (getLargestDecentNumber (lines[i]));
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

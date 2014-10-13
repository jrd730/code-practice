
function getChocolate (N, C, M) {
	var cc = Math.floor (N / C);
	var w = cc;
	
	while (w >= M) {
		cc++;
		w -= M;
		w++;
	}	
	return cc;
}

function processData(input) {
	lines = input.split ("\n");
	//console.log(lines);
	//console.log(lines.length);
	for (var i=1; i < lines.length; i++){
		var line = lines[i].split (' ').map (function (item){
			return parseInt (item, 10);
		});
		//console.log (line);
		console.log (getChocolate(line[0], line[1], line[2]));
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

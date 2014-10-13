var T, N = 0;
var widths = [];
var data = [];

function processData(input) {
	data = input.split (new RegExp ("\\s+"));
	for (var i=0; i < data.length; i++) { 
		data[i] = parseInt (data[i], 10);}
	N = data[0];
	T = data[1];

	for (var i=0; i < N; i++){
		widths.push (data[2+i]);
	}

	//console.log (widths);

	var open = T*2;
	for (var i=0; i < open; i+=2){
		var min_width = 4;
		var start	= data[2+N+i];
		var end 	= data[2+N+i+1];
		
		for (var j = start; j <= end; j++){
			min_width = Math.min (min_width, widths[j]);
		}
		console.log (min_width);
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

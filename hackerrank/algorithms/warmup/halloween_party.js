// halloween party

function processData(input) {
    var cuts = input.split ("\n");
    for (var i = 1; i < cuts.length; i++) {
    	if (cuts[i]%2 == 0) {
    		console.log (cuts[i]*cuts[i]/4);
    	}
    	else {
    		console.log (Math.ceil(cuts[i]/2.0) * Math.floor(cuts[i]/2.0));
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

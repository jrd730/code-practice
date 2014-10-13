// gem stones

var num_gem_elements = 0;

function processData(input) {
    var lines = input.split ("\n");
    for (var e = 'a'.charCodeAt(0); e <= 'z'.charCodeAt(0); e++){
    	var isGemElement = true;
	    for (var i = 1; i < lines.length; i++) {
	    	if (lines[i].indexOf(String.fromCharCode(e)) == -1) {
	    		isGemElement = false;
	    		break;
	    	}
	    }
	    if (isGemElement) {
	    	num_gem_elements++;
	    }
	}
	console.log (num_gem_elements);
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

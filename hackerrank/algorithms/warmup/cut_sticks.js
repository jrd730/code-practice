// cut the sticks


function processData(input) {
    lines = input.split("\n");
    lengths = lines[1].split(' ');
    for (var i = 0; i < lengths.length; i++) {
    	lengths[i] = parseInt(lengths[i]);
    }

    var min_length = 99999999;
    while (lengths.length > 0){
    	var cuts = 0;
    	min_length = Math.min.apply(Math, lengths);

    	for (var i = 0; i < lengths.length; ) {
    		lengths[i] -= min_length;
    		cuts++;
    		if (lengths[i] == 0){
    			lengths.splice (i, 1);
    		}
    		else {
    			i++;
    		}
    	}
    	//console.log (lengths);
    	console.log (cuts);
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

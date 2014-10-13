// Utopian Tree

var tree_height = 1;
var cycles = 0;

function getNewTreeHeight (start_height, cycles) {
	var new_height = start_height;
	for (var i = 0; i < cycles; i++){
		new_height = (i%2 == 0) ? (new_height * 2) : (new_height + 1); 
	}
	return new_height;
}

function processData(input) {
	var parse_fun = function (s) { return parseInt(s, 10); };
	var lines = input.split('\n');
	var T = parse_fun(lines.shift());
	var data = lines.splice(0, T).map(parse_fun);
	for (var i = 0; i < data.length; i++){
		console.log (//'height after ' + data[i] + ' cycles = ' + 
			getNewTreeHeight(tree_height, data[i]));
	}
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
var _input = "";
process.stdin.on("data", function (input) { _input += input; });
process.stdin.on("end", function () { processData(_input); });
process.stdin.resume();
process.stdin.setEncoding('ascii');

var __input_stdin = "";
var __input_stdin_array = "";
var __input_currentline = 0;

process.stdin.on('data', function (data) {
    __input_stdin += data;
});
/*
 * Complete the function below.
 */
function maxXor(l, r) {
	var max_val = 0;
	for (var a = l; a <= r; a++){
		for (var b = a; b <= r; b++){
			max_val = Math.max (max_val, a^b);
		}
	}
	console.log (max_val);
}

process.stdin.on('end', function () {
    __input_stdin_array = __input_stdin.split("\n");
    var res;
    var _l = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;
    
    var _r = parseInt(__input_stdin_array[__input_currentline].trim(), 10);
    __input_currentline += 1;
    
    res = maxXor(_l, _r);
    //process.stdout.write(""+res);
    
});

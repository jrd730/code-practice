function processData(input) {
    var N, M, total_candy = 0;
    var lines = input.split ('\n');
    var line = lines[0].split(' ').map ( function (item){
    		return parseInt (item, 10);
    	});
    N = line[0]; M = line[1];

    for (var i = 1; i < lines.length; i++) {
    	var line = lines[i].split(' ').map ( function (item){
    		return parseInt (item, 10);
    	});
    	total_candy += (line[1] - line[0] + 1) * line[2];
    }
    console.log (Math.floor (total_candy/N));
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

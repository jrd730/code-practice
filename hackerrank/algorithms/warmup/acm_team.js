function getMaxTopics (m, n) {
    var maxTopics = 0;
    for (var i = 0; i < m.length; i++){
        for (var j = i+1; j < m.length; j++){
            var topics = 0;
            for (var k = 0; k < n; k++){
                if ( (m[i][k] == '1') || (m[j][k] == '1') ){
                    topics += 1;
                }
            }
            maxTopics = Math.max (topics, maxTopics);
        }
    }
    return maxTopics;
}

function getMaxTeams (m, n, t) {
    var teams = 0;
    for (var i = 0; i < m.length; i++){
        for (var j = i+1; j < m.length; j++){
            var topics = 0;
            for (var k = 0; k < n; k++){
                if ( (m[i][k] == '1') || (m[j][k] == '1') ){
                    topics += 1;
                }
            }
            if (topics >= t){
                teams++;
            }
        }
    }
    return teams;
}

function processData(input) {
    var N, M;
    var members = [];
    var lines = input.split ('\n');
    var line = lines[0].split(' ').map ( function (item) {
            return parseInt (item, 10);
    });
    N = line[0]; M = line[1];
    for (var i = 1; i < lines.length; i++) {
    	members.push ( lines[i] );
    }

    var mt = getMaxTopics (members, M);
    console.log (mt);
    console.log (getMaxTeams (members, M, mt));
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

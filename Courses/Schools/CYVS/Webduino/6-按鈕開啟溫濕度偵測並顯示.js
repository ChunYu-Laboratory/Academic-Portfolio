var button;
var dht;
var celsius;
var fahrenheit;


boardReady({board: 'Smart', device: 'E37r4', transport: 'mqtt'}, function (board) {
  board.samplingInterval = 50;
  button = getPullupButton(board, 4);
  dht = getDht(board, 5);
  button.on('pressed', function () {
    dht.read(function(evt){
      celsius = dht.temperature;
      fahrenheit = celsius*1.8 + 32;
      document.getElementById('demo-area-01-show').style.fontSize = 20 + 'px';
      document.getElementById('demo-area-01-show').style.lineHeight = 20 + 'px';
      document.getElementById('demo-area-01-show').innerHTML = (['攝氏溫度：',celsius,'°C',("<br/>"),'華氏溫度：',fahrenheit,'°F'].join(''));
    }, 1000);
  });
});

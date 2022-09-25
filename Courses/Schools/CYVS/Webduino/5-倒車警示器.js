(async function () {

var rgbled;
var ultrasonic;
var distance;


boardReady({board: 'Smart', device: 'E37r4', transport: 'mqtt'}, async function (board) {
  board.samplingInterval = 50;
  rgbled = getRGBLedCathode(board, 15, 12, 13);
  ultrasonic = getUltrasonic(board, 16, 14);
  while (!false) {
    await ultrasonic.ping();
    distance = ultrasonic.distance;
    document.getElementById('demo-area-01-show').innerHTML = ultrasonic.distance;
    if (distance <= 5) {
      rgbled.setColor('#ff0000');
    } else if (5 < distance && distance <= 10) {
      rgbled.setColor('#ff3300');
    } else if (10 < distance && distance <= 20) {
      rgbled.setColor('#00ff00');
    } else {
      rgbled.setColor('#000000');
    }
  }
});

}());
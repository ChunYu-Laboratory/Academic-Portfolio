(async function () {

var button;
var rgbled;
var matrix;
var num;

boardReady({board: 'Smart', device: 'E37r4', transport: 'mqtt'}, async function (board) {
  button = getPullupButton(board, 4);
  rgbled = getRGBLedCathode(board, 15, 12, 13);
  matrix = getMax7219(board, 16, 14, 5);
  button.on('pressed', async function () {
    rgbled.setColor('#00ff00');
    await delay(5);
    rgbled.setColor('#ffff00');
    await delay(2);
    rgbled.setColor('#ff0000');
    num = 5;
    for (var count = 0; count < 5; count++) {
      matrix.animateStop();
      matrix.on('0000000000000000');
      matrix.on((max7219_number(num)));
      num -= 1;
      await delay(1);
    }
    rgbled.setColor('#000000');
    matrix.animateStop();
    matrix.off();
  });
});

}());
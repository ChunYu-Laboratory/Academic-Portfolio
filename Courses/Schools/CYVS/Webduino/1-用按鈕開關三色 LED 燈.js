var button;
var rgbled;
var num;

boardReady({board: 'Smart', device: 'E37r4', transport: 'mqtt'}, function (board) {
  button = getPullupButton(board, 4);
  rgbled = getRGBLedCathode(board, 15, 12, 13);
  num = 0;
  document.getElementById('demo-area-01-show').innerHTML = num; //於瀏覽器互動區域顯示文字，若要於後端 console 執行則可用 console.log(num)
  button.on('pressed', function () {
    rgbled.setColor('#ff0000');
    num += 1;
    document.getElementById('demo-area-01-show').innerHTML = num;
  });
  button.on('released', function () {
    rgbled.setColor('#0000ff');
  });
  button.on('longPress', function () {
    rgbled.setColor('#000000');
  });
});

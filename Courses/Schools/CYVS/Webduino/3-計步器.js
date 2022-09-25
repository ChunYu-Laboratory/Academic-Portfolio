var shake;
var num;

boardReady({board: 'Smart', device: 'E37r4', transport: 'mqtt'}, function (board) {
  shake = getShock(board, 5);
  num = 0;
  document.getElementById('demo-area-01-show').innerHTML = num;
  shake.on('high', function () {
    num += 1;
    document.getElementById('demo-area-01-show').innerHTML = num;
    if (10 < num && num <= 20) {
      document.getElementById('demo-area-01-show').innerHTML = ([num,("<br/>"),'已經完成一半了!加油!'].join(''));
    } else if (num > 20) {
      document.getElementById('demo-area-01-show').innerHTML = ([num,("<br/>"),'恭喜完成了!'].join(''));
    }
  });
});

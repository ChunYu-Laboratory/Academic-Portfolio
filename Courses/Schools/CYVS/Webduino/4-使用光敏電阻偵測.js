(async function () {

var photocell;
var buzzer;
var rgbled;

function buzzer_music(m) {
  var musicNotes = {};
  musicNotes.notes = [];
  musicNotes.tempos = [];
  if (m[0].notes.length > 1) {
    for (var i = 0; i < m.length; i++) {
      if (Array.isArray(m[i].notes)) {
        var cn = musicNotes.notes.concat(m[i].notes);
        musicNotes.notes = cn;
      } else {
        musicNotes.notes.push(m[i].notes);
      }
      if (Array.isArray(m[i].tempos)) {
        var ct = musicNotes.tempos.concat(m[i].tempos);
        musicNotes.tempos = ct;
      } else {
        musicNotes.tempos.push(m[i].tempos);
      }
    }
  } else {
    musicNotes.notes = [m[0].notes];
    musicNotes.tempos = [m[0].tempos];
  }
  return musicNotes;
}


boardReady({board: 'Smart', device: 'E37r4', transport: 'mqtt'}, async function (board) {
  board.samplingInterval = 50;
  photocell = getPhotocell(board, 0);
  buzzer = getBuzzer(board, 5);
  rgbled = getRGBLedCathode(board, 15, 12, 13);
  photocell.measure(async function (val) {
    photocell.detectedVal = val;
    rgbled.setColor('#ff0000');
  });
  await delay(5);
  photocell.off();
  rgbled.setColor('#000000');
  buzzer.play(buzzer_music([{ notes : ["C6","D6","E6","F6","G6","A6","B6"] , tempos : ["8","8","8","8","8","8","8"] }]).notes ,buzzer_music([{ notes : ["C6","D6","E6","F6","G6","A6","B6"] , tempos : ["8","8","8","8","8","8","8"] }]).tempos );
});

}());
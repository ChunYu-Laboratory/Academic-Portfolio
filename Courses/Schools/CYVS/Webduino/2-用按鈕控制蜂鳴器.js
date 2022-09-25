var button;
var buzzer;
var num;

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


boardReady({board: 'Smart', device: 'E37r4', transport: 'mqtt'}, function (board) {
  button = getPullupButton(board, 4);
  buzzer = getBuzzer(board, 5);
  num = 0;
  document.getElementById('demo-area-01-show').innerHTML = num;
  button.on('pressed', function () {
    num += 1;
    if (num == 1) {
      buzzer.play(buzzer_music([{ notes: 'C6', tempos: '8' }]).notes ,buzzer_music([{ notes: 'C6', tempos: '8' }]).tempos );
    } else if (num == 2) {
      buzzer.play(buzzer_music([{ notes: 'D6', tempos: '8' }]).notes ,buzzer_music([{ notes: 'D6', tempos: '8' }]).tempos );
    } else if (num == 3) {
      buzzer.play(buzzer_music([{ notes: 'E6', tempos: '8' }]).notes ,buzzer_music([{ notes: 'E6', tempos: '8' }]).tempos );
    } else {
      num = 0;
    }
    document.getElementById('demo-area-01-show').innerHTML = num;
  });
});

function play(letter) {
  if (letter == 'w') {
    var audio = new Audio("sounds/crash.mp3");
  }
  else if (letter == 'a') {
    var audio = new Audio("sounds/kick-bass.mp3");
  }
  else if (letter == 's') {
    var audio = new Audio("sounds/snare.mp3");
  }
  else if (letter == 'd') {
    var audio = new Audio("sounds/tom-1.mp3");
  }
  else if (letter == 'j') {
    var audio = new Audio("sounds/tom-2.mp3");
  }
  else if (letter == 'k') {
    var audio = new Audio("sounds/tom-3.mp3");
  }
  else {
    var audio = new Audio("sounds/tom-4.mp3");
  }
  audio.play();
}
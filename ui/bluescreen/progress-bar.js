  /* disable right click */
  document.addEventListener('contextmenu', e => event.preventDefault());

  /* progress bar */
  var myVar = setInterval(updateBar, 500);

  function updateBar() {
    let val = document.getElementById("val")
    let progressVal = document.getElementById("progress-bar").value;

    if (progressVal >= 99) {
      clearInterval(myVar);
    }

    if (progressVal === 80) {
      clearInterval(myVar);
      myVar =  setInterval(updateBar, 2000);

    }
    progressVal++;

    val.innerHTML = `${progressVal}% 
      <progress id="progress-bar" 
        name="progress-bar" 
        value="${progressVal}" 
        max="100">
      </progress>`;   
  }
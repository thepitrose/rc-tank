R"=====(
<!DOCTYPE HTML>
<html>
    <head>
    </head>
<body>

  <p>Press any button on the joystick , for  mapping </p>
  <form action="http://192.168.14.203/submit" method="POST">

<div>
<img id="Arducam" src="http://192.168.14.203/stream">
</div>
</form>

<div>

</div>
</form>

</body>

  <script>

var isFireIR=false;
var isFireLaser=false;


window.addEventListener("gamepadconnected", function(e) {
  var gp = navigator.getGamepads()[e.gamepad.index];
  alert("A " + gp.id + " was successfully detected!")

  setInterval(function(){

var xhr = new XMLHttpRequest();
    

  
  if (navigator.getGamepads()[0].buttons[0].pressed==true)
    {
    //   L DOWN
   //  alert("L DOWN");
     var url = "/ldown";
     xhr.open("GET", url, true);
     xhr.send();
    }

     if (navigator.getGamepads()[0].buttons[1].pressed==true)
    {
     //  L UP
  //   alert("L UP")
     var url = "/lup";
     xhr.open("GET", url, true);
     xhr.send();
    }
    

     if (navigator.getGamepads()[0].buttons[2].pressed==true)
    {
     // R DOWN
     //alert("R DOWN");
     var url = "/rdown";
     xhr.open("GET", url, true);
     xhr.send();
    }

     if (navigator.getGamepads()[0].buttons[3].pressed==true)
    {
      // ziv
         alert("3  was successfully detected!")
    }

    
     if (navigator.getGamepads()[0].buttons[4].pressed==true)
    {
    //  R UP
   //  alert("R UP");
     var url = "/rup";
     xhr.open("GET", url, true);
     xhr.send();
    }



/////////////////////////////////////////////////////////////////

 
    if (navigator.getGamepads()[0].buttons[1].pressed==true && navigator.getGamepads()[0].buttons[4].pressed==true)
    {
    
      // DOUBLE UP
  //   alert("DOUBLE UP");
  // console.log(dubleup);
     var url = "/dubleup";
     xhr.open("GET", url, true);
     xhr.send();
    }
    

    if (navigator.getGamepads()[0].buttons[0].pressed==true && navigator.getGamepads()[0].buttons[2].pressed==true)
    {
      // DOUBLE DOWN
     // alert("DOUBLE DOWN");
     var url = "/dbdown";
     xhr.open("GET", url, true);
     xhr.send();
    }

      if (navigator.getGamepads()[0].buttons[1].pressed==true && navigator.getGamepads()[0].buttons[2].pressed==true)
    {
      //  LUP RDOWN
     // alert("LUP RDOWN");
     var url = "/lurd";
     xhr.open("GET", url, true);
     xhr.send();
    }

    if (navigator.getGamepads()[0].buttons[0].pressed==true && navigator.getGamepads()[0].buttons[4].pressed==true)
    {
      // LDOWN RUP
    //  alert("LDOWN RUP");
     var url = "/ldru";
     xhr.open("GET", url, true);
     xhr.send();
    }


//////////////////////////////////////////////////////////////////


    


    if (navigator.getGamepads()[0].buttons[5].pressed==true && isFireIR==false )
    {
    //LT
   //  alert("LT")
     isFireIR=true;
     fireIR();

   //  var url = "/lstop";
  //   xhr.open("GET", url, true);
    // xhr.send();
    }

    
    if (navigator.getGamepads()[0].buttons[6].pressed==true)
    {
    // LB
    // alert("LB")
     var url = "/shieldOFF";
     xhr.open("GET", url, true);
     xhr.send();
    }

    if (navigator.getGamepads()[0].buttons[7].pressed==true  && isFireLaser==false  )
    {
    //RT
   //  alert("RT")
     isFireLaser=true;
     fireLaser();
    }

    
     if (navigator.getGamepads()[0].buttons[8].pressed==true)
    {
    // RB
   //  alert("RB")
     var url = "/shieldON";
     xhr.open("GET", url, true);
     xhr.send();
    } 


 
    if (navigator.getGamepads()[0].buttons[9].pressed==true && navigator.getGamepads()[0].buttons[10].pressed==true)
    {
    //   left pedal right pedal
   // alert(" left pedal right pedal")
     var url = "/ddstop";
     xhr.open("GET", url, true);
     xhr.send();
    } 
    
    if (navigator.getGamepads()[0].buttons[9].pressed==true)
    {
     //  left pedal
   // alert("left pedal")
     var url = "/lstop";
     xhr.open("GET", url, true);
     xhr.send();
    } 

    if (navigator.getGamepads()[0].buttons[10].pressed==true)
    {
    //   right pedal
     //     alert(" right pedal")
     var url = "/rstop";
     xhr.open("GET", url, true);
     xhr.send();
    } 

  

  }, 100)
});

async function fireIR() {

var xhr = new XMLHttpRequest();

    var url = "/irShot";
    xhr.open("GET", url, true);
    xhr.send();

  await new Promise(resolve => setTimeout(resolve, 1000));

    var url = "/irShotNOT";
    xhr.open("GET", url, true);
    xhr.send();
             
    await new Promise(resolve => setTimeout(resolve, 2000));
    isFireIR=false;

}


async function fireLaser() {

var xhr = new XMLHttpRequest();

    var url = "/laserShot";
    xhr.open("GET", url, true);
    xhr.send();

  await new Promise(resolve => setTimeout(resolve, 1000));

    var url = "/laserShotNOT";
    xhr.open("GET", url, true);
    xhr.send();
             
    await new Promise(resolve => setTimeout(resolve, 2000));
    isFireLaser=false;

}


  </script>

  
</body>

</html>
)=====";

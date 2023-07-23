//The html code for the website

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <script src="https://kit.fontawesome.com/5410311b30.js" crossorigin="anonymous"></script>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
  @import url('https://fonts.googleapis.com/css2?family=Josefin+Sans:wght@300&display=swap');
  :root{
      --background-color: #314453;
      --darker-background-color: #243848;
      --accent-color: #18a8ad;
      --text-color:#FFFFFF;

    }
  html{
    scroll-behavior: smooth;
  }
  body {
    margin:0;font-family:Arial;
    background-image: url(https://images.unsplash.com/photo-1484199316358-d7acb93729f2?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1790&q=80);
    background-repeat: no-repeat;
    background-attachment: fixed;
    background-size: cover;
    text-align: center;
    align-items: center;

    }
    .City{
      margin-top: 110px;
      text-align: center;
      line-height: 10px;
    }
    .values_ow{
      margin-top: 30px;
      line-height: 30px;
      width: 350px;
    }
    .City_name{
      font-size: 40px;
      margin-bottom: 0px;
      margin-top: 20px;
    }
    .City_Startseite{
      margin-top: 20px;
      text-align: center;
      line-height: 10px;
    }
    input[type=button]{
      margin-top: 10px;
      margin-bottom: 0px;
      width: 90px;
      padding: 9px;
      background: linear-gradient(to right, #ffb369, #ff4272);  
      display:block;
      border-radius:200px;
      text-align:center;
      border: 2px solid var(--text-color);
      color:rgba(255,255,255,1);
      text-decoration:none;
      cursor: pointer;
    }
    .ow_links{
      float: left;
    }
    .ow_rechts{
      float: right;
    }
    #Einstellungen{
      background-color: rgba(52, 52, 52, 1);
      padding-top: 2vh;
      height: 100vh;
      width: 100%%; //library braucht doppelte %, weil der template processor diesen css code ansonsten nicht verarbeitet
      color: var(--text-color);
    }
    .Einstellungen_bereiche{
      background-color: rgb(24,24,24, 1);
      height: 550px;
      width: 370px;
      position: relative;
      border-radius: 25px;
      border: 2px solid white;
      margin: 0 auto;
      padding: 10px;
      display: flex;
      flex-direction: column;
      
    }
    .Einstellungen_input{
      margin-top: 8px;
      width: 100%%;
      margin-bottom: 0px;
      font-size: 19px;
      display: flex;
      flex-direction: column;
      justify-content: space-evenly;  
    }
    .Einstellungen_head{
      margin-bottom: 15px;
      margin-top: 30px;
    }
    .select{
      padding: 8px 10px;
      margin: 8px 0;
      display: inline-block;
      border: 2px solid #ccc;
      border-radius: 4px;
      box-sizing: border-box;
    }
    

    .save{
      margin-top: 25px;
      width: 130px;
      padding: 9px;
      background: none;  
      display:block;
      border-radius:200px;
      text-align:center;
      border: 2px solid #0200E9;
      color:rgba(255,255,255,1);
      text-decoration:none;
      cursor: pointer;
      margin-left: 50%%;
      transform: translateX(-50%%);
    }
    .head_time{
      font-size: 100px;
      margin-top: 30px;
      padding: 0;
      color: #FFFFFF;
      font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
      margin-bottom: 0px;
    }
    .head_date{
      margin-top: 10px;
      color: #FFFFFF;
      font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
      font-size: 30px;
    }
  .topnav {
    overflow: hidden;
    background-color: var(--background-color);
    z-index: 3;
  }

  .topnav a {
    float: left;
    display: block;
    color: var(--text-color);
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    font-size: 17px;
    cursor: default;
  }

  .active {
    background-color: darkcyan;
    color: var(--text-color);
  }

  .topnav .icon {
    display: none;
  }

  .dropdown {
    float: left;
    overflow: hidden;
  }

  .dropdown .dropbtn {
    font-size: 17px;    
    border: none;
    outline: none;
    color: white;
    padding: 14px 16px;
    background-color: inherit;
    font-family: inherit;
    margin: 0;
  }

  .dropdown-content {
    display: none;
    position: absolute;
    background-color: white;
    min-width: 160px;
    box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
    z-index: 1;
  }

  .dropdown-content a {
    float: none;
    background-color: var(--darker-background-color);
    color: white;
    padding: 12px 16px;
    text-decoration: none;
    display: block;
    text-align: left;
  }

  .topnav a:hover, .dropdown:hover .dropbtn {
    background-color: var(--accent-color);
    color: white;
  }

  .dropdown-content a:hover {
    background-color: var(--accent-color);
    color: white;
  }

  .dropdown:hover .dropdown-content {
    display: block;
  }

  @media screen and (max-width: 600px) {
    .topnav a:not(:first-child), .dropdown .dropbtn {
      display: none;
    }
    .topnav a.icon {
      float: right;
      display: block;
    }
  }

  @media screen and (max-width: 600px) {
    .topnav.responsive {position: relative;}
    .topnav.responsive .icon {
      position: absolute;
      right: 0;
      top: 0;
    }
    .topnav.responsive a {
      float: none;
      display: block;
      text-align: left;
    }
    .topnav.responsive .dropdown {float: none;}
    .topnav.responsive .dropdown-content {position: relative;}
    .topnav.responsive .dropdown .dropbtn {
      display: block;
      width: 100%%;
      text-align: left;
    }
  } 
    .content{
      display: none;
      height: 100%%;
      align-items: center;
      text-align: center;
      justify-content: center;
    }
    #WetterApp{
      display: block;
    }
  .values_darstellung{
    background-color: rgba(72, 81, 90, 0.7);
    height: min-content;
    width: max-content;
    position: relative;
    border-radius: 25px;
    border: 2px solid white;
    margin: 0 auto;
    padding: 20px;
    color: var(--text-color);
  }

  h3{
      font-size: 27px;
      margin-top: 10px;
    }
    .Wert {
       font-size: 2.5rem; 
      }
    .Einheit { 
      font-size: 1.5rem; 
    }
    .Bmevalues{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
    .head{
      font-size: 70px;
      padding: 0;
      color: #FFFFFF;
      font-family: 'Josefin Sans', sans-serif;
    }
    .suche{
      height: 170px;
      width: 350px;
      font-size: 1.8rem;
      line-height: 34px;
      align-items: center;
      display: flex;
      flex-direction: column;
      justify-content: space-between;
      margin-bottom: 0px;
      
    }
    input[type=text]{
      padding: 10px 12px;
      margin: 12px 0;
      display: inline-block;
      border: 2px solid #ccc;
      border-radius: 4px;
      box-sizing: border-box;
    }

  </style>
</head>
<body>
  <div class="topnav" id="myTopnav">
    <a class="active" onclick="Anzeige('WetterApp')">WetterApp</a>
    <a onclick="Anzeige('OpenWeather')">OpenWeather</a>
    <div class="dropdown">
      <button class="dropbtn">BME Sensoren 
        <i class="fa fa-caret-down"></i>
      </button>
      <div class="dropdown-content">
        <a href="#" onclick="Anzeige('BME1')">BME 1</a>
        <a onclick="Anzeige('BME2')">BME 2</a>
      </div>
    </div> 
    <a onclick="Anzeige('Einstellungen')">Einstellungen</a>
    <a href="javascript:void(0);" style="font-size:15px;" class="icon" onclick="Burger_menu()">&#9776;</a>
  </div>
  <div class="content"id="WetterApp">
    <h1 class="head_time" id="time">ZEIT</h1>
    <h2 class="head_date" id="date">Datum</h2>
    <div class="values_darstellung">
      <p class="City_Startseite">
        <h2 class="City_name" id="Name_Startseite">Name</h2>
        <pre id="coord_Startseite">coord</pre>
      </p>
      <p class="values_ow">
        <span name="Name" class="ow_links">Beschreibung</span><span class="ow_rechts" id="Beschreibung_Startseite"></span><br>
        <span name="Name" class="ow_links">Temperatur</span><span class="ow_rechts" id="Temp_Startseite"></span><br>
        <span class="ow_links">Temperatur Verlauf</span><span class="ow_rechts">
          <span id="Temp_min_Startseite"></span> - <span id="Temp_max_Startseite"></span>
        </span><br>
        <span class="ow_links">Luftfeuchte</span><span class="ow_rechts" id="Feuchte_Startseite"></span><br>
        <span class="ow_links">Luftdruck</span><span class="ow_rechts" id="Druck_Startseite"></span><br>
        <span class="ow_links">Windgeschwindigkeit</span><span class="ow_rechts" id="Wind_Startseite"></span><br>
        
      </p>
    </div>
  </div>
  <div class="content"id="BME1">
    
    <h2 class="head">BME 1</h2>
    <div class="values_darstellung">
      <p class="Wert">
        <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
        <span class="Bmevalues">Temperatur</span> 
        <span id="Temperatur_BME1">%Temperatur_BME1%</span>
        <sup class="Einheit">&deg;C</sup>
      </p>
      <p class="Wert">
        <i class="fas fa-tint" style="color:#00add6;"></i> 
        <span class="Bmevalues">Feuchte</span>
        <span id="Feuchte_BME1">%Feuchte_BME1%</span>
        <sup class="Einheit">&percnt;</sup>
      </p>
      <p class="Wert">
        <i class="fa-solid fa-arrows-to-circle" style="color:#002050;"></i> 
        <span class="Bmevalues">Druck</span>
        <span id="Druck_BME1">%Druck_BME1%</span>
        <sup class="Einheit">hPa</sup>
      </p>
      <p class="Wert">
        <i class="fas fa-square-rss" style="color:rgb(22, 129, 190);"></i> 
        <span class="Bmevalues">Verbindung</span>
        <span id="rssi_BME1">%rssi_BME1%</span>
        <sup class="Einheit">dBm</sup>
      </p>
    </div>
  </div>
  <div class="content" id="BME2">
    <h2 class="head">BME 2</h2>
    <div class="values_darstellung">
      <p class="Wert">
        <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
        <span class="Bmevalues">Temperatur</span> 
        <span id="Temperatur_BME2"></span>
        <sup class="Einheit">&deg;C</sup>
      </p>
      <p class="Wert">
        <i class="fas fa-tint" style="color:#00add6;"></i> 
        <span class="Bmevalues">Feuchte</span>
        <span id="Feuchte_BME2"></span>
        <sup class="Einheit">&percnt;</sup>
      </p>
      <p class="Wert">
        <i class="fa-solid fa-arrows-to-circle" style="color:#002050;"></i> 
        <span class="Bmevalues">Druck</span>
        <span id="Druck_BME2"></span>
        <sup class="Einheit">hPa</sup>
      </p>
      <p class="Wert">
        <i class="fas fa-square-rss" style="color:rgb(22, 129, 190);"></i> 
        <span class="Bmevalues">Verbindung</span>
        <span id="rssi_BME2"></span>
        <sup class="Einheit">dBm</sup>
      </p>
    </div>
  </div>
  <div class="content" id="OpenWeather">
    <h2 class="head">Open Weather Map</h2>
    <div class="values_darstellung">
      <form class="suche">
        <label for="input_City">City</label>
        <input type="text" id="input_City" value="Karlsruhe" placeholder="Cityname">
        
        <label for="input_land">Land</label>
        <input type="text" id="input_land" value="DE" placeholder="ISO 3166 Code">
        
        
        <input type="button" onclick="suche();" value="suchen">  
      </form>
      <p class="City">
        <h3 class="City_name" id="Name">Name</h3>
        <pre id="coord">coord</pre>
      </p>
      <p class="values_ow">
        <span class="ow_links">Beschreibung</span><span class="ow_rechts" id="Beschreibung"></span><br>
        <span class="ow_links">Temperatur</span><span class="ow_rechts" id="Temp"></span><br>
        <span class="ow_links">Luftfeuchte</span><span class="ow_rechts" id="Feuchte"></span><br>
        <span class="ow_links">Luftdruck</span><span class="ow_rechts" id="Druck"></span><br>
        <span class="ow_links">Windgeschwindigkeit</span><span class="ow_rechts" id="Wind"></span><br>
      </p>
    </div>
    <br>
    <br>
  </div>
  <div id="Einstellungen">
    <h2 class="head" id="Einstellungen_head">Einstellungen</h2>
    <div class="Einstellungen_bereiche">
      <h3 class="Einstellungen_head">Allgemein</h3>
          <div class="Einstellungen_input">
            <label for="input_url">Hintergrundbild</label>
            <input oninput="save_rot()" type="text" id="input_url" placeholder="hier url eingeben">
            <label for="preset">Presets</label>
            <select class="select" onchange="save_rot()" id="preset">
              <option value="https://images.unsplash.com/photo-1484199316358-d7acb93729f2?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1790&q=80">Wolken</option>
              <option value="https://cdn.pixabay.com/photo/2017/05/11/09/20/shanghai-2303480_960_720.jpg">City Tag</option>
              <option value="https://cdn.pixabay.com/photo/2016/11/29/09/16/architecture-1868667_960_720.jpg">City Nacht</option>
              <option value="https://cdn.pixabay.com/photo/2016/11/29/02/20/cosmos-1866820_960_720.jpg">Sterne</option>
            </select>
          </div>
          
        <h3 class="Einstellungen_head">Startseite</h3>
          <div class="Einstellungen_input">
            <label for="input_url">angezeigte City</label>
            <input oninput="save_rot()" type="text" id="input_City_Startseite" placeholder="hier City eingeben" value="Knielingen">
            <input oninput="save_rot()" type="text" id="input_land_Startseite" placeholder="hier Laendercode eingeben" value="DE">
          </div>
      <button onclick="save()" id="savebutton" class="save">Speichern</button>
      
      
    </div>

  </div>
</body>
<script>
                          
  var OpeanWeatherKey = "";
  var ThingspeakKey = "";
                          
  function save(){
    if(document.getElementById("input_url").value !== ""){
      document.body.style.backgroundImage = "url(" + document.getElementById("input_url").value + ")"
      document.getElementById("input_url").value = "";
    }
    else{
      document.body.style.backgroundImage = "url(" + document.getElementById("preset").value + ")"
    }
    document.getElementById("savebutton").style.border = "2px solid lime";
    Startseite();
    setTimeout(function(){Anzeige("WetterApp")}, 100);
    
  }


  function save_rot(){
    document.getElementById("savebutton").style.border = "2px solid red";
  }
  function Burger_menu() {
    var x = document.getElementById("myTopnav");
    if (x.className === "topnav") {
      x.className += " responsive";
    } else {
      x.className = "topnav";
    }
  } 

function Anzeige(id){
  
  if(id == "OpenWeather"){
    suche();
  }
  if(!(id == "WetterApp")){
    Burger_menu();
  }
  if(document.getElementById("savebutton").style.border == "2px solid red"){
    document.getElementById("Einstellungen_head").innerHTML = "Nicht Gespeichert";
    document.getElementById("Einstellungen_head").style.color = "red";
  }
  else{
    if(id=="Einstellungen"){
      document.getElementById("savebutton").style.border = "2px solid #0200E9";
    }
    document.getElementById("Einstellungen_head").innerHTML = "Einstellungen";
    document.getElementById("Einstellungen_head").style.color = "var(--text-color)";
    hide_content();
    document.getElementById(id).style.display = "block";
  }
}


function hide_content(){
  document.getElementById("WetterApp").style.display = "none";
  document.getElementById("BME1").style.display = "none";
  document.getElementById("BME2").style.display = "none";
  document.getElementById("OpenWeather").style.display = "none";
  document.getElementById("Einstellungen").style.display = "none";
}
window.onload= ()=>{
  hide_content();
  Startseite();
  document.getElementById("WetterApp").style.display = "block";
}

setInterval(function(){
  var dt = new Date();
  document.getElementById("time").innerHTML = (("0"+dt.getHours()).slice(-2)) +":"+ (("0"+dt.getMinutes()).slice(-2));
  document.getElementById("date").innerHTML = (("0"+dt.getDate()).slice(-2) +"."+ ("0"+(dt.getMonth()+1)).slice(-2))   +"."+ (dt.getFullYear());
},100);
function suche(){
  
  
  const request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if(this.status == 200){
      console.log(this.responseText);
      console.log(this.readyState);
      var Ergebnis = JSON.parse(this.responseText);
      if(City == "Bielefeld"){
        Bielefeld();
      }
      else{
        document.getElementById("Name").innerHTML = Ergebnis.name;
        if(Ergebnis.coord.lon < 0){
          if(Ergebnis.coord.lat < 0){
            document.getElementById("coord").innerHTML = Ergebnis.coord.lat + "S" + "   " + Ergebnis.coord.lon + "W";
          }
          else{
            document.getElementById("coord").innerHTML = Ergebnis.coord.lat + "N" + "   " + Ergebnis.coord.lon + "W";
          }
        }
        else{
          if(Ergebnis.coord.lat < 0){
            document.getElementById("coord").innerHTML = Ergebnis.coord.lat + "S" + "   "  + Ergebnis.coord.lon + "E";
          }
          else{
            document.getElementById("coord").innerHTML = Ergebnis.coord.lat + "N" + "   " + Ergebnis.coord.lon + "E";
          }
        }
        
        document.getElementById("Beschreibung").innerHTML = Ergebnis.weather[0].description;
        document.getElementById("Temp").innerHTML = Ergebnis.main.temp + " " + "&degC";
        document.getElementById("Feuchte").innerHTML = Ergebnis.main.humidity + " %";
        document.getElementById("Druck").innerHTML = Ergebnis.main.pressure + " hPa";
        document.getElementById("Wind").innerHTML = Ergebnis.wind.speed + " m/s";
      }
      
      
    }
    if(this.status == 404){
      console.log("nix gefunden");
    }
  }
  var key = OpeanWeatherKey;
  var City = document.getElementById("input_City").value;
  var Laendercode = document.getElementById("input_land").value;
  request.open("GET", "https://api.openweathermap.org/data/2.5/weather?q=" + City+ ","+ Laendercode+ "&lang=de&units=metric&appid=" + key, true);
  request.send(); 

  
};

function Bielefeld(){
  document.getElementById("Name").innerHTML = "Bielefeld?";
  document.getElementById("Beschreibung").innerHTML = "Error 404: Not found";
  document.getElementById("Temp").innerHTML = "Error 404: Not found";
  document.getElementById("Feuchte").innerHTML =  "Error 404: Not found";
  document.getElementById("Druck").innerHTML = "Error 404: Not found";
  document.getElementById("Wind").innerHTML = "Error 404: Not found";
  document.getElementById("coord").innerHTML = "Error 404: Not found";
}
setInterval(function (){
  Startseite();
}, 20000);
function Startseite(){
  const request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if(this.status == 200){
      console.log(this.responseText);
      console.log(this.readyState);
      var Ergebnis = JSON.parse(this.responseText);
      document.getElementById("Name_Startseite").innerHTML = Ergebnis.name;
      if(Ergebnis.coord.lon < 0){
        if(Ergebnis.coord.lat < 0){
          document.getElementById("coord_Startseite").innerHTML = Ergebnis.coord.lat + "S" + "   " + Ergebnis.coord.lon + "W";
        }
        else{
          document.getElementById("coord_Startseite").innerHTML = Ergebnis.coord.lat + "N" + "   " + Ergebnis.coord.lon + "W";
        }
      }
      else{
        if(Ergebnis.coord.lat < 0){
          document.getElementById("coord_Startseite").innerHTML = Ergebnis.coord.lat + "S" + "   "  + Ergebnis.coord.lon + "E";
        }
        else{
          document.getElementById("coord_Startseite").innerHTML = Ergebnis.coord.lat + "N" + "   " + Ergebnis.coord.lon + "E";
        }
      }
      
      document.getElementById("Beschreibung_Startseite").innerHTML = Ergebnis.weather[0].description;
      document.getElementById("Temp_Startseite").innerHTML = Ergebnis.main.temp + " " + "&degC";
      document.getElementById("Temp_min_Startseite").innerHTML = Ergebnis.main.temp_min + " " + "&degC";
      document.getElementById("Temp_max_Startseite").innerHTML = Ergebnis.main.temp_max + " " + "&degC";
      document.getElementById("Feuchte_Startseite").innerHTML = Ergebnis.main.humidity + " %";
      document.getElementById("Druck_Startseite").innerHTML = Ergebnis.main.pressure + " hPa";
      document.getElementById("Wind_Startseite").innerHTML = Ergebnis.wind.speed + " m/s";
      
      
    }
    if(this.status == 404){
      console.log("nix gefunden");
    }
  }
  var key = OpeanWeatherKey;
  var City = document.getElementById("input_City_Startseite").value;
  var Laendercode = document.getElementById("input_land_Startseite").value;
  request.open("GET", "https://api.openweathermap.org/data/2.5/weather?q=" + City+ ","+ Laendercode+ "&lang=de&units=metric&appid=" + key, true);
  request.send(); 
}

setInterval(function (){
  const request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if(this.status == 200){
      var Ergebnis = JSON.parse(this.responseText);
      if(!Ergebnis.feeds[0].field1 == 0){
        document.getElementById("Temperatur_BME2").innerHTML = Math.round(Ergebnis.feeds[0].field2 *1000)/1000;
        document.getElementById("Druck_BME2").innerHTML = Math.round(Ergebnis.feeds[0].field4 *100)/100;
        document.getElementById("Feuchte_BME2").innerHTML = Math.round(Ergebnis.feeds[0].field3 *100)/100;
        document.getElementById("rssi_BME2").innerHTML = Math.round(Ergebnis.feeds[0].field1 *100)/100;
      }
      
  }
    
    if(this.status == 404){
      console.log("nix gefunden");
    }
  }
  var key = '';
  var channel_id = 1724531;
  entries=1;
  request.open("GET","https://api.thingspeak.com/channels/1788949/feeds.json?api_key=XE4F8FNYWGRATCIF&results=" +entries, true);
  request.send(); 
}, 3000);
//Funktion zur Abfrage von Thingspeak


//-----------------------------------------------------------------------------------------------------
//Funktionen für die Abfrage der BME1 values
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Temperatur_BME1").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Temperatur_BME1", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Druck_BME1").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Druck_BME1", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Feuchte_BME1").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Feuchte_BME1", true);
  xhttp.send();
}, 10000 ) ;
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("rssi_BME1").innerHTML = MAth.round(this.responseText);
    }
  };
  xhttp.open("GET", "/rssi_BME1", true);
  xhttp.send();
}, 10000 ) ;
</script>
</html>

)rawliteral";

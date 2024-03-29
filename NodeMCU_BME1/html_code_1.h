//The html code for the website; saved as a raw String for the AsyncWebserver Template compiler

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
    .City_homepage{
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
    .ow_left{
      float: left;
    }
    .ow_right{
      float: right;
    }
    #Settings{
      background-color: rgba(52, 52, 52, 1);
      padding-top: 2vh;
      height: 100vh;
      width: 100%%; 
      color: var(--text-color);
    }
    .Settings_fields{
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
    .Settings_input{
      margin-top: 8px;
      width: 100%%;
      margin-bottom: 0px;
      font-size: 19px;
      display: flex;
      flex-direction: column;
      justify-content: space-evenly;  
    }
    .Settings_head{
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
    #WeatherApp{
      display: block;
    }
  .values_depiction{
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
    .value {
       font-size: 2.5rem; 
      }
    .unit { 
      font-size: 1.5rem; 
    }
    .BMEvalues{
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
    .search{
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
    <a class="active" onclick="display('WeatherApp')">WeatherApp</a>
    <a onclick="display('OpenWeather')">OpenWeather</a>
    <div class="dropdown">
      <button class="dropbtn">BME Sensors 
        <i class="fa fa-caret-down"></i>
      </button>
      <div class="dropdown-content">
        <a href="#" onclick="display('BME1')">BME 1</a>
        <a onclick="display('BME2')">BME 2</a>
      </div>
    </div> 
    <a onclick="display('Settings')">Settings</a>
    <a href="javascript:void(0);" style="font-size:15px;" class="icon" onclick="Burger_menu()">&#9776;</a>
  </div>

  <div class="content"id="WeatherApp">
    <h1 class="head_time" id="time">TIME</h1>
    <h2 class="head_date" id="date">Date</h2>
    <div class="values_depiction">
      <p class="City_homepage">
        <h2 class="City_name" id="Name_homepage">Name</h2>
        <pre id="coord_homepage">coord</pre>
      </p>
      <p class="values_ow">
        <span name="Name" class="ow_left">Description</span><span class="ow_right" id="Description_homepage"></span><br>
        <span name="Name" class="ow_left">Temperature</span><span class="ow_right" id="Temp_homepage"></span><br>
        <span class="ow_left">Temperature Course</span><span class="ow_right">
          <span id="Temp_min_homepage"></span> - <span id="Temp_max_homepage"></span>
        </span><br>
        <span class="ow_left">Humidity</span><span class="ow_right" id="Humidity_homepage"></span><br>
        <span class="ow_left">Pressure</span><span class="ow_right" id="Pressure_homepage"></span><br>
        <span class="ow_left">Wind speed</span><span class="ow_right" id="Wind_homepage"></span><br>
        
      </p>
    </div>
  </div>

  <div class="content"id="BME1"> 
    <h2 class="head">BME 1</h2>
    <div class="values_depiction">
      <p class="value">
        <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
        <span class="BMEvalues">Temperature</span> 
        <span id="Temperature_BME1">%Temperature_BME1%</span>
        <sup class="unit">&deg;C</sup>
      </p>
      <p class="value">
        <i class="fas fa-tint" style="color:#00add6;"></i> 
        <span class="BMEvalues">Humidity</span>
        <span id="Humidity_BME1">%Humidity_BME1%</span>
        <sup class="unit">&percnt;</sup>
      </p>
      <p class="value">
        <i class="fa-solid fa-arrows-to-circle" style="color:#002050;"></i> 
        <span class="BMEvalues">Pressure</span>
        <span id="Pressure_BME1">%Pressure_BME1%</span>
        <sup class="unit">hPa</sup>
      </p>
      <p class="value">
        <i class="fas fa-square-rss" style="color:rgb(22, 129, 190);"></i> 
        <span class="BMEvalues">Connection</span>
        <span id="rssi_BME1">%rssi_BME1%</span>
        <sup class="unit">dBm</sup>
      </p>
    </div>
  </div>

  <div class="content" id="BME2">
    <h2 class="head">BME 2</h2>
    <div class="values_depiction">
      <p class="value">
        <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
        <span class="BMEvalues">Temperature</span> 
        <span id="Temperature_BME2"></span>
        <sup class="unit">&deg;C</sup>
      </p>
      <p class="value">
        <i class="fas fa-tint" style="color:#00add6;"></i> 
        <span class="BMEvalues">Humidity</span>
        <span id="Humidity_BME2"></span>
        <sup class="unit">&percnt;</sup>
      </p>
      <p class="value">
        <i class="fa-solid fa-arrows-to-circle" style="color:#002050;"></i> 
        <span class="BMEvalues">Pressure</span>
        <span id="Pressure_BME2"></span>
        <sup class="unit">hPa</sup>
      </p>
      <p class="value">
        <i class="fas fa-square-rss" style="color:rgb(22, 129, 190);"></i> 
        <span class="BMEvalues">Connection</span>
        <span id="rssi_BME2"></span>
        <sup class="unit">dBm</sup>
      </p>
    </div>
  </div>

  <div class="content" id="OpenWeather">
    <h2 class="head">Open Weather Map</h2>
    <div class="values_depiction">
      <form class="search">
        <label for="input_City">City</label>
        <input type="text" id="input_City" value="Karlsruhe" placeholder="City">
        <label for="input_country">Country</label>
        <input type="text" id="input_country" value="DE" placeholder="ISO 3166 Code">
        <input type="button" onclick="search();" value="search">  
      </form>
      <p class="City">
        <h3 class="City_name" id="Name">Name</h3>
        <pre id="coord">coord</pre>
      </p>
      <p class="values_ow">
        <span class="ow_left">Description</span><span class="ow_right" id="Description"></span><br>
        <span class="ow_left">Temperature</span><span class="ow_right" id="Temp"></span><br>
        <span class="ow_left">Humidity</span><span class="ow_right" id="Humidity"></span><br>
        <span class="ow_left">Pressure</span><span class="ow_right" id="Pressure"></span><br>
        <span class="ow_left">Wind speed</span><span class="ow_right" id="Wind"></span><br>
      </p>
    </div>
    <br>
    <br>
  </div>

  <div id="Settings">
    <h2 class="head" id="Settings_head">Settings</h2>
    <div class="Settings_fields">
      <h3 class="Settings_head">General</h3>
          <div class="Settings_input">
            <label for="input_url">Background image</label>
            <input oninput="save_red()" type="text" id="input_url" placeholder="enter url here">
            <label for="preset">Presets</label>
            <select class="select" onchange="save_red()" id="preset">
              <option value="https://images.unsplash.com/photo-1484199316358-d7acb93729f2?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1790&q=80">Clouds</option>
              <option value="https://cdn.pixabay.com/photo/2017/05/11/09/20/shanghai-2303480_960_720.jpg">City day</option>
              <option value="https://cdn.pixabay.com/photo/2016/11/29/09/16/architecture-1868667_960_720.jpg">City night</option>
              <option value="https://cdn.pixabay.com/photo/2016/11/29/02/20/cosmos-1866820_960_720.jpg">stars</option>
            </select>
          </div>
          
        <h3 class="Settings_head">Homepage</h3>
          <div class="Settings_input">
            <label for="input_url">depicted City</label>
            <input oninput="save_red()" type="text" id="input_City_homepage" placeholder="Enter City here" value="Knielingen">
            <input oninput="save_red()" type="text" id="input_country_homepage" placeholder="Enter country code here" value="DE">
          </div>
      <button onclick="save()" id="savebutton" class="save">Save</button>
    </div>
  </div>

</body>

<script>
                          
  var OpeanWeatherKey = ""; // enter OW key here
  var ThingspeakKey = ""; // enter Thingspeak code here
  var ChannelID = 123; //enter Thingspeak ChannelID here                        
  function save(){
    if(document.getElementById("input_url").value !== ""){
      document.body.style.backgroundImage = "url(" + document.getElementById("input_url").value + ")"
      document.getElementById("input_url").value = "";
    }
    else{
      document.body.style.backgroundImage = "url(" + document.getElementById("preset").value + ")"
    }
    document.getElementById("savebutton").style.border = "2px solid lime";
    homepage();
    setTimeout(function(){display("WeatherApp")}, 100);
    
  }


  function save_red(){
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

function display(id){
  
  if(id == "OpenWeather"){
    search();
  }
  if(!(id == "WeatherApp")){
    Burger_menu();
  }
  if(document.getElementById("savebutton").style.border == "2px solid red"){
    document.getElementById("Settings_head").innerHTML = "Not Saved";
    document.getElementById("Settings_head").style.color = "red";
  }
  else{
    if(id=="Settings"){
      document.getElementById("savebutton").style.border = "2px solid #0200E9";
    }
    document.getElementById("Settings_head").innerHTML = "Settings";
    document.getElementById("Settings_head").style.color = "var(--text-color)";
    hide_content();
    document.getElementById(id).style.display = "block";
  }
}


function hide_content(){
  document.getElementById("WeatherApp").style.display = "none";
  document.getElementById("BME1").style.display = "none";
  document.getElementById("BME2").style.display = "none";
  document.getElementById("OpenWeather").style.display = "none";
  document.getElementById("Settings").style.display = "none";
}
window.onload= ()=>{
  hide_content();
  homepage();
  document.getElementById("WeatherApp").style.display = "block";
}

setInterval(function(){
  var dt = new Date();
  document.getElementById("time").innerHTML = (("0"+dt.getHours()).slice(-2)) +":"+ (("0"+dt.getMinutes()).slice(-2));
  document.getElementById("date").innerHTML = (("0"+dt.getDate()).slice(-2) +"."+ ("0"+(dt.getMonth()+1)).slice(-2))   +"."+ (dt.getFullYear());
},100);
function search(){
  
  
  const request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if(this.status == 200){
      console.log(this.responseText);
      console.log(this.readyState);
      var Response = JSON.parse(this.responseText);
      if(City == "Bielefeld"){
        Bielefeld();
      }
      else{
        document.getElementById("Name").innerHTML = Response.name;
        if(Response.coord.lon < 0){
          if(Response.coord.lat < 0){
            document.getElementById("coord").innerHTML = Response.coord.lat + "S" + "   " + Response.coord.lon + "W";
          }
          else{
            document.getElementById("coord").innerHTML = Response.coord.lat + "N" + "   " + Response.coord.lon + "W";
          }
        }
        else{
          if(Response.coord.lat < 0){
            document.getElementById("coord").innerHTML = Response.coord.lat + "S" + "   "  + Response.coord.lon + "E";
          }
          else{
            document.getElementById("coord").innerHTML = Response.coord.lat + "N" + "   " + Response.coord.lon + "E";
          }
        }
        
        document.getElementById("Description").innerHTML = Response.weather[0].description;
        document.getElementById("Temp").innerHTML = Response.main.temp + " " + "&degC";
        document.getElementById("Humidity").innerHTML = Response.main.humidity + " %";
        document.getElementById("Pressure").innerHTML = Response.main.pressure + " hPa";
        document.getElementById("Wind").innerHTML = Response.wind.speed + " m/s";
      }
      
      
    }
    if(this.status == 404){
      console.log("nix gefunden");
    }
  }
  var key = OpeanWeatherKey;
  var City = document.getElementById("input_City").value;
  var CountryCode = document.getElementById("input_country").value;
  request.open("GET", "https://api.openweathermap.org/data/2.5/weather?q=" + City+ ","+ CountryCode+ "&lang=de&units=metric&appid=" + key, true);
  request.send(); 

  
};

function Bielefeld(){
  document.getElementById("Name").innerHTML = "Bielefeld?";
  document.getElementById("Description").innerHTML = "Error 404: Not found";
  document.getElementById("Temp").innerHTML = "Error 404: Not found";
  document.getElementById("Humidity").innerHTML =  "Error 404: Not found";
  document.getElementById("Pressure").innerHTML = "Error 404: Not found";
  document.getElementById("Wind").innerHTML = "Error 404: Not found";
  document.getElementById("coord").innerHTML = "Error 404: Not found";
}
setInterval(function (){
  homepage();
}, 20000);
function homepage(){
  const request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if(this.status == 200){
      console.log(this.responseText);
      console.log(this.readyState);
      var Response = JSON.parse(this.responseText);
      document.getElementById("Name_homepage").innerHTML = Response.name;
      if(Response.coord.lon < 0){
        if(Response.coord.lat < 0){
          document.getElementById("coord_homepage").innerHTML = Response.coord.lat + "S" + "   " + Response.coord.lon + "W";
        }
        else{
          document.getElementById("coord_homepage").innerHTML = Response.coord.lat + "N" + "   " + Response.coord.lon + "W";
        }
      }
      else{
        if(Response.coord.lat < 0){
          document.getElementById("coord_homepage").innerHTML = Response.coord.lat + "S" + "   "  + Response.coord.lon + "E";
        }
        else{
          document.getElementById("coord_homepage").innerHTML = Response.coord.lat + "N" + "   " + Response.coord.lon + "E";
        }
      }
      
      document.getElementById("Description_homepage").innerHTML = Response.weather[0].description;
      document.getElementById("Temp_homepage").innerHTML = Response.main.temp + " " + "&degC";
      document.getElementById("Temp_min_homepage").innerHTML = Response.main.temp_min + " " + "&degC";
      document.getElementById("Temp_max_homepage").innerHTML = Response.main.temp_max + " " + "&degC";
      document.getElementById("Humidity_homepage").innerHTML = Response.main.humidity + " %";
      document.getElementById("Pressure_homepage").innerHTML = Response.main.pressure + " hPa";
      document.getElementById("Wind_homepage").innerHTML = Response.wind.speed + " m/s";
      
      
    }
    if(this.status == 404){
      console.log("nix gefunden");
    }
  }
  var key = OpeanWeatherKey;
  var City = document.getElementById("input_City_homepage").value;
  var CountryCode = document.getElementById("input_country_homepage").value;
  request.open("GET", "https://api.openweathermap.org/data/2.5/weather?q=" + City+ ","+ CountryCode+ "&lang=de&units=metric&appid=" + key, true);
  request.send(); 
}
//Thingspeak request function
setInterval(function (){
  const request = new XMLHttpRequest();
  request.onreadystatechange = function() {
    if(this.status == 200){
      var Response = JSON.parse(this.responseText);
      if(!Response.feeds[0].field1 == 0){
        document.getElementById("Temperature_BME2").innerHTML = Math.round(Response.feeds[0].field2 *1000)/1000;
        document.getElementById("Pressure_BME2").innerHTML = Math.round(Response.feeds[0].field4 *100)/100;
        document.getElementById("Humidity_BME2").innerHTML = Math.round(Response.feeds[0].field3 *100)/100;
        document.getElementById("rssi_BME2").innerHTML = Math.round(Response.feeds[0].field1 *100)/100;
      }
      
  }
    
    if(this.status == 404){
      console.log("nothing found");
    }
  }
  var key = ThingspeakKey;
  var channel_id = ChannelID;
  entries=1;
  request.open("GET","https://api.thingspeak.com/channels/"+ ChannelID +"/feeds.json?api_key="+ThingspeakKey+"&results=" +entries, true);
  request.send(); 
}, 3000);



//-----------------------------------------------------------------------------------------------------
//BME1 value request functions
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Temperature_BME1").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Temperature_BME1", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Pressure_BME1").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Pressure_BME1", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Humidity_BME1").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Humidity_BME1", true);
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

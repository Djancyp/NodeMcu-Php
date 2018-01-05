$(document).ready(function(){

  //json file check and activate
$.getJSON( "/public/light.json", function( data ) {
  $.each( data, function( key, val ) {
    console.log(val);
    if (val == "on"){  
      $('.led').bootstrapToggle('on')
    }else{
      $('.led').bootstrapToggle('off')
    }
  });
});//GetJson

function readJson($file){
  $.getJSON( "{$file}", function( data ) {
    $.each( data, function( key, val ) {
    var  data = val;
    return readJson;
    });
  });//GetJson
}


function getTemp(){
  $.getJSON( "/public/sensor.json", function( data ) {
          $.each( data, function( key, val ) {
            console.log("Temp sensor: " + val);
            $('.temptext').text(val+"°C");
            $('.temp').attr('style', 'height:' + val + '% !important');
          });
    });//GetJson
}


function jsonlight($url, $function){
  $.ajax({
              url: $url,
              cache: false,
              type: 'GET',
              data : {
                  "light" : $function
              },
              success: function(json) {
              console.log("axaj function work");             }
  });
}


//Ajax php Led on/off
$('.led').change(function() {
        if(this.checked) {
          jsonlight('/private/devices/add.php', 'on');
        } else {
          jsonlight('/private/devices/add.php', 'off');
        }
});
   
function getjson(){
  var d = "on"         
  $.ajax({
    url: '/private/devices/read.php',
    cache: false,
    type: 'GET',
    data : {
        "light" : d
    },
    success: function(json) {
    console.log("read.php ");             
    }
  });
}   

  
setInterval(getTemp, 100);


});



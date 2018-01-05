$(document).ready(function(){
  
  $( "input[type='checkbox']" ).prop( "checked", function( i, val ) {
    if ($('#light').prop('checked', true)){
      //$.get("http://192.168.0.4", {light:"on"} );
    } else {
     // $.get("http://192.168.0.4", {light:"off"} );
    }
  });

 $('.myCheckbox').prop('checked', false);
  
  $(".led").click(function(){
            var p = $(this).attr('id'); // get id value (i.e. pin13, pin12, or pin11)
            // send HTTP GET request to the IP address with the parameter "pin" and value "p", then execute the function
            $.get("http://192.168.0.4", {"light":"on"} );
        });
 
  $.getJSON( "light.json", function( data ) {
    var items = [];
        $.each( data, function( key, val ) {
          console.log(val);
          if (val == "on"){

            $('.light').prop('checked', true);
          }else{
           $('.light').prop('checked', false);

          }
        });
  });//GetJson
   
});

<?php  
require_once('../initialize.php');

            $light = $_GET['light'];
          
           //echo file_get_contents(PUBLIC_PATH."/light.json");
           
            if($light == "on") {  
              $file = fopen(PUBLIC_PATH."/light.json", "w") or die("can't open file");
              fwrite($file, '{"light": "on"}');
              fclose($file);
              echo "file write ON";
            } 
            
            else if ($light == "off") {  
              $file = fopen(PUBLIC_PATH."/light.json", "w") or die("can't open file");
              fwrite($file, '{"light": "off"}');
              fclose($file);
              echo "file write Off";
            }



?>

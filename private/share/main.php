     <!-- Content Wrapper. Contains page content -->
  <div class="content-wrapper">
    <!-- Content Header (Page header) -->
    <section class="content-header">
      <h1>
        Dashboard
        <small>Home Automation Dashboard.</small>
      </h1>
    </section>
    <!-- Main content -->
<section class="content container-fluid">
  <div class="col-md-4">
    <div class="box box-primary">
      <div class="box-header with-border">
              <h3 class="box-title">Online Devices</h3>
              <div class="box-tools pull-right">
                <button type="button" class="btn btn-box-tool" data-widget="collapse"><i class="fa fa-minus"></i>
                </button>
                <button type="button" class="btn btn-box-tool" data-widget="remove"><i class="fa fa-times"></i></button>
              </div>
            </div>
          <div class="box-body">      
            <table class="table table-bordered">
                <tr>
                  <th style="width: 10px">#</th>
                  <th>Device Name</th>
                  <th>Status</th>
                </tr>
                <tr>
                  <td><i class="fa fa-lightbulb-o" aria-hidden="true"></i></td>
                  <td> ESP8266 Living Room</td>
                  <td>
                   <div class="checkbox">
                    <label>
                      <input class="led" type="checkbox"  data-toggle="toggle" data-onstyle="danger" data-size="small">
                    </label>
                  </div>
                  </td>
                </tr>  
            </table>
      </div><!-- /.box-body -->
    </div><!-- /.box -->
  </div><!--/col-md-6-->  


        <div class="col-md-3 stemp">
      <div class="box box-solid text-center">
        
            <div class="progress vertical active">
                <div class="temp progress-bar progress-bar-danger progress-bar-striped" role="progressbar" aria-valuenow="40" aria-valuemin="0" aria-valuemax="100" style="height: 40%">
                  <div class="tempicon">
                    <img class="tempimage" src="images/temp.png">
                  <i class="fa fa-thermometer-half"></i>
                  <h6 class="temptext"></h6>
                </div><!--icon-->
                  <span class="sr-only">%</span>  
                </div>
              </div>

        </div>
      </div>          
    </div> 

  </div> 
</section>
    <!-- /.content -->
  </div>
  <!-- /.content-wrapper -->
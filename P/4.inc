<style>
.btnsmt
	{
                display: inline-block;
                outline: 0;
                border: 0;
                cursor: pointer;
                will-change: box-shadow,transform;
                background: radial-gradient( 100% 100% at 100% 0%, #89E5FF 0%, #5468FF 100% );
                box-shadow: 0px 2px 4px rgb(45 35 66 / 40%), 0px 7px 13px -3px rgb(45 35 66 / 30%), inset 0px -3px 0px rgb(58 65 111 / 50%);
                padding: 0 25px;
                border-radius: 6px;
                color: #fff;
                height: 35px;
                font-size: 12px;
                text-shadow: 0 1px 0 rgb(0 0 0 / 40%);
                transition: box-shadow 0.15s ease,transform 0.15s ease;
                :hover {
                    box-shadow: 0px 4px 8px rgb(45 35 66 / 40%), 0px 7px 13px -3px rgb(45 35 66 / 30%), inset 0px -3px 0px #3c4fe0;
                    transform: translateY(-2px);
                }
                :active{
                    box-shadow: inset 0px 3px 7px #3c4fe0;
                    transform: translateY(2px);
                }
	}
</style>
<?php
	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}
	$sql = "SELECT * from booktable";
	$result = $conn->query($sql);
?>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>

<main class="flex-1 overflow-auto p-6">
    <section id="reservationSection" >
      <h1 class="text-3xl font-bold text-gray-800 mb-6">Table Reservations</h1>
      <div class="overflow-x-auto">

        <table class="min-w-full bg-white rounded-lg shadow" id=tbl1>
          <thead>
            <tr class="bg-gray-100 text-gray-700 text-left">
              <th class="py-3 px-4">Customer Name</th>
              <th class="py-3 px-4">Date</th>
              <th class="py-3 px-4">Time</th>
              <th class="py-3 px-4">Guests</th>
              <th class="py-3 px-4">Table Number</th>
              <th class="py-3 px-4">Status</th>
              <th class="py-3 px-4">Action</th>
            </tr>
          </thead>
          <tbody class="text-gray-600">
		<?php
			$i=1;
			if ($result->num_rows > 0) 
			{
				while($row = $result->fetch_assoc()) 
				{
				?>
					<tr class="border-t">
				              <td class="py-3 px-4"><?php echo $row["custname"]; ?> </td>
				              <td class="py-3 px-4"><?php echo $row["date"]; ?></td>
				              <td class="py-3 px-4"><?php echo $row["time"]; ?></td>
				              <td class="py-3 px-4"><?php echo $row["guests"]; ?> Guests </td>
				              <td class="py-3 px-4">Table-<?php echo $row["tn"]; ?></td>
				              <td class="py-3 px-4"> <?php echo $row["status"]; ?>  </td>
					      <td class="py-3 px-4"><span><input type='hidden' value='<?php echo $row["tid"];?>' name='ID<?php echo $row["tid"];?>' id='ID<?php echo $row["tid"];?>' ><button id="cnf<?php echo $i;?>" class='btnsmt'> Confirm </button><button id="cncl<?php echo $i;?>" class='btnsmt'>Cancel</button></span> </td>
				        </tr>
					<script>
					$('#cnf<?php echo $i; ?>').click(function()
					{
					
						var tid = $('#ID<?php echo $row["tid"];?>').val();
						
						$.post("cnfseat.php", 
						{
					
							tid:tid
						},		
						function(data)
						{
				    			alert(data);
	 	 				});
					});
					$('#cncl<?php echo $i; ?>').click(function()
					{
						
						var tid = $('#ID<?php echo $row["tid"];?>').val();
						
						$.post("cnclseat.php", 
						{
							
							tid:tid
						},		
						function(data)
						{
				    			alert(data);
							window.location.reload();
	 	 				});
					});
					</script>
				<?php
				$i=$i+1;
				}
			} 
			else 
			{
		  		echo "0 results";
			}
			
			$conn->close();
		?>
		
            
            <tr class="border-t">
              <td class="py-3 px-4"><input type="text" name="customer" id="customer" class="w-full border rounded px-2 py-1"></td>
              <td class="py-3 px-4"><input type="date" name="date" id="date" class="w-full border rounded px-2 py-1"></td>
              <td class="py-3 px-4"><input type="time" name="time" id="time" class="w-full border rounded px-2 py-1"></td>
              <td class="py-3 px-4"><input type="number" name="guests" id="guests" class="w-full border rounded px-2 py-1" min="1"></td>
              <td class="py-3 px-4"><input type="number" name="table" id="table" class="w-full border rounded px-2 py-1" min="1"></td>
              <td class="py-3 px-4">

                <select name="status" id="status" class="w-full border rounded px-2 py-1">
                  <option>Pending</option>
                </select>
              </td>
              <td class="py-3 px-4 text-center">
                <button id='btnsmt' class='btnsmt'>Submit</button>
              </td>
            </tr>
          </tbody>
        </table>

      </div>
    </section>
  </main>

<script>

	$('#btnsmt').click(function()
	{
		var cn = $('#customer').val();
		var d = $('#date').val();  
		var T = $('#time').val();  
		var g = $('#guests').val();  
		var tn = $('#table').val();  
		var st = $('#status').val();    
		$.post("Book.php", 
		{
			CN: cn,
			d:d,
			T:T,
			g:g,
			tn:tn,
			st:st
		},		
		function(data){

			document.getElementById("tbl1").innerHTML=data;
			
 	 	});
		
	});

</script>


<style>
    .bg-hero {
      background-image: url('https://images.unsplash.com/photo-1600891964599-f61ba0e24092?auto=format&fit=crop&w=1950&q=80');
      background-size: cover;
      background-position: center;
    }
body {
      font-family: 'Segoe UI', sans-serif;
      background: #fffdf5;
      margin: 0;
      padding: 0;
      color: #333;
    }
    .menu-container {
      max-width: 800px;
      margin: 30px auto;
      padding: 20px;
      background: #ffffff;
      border-radius: 12px;
      box-shadow: 0 4px 12px rgba(0, 0, 0, 0.1);
    }
    .page {
      display: none;
    }
    .page.active {
      display: block;
    }
    h2 {
      border-bottom: 2px solid #f4d03f;
      padding-bottom: 6px;
      margin-top: 30px;
      color: #e67e22;
    }
    ul {
      list-style: none;
      padding: 0;
    }
    li {
      display: flex;
      justify-content: space-between;
      padding: 10px 0;
      border-bottom: 1px dotted #ccc;
    }
    .pagination {
      text-align: center;
      margin-top: 30px;
    }
    .pagination button {
      background: #e67e22;
      color: white;
      border: none;
      margin: 0 10px;
      padding: 10px 20px;
      font-size: 16px;
      border-radius: 6px;
      cursor: pointer;
    }
    .pagination button:disabled {
      background: #ccc;
      cursor: not-allowed;
    }
    input
    {

                border: 1px solid #000;
                border-radius: 5px;
                height: 30px;
                line-height: normal;
                color: #282828;
                display: block;
                width: 100%;
                box-sizing: border-box;
                user-select: auto;
                font-size: 12px;
                padding: 0 2px;
                padding-left: 6px;
                :focus{
                    border: 3px solid #5551ff;
                }
	}
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
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>

<main class="flex-1 overflow-auto p-6">
    <section id="reservationSection" >
    <div class="menu-container">
	<?php
	$i=1;
	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}
	$sql = "SELECT * from booktable where status='confirmed'";
	$result = $conn->query($sql);
	?>
 <span id='Drinks'> 
	<h2>Orders </h2>
		<UL id='Fd1'> 
			<li> 
			  <span> 
				<select id="selTbl" name="selTbl" >
					<?php	
					if ($result->num_rows > 0) 
					{
						while($row = $result->fetch_assoc() ) 
						{
							echo "<option value='".$row["tid"]."'> Table- ".$row["tn"] . "</option>";
	
						}
					}
					?>
					</select>
			</span> 
			</li>
			<li>
				<span id='cdata'>
				
				</span>
			</li> 
			<li>
			<span id='orders' style="visibility:hidden">
				<table class="min-w-full bg-white rounded-lg shadow" id=tbl1 >
			          <thead>
			            <tr class="bg-gray-100 text-gray-700 text-left">
				              <th class="py-3 px-4">Item Code</th>
				              <th class="py-3 px-4">Item Name </th>
				              <th class="py-3 px-4">Item Price</th>
				              <th class="py-3 px-4">Quantity</th>
				              <th class="py-3 px-4">Amount</th>
				              <th class="py-3 px-4">&nbsp;</th>
				     </tr>
			          </thead>
				  <tbody class="text-gray-600" id="tblbody">
					<tr class="border-t">
				              <td class="py-3 px-4">
					      Sample Data
 					      </td>
				        </tr>
				  </tbody>	
        			  <tfoot class="text-gray-600">	
					<tr class="border-t">
				              <td class="py-3 px-4">
					      	<span id="ic">
						</span>
 					      </td>
				              <td class="py-3 px-4">
					      	<select id="itname">
							<?php	
								$sql2 = "SELECT * from foodmenu";
								$result2 = $conn->query($sql2);
								if ($result2->num_rows > 0) 
								{
									while($row2 = $result2->fetch_assoc() ) 
									{
										echo "<option value='".$row2["Food_id"]."'> ".$row2["itemname"]."</option>";		
									}
								}
							?>
						</select>
					      </td>
				              <td class="py-3 px-4">
					      	<input type="text" id="ip" readonly >
					      </td>
				              <td class="py-3 px-4"><input type="text" id="Qty" value="0"></td>
				              <td class="py-3 px-4"><input type="text" id="amt"> </td>
					      <td class="py-3 px-4"><span><button id="add" class='btnsmt'> ADD </button></td>
				        </tr>
					</tfoot>
				</table>
			</span>
			</li> 
		</UL>
</span>	
<script>
$("#selTbl").change(function(){
	var rid=$( "#selTbl" ).val();
	$.post("getCust.php", 
	{
		rid:rid
	},		
	function(data)
	{
		document.getElementById("cdata").innerHTML = data;
		document.getElementById("orders").style.visibility = "visible";
	});

	$.post("getorders.php", 
	{
		rid:rid
	},		
	function(data)
	{
		document.getElementById("tblbody").innerHTML = data;
		
	});


});
$("#itname").change(function(){
	var fid=$( "#itname" ).val();
	document.getElementById("ic").innerHTML = fid;	
	var amt = document.getElementById("amt").value;
	var qty = document.getElementById("Qty").value;
	var ip = document.getElementById("ip").value;
	amt=qty* ip;
	$.post("getprice.php", 
	{
		fid:fid
	},		
	function(data)
	{
		document.getElementById("ip").value= data;
	});

});
$("#Qty").keyup(function()
{
	
	var qty = document.getElementById("Qty").value;
	var ip = document.getElementById("ip").value;
	document.getElementById("amt").value =qty* ip;
});
$("#add").click(function(){
	var ic=$( "#itname" ).val();
	var rid=$( "#selTbl" ).val();
	var qty = document.getElementById("Qty").value;
	var ip = document.getElementById("ip").value;
	var amt=qty*ip;
	const selectElement = document.getElementById('itname');
	const selectedIndex = selectElement.selectedIndex;
   	const ItemName = selectElement.options[selectedIndex].innerHTML;
	
	$.post("addorder.php", 
	{
		Itemname:ItemName,
		ic:ic,
		rid:rid,
		qty:qty,
		ip:ip,
		amt:amt
		
		
	},		
	function(data)
	{
		document.getElementById("tblbody").innerHTML = data;

	});

});
function myFunction(p1, p2) 
{
		
		$.post("deleteorder.php", 
		{
			ic:p1,
			rid:p2
		},		
		function(data)
		{
			document.getElementById("tblbody").innerHTML = data;

		});

		
}
function myF(p1) 
{
		
		$.post("completebill.php", 
		{
			rid:p1
		},		
		function(data)
		{
			alert(data);

		});

		
}
</script>
</div>
</section>
</main>
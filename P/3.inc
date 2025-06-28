<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
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

<main class="flex-1 overflow-auto p-6">
    <section id="reservationSection" >
  <div class="menu-container">
    
    <!-- Page 1 -->
    <div class="page active" id="page1">

<?php
	$i=1;
	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}
	$sql = "SELECT distinct itemtype from foodmenu ";
	$result = $conn->query($sql);
	if ($result->num_rows > 0) 
	{
		while($row = $result->fetch_assoc() ) 
		{
			echo "\n <span id='".$row["itemtype"]."'> <h2>".$row["itemtype"] . "</h2>";
			$sql1 = "SELECT * FROM foodmenu where itemtype='".$row["itemtype"]."' ";
			$result1 = $conn->query($sql1);
			if ($result1->num_rows > 0) 
			{
				while($row1 = $result1->fetch_assoc() ) 
				{
					echo "<UL id='Fd".$row1["Food_id"]."'> ";
					echo "\n<li> \n  <span>  <input type='hidden' name='Food".$row1["Food_id"]."' id='Food".$row1["Food_id"]."' value='".$row1["Food_id"]."' > <input type='text' value='".$row1["itemname"]."' id='upin".$row1["Food_id"]."' ></span> \n <span> <input type='text' id='upip".$row1["Food_id"]."' Rs. value='".$row1["itemprice"] ."'  ></span> \n <span> <button id='upd".$row1["Food_id"]."' class='btnsmt'> Update </button> &nbsp;&nbsp; <button id='cncl".$row1["Food_id"]."' class='btnsmt'>Cancel</button></span>\n</li> ";
					echo "\n</UL>";
					?>
					<script>
					$('#upd<?php echo $row1["Food_id"]; ?>').click(function()
					{
						var fid = $('#Food<?php echo $row1["Food_id"];?>').val();
						var upin = $('#upin<?php echo $row1["Food_id"];?>').val();
						var upip = $('#upip<?php echo $row1["Food_id"];?>').val();

						$.post("updfood.php", 
						{
							fid:fid,
							upin: upin,
							upip: upip
						},		
						function(data)
						{
				    			alert(data);
	 	 				});
					});

					$('#cncl<?php echo $row1["Food_id"]; ?>').click(function()
					{
						var itType="<?php echo $row["itemtype"];?>";
						var fid = $('#Food<?php echo $row1["Food_id"];?>').val();
						var upin = $('#upin<?php echo $row1["Food_id"];?>').val();
						var upip = $('#upip<?php echo $row1["Food_id"];?>').val();

						$.post("cnclfood.php", 
						{
							itType:itType,
							fid:fid,
							upin: upin,
							upip: upip
						},		
						function(data)
						{
					
							document.getElementById("Fd<?php echo $row1["Food_id"] ?>").innerHTML = "";
	 	 				});
					});
					</script>
					<?php	
				}
			}	
			?>
			</span>



			<ul>
				<li>
					<span> <input type="hidden" name="nit<?php echo $i;?>" id="nit<?php echo $i;?>" value="<?php echo $row["itemtype"] ?>"> <input type="text" name="nin<?php echo $i;?>" id="nin<?php echo $i;?>" value="add item" > </span>  <span> <input type="number" name="nip<?php echo $i;?>" id="nip<?php echo $i;?>" value="0" ></span> <span>&nbsp;</span>  <span><button id='btnsmt<?php echo $i;?>' class='btnsmt'> ADD </button> </span></li>	
				</li>
			</ul>			
		<script>
		$('#btnsmt<?php echo $i;?>').click(function()
		{

			var newit = $('#nit<?php echo $i;?>').val();
			var newin = $('#nin<?php echo $i;?>').val();
			var newip = $('#nip<?php echo $i;?>').val();
		
			$.post("addfood.php", 
			{
				newit: newit,
				newin: newin,
				newip: newip
			},		
			function(data)
			{
	    			alert(data);
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
      <h2>Add Item in new Category : Category Name :</h2><input type="text" name="nit<?php echo $i;?>" id="nit<?php echo $i;?>" >
      <ul>
	<li>
		<span>  <input type="text" name="nin<?php echo $i;?>" id="nin<?php echo $i;?>" > </span> <span> <input type="number" name="nip<?php echo $i;?>" id="nip<?php echo $i;?>" ></span>
	</li>
      </ul><br>
	<center><button id='btnsmt<?php echo $i;?>' class="btnsmt"> ADD </button></center>

		
	
	
	
    </div>

    <!-- Page 2 -->
    <div class="page" id="page2">

      <h2>Salads</h2>
      <ul>
        <li><span>Fresh Garden Greens</span><span>₹120</span></li>
        <li><span>Caesar Salad</span><span>₹195</span></li>
        <li><span>Apple Corn Hawaiian</span><span>₹195</span></li>
        <li><span>All-Time Favourite Russian</span><span>₹195</span></li>
      </ul>

      <h2>Side Orders</h2>
      <ul>
        <li><span>Papad (Roasted)</span><span>₹30</span></li>
        <li><span>Masala Papad with Cheese</span><span>₹85</span></li>
        <li><span>Raita</span><span>₹130</span></li>
      </ul>
    </div>

    <!-- Page 3 -->
    <div class="page" id="page3">
      <h2>Sabzi (Curries)</h2>
      <ul>
        <li><span>Paneer Makhani</span><span>₹400</span></li>
        <li><span>Paneer Kadhai</span><span>₹400</span></li>
        <li><span>Paneer Tikka Masala</span><span>₹400</span></li>
      </ul>

      <h2>Rice</h2>
      <ul>
        <li><span>Plain Basmati Rice</span><span>₹210</span></li>
        <li><span>Jeera Rice</span><span>₹245</span></li>
        <li><span>Hyderabadi Biryani</span><span>₹325</span></li>
        <li><span>Mix Veg. Khichdi</span><span>₹325</span></li>
      </ul>

      <h2>Roti & Breads</h2>
      <ul>
        <li><span>Roti</span><span>₹45</span></li>
        <li><span>Paratha</span><span>₹60</span></li>
        <li><span>Kulcha</span><span>₹70</span></li>
        <li><span>Naan</span><span>₹60</span></li>
      </ul>
    </div>

    <!-- Pagination -->
    <div class="pagination">
      <button id="prevBtn" onclick="changePage(-1)">Previous</button>
      <button id="nextBtn" onclick="changePage(1)">Next</button>
    </div>
  </div>

  <script>

    let currentPage = 1;
    const totalPages = 3;

    function showPage(page) {
      for (let i = 1; i <= totalPages; i++) {
        document.getElementById(`page${i}`).classList.remove('active');
      }
      document.getElementById(`page${page}`).classList.add('active');

      document.getElementById('prevBtn').disabled = page === 1;
      document.getElementById('nextBtn').disabled = page === totalPages;
    }

    function changePage(direction) {
      currentPage += direction;
      if (currentPage < 1) currentPage = 1;
      if (currentPage > totalPages) currentPage = totalPages;
      showPage(currentPage);
    }
    showPage(currentPage);	
</script>
    </section>
  </main>

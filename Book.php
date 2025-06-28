<?php


	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}

	$sql="INSERT INTO `booktable` (`custname`, `date`, `time`, `guests`, `tn`, `status`) VALUES ('".$_POST['CN']."', '".$_POST['d']."', '".$_POST['T']."', '".$_POST['g']."', '".$_POST['tn']."', '".$_POST['st']."');";
	if ($conn->query($sql) === TRUE) 
	{
	?>
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
			$sql1 = "SELECT * from booktable";
			$result1 = $conn->query($sql1);

			if ($result1->num_rows > 0) 
			{
				while($row1 = $result1->fetch_assoc()) 
				{
				?>
					<tr class="border-t">
				              <td class="py-3 px-4"><?php echo $row1["custname"]; ?> </td>
				              <td class="py-3 px-4"><?php echo $row1["date"]; ?></td>
				              <td class="py-3 px-4"><?php echo $row1["time"]; ?></td>
				              <td class="py-3 px-4"><?php echo $row1["guests"]; ?> Guests </td>
				              <td class="py-3 px-4">Table-<?php echo $row1["tn"]; ?></td>
				              <td class="py-3 px-4"> <?php echo $row1["status"]; ?>  </td>
				            </tr>
				<?php
				}
			} 
		?>
		<tr class="border-t">
              <td class="py-3 px-4"><input type="text" name="customer" id="customer" class="w-full border rounded px-2 py-1"></td>
              <td class="py-3 px-4"><input type="date" name="date" id="date" class="w-full border rounded px-2 py-1"></td>
              <td class="py-3 px-4"><input type="time" name="time" id="time" class="w-full border rounded px-2 py-1"></td>
              <td class="py-3 px-4"><input type="number" name="guests" id="guests" class="w-full border rounded px-2 py-1" min="1"></td>
              <td class="py-3 px-4"><input type="number" name="table" id="table" class="w-full border rounded px-2 py-1" min="1"></td>
              <td class="py-3 px-4">

                <select name="status" id="status" class="w-full border rounded px-2 py-1">
                  <option>Confirmed</option>
                  <option>Pending</option>
                  <option>Cancelled</option>
                </select>
              </td>
              <td class="py-3 px-4 text-center">
                <button id='btnsmt'  class="bg-blue-600 text-white px-4 py-1 rounded hover:bg-blue-700">Submit</button>
              </td>
            </tr>	
	</tbody>
		<?php		
	} 
	else 
	{
 	 echo "Error: " . $sql . "<br>" . $conn->error;
	}
	$conn->close();

?>
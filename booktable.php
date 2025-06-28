<?php 
	$C= $_POST['customer'];
	$D= $_POST['date'];
	$t= $_POST['time'];
	$G= $_POST['guests'];
	$T= $_POST['table'];
	$S= $_POST['status'];

	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = mysqli_connect($servername, $username, $password, $database);
	// Connection Check
	if (!$conn) {die("Connection failed: " . $conn->connect_error);}
	else
	{


		$sql = "Describe booktable ";		
		if ($result = $conn->query($sql)) 
		{
			/* fetch associative array */
    			while ($row = $result->fetch_assoc()) 
			{
			echo "<tr><td>" . $row['Field'] . "</td><td>" . $row['Type'] . "</td></tr>";
			}
		}
		

		//$sqlI = "insert into Uname (custname,time,guests,tn,status) VAlues ('".$C."', '".$D."', '".$t."','".$G."', '".$T."', '".$S."')";
		//echo $sqlI;
			//	if ($conn->query($sqlI) === TRUE) 
			//	{
			//		  echo "New data entered successfully ";
			//	} 
			//	else 
			//	{
			//		  echo "Error: " . $sqlI . "<br>" . $conn->error;
			//	}
				
	}
?>
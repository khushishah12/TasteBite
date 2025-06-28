<?php


	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}

	$sql="select * from foodmenu where Food_id=".$_POST['fid']."";
	$result = $conn->query($sql);
	if ($result->num_rows > 0) 
	{
		$row = $result->fetch_assoc();
		echo $row["itemprice"];
		
	}
	else 
	{
 	 echo "Error: " . $sql . "<br>" . $conn->error;
	}
	$conn->close();

?>
<?php


	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}

	$sql="INSERT INTO `foodmenu` (`itemtype`,`itemname`, `itemprice`) VALUES ('".$_POST['newit']."','".$_POST['newin']."', '".$_POST['newip']."');";
	echo $sql;
	if ($conn->query($sql) === TRUE) {
		  echo "New record created successfully";
	} 
	else 
	{
 	 echo "Error: " . $sql . "<br>" . $conn->error;
	}
	$conn->close();

?>
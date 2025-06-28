<?php


	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}

	$sql="UPDATE foodmenu SET itemname='".$_POST['upin']."' , itemprice='".$_POST['upip']."' WHERE Food_id='".$_POST['fid']."' ";


	echo $sql;
	if ($conn->query($sql) === TRUE) {
		  echo "record updated successfully";
	} 
	else 
	{
 	 echo "Error: " . $sql . "<br>" . $conn->error;
	}
	$conn->close();

?>
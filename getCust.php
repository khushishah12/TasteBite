
<?php


	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}

	$sql="select * from booktable where tid='".$_POST['rid']."' ";
	$result = $conn->query($sql);
	if ($result->num_rows > 0) 
	{
		$row = $result->fetch_assoc();
		echo " <h2> Customer Name :".$row["custname"] . "</h2> <br > <p> Number of Guest :".$row["guests"] . "</p> <a href='Bill.php?rid=".$_POST['rid']."'  class='btnsmt'>Prepare Bill </a>&nbsp;&nbsp;<a href='Bill.php?rid=".$_POST['rid']."'  class='btnsmt'>Complete Bill </a> ";

		
	}
	else 
	{
 	 echo "Error: " . $sql . "<br>" . $conn->error;
	}
	$conn->close();

?>
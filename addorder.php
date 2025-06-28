<?php


	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = new mysqli($servername, $username, $password, $database);
	if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}

	$sql="INSERT INTO `orders` (`Itemcode`,`rid`, `itemname`,`itemprice`,`Qty`, `amount`) VALUES ('".$_POST['ic']."','".$_POST['rid']."', '".$_POST['Itemname']."','".$_POST['ip']."','".$_POST['qty']."', '".$_POST['amt']."');";
	
	if ($conn->query($sql) === TRUE) 
	{
		$sql1="select * from orders where rid='".$_POST['rid']."' ";
		$result1 = $conn->query($sql1);
		if ($result1->num_rows > 0) 
		{
			while($row = $result1->fetch_assoc() ) 
			{
				?>
				<tr>
					<td class="py-3 px-4"><?php  echo $row["Itemcode"] ?> </td>
					<td class="py-3 px-4"><?php  echo $row["itemname"] ?></td>
					<td class="py-3 px-4"><?php  echo $row["itemprice"] ?></td>
					<td class="py-3 px-4"><?php  echo $row["Qty"] ?></td>
					<td class="py-3 px-4"><?php  echo $row["amount"] ?></td>
					<td class="py-3 px-4"><span><button id="btnCncl<?php  echo $row["Itemcode"] ?>" class='btnsmt' onclick="myFunction(<?php  echo $row["Itemcode"] ?>,<?php echo $_POST['rid'] ?>);">Cancel </button></td>
									</tr>
				<?php
			}
		
		}

	} 
	else 
	{
 	 echo "Error: " . $sql . "<br>" . $conn->error;
	}
	$conn->close();

?>
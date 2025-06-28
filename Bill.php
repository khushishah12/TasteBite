<?php
require('.//fpdf//fpdf.php');
class PDF extends FPDF
{
	function Header()
	{
 	
	}

	// Page footer
	function Footer()
	{
    
	}
}

$pdf = new PDF();
$pdf->AddPage("P","A5");
$pdf->SetFont('Times','B',18);
$pdf->Cell(0, 8, 'TasteBite', 0, 0, 'C');
$pdf->ln(6);
$pdf->SetFont('Times','',12);
$pdf->Cell(0, 8, 'Email : Customercare@TasteBite.in', 0, 0, 'C');
$pdf->ln(6);
$pdf->SetFont('Times','',12);
$pdf->Cell(0, 8, 'Phone : +91-92271 92271', 0, 0, 'C');
$pdf->ln(6);
$pdf->ln(6);
$pdf->Cell(40, 8, 'Customer Detail:', 0, 0, 'L');
$pdf->Cell(45, 8, '', 0, 0, 'C');
$pdf->Cell(50, 8, 'Mobile: 92789 90878', 0, 0, 'L');


$servername = "118.139.181.71";
$database = "c12";
$username = "Khushi";
$password = "Alpesh@01";
$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) { die("Connection failed: " . $conn->connect_error);}

$sql1="select * from booktable where tid='".$_GET['rid']."' ";
$result1 = $conn->query($sql1);

if ($result1->num_rows > 0) 
{
	$row1 = $result1->fetch_assoc();
	
	$pdf->ln(6);
	$pdf->Cell(40, 8, $row1["custname"], 0, 0, 'L');
	$pdf->Cell(45, 8, '', 0, 0, 'C');
	$pdf->Cell(50, 8, 'Address: Chinnar Complex ', 0, 0, 'L');

	
}
else 
{
 	 echo "Error: " . $sql . "<br>" . $conn->error;
}


$pdf->ln(6);
$pdf->Cell(40, 8, 'Date: '.date("d-m-Y"), 0, 0, 'L');
$pdf->ln();
$pdf->Cell(10, 10, 'Sr', 1, 0, 'C');
$pdf->Cell(10, 10, 'Code', 1, 0, 'C');
$pdf->Cell(65, 10, 'Item Name', 1, 0, 'C');
$pdf->Cell(15, 10, 'Price', 1, 0, 'C');
$pdf->Cell(15, 10, 'Qty', 1, 0, 'C');
$pdf->Cell(20, 10, 'Amount', 1, 0, 'C');

$sql="select * from orders where rid='".$_GET['rid']."' ";
$result = $conn->query($sql);
$i=1;
$Amt=0;
$CGST=0;
$SGST=0;
$Total=0;
if ($result->num_rows > 0) 
{
	while($row = $result->fetch_assoc() ) 
	{
	
		$pdf->ln();
		$pdf->Cell(10, 10, $i, 1, 0, 'C');
		$pdf->Cell(10, 10, $row["Itemcode"], 1, 0, 'C');
		$pdf->Cell(65, 10, $row["itemname"], 1, 0, 'C');
		$pdf->Cell(15, 10, $row["itemprice"], 1, 0, 'C');
		$pdf->Cell(15, 10, $row["Qty"], 1, 0, 'C');
		$pdf->Cell(20, 10, $row["amount"], 1, 0, 'C');
		$i=$i+1;
		$Amt=$Amt+$row["amount"];
	}
	$CGST=0.025*$Amt;
	$SGST=0.025*$Amt;
	$Total=$CGST+$SGST+$Amt;
	$pdf->ln();
	$pdf->Cell(85, 6, " ",0, 0, 'C');
	$pdf->Cell(35, 6, "Subtotal", 'L', 0, 'C');
	$pdf->Cell(15, 6, $Amt, 'R', 0, 'C');
	$pdf->ln(6);
	$pdf->Cell(85, 6, " ",0, 0, 'C');
	$pdf->Cell(35, 6, "CGST", 'L', 0, 'C');
	$pdf->Cell(15, 6, $CGST, 'R', 0, 'C');
	$pdf->ln(6);
	$pdf->Cell(85, 6, " ",0, 0, 'C');
	$pdf->Cell(35, 6, "SGST", 'L,B', 0, 'C');
	$pdf->Cell(15, 6, $SGST, 'R,B', 0, 'C');
	$pdf->ln(6);
	$pdf->Cell(85, 6, " ",0, 0, 'C');
	$pdf->Cell(35, 6, "Total", 'L,B', 0, 'C');
	$pdf->Cell(15, 6, $Total, 'R,B', 0, 'C');


	
	
}
else 
{
	 echo "Error: " . $sql . "<br>" . $conn->error;
}
$conn->close();


$pdf->Output();

?>
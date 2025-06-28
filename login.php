<?php 
	$U= $_POST['un'];
	$P= $_POST['Pw'];	
	$op= $_GET['op'];	
	if ($U=="")
	{
		//must have been called from login.php
		session_start();
		$U=$_SESSION["UN"];
		$P=$_SESSION["PW"];
	}
	else
	{
		session_start();
		$_SESSION["UN"]=$U;
		$_SESSION["PW"]=$P;
	}
	$servername = "118.139.181.71";
	$database = "c12";
	$username = "Khushi";
	$password = "Alpesh@01";
	$conn = mysqli_connect($servername, $username, $password, $database);
	// Connection Check
	if (!$conn) {die("Connection failed: " . $conn->connect_error);}
	else
	{
		$sql = "Select * from Uname where UN='".$U."'";		
		if ($result = $conn->query($sql)) 
		{
			/* fetch associative array */
    			if ($row = $result->fetch_assoc()) 
			{
				if ($row["PW"]==$P)
				{
					
					include 'P/Nav.inc';
		?>

		<style>
		        .item 
			{
            			position: absolute;
            			right: 0;
            			background-color: #f4511e;
  				border: none;
  				color: white;
  				padding: 16px 32px;
  				text-align: center;
  				font-size: 16px;
  				margin: 4px 2px;
  				opacity: 0.6;
  				transition: 0.3s;
        		}
			.item:hover {opacity: 1}
			.dropbtn {
			  background-color: #04AA6D;
			  color: white;
			  padding: 16px;
			  font-size: 16px;
			  border: none;
			}
			.dropdown {
				position: absolute;
            			right: 0;
  				display: inline-block;
			}

			.dropdown-content 
			{
  				display: none;
  				position: absolute;
  				background-color: #f1f1f1;
  				min-width: 160px;
  				box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
  				z-index: 1;
			}

			.dropdown-content a 
			{
				color: black;
				padding: 12px 16px;
				
				text-decoration: none;
				display: block;
			}

			.dropdown-content a:hover {background-color: #ddd;}
			.dropdown:hover .dropdown-content {display: block;}
			.dropdown:hover .dropbtn {background-color: #3e8e41;}
		</style>
		        <div class="dropdown">
  				<button class="dropbtn"><?php echo $U;?></button>
  				<div class="dropdown-content">
    					<a href="#">Logout</a>
  				</div>
			</div>
		<?php

					include 'P/Main.inc';
					include 'P/Footer.inc';


				}
				else
				{
				?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Restaurant Login</title>
  <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;500;700&display=swap" rel="stylesheet">
  <style>
    * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
      font-family: 'Poppins', sans-serif;
    }

    body {
      background-image: url('https://images.unsplash.com/photo-1600891964599-f61ba0e24092');
      background-size: cover;
      background-position: center;
      height: 100vh;
      display: flex;
      align-items: center;
      justify-content: center;
    }

    .form-box {
      background-color: rgba(255, 255, 255, 0.95);
      padding: 40px;
      border-radius: 15px;
      box-shadow: 0 10px 25px rgba(0, 0, 0, 0.3);
      width: 350px;
      animation: slideIn 1s ease-out;
    }

    @keyframes slideIn {
      from {
        opacity: 0;
        transform: translateY(-25px);
      }
      to {
        opacity: 1;
        transform: translateY(0);
      }
    }

    h2 {
      text-align: center;
      margin-bottom: 25px;
      color: #e63946;
    }

    .input-group {
      margin-bottom: 20px;
    }

    .input-group label {
      display: block;
      margin-bottom: 5px;
      font-weight: 500;
    }

    .input-group input {
      width: 100%;
      padding: 10px;
      border: 1px solid #ccc;
      border-radius: 8px;
      transition: 0.3s;
    }

    .input-group input:focus {
      border-color: #e63946;
      outline: none;
      box-shadow: 0 0 8px rgba(230, 57, 70, 0.3);
    }

    .btn {
      width: 100%;
      background-color: #e63946;
      color: #fff;
      padding: 10px;
      border: none;
      border-radius: 8px;
      font-size: 16px;
      cursor: pointer;
      transition: background-color 0.3s;
    }
    .btn:hover {
      background-color: #d62828;
    }
    .footer {
      text-align: center;
      margin-top: 15px;
      font-size: 14px;
    }
    .footer a {
      color: #e63946;
      text-decoration: none;
      cursor: pointer;
    }
  </style>
</head>
<body>
  <div class="form-box" id="loginBox">
    <h2>Welcome to TasteBite</h2>
    <center> <p> Invalid Password</p> </center>
    <form id="loginForm" action=login.php method=post >
      <div class="input-group">
        <label for="username">Username</label>
        <input type="text" id="username" name="un" required />
      </div>
      <div class="input-group">
        <label for="password">Password</label>
        <input type="password" id="password" name="Pw" required />
      </div>
      <button class="btn" type="submit">Login</button>
      <div class="footer">
        Don't have an account? <a onclick="showSignUp()">Register</a>
      </div>
    </form>
  </div>

  <div class="form-box" id="signupBox" style="display: none;">
    <h2>Create Account</h2>
    <form id="signupForm" action=SignUp.php method=post>
      <div class="input-group">
        <label for="newUsername">Username</label>
        <input type="text" id="newUsername" name="un" required />
      </div>
      <div class="input-group">
        <label for="email">Email</label>
        <input type="email" id="email" name="eml" required />
      </div>
      <div class="input-group">
        <label for="newPassword">Password</label>
        <input type="password" id="newPassword" name="pw" required />
      </div>
      <button class="btn" type="submit">Sign Up</button>
      <div class="footer">
        Already have an account? <a onclick="showLogin()">Login</a>
      </div>
    </form>
  </div>

  <script>
    const loginBox = document.getElementById('loginBox');
    const signupBox = document.getElementById('signupBox');

    function showSignUp() {
      loginBox.style.display = 'none';
      signupBox.style.display = 'block';
    }
    function showLogin() 
    {
      signupBox.style.display = 'none';
      loginBox.style.display = 'block';
    }
  </script>
</body>
</html>
<?php
				}
			}
			else
			{
					echo "Invalid username";
			}
				
						
		}
	}
?>
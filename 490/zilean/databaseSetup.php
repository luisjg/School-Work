<html>
<head>
</head>
<body>
<?php
//Connects to local server: localhost/phpmyadmin
//Note: Username might be initialized to 'root' with no password "". 
//Change zilean to root if not working in the line below (in mysqli_connect...)
$con = mysqli_connect("localhost", "zilean", "");
if (!$con){
die("Can not connect: " . mysqli_error($con));
}

//Create the database
if (mysqli_query($con, "CREATE DATABASE zilean")){
echo "Your database was created successfully";
} else echo "Error: ".mysqli_error($con);

mysqli_select_db($con, "zilean");

//Create Table for UserData
$sql1 = "CREATE TABLE UserData (
Name varchar(20),
Current_Classes varchar(20),
Times varchar(20),
Professor varchar(20),
Class_ID int,
Total_Units int
)";

//Create Table for CompSci Data
$sql2 = "CREATE TABLE CompSciData (
Current_Classes varchar(20),
Times varchar(20),
Professor varchar(20),
Class_ID int,
Total_Units int,
Requirements_Grad_Class varchar(20)
)";

mysqli_query($con, $sql1);
mysqli_query($con, $sql2);

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

//Delete Specified User Data
if (isset($_POST['delete'])){
$DeleteQuery = "DELETE FROM UserData WHERE Name='$_POST[hidden]'";
mysqli_query($con, $DeleteQuery);
};

//Insert new User and data
if (isset($_POST['add'])){
$AddQuery = "INSERT INTO UserData (Name, Current_Classes, Times, Professor, Class_ID, Total_Units) VALUES ('$_POST[uname]','$_POST[ucurrentclasses]','$_POST[utimes]','$_POST[uprofessor]','$_POST[uclassid]','$_POST[utotalunits]')";
mysqli_query($con, $AddQuery);
};


//Retrieve database information for UserData and Display in a table
$sql = "SELECT * FROM UserData";
$myData = mysqli_query($con, $sql);
echo "<table border = 1>
<tr>
<th>Name</th>
<th>Classes</th>
<th>Times</th>
<th>Professor</th>
<th>Class_ID</th>
<th>Total_Units</th>
</tr>";
while($record = mysqli_fetch_array($myData)){
echo "<form action=databaseSetup.php method=post>";
echo "<tr>";
echo "<td>" . "<input type=text name=name value=" . $record['Name'] . " </td>";
echo "<td>" . "<input type=text name=current_classes value=" . $record['Current_Classes'] . " </td>";
echo "<td>" . "<input type=text name=times value=" . $record['Times'] . " </td>";
echo "<td>" . "<input type=text name=professor value=" . $record['Professor'] . " </td>";
echo "<td>" . "<input type=text name=class_id value=" . $record['Class_ID'] . " </td>";
echo "<td>" . "<input type=text name=total_units value=" . $record['Total_Units'] . " </td>";
echo "<td>" . "<input type=hidden name=hidden value=" . $record['Name'] . " </td>";
echo "<td>" . "<input type=submit name=update value=update" . " </td>";
echo "<td>" . "<input type=submit name=delete value=delete" . " </td>";
echo "</tr>";
echo "</form>";
}
echo "<form action=databaseSetup.php method=post>";
echo "<tr>";
echo "<td><input type=text name=uname></td>";
echo "<td><input type=text name=ucurrentclasses></td>";
echo "<td><input type=text name=utimes></td>";
echo "<td><input type=text name=uprofessor></td>";
echo "<td><input type=text name=uclassid></td>";
echo "<td><input type=text name=utotalunits></td>";
echo "<td>" . "<input type=submit name=add value=add" . " </td>";
echo "</form>";
echo "</table>";
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

mysqli_close($con);

//Close php

?>

</body>
</html>
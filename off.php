<?php
include('db.con.php');

$result = mysqli_query($con , "UPDATE `statu` SET`state`='OFF' WHERE 1");
if($result){
    
$con->close();
}

?>